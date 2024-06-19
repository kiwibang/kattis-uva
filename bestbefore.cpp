#include <bits/stdc++.h>
using namespace std;

bool isleapyr(long long year) {
    if (year % 400 == 0) {
        return true;
    }
    if (year % 100 == 0) {
        return false;
    }
    if (year % 4 == 0) {
        return true;
    }
    return false;
}

map<int, int> mxd;

bool isvalid(int year, int month, int day) {
    // convert the year 
    year = year / 100 == 0 ? 2000 + year : year;
    // invalid year
    if (year < 2000 || year > 2999) {
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
        if (isleapyr(year)) {
            return true;
        }
        return false;
    }
    // check whether the day is within range for the month
    return day <= mxd[month];
}

bool issmaller(int yr1, int mn1, int d1, int yr2, int mn2, int d2) {
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

    // read the inputs
    string date, temp, tok;
    cin >> date;
    temp = date;
    istringstream iss(temp);
    vector<int> nms(3, 0);
    // extract the 3 digits
    int j = 0;
    while (getline(iss, tok, '/')) {
        nms[j++] = stoi(tok);
    }
    // go over the possible permutations, keep the earliest possible date
    int yr = 3000, mnth = 3000, day = 3000;
    for (int i = 0; i < 6; ++i) {
        // try the current permutation
        if (isvalid(nms[pmts[i][0]], nms[pmts[i][1]], nms[pmts[i][2]]) && issmaller(nms[pmts[i][0]], nms[pmts[i][1]], nms[pmts[i][2]], yr, mnth, day)) {
            yr = nms[pmts[i][0]];
            mnth = nms[pmts[i][1]];
            day = nms[pmts[i][2]];
        }
    }
    // case where no valid date
    if (yr == 3000 && mnth == 3000 && day == 3000) {
        cout << date << " is illegal" << endl;
        return 0; 
    }
    // print the earliest date
    yr = yr / 100 == 0 ? 2000 + yr : yr;
    cout << yr << "-";
    cout << setfill('0') << setw(2) << mnth << "-";
    cout << setfill('0') << setw(2) << day << endl;
    return 0;
}
