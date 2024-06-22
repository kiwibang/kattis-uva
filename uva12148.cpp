#include <bits/stdc++.h>
using namespace std;

map<int, int> monthsindays;

bool eqsdate(vector<long long>& a, vector<long long>& b) {
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
}

bool isleapyr(long long y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

vector<long long> addd(long long d, long long m, long long y) {
    if (m == 12) {
        if (d == 31) {
            d = 1;
            m = 1;
            ++y;
        } else {
            ++d;
        }
    } else if (m == 2) {
        if (isleapyr(y)) {
            if (d == 29) {
                d = 1;
                ++m;
            } else {
                ++d;
            }
        } else {
            if (d == 28) {
                d = 1;
                ++m;
            } else {
                ++d;
            }
        }
    } else {
        if (monthsindays[m] == d) {
            d = 1;
            ++m;
        } else {
            ++d;
        }
    }
    vector<long long> res;
    res.push_back(d);
    res.push_back(m);
    res.push_back(y);
    return res;
}

int main() {
    monthsindays[1] = 31;
    monthsindays[2] = 28;
    monthsindays[3] = 31;
    monthsindays[4] = 30;
    monthsindays[5] = 31;
    monthsindays[6] = 30;
    monthsindays[7] = 31;
    monthsindays[8] = 31;
    monthsindays[9] = 30;
    monthsindays[10] = 31;
    monthsindays[11] = 30;
    monthsindays[12] = 31;

    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        // read in the first date
        long long pd, pm, py, pc, d, m, y, c;
        cin >> pd >> pm >> py >> pc;
        long long daysconsec = 0, res = 0;
        // read in the remaining dates
        for (int i = 0; i < n - 1; ++i) {
            // read in the current date
            cin >> d >> m >> y >> c;
            vector<long long> curr;
            curr.push_back(d);
            curr.push_back(m);
            curr.push_back(y);
            vector<long long> addone = addd(pd, pm, py);
            // check if adding 1 day to the previous date equals to the current date
            if (eqsdate(curr, addone)) {
                // update the consumption
                res += c - pc;
                ++daysconsec;
            }
            // update the previous record to the current one
            pd = d;
            pm = m;
            py = y;
            pc = c;
        }
        // print the res
        cout << daysconsec << " " << res << endl;
    }
    return 0;
}
