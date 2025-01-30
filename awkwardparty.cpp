#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, clang;
    cin >> n;
    int res = n;
    unordered_map<int, int> langtopos;
    for (int i = 0; i < n; ++i) {
        cin >> clang;
        // case where someone earlier speaks the same language
        // as the current guest
        if (langtopos.find(clang) != langtopos.end()) {
            res = min(res, i - langtopos[clang]);
        }
        langtopos[clang] = i;
    }
    cout << res << endl;
    return 0;
}

