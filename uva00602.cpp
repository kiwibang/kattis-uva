#include <bits/stdc++.h>
using namespace std;

map<int, int> daysinmonths;

bool isleapyr(int year) {
    return year <= 1752 ? year % 4 == 0 : (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int invalid(int month, int day, int year) {
    if(month < 1 || month > 12 || day < 1 || year < 1 ||
       (year == 1752 && month == 9 && day < 14 && day > 2) ||
       day > daysinmonths[month] + (month == 2 && isleapyr(year))) {
            return 1;
       }
    return 0;
}

// function that gets the day given a date
string getday(int month, int day, int year) {
    // Create a tm structure and set the date
    tm time_in = { 0, 0, 0, day, month - 1, year - 1900 };

    // Call mktime to normalize the tm structure and calculate the day of the week
    mktime(&time_in);

    // Array with the names of the days of the week
    const char* daysOfWeek[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

    // Return the name of the day of the week
    return daysOfWeek[time_in.tm_wday];
}

char weekName[7][10]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
char monthName[13][10] = {"", "January","February","March","April","May","June",
                          "July","August","September","October","November","December"};

void solve(int m, int d, int y) {
    int i, w = 1;

    if(invalid(m, d, y)) {
        printf("%d/%d/%d is an invalid date.\n", m, d, y);
        return;
    }

    for(i = 1; i < y; ++i) {
        w += 365 + isleapyr(i);
    }
    for(i = 1; i < m; ++i) {
        w += daysinmonths[i];
        if(i == 2) w += isleapyr(y);
    }
    w += d;

    if((y < 1752) || (y == 1752 && m < 9) || (y == 1752 && m == 9 && d < 3)) {
        w += 11;
    }

    printf("%s %d, %d is a %s\n", monthName[m], d, y, weekName[w%7]);
}

int main() {
    daysinmonths[1] = 31;
    daysinmonths[2] = 28;
    daysinmonths[3] = 31;
    daysinmonths[4] = 30;
    daysinmonths[5] = 31;
    daysinmonths[6] = 30;
    daysinmonths[7] = 31;
    daysinmonths[8] = 31;
    daysinmonths[9] = 30;
    daysinmonths[10] = 31;
    daysinmonths[11] = 30;
    daysinmonths[12] = 31;

    while (true) {
        int month, day, year;
        cin >> month >> day >> year;
        if (month == 0 && day == 0 && year == 0) {
            return 0;
        }
        solve(month, day, year);
    }
    return 0;
}
