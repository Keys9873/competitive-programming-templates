struct dsu {
    vector<int> a;

    dsu(int n) : a(n, -1) {}

    int find(int x) {
        return a[x] < 0 ? x : a[x] = find(a[x]);
    }

    int size(int x) {
        return -a[find(x)];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return 0;
        }
        if (a[x] > a[y]) {
            swap(x, y);
        }
        a[x] += a[y];
        a[y] = x;
        return 1;
    }
};
