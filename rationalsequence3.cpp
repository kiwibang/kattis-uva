#include <bits/stdc++.h>
using namespace std;

pair<int, int> getf(int n) {
    if (n == 1) return pair<int, int>(1, 1);
    pair<int, int> parent = n & 1 ? getf((n - 1) / 2) : getf(n / 2);
    return n & 1 ? pair<int, int>(parent.first + parent.second, parent.second) : pair<int, int>(parent.first, parent.first + parent.second);
}

int main() {
    int p, id, n;
    cin >> p;
    while (p--) {
        cin >> id >> n;
        pair<int, int> f = getf(n);
        cout << id << " " << f.first << "/" << f.second << endl;
    }
    return 0;
}

