struct FastSet {
    static constexpr int BASE = 6;
    static constexpr int RANGE = 1 << BASE;
    static constexpr int FILTER = RANGE - 1;
    int N, log;
    vector<vector<u64>> seg;
    FastSet(int _N) { build(_N); }
    void build(int _N) {
        seg.clear();
        N = _N;
        while(true) {
            seg.emplace_back((_N + FILTER) >> BASE, 0);
            if(seg.back().size() <= 1) break;
            _N = seg.back().size();
        }
    }
    void insert(int k) {
        for(int i = 0; i < seg.size(); ++i, k >>= BASE) {
            if(seg[i][k >> BASE] >> (k & FILTER) & 1) break;
            seg[i][k >> BASE] ^= u64(1) << (k & FILTER);
        }
    }
    void erase(int k) {
        u64 x = 0;
        for(int i = 0; i < seg.size(); ++i, k >>= BASE) {
            seg[i][k >> BASE] &= ~(u64(1) << (k & FILTER));
            seg[i][k >> BASE] |= x << (k & FILTER);
            x = bool(seg[i][k >> BASE]);
            if(x) break;
        }
    }
    bool operator[](int k) {
        assert(0 <= k && k < N);
        return seg[0][k >> BASE] >> (k & FILTER) & 1;
    }
    int next(int k) {
        k = max(0, k);
        for(int i = 0; i < seg.size(); ++i) {
            if((k >> BASE) >= seg[i].size()) break;
            u64 x = seg[i][k >> BASE] >> (k & FILTER);
            if(!x) { ++(k >>= BASE); continue; }
            k += __builtin_ctzll(x);
            for(int j = i - 1; j >= 0; --j) k = (k << BASE) | __builtin_ctzll(seg[j][k]);
            return k;
        }
        return N;
    }
    int prev(int k) {
        k = min(k, N - 1);
        for(int i = 0; i < seg.size(); ++i) {
            if(k < 0) break;
            u64 x = seg[i][k >> BASE] << (63 - (k & FILTER));
            if(!x) { --(k >>= BASE); continue; }
            k -= __builtin_clzll(x);
            for(int j = i - 1; j >= 0; --j) k = (k << BASE) | (63 - __builtin_clzll(seg[j][k]));
            return k;
        }
        return -1;
    }
    template<typename F>
    void enumerate(int L, int R, F f) {
        for(int i = next(L); i < R; i = next(i + 1)) f(i);
    }
};