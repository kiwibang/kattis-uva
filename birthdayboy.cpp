#include <bits/stdc++.h>
using namespace std;

map<int, int> mxd;

// date to day converter
int convertdate(string date) {
    // get the month
    int months = stoi(date.substr(0, date.find('-')));
    // get the day
    int days = stoi(date.substr(date.find('-') + 1, date.size()));
    // convert
    int res = 0;
    for (int i = 1; i < months; ++i) {
        res += mxd[i];
    }
    res += days;
    return res;
}

// day to date converter
void convertandprintday(int day) {
    // track the month
    int month = 1;
    while (true) {
        // case where number of days is less than or equals the number of days in the current month
        if (day <= mxd[month]) {
            break;
        }
        // else, deduct the number of days in the current month from the current number of days remaining, and update the month
        day -= mxd[month++];
    }
    // then, parse the day and month into the string of the required format
    cout << setfill('0') << setw(2) << month << "-";
    cout << setfill('0') << setw(2) << day << endl;
}

// compute the gap
int computegap(int proposed, vector<bool>& calendar) {
    int res = 0;
    while (true) {
        --proposed;
        ++res;
        if (proposed == 0) {
            proposed = 365;
        }
        if (calendar[proposed - 1]) {
            break;
        }
    }
    return res;
}

int main() {
    // month to number of days conversion table
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
    
    string name, date;
    // read in the number of colleagues
    int n;
    cin >> n;
    vector<bool> calendar(365, false);
    // loop over the birthdays of bobby's colleagues
    for (int i = 0; i < n; ++i) {
        // read in the current birthday
        cin >> name >> date;
        // convert the current birthday to some day
        int day = convertdate(date);
        // mark the calendar
        calendar[day - 1] = true;
    }
    // try all possible days, starting from the earliest day
    int curr = convertdate("10-28"), lim = convertdate("10-27");
    int bestgap = -1, bestday, currgap;
    // track the biggest gap and the best day
    while (curr != lim) {
        // case where have no one celebrating on the current day
        if (!calendar[curr - 1]) {
            // get the largest gap
            currgap = computegap(curr, calendar); 
            if (currgap > bestgap) {
                bestgap = currgap;
                bestday = curr;
            }
        }
        // update the current day
        ++curr;
        // handle overflow
        if (curr > 365) {
            curr -= 365;
        }
    }
    // edge case: account for the last day
    currgap = computegap(lim, calendar);
    if (!calendar[lim - 1] && currgap > bestgap) {
        bestgap = currgap;
        bestday = lim;
    }
    // convert and print the best day into a date
    convertandprintday(bestday);
    return 0;
}
