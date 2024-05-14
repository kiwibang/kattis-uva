#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    int t, money = 0, curr;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, line);
        istringstream iss(line);
        string id;
        iss >> id;
        if (id == "donate") {
            iss >> curr;
            money += curr;
        } else if (id == "report") {
            cout << money << endl;
        }
    }
    return 0;
}
