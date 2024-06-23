#include <bits/stdc++.h>
using namespace std;

vector<int> parsedate(string date) {
    vector<int> res(3);
    res[0] = stoi(date.substr(0, 2));
    res[1] = stoi(date.substr(3, 2));
    res[2] = stoi(date.substr(6, 4));
    return res;
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        string curr, born;
        cin >> curr >> born;
        vector<int> currinfo = parsedate(curr);
        vector<int> borninfo = parsedate(born);
        cout << "Case #" << tc << ": ";
        int age = currinfo[2] - borninfo[2];
        if (borninfo[1] > currinfo[1] || (borninfo[1] == currinfo[1] && borninfo[0] > currinfo[0])) {
            --age;
        }
        if (age < 0) {
            cout << "Invalid birth date" << endl;
        } else if (age > 130) {
            cout << "Check birth date" << endl;
        } else {
            cout << age << endl;
        }
    }
    return 0;
}
