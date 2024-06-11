#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int tc = 1; tc <= n; ++tc) {
        string w;
        getline(cin, w);
        int a = 0, b = 0;
        int idx = 0;
        while (idx < w.size() && isdigit(w[idx])) {
            a = (a * 10) + (w[idx] - '0');
            ++idx;
        }
        ++idx;
        while (idx < w.size() && !isdigit(w[idx])) {
            ++idx;
        }
        if (idx < w.size()) {
            b = (w[idx] - '0');
        }
        cout << "Case " << tc << ": " << a * 0.5 + b * 0.05 << endl;
    }
    return 0;
}
