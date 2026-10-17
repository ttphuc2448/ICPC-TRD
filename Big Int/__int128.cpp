istream& operator>>(istream& in, __int128_t &n) {
    string s;
    if (!(in >> s)) return in;
    n = 0;
    int i = 0, sign = 1;
    if (s[0] == '-') {
        sign = -1;
        i = 1;
    } else if (s[0] == '+') {
        i = 1;
    }
    for (; i < s.length(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            n = n * 10 + (s[i] - '0');
        }
    }
    n *= sign;
    return in;
}

ostream& operator<<(ostream& out, __int128_t n) {
    if (n == 0) return out << 0;
    if (n < 0) {
        out << '-';
        n = -n;
    }
    string s = "";
    while (n > 0) {
        s += (char)('0' + (n % 10));
        n /= 10;
    }
    for (int i = (int)s.length() - 1; i >= 0; --i) {
        out << s[i];
    }
    return out;
}