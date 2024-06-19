#include <bits/stdc++.h>
using namespace std;

bool isleapyr(int y) {
    if (y == 0) {
        return true;
    }
    if (y % 4 == 0) {
        return true;
    }
    if (y % 400 == 0) {
        return true;
    }
    return false;
}

string nly(int days) {
    if (21 <= days && days <= 50) {
        return "aquarius";
    } else if (51 <= days && days <= 79) {
        return "pisces";
    } else if (80 <= days && days <= 110) {
        return "aries";
    } else if (111 <= days && days <= 141) {
        return "taurus";
    } else if (142 <= days && days <= 172) {
        return "gemini";
    } else if (173 <= days && days <= 203) {
        return "cancer";
    } else if (204 <= days && days <= 233) {
        return "leo";
    } else if (234 <= days && days <= 266) {
        return "virgo";
    } else if (267 <= days && days <= 296) {
        return "libra";
    } else if (297 <= days && days <= 326) {
        return "scorpio";
    } else if (327 <= days && days <= 356) {
        return "sagittarius";
    } else if ((357 <= days && days <= 365) || (1 <= days && days <= 20)) {
        return "capricorn";
    } else {
        return "";
    }
}

string ly(int days) {
    if (21 <= days && days <= 50) {
        return "aquarius";
    } else if (51 <= days && days <= 80) {
        return "pisces";
    } else if (81 <= days && days <= 111) {
        return "aries";
    } else if (112 <= days && days <= 142) {
        return "taurus";
    } else if (143 <= days && days <= 173) {
        return "gemini";
    } else if (174 <= days && days <= 204) {
        return "cancer";
    } else if (205 <= days && days <= 234) {
        return "leo";
    } else if (235 <= days && days <= 267) {
        return "virgo";
    } else if (268 <= days && days <= 297) {
        return "libra";
    } else if (298 <= days && days <= 327) {
        return "scorpio";
    } else if (328 <= days && days <= 357) {
        return "sagittarius";
    } else if ((358 <= days && days <= 366) || (1 <= days && days <= 20)) {
        return "capricorn";
    } else {
        return "";
    }
}

int main() {
    map<int, int> daysinmonth;
    daysinmonth[1] = 31;
    daysinmonth[2] = 28; // assume non-leap year
    daysinmonth[3] = 31;
    daysinmonth[4] = 30;
    daysinmonth[5] = 31;
    daysinmonth[6] = 30;
    daysinmonth[7] = 31;
    daysinmonth[8] = 31;
    daysinmonth[9] = 30;
    daysinmonth[10] = 31;
    daysinmonth[11] = 30;
    daysinmonth[12] = 31;

    // read in the number of testcases
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        // get the date
        string date;
        cin >> date;
        int month = (date[0] - '0') * 10 + (date[1] - '0');
        int day = (date[2] - '0') * 10 + (date[3] - '0');
        int year = (date[4] - '0') * 1000 + (date[5] - '0') * 100 + (date[6] - '0') * 10 + (date[7] - '0');
        // convert the date into an integer number of days
        int days = 0;
        for (int mth = 1; mth < month; ++mth) {
            if (mth == 2 && isleapyr(year)) {
                days += 29;
                continue;
            }
            days += daysinmonth[mth];
        }
        days += day;
        // add 40 weeks to the day
        days += 280;
        // case where go to the next year
        if (!isleapyr(year) && days > 365) { // non-leap year
            days -= 365;
            ++year;
        } else if (isleapyr(year) && days > 366) { // leap year
            days -= 366;
            ++year;
        }
        // then check whether the new year is a leap year, and print output accordingly
        // print the case number
        cout << tc << " ";
        // get the date
        int newdays = days, newmonths = 1, newyear = year; 
        while (true) {
            // if the current number of days is less than the number of days in the current month
            if (isleapyr(year) && newmonths == 2 && newdays <= 29) {
                break;
            }
            if (newdays <= daysinmonth[newmonths]) {
                break;
            }
            if (isleapyr(year) && newmonths == 2 && newdays > 29) {
                newdays -= 29;
            } else {
                newdays -= daysinmonth[newmonths];
            }
            ++newmonths;
        }
        // print the date
        cout << setfill('0') << setw(2) << newmonths << "/";
        cout << setfill('0') << setw(2) << newdays << "/";
        cout << setfill('0') << setw(4) << newyear << " ";
        // get and print the 
        string zodiac;
        if (isleapyr(newyear)) {
            zodiac = ly(days);
        } else {
            zodiac = nly(days);
        }
        cout << zodiac << endl;
    }
    return 0;
}
