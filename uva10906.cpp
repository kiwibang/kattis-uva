// credits: https://github.com/BIT-zhaoyang/competitive_programming/blob/master/uva10906.cpp
#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

// data structures to maintain
map<string, bool> isRoot;
map<string, tuple<string, string, string> > eq;

void rsolve(string& lh, string lastOP, bool leftSide) {
    if ('0' <= lh[0] && lh[0] <= '9') {
        cout << lh;
        return;
    }
    string var1, op, var2;
    tie(var1, op, var2) = eq[lh];
    bool brac = false;
    if (lastOP == "*") {
        if (!leftSide || op == "+") brac = true;
    } else {
        if (!leftSide && op == "+") brac = true;
    }
    if (brac) cout << "(";
    rsolve(var1, op, true);
    cout << op;
    rsolve(var2, op, false);
    if (brac) cout << ")";
}
int main() {
    // read the number of testcases
    int t;
    cin >> t;
    // loop over the testcases
    for (int tc = 1; tc <= t; ++tc) {
        // read the number of equations
        int n;
        cin >> n;
        // clear the data structures of the last testcase
        eq.clear();
        isRoot.clear();
        // strings to hold the current equation
        string lh, var1, var2, op, rh;
        while (n--) {
            // read in the equations
            cin >> lh >> op >> var1 >> op >> var2;
            isRoot[lh] = true;
            eq[lh] = make_tuple(var1, op, var2);
            if (isalpha(var1[0])) {
                isRoot[var1] = false;
            }
            if (isalpha(var2[0])) {
                isRoot[var2] = false;
            }
        }
        string root;
        for (auto it : isRoot) {
            if (it.second) {
                root = it.first;
                break;
            }
        }
        cout << "Expression #" << tc << ": ";
        rsolve(root, "", true);
        cout << endl;
    }
    return 0;
}
