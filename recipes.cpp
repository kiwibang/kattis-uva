#include <bits/stdc++.h>
using namespace std;

int main() {
    // read in the number of testcases
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        // get the number of ingredients, num of portions, and num of desired portions
        double r, p, d;
        cin >> r >> p >> d;
        // get the scaling factor
        double sf = d / p;
        double mwt;
        vector<string> foods;
        vector<double> wts;
        vector<double> pctgs;
        for (int i = 0; i < r; ++i) {
            string name;
            double wt, pct;
            cin >> name >> wt >> pct;
            foods.push_back(name);
            wts.push_back(wt);
            pctgs.push_back(pct);
            // check if this is the baker's percentage food
            if (pct == 100.0) {
                mwt = wt;
                mwt *= sf;
            }
        }
        // print out the scaled foods
        cout << "Recipe # " << tc << endl;
        for (int i = 0; i < foods.size(); ++i) {
            cout << foods[i] << " ";
            cout << fixed << setprecision(1) << mwt * (pctgs[i] / 100) << endl;
        }
        cout << "----------------------------------------" << endl;
    }
    return 0;
}
