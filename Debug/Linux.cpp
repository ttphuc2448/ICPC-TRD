#include <bits/stdc++.h>
using namespace std;

#define file "TASK"
const int NTEST = 100;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
long long Rand(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

void makeTest() {
    ofstream cout(file".inp");

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(time(NULL));
    
    system("g++ -O2 " file ".cpp -o " file);
    system("g++ -O2 " file "_brute.cpp -o " file "_brute");

    for (int idT = 1; idT <= NTEST; idT++) {
        makeTest();
        system("./" file " < " file ".inp > " file ".out");
        system("./" file "_brute < " file ".inp > " file ".ans");

        cerr << "Test " << idT << ": ";

        if (system("diff -q -Z " file ".out " file ".ans > /dev/null") != 0) {
            cerr << "WA\n";
            cerr << "\nCheck " file ".inp, " file ".out, and " file ".ans\n";
            return 0;
        }
        cerr << "AC\n";
    }

    cerr << "\nPassed all " << NTEST << " tests!\n";
    return 0;
}