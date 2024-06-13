struct ft {
    vector<int> bit; int n;
    ft(int _n) {bit.resize(_n + 1); n = _n + 1;}
    void upd(int i, int x) {++i; for (;i < n; i += i & (-i)) bit[i] += x;}
    int query(int i) {++i; int x = 0; for(; i > 0; i -= i & (-i)) x += bit[i]; return x;}
    int query(int i, int j) {return query(j) - query(i - 1);}
};

template <class T>
struct fenwick_tree {
  int n;
  vector<int> tree;

  fenwick_tree(int _n) : n(_n), tree(n + 5, 0) {}

  void update(int i, T x) {
    for (++i; i < n; i += i & (-i)) {
      tree[i] += x;
    }
  }

  T query(int i) {
    T res = 0;
    for (++i; i > 0; i -= i & (-i)) {
      res += tree[i];
    }
    return res;
  }

  T query(int l, int r) {
    return query(r) - (l ? query(l - 1) : 0);
  }
}
