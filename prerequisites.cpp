#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
    int k, m;
        cin >> k >> m;
        if (k == 0) {
            return 0;
        }
        // get the set of courses that the dude has taken
        set<string> courses;
        for (int i = 0; i < k; ++i) {
            string curr;
            cin >> curr;
            courses.insert(curr);
        }
        // loop over the categories
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            int c, r;
            cin >> c >> r;
            // loop over the courses for the current category
            int numSatisfied = 0;
            for (int j = 0; j < c; ++j) {
                string curr;
                cin >> curr;
                if (courses.find(curr) != courses.end()) {
                    ++numSatisfied;
                }
            }
            if (numSatisfied >= r) {
                ++cnt;
            }
        }
        // check if can grad
        if (cnt == m) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}
