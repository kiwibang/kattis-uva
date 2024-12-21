#include <bits/stdc++.h>
using namespace std;

int tomin(string time) {
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}
int main() {
    string s1, s2, i1, i2;
    cin >> s1 >> s2 >> i1 >> i2;
    int start1 = tomin(s1), start2 = tomin(s2), ii1 = tomin(i1), ii2 = tomin(i2);
    vector<bool> se1(10000000, false);
    vector<string> daystrs; 
    daystrs.push_back("Saturday");
    daystrs.push_back("Sunday");
    daystrs.push_back("Monday");
    daystrs.push_back("Tuesday");
    daystrs.push_back("Wednesday");
    daystrs.push_back("Thursday");
    daystrs.push_back("Friday");
    int curr = start1;
    while (curr <= 10000000) {
        se1[curr] = true;
        curr += ii1;
    }
    curr = start2;
    while (curr <= 10000000) {
        if (se1[curr]) {
            int dayse = (curr / 1440) % 7;
            int minse = curr % 1440;
            int hr = minse / 60, min = minse % 60;
            cout << daystrs[dayse] << endl;
            cout << setfill('0') << setw(2) << hr << ":" << setfill('0') << setw(2) << min << endl;
            return 0;
        }
        curr += ii2;
    }
    cout << "Never" << endl;
    return 0;
}
