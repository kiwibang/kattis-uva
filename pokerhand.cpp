#include <bits/stdc++.h>
using namespace std;

int main() {
    string cd;
    map<char, int> d;
    for (int i = 0; i < 5; ++i) {
        cin >> cd;
        if (!d[cd[0]]) {
            d[cd[0]] = 0;
        }
        d[cd[0]]++;
    }
    int res = 0;
    for (const auto& p : d) {
        res = max(res, p.second);
    }
    cout << res << endl;
    return 0;
}
