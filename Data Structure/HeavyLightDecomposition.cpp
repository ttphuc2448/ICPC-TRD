struct Heavy_light_decomposition {
    int head[N], id[N];
    int idCnt = 0;

    void dfs(int u, int pre, int top) {
        id[u] = ++idCnt;
        head[u] = top;

        int heavySz = 0, heavy = -1;
        for (int v: adj[u]) if (v != pre) if (maxi(heavySz, sz[v])) heavy = v;

        if (heavy == -1) return;
        dfs(heavy, u, top);
        for (int v: adj[u]) if (v != pre and v != heavy) dfs(v, u, v);
    }

    void init() {
        dfs(1, 1, 1);
        for (int u = 1; u <= n; u++) valHld[id[u]] = a[u];
        seg.init(1, 1, n);
    }

    void update(int pos, int val) {
        seg.update(1, 1, n, id[pos], val);
    }

    int get(int u, int v) {
        int res = -inf;

        while (head[u] != head[v]) {
            if (id[u] > id[v]) swap(u, v);
            maxi(res, seg.get(1, 1, n, id[head[v]], id[v]));
            v = par[head[v]];
        }

        if (id[u] > id[v]) swap(u, v);
        maxi(res, seg.get(1, 1, n, id[u], id[v]));
        return res;
    }
} hld;