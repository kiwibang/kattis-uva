#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<string> expr;
        string curr;
        cin >> curr;
        int i = 0, n = curr.size();
        while (i < n) {
            if (isdigit(curr[i])) {
                string token = "";
                while (i < n && isdigit(curr[i])) {
                    token.push_back(curr[i]);
                    ++i;
                }
                if (curr[i] == 'x') {
                    token.push_back('x');
                    // shift the pointer
                    ++i;
                }
                expr.push_back(token);
            } else if (curr[i] == 'x') {
                expr.push_back("1x");
                ++i;
            } else if (curr[i] == '-' || curr[i] == '+' || curr[i] == '=') {
                string temp = "";
                temp.push_back(curr[i]);
                expr.push_back(temp);
                ++i;
            }
        }
        // compile all the X'es and normal vals
        int lhsval = 0, lhsx = 0, rhsval = 0, rhsx = 0;
        bool isplus = true, islhs = true;
        for (int j = 0; j < expr.size(); ++j) {
            if (expr[j] == "+" || expr[j] == "-") {
                isplus = expr[j] == "+";
            } else if (expr[j][expr[j].size() - 1] == 'x') {
                int currval = isplus ? stoi(expr[j].substr(0, expr[j].size() - 1)) : -stoi(expr[j].substr(0, expr[j].size() - 1));
                if (islhs) {
                    lhsx += currval;
                } else {
                    rhsx += currval;
                }
            } else if (!expr.empty() && all_of(expr[j].begin(), expr[j].end(), ::isdigit)) {
                int currval = isplus ? stoi(expr[j]) : -stoi(expr[j]);
                if (islhs) {
                    lhsval += currval;
                } else {
                    rhsval += currval;
                }
            } else if (expr[j] == "=") {
                islhs = false;
                isplus = true;
            }
        }
        // place the X'es on the left, and vals on the right
        // print the cases
        if (lhsx == rhsx && lhsval == rhsval) {
            cout << "IDENTITY" << endl;
        } else if (lhsx == rhsx && lhsval != rhsval) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << (int) floor((double) (rhsval - lhsval) / (lhsx - rhsx)) << endl;
        }
    }
    return 0;
}
