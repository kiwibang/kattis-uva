#include <bits/stdc++.h>
using namespace std;

int main() {
    set<long long> res;
    long long n;
    cin >> n;
    for (long long i = 1; i <= (long long) sqrt(n); ++i) {
        if (!(n % i)) {
            res.insert(i - 1);
            res.insert((n / i) - 1);
        }
    }
    for (auto r = res.begin(); r != res.end(); ++r) {
        cout << *r << " ";
    }
    cout << endl;
    return 0;
}

