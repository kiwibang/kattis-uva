#include <bits/stdc++.h>
using namespace std;

bool isleapyr(long long century, long long year) {
    long long temp = century + year;
    if (temp == 0) {
        return true;
    }
    if (temp % 4 == 0) {
        return true;
    }
    if (temp % 400 == 0) {
        return true;
    }
    return false;
}

map<int, int> mxd;

bool isv(int year, int month, int day, long long century) {
    // invalid year
    if (year < 0 || year >= 100) {
        return false;
    }
    // invalid month 
    if (month <= 0 || month > 12) {
        return false;
    }
    // invalid day
    if (day <= 0 || day > 31) {
        return false;
    }
    // check whether day is feb 29 
    if (month == 2 && day == 29) {
        // check whether leap year
        if (isleapyr(century, year)) {
            return true;
        }
        return false;
    }
    // check whether the day is within range for the month
    if (day > mxd[month]) {
        return false;
    }
    return true;
}

bool smaller(int yr1, int mn1, int d1, int yr2, int mn2, int d2) {
    if (yr1 < yr2) {
        return true;
    }
    if (yr1 > yr2) {
        return false;
    }
    // yr1 == yr2
    if (mn1 < mn2) {
        return true;
    }
    if (mn1 > mn2) {
        return false;
    }
    // mn1 == mn2
    if (d1 < d2) {
        return true;
    }
    return false;
}

int main() {
    // possible permutations
    vector<vector<int> > pmts;
    vector<int> p1;
    p1.push_back(0);
    p1.push_back(1);
    p1.push_back(2);
    vector<int> p2;
    p2.push_back(0);
    p2.push_back(2);
    p2.push_back(1);
    vector<int> p3;
    p3.push_back(1);
    p3.push_back(0);
    p3.push_back(2);
    vector<int> p4;
    p4.push_back(1);
    p4.push_back(2);
    p4.push_back(0);
    vector<int> p5;
    p5.push_back(2);
    p5.push_back(0);
    p5.push_back(1);
    vector<int> p6;
    p6.push_back(2);
    p6.push_back(1);
    p6.push_back(0);
    pmts.push_back(p1);
    pmts.push_back(p2);
    pmts.push_back(p3);
    pmts.push_back(p4);
    pmts.push_back(p5);
    pmts.push_back(p6);

    mxd[1] = 31;
    mxd[2] = 28;
    mxd[3] = 31;
    mxd[4] = 30;
    mxd[5] = 31;
    mxd[6] = 30;
    mxd[7] = 31;
    mxd[8] = 31;
    mxd[9] = 30;
    mxd[10] = 31;
    mxd[11] = 30;
    mxd[12] = 31;

    // read the number of testcases
    int t;
    cin >> t;
    // loop over the testcases
    while (t--) {
        // get the century that jimmy is living in, along with the expiry date
        long long c;
        vector<int> nms(3, 0);
        cin >> c >> nms[0] >> nms[1] >> nms[2];
        // track the minimum date
        int mnyr = 200, mnmnth = 200, mnd = 200;
        // try all possible permutations
        for (int i = 0; i < 6; ++i) {
            if (isv(nms[pmts[i][0]], nms[pmts[i][1]], nms[pmts[i][2]], c) && smaller(nms[pmts[i][0]], nms[pmts[i][1]], nms[pmts[i][2]], mnyr, mnmnth, mnd)) {
                mnyr = nms[pmts[i][0]];
                mnmnth = nms[pmts[i][1]];
                mnd = nms[pmts[i][2]];
            }
        }
        if (mnd == 200 && mnmnth == 200 && mnyr == 200) {
            cout << -1 << endl;
            continue;
        }
        cout << setfill('0') << setw(2)<< mnyr << " ";
        cout << setfill('0') << setw(2) << mnmnth << " ";
        cout << setfill('0') << setw(2) << mnd << endl;
    }
    return 0;
}
