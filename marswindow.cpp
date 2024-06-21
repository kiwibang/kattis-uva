#include <bits/stdc++.h>
using namespace std;

int main() {
    int year;
    cin >> year;
    int startyear = 2018, startmonth = 3;
    while (startyear < year) {
        startmonth += 26;
        while (startmonth >= 12) {
            startmonth -= 12;
            ++startyear;
        }
    }
    if (startyear == year) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}
