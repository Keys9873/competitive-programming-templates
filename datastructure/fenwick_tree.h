template <class T>
struct fenwick {
  int n;
  vector<int> tree;

  fenwick(int _n) : n(_n + 1), tree(n + 1, 0) {}

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
};
