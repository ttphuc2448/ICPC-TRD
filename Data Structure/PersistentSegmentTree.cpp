struct Persistent_segment_tree {
    int cntNode = 0;
    struct Node {
        ll sum;
        int left, right;
 
        Node() {
            sum = 0;
            left = 0;
            right = 0;
        }
    } d[N * 4 + N * LOG];
    vector <int> version;
 
    int build(int l, int r) {
        int id = ++cntNode;
        if (l == r) {
            d[id].sum = a[l];
            return id;
        }
        int mid = (l + r) >> 1;
        d[id].left = build(l, mid);
        d[id].right = build(mid + 1, r);
        d[id].sum = d[d[id].left].sum + d[d[id].right].sum;
        return id;
    }
 
    int update(int id, int l, int r, int pos, int val) {
        if (r < pos or l > pos) return id;
        int idx = ++cntNode;
        if (l == r and r == pos) {
            d[idx].sum = val;
            return idx;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            d[idx].right = d[id].right;
            d[idx].left = update(d[id].left, l, mid, pos, val);
        }
        else {
            d[idx].left = d[id].left;
            d[idx].right = update(d[id].right, mid + 1, r, pos, val);
        }
        d[idx].sum = d[d[idx].left].sum + d[d[idx].right].sum;
        return idx;
    }
 
    ll get(int id, int l, int r, int x, int y) {
        if (r < x or l > y) return 0;
        if (x <= l and r <= y) return d[id].sum;
        int mid = (l + r) >> 1;
        return get(d[id].left, l, mid, x, y) + get(d[id].right, mid + 1, r, x, y);
    }
 
    void init() {
        version.push_back(build(1, n));
    }
 
    void update(int ver, int pos, int val) {
        version[ver] = update(version[ver], 1, n, pos, val);
    }
 
    void get(int ver, int l, int r) {
        cout << get(version[ver], 1, n, l, r) << "\n";
    }
 
    void copy(int ver) {
        int id = ++cntNode;
        version.push_back(id);
        d[id] = d[version[ver]];
    }
} seg;