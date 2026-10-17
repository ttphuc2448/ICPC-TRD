struct Convex_hull_trick {
    struct Line {
        ll a, b;

        double inter(const Line &ot) const {
            return 1.0 * (ot.b - b) / (a - ot.a);
        }

        ll eval(int x) {
            return a * x + b;
        }
    };

    vector <Line> hull;
    int ptr = 0;

    bool bad(const Line &pre, const Line &cur, const Line &nxt) {
        return nxt.inter(pre) <= cur.inter(pre);
    }

    void reset() {
        hull.clear();
    }

    void add(ll a, ll b) {
        Line cur = {a, b};
        while (Sz(hull) >= 2 and bad(hull[Sz(hull) - 2], hull.back(), cur)) hull.pop_back();
        hull.pb(cur);
    }

    ll get(int x) {
        if (ptr >= Sz(hull)) ptr = Sz(hull) - 1;
        while (ptr < Sz(hull) - 1 and hull[ptr + 1].inter(hull[ptr]) <= x) ptr++;
        return hull[ptr].eval(x);
    }
} cht;