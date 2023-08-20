/**
 * Description: Performs static range queries in O(1).
 * Merge function must be idempotent, meaning that it doesn't matter
 * if some item is considered more than once while querying.
 * Verification: https://judge.yosupo.jp/submission/156288
 */

template <typename T>
struct SparseTable {
    vector<vector<T>> table;
 
    SparseTable(vector<T> &a) : table(__lg(ssize(a)) + 1, vector<T>(ssize(a))) {
        table[0] = a;
        for (int i = 1; i <= __lg(ssize(a)); i++) {
            for (int j = 0; j + (1 << i) <= ssize(a); j++) {
                table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
 
    T query(int l, int r) {
        int i = __lg(r - l);
        return min(table[i][l], table[i][r - (1 << i)]);
    }
};