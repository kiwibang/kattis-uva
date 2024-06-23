#include <bits/stdc++.h>
using namespace std;

int main() {
    string daysofweek[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    int daysinmonths[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int d, m;
    cin >> d >> m;
    int days = d;
    for (int mnth = 1; mnth < m; ++mnth) {
        days += daysinmonths[mnth];
    }
    cout << daysofweek[(((days) % 7) + 2) % 7] << endl;
    return 0;
}
