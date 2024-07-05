#include <bits/stdc++.h>
using namespace std;

int main() {
    string cl, temp;
    while (true) {
        getline(cin, cl);
        if (cin.eof()) {
            break;
        }
        istringstream iss(cl);
        string res = "";
        while (iss >> temp) {
            reverse(temp.begin(), temp.end());
            res += temp;
            res += " ";
        }
        cout << res.substr(0, res.size() - 1) << endl;
    }
    return 0;
}
