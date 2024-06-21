#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> monthtoid;
    monthtoid["JAN"] = 1;
    monthtoid["FEB"] = 2;
    monthtoid["MAR"] = 3;
    monthtoid["APR"] = 4;
    monthtoid["MAY"] = 5;
    monthtoid["JUN"] = 6;
    monthtoid["JUL"] = 7;
    monthtoid["AUG"] = 8;
    monthtoid["SEP"] = 9;
    monthtoid["OCT"] = 10;
    monthtoid["NOV"] = 11;
    monthtoid["DEC"] = 12;

    vector<string> months;
    months.push_back("JAN");
    months.push_back("FEB");
    months.push_back("MAR");
    months.push_back("APR");
    months.push_back("MAY");
    months.push_back("JUN");
    months.push_back("JUL");
    months.push_back("AUG");
    months.push_back("SEP");
    months.push_back("OCT");
    months.push_back("NOV");
    months.push_back("DEC");

    map<string, int> days;
    days["MON"] = 1;
    days["TUE"] = 2;
    days["WED"] = 3;
    days["THU"] = 4;
    days["FRI"] = 5;
    days["SAT"] = 6;
    days["SUN"] = 7;

    map<string, int> monthtodays;
    monthtodays["JAN"] = 31;
    monthtodays["FEB"] = 28;
    monthtodays["MAR"] = 31;
    monthtodays["APR"] = 30;
    monthtodays["MAY"] = 31;
    monthtodays["JUN"] = 30;
    monthtodays["JUL"] = 31;
    monthtodays["AUG"] = 31;
    monthtodays["SEP"] = 30;
    monthtodays["OCT"] = 31;
    monthtodays["NOV"] = 30;
    monthtodays["DEC"] = 31;

    int d;
    string dom, day;
    cin >> d >> dom >> day;
    int daysp = 0;
    for (int i = 0; i < 12; ++i) {
        if (months[i] == dom) {
            break;
        }
        daysp += monthtodays[months[i]];
    }
    daysp += (d - 1);
    int res = (days[day] + daysp) % 7;
    if ((res == 5 || res == 4) && monthtoid[dom] > 2) {
        cout << "not sure" << endl;
    } else if (res == 5) {
        cout << "TGIF" << endl;
    } else {
        cout << ":(" << endl;
    }
    return 0;
}
