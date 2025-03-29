// this doesnt work lol
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long mnodd = LLONG_MAX, mneven = LLONG_MAX,  mx = LLONG_MIN;
        long long sum = 0;
        int numodd = 0, numeven = 0;
        for (int i = 0; i < n; ++i) {
            long long curr;
            cin >> curr;
            sum += curr,  mx = max(mx, curr);
            if (curr & 1) {
                ++numodd;
                mnodd = min(mnodd, curr);
            } else {
                ++numeven;
                mneven = min(mneven, curr);
            } 
        }
        if (numodd == 0 || numeven == 0) { // no transfers can be made
            cout << mx << endl;
        } else if (numodd == 1 && numeven == 1) {
            cout << sum << endl;
        } else { // transfers can be made
            if (numodd < numeven) {
                cout << sum - mnodd << endl;
            } else if (numodd > numeven) {
                cout << sum - mneven << endl;
            } else {
                cout << sum - min(mnodd, mneven) << endl;
            }
        }
    }
    return 0;
}

