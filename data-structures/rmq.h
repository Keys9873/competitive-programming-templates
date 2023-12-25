template <typename T>
struct RMQ {
    vector<vector<T>> table;

    T merge(T a, T b) { // idempotent fn
        return min(a, b);
    }

    RMQ(vector<T> &a) : table(__lg(a.size()) + 1, vector<T>(a.size())) {
        table[0] = a;
        for (int i = 1; i <= __lg(a.size()); i++) {
            for (int j = 0; j + (1 << i) <= a.size(); j++) {
                table[i][j] = merge(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T query(int l, int r) {
        int i = __lg(r - l);
        return merge(table[i][l], table[i][r - (1 << i)]);
    }
};