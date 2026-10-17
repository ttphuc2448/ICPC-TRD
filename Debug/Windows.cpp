#include <bits/stdc++.h>
using namespace std;
#define file "TASK"
const int NTEST = 100;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
long long Rand(long long l, long long r) {
    return uniform_int_distribution <int> (l, r) (rng);
}

void makeTest() {
    ofstream cout(file".inp");

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(time(NULL));

    for (int idT = 1; idT <= NTEST; idT++) {
        makeTest();
        system(file".exe");
        system(file"_brute.exe");

        cerr << "Test " << idT << ": ";
        if (system("fc "file".out "file".ans")) {
            cerr << "WA\n";
            return 0;
        }
        cerr << "AC\n";
    }
    return 0;
}