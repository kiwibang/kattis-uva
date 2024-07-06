#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<char> downshift;
    vector<char> upshift;
    string t1, t2;
    getline(cin, t1);
    getline(cin, t2);
    for (int i = 0; i < t1.size(); ++i) {
        downshift.push_back(t1[i]);
        upshift.push_back(t2[i]);
    }
    string currline;
    while (true) {
        getline(cin, currline);
        if (cin.eof()) {
            break;
        }
        int shifted = 0;
        for (int i = 0; i < currline.size(); i += 5) {
            // get the substring
            string substrr = currline.substr(i, 5);
            // check if upshift or downshift
            if (substrr == "11011") {
                shifted = 0;
                continue;
            }
            if (substrr == "11111") {
                shifted = 1;
                continue;
            }
            int pos = stoi(substrr, nullptr, 2);
            char cc = shifted == 0 ? downshift[pos] : upshift[pos];
            cout << cc;
        }
        cout << endl;
    }
    return 0;
}
