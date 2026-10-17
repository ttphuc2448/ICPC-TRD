struct Point {
    ll x, y;
 
    Point(ll x = 0, ll y = 0) : x(x), y(y) {}
};
 
struct Vector {
    ll x, y;
 
    Vector(Point A, Point B) : x(B.x - A.x), y(B.y - A.y) {}
 
    ll cross(const Vector &ot) const {
        return x * ot.y - ot.x * y;
    }
};
 
bool cw(const Point &A, const Point &B, const Point &C) {
    return Vector(A, B).cross(Vector(A, C)) < 0;
}
 
int n;
vector <Point> a;
 
vector <Point> Convex_hull() {
    vector <Point> lower, upper;
    sort(a.begin(), a.end(), [] (const Point &A, const Point &B) {
        if (A.x == B.x) return A.y < B.y;
        return A.x < B.x;
    });
 
    lower.pb(a[0]);
    for (int i = 1; i < n; i++) {
        while (Sz(lower) >= 2 and cw(lower[Sz(lower) - 2], lower.back(), a[i])) lower.pop_back();
        lower.pb(a[i]);
    }
 
    upper.pb(a[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        while (Sz(upper) >= 2 and cw(upper[Sz(upper) - 2], upper.back(), a[i])) upper.pop_back();
        upper.pb(a[i]);
    }
 
    if (Sz(lower) + Sz(upper) == 2) return lower;
    lower.pop_back();
    upper.pop_back();
    vector <Point> hull = lower;
    hull.insert(hull.end(), upper.begin(), upper.end());
    return hull;
}