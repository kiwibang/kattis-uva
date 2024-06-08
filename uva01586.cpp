#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, double> mp;
    mp['C'] = 12.01;
    mp['H'] = 1.008;
    mp['O'] = 16.00;
    mp['N'] = 14.01;
    int t;
    cin >> t;
    while (t--) {
        string formula;
        cin >> formula;
        int i = 0;
        double mol = 0;
        int n = formula.size();
        while (i < n) {
            // get the element
            char element = formula[i++];
            // get the number of elements
            int count = 0;
            while (i < n && !isalpha(formula[i])) {
                count = count * 10 + (formula[i] - '0');
                ++i;
            }
            if (count == 0) {
                mol += mp[element];
            } else {
                mol += mp[element] * count;
            }
        }
        cout << fixed << setprecision(3) << mol << endl;
    }
    return 0;
}
