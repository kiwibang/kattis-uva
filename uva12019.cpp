#include <bits/stdc++.h>
using namespace std;

int main() {
    string daysofweek[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    int daysinmonths[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int t;
    cin >> t;
    while (t--) {
        int month, day;
        cin >> month >> day;
        if (month == 1 && day < 10) {
            if (day == 9) {
                cout << "Sunday" << endl;
            } else if (day == 8) {
                cout << "Saturday" << endl;
            } else if (day == 7) {
                cout << "Friday" << endl;
            } else if (day == 6) {
                cout << "Thursday" << endl;
            } else if (day == 5) {
                cout << "Wednesday" << endl;
            } else if (day == 4) {
                cout << "Tuesday" << endl;
            } else if (day == 3) {
                cout << "Monday" << endl;
            } else if (day == 2) {
                cout << "Sunday" << endl;
            } else if (day == 1) {
                cout << "Saturday" << endl;
            }
            continue;
        }
        int days = day;
        for (int mnth = 1; mnth < month; ++mnth) {
            days += daysinmonths[mnth];
        }
        cout << daysofweek[(days - 10) % 7] << endl;
    }
    return 0;
}
