#include <bits/stdc++.h>
using namespace std;

int main() {
    // read in inputs
    int n;
    cin >> n;
    vector<int> cards(n);
    for (int i = 0; i < n; ++i) cin >> cards[i];
    vector<int> sorted = cards;
    sort(sorted.begin(), sorted.end());
    int l = 0, r = n - 1;
    while (l < n && cards[l] == sorted[l]) ++l;
    if (l == n) l = r = n / 2;
    else {
        while (cards[r] == sorted[r]) --r;
        reverse(cards.begin() + l, cards.begin() + r + 1);
    }
    cout << (cards == sorted ? to_string(l + 1) + " " + to_string(r + 1) : "impossible") << endl;
    return 0;
}
