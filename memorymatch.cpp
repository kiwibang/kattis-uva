#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1. read the inputs
    int n, k;
    cin >> n >> k;
    set<string> finished;
    map<string, set<int> > mp;
    set<int> seen;
    for (int i = 0; i < k; ++i) {
        int c1, c2;
        string p1, p2;
        cin >> c1 >> c2 >> p1 >> p2;
        if (p1 == p2) {
            finished.insert(p1);
        } else {
            mp[p1].insert(c1);
            mp[p2].insert(c2);
        }
        seen.insert(c1);
        seen.insert(c2);
    }
    // 2. process the inputs
    // if number of seen pairs is equal to the total number of pairs
    if (mp.size() + finished.size() >= n / 2) {
        cout << n / 2 - finished.size() << endl;
        return 0;
    }
    // else, count number of completable pairs
    int cnt = 0;
    for (auto& [card, se] : mp) {
        // if not finished and we have enough information to determine the pair
        // then we count
        if (finished.count(card) == 0 && se.size() >= 2) {
            ++cnt;
        }
    }
    // edge case: if we have flipped all but one pair left => can deduce
    if (seen.size() == n - 2 && mp.size() + finished.size() >= (n / 2) - 1) {
        ++cnt;
    }
    cout << cnt << endl;
    return 0;
}
