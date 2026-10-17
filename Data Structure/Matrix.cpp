struct Matrix {
    int n, m;
    vector <vector <ll>> val;

    Matrix(int _n = 0, int _m = 0) : n(_n), m(_m) {
        val.assign(n + 5, vector <ll> (m + 5, 0));
    }

    Matrix(vector <vector <ll>> _val) : val(_val) {
        n = Sz(val);
        m = Sz(val[0]);
    }

    vector <ll> & operator [] (const int &id) {
        return val[id];
    }

    Matrix operator * (Matrix ot) {
        Matrix res(n, ot.m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < ot.m; j++) {
                for (int k = 0; k < m; k++) {
                    res[i][j] += val[i][k] * ot[k][j];
                    if (res[i][j] >= modSqr) res[i][j] -= modSqr;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < ot.m; j++) {
                res[i][j] %= mod;
            }
        }

        return res;
    }

    Matrix Pow(ll pw) {
        Matrix res(n, n);
        for (int i = 0; i < n; i++) res[i][i] = 1;

        Matrix A = (*this);

        while (pw) {
            if (pw & 1) res = res * A;
            A = A * A;
            pw >>= 1;
        }
        return res;
    }
};