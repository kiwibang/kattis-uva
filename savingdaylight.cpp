#include <bits/stdc++.h>
using namespace std;

int getmins(string time) {
    return stoi(time.substr(0, time.find(':'))) * 60 + stoi(time.substr(time.find(':') + 1, time.size()));
}

int main() {
    while (true) {
        string month, start, end;
        int day, year;
        cin >> month >> day >> year;
        if (cin.eof()) {
            break;
        }
        cin >> start >> end;
        int dur = getmins(end) - getmins(start);
        cout << month << " " << day << " " << year << " " << dur / 60 << " hours " << dur % 60 << " minutes" << endl;
    }
    return 0;
}
