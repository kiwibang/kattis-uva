#include <bits/stdc++.h>
using namespace std;

bool isleapyr(long long year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
    map<string, int> monthtoint;
    monthtoint["January"] = 1;
    monthtoint["February"] = 2;
    monthtoint["March"] = 3;
    monthtoint["April"] = 4;
    monthtoint["May"] = 5;
    monthtoint["June"] = 6;
    monthtoint["July"] = 7;
    monthtoint["August"] = 8;
    monthtoint["September"] = 9;
    monthtoint["October"] = 10;
    monthtoint["November"] = 11;
    monthtoint["December"] = 12;

    vector<int> daysinmonths(12, 0);
    daysinmonths[0] = 31;
    daysinmonths[1] = 31;
    daysinmonths[2] = 31;
    daysinmonths[3] = 31;
    daysinmonths[4] = 31;
    daysinmonths[5] = 31;
    daysinmonths[6] = 31;
    daysinmonths[7] = 31;
    daysinmonths[8] = 31;
    daysinmonths[9] = 31;
    daysinmonths[10] = 31;
    daysinmonths[11] = 31;

    int t;
    cin >> t;
    // loop over the testcases
    for (int tc = 1; tc <= t; ++tc) {
        // read in the testcases
        string month;
        long long day, monthint, year;
        cin >> month;
        cin >> day;
        cin.ignore(1, ',');
        cin >> year;

        string monthend;
        long long dayend, monthintend, yearend;
        cin >> monthend;
        cin >> dayend;
        cin.ignore(1, ',');
        cin >> yearend;

        monthint = monthtoint[month];
        monthintend = monthtoint[monthend];
        if (monthint > 2) {
            ++year;
        }
        if (monthintend < 2 || (monthintend == 2 && dayend < 29)) {
            --yearend;
        }
        int res = (yearend / 4) - (year - 1) / 4;
        res -= yearend / 100 - (year - 1) / 100;
        res += yearend / 400 - (year - 1) / 400;
        cout << "Case " << tc << ": " << res << endl;
    }
    return 0;
}
