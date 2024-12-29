#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int s;
        cin >> s;
        vector<int> blues;
        vector<int> reds;
        for (int j = 0; j < s; ++j) {
            string curr;
            cin >> curr;
            if (curr[curr.size() - 1] == 'B') {
                blues.push_back(stoi(curr.substr(0, curr.size() - 1)));
            } else {
                reds.push_back(stoi(curr.substr(0, curr.size() - 1)));
            }
        }
        sort(blues.begin(), blues.end());
        sort(reds.begin(), reds.end());
        int p1 = blues.size() - 1, p2 = reds.size() - 1, res = 0, cmp = 0;
        while (p1 >= 0 && p2 >= 0) {
            res += blues[p1--] + reds[p2--];
            cmp += 2;
        }
        cout << "Case #" << i << ": " << res - cmp << endl; 
    } 
    return 0;
}

