#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, n, m;
    cin >> s >> n >> m;
    vector<int> prices(s);
    for (int i = 0; i < s; ++i) cin >> prices[i];
    int incl = 1, decl = 1, peaks = 0, valleys = 0, prevdecl = 0, previncl;
    bool ri = true, rd = true;
    for (int i = 1; i < s; ++i) {
        if (prices[i - 1] <= prices[i]) {
            ++incl; // update size of increasing segment
            // end of increasing segment
            if (i == s - 1 || prices[i] > prices[i + 1]) {
                // check for valley
                if (prevdecl >= m && incl >= m) ++valleys;
                previncl = incl, incl = 1, decl = 1;
            }
        } else {
            ++decl; // update decreasing segment
            // end of decreasing segment
            if (i == s - 1 || prices[i] < prices[i + 1]) {
                // check for peak
                if (decl >= n && previncl >= n) ++peaks;
                prevdecl = decl, incl = 1, decl = 1;
            }
        }
    }
    cout << peaks << " " << valleys << endl;
    return 0;
}

