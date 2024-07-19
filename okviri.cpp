#include <bits/stdc++.h>
using namespace std;

int main() {
    string l;
    cin >> l;
    vector<string> toprint(5, "");
    // set up the rows
    // first row
    toprint[0] += "..#..";
    for (int i = 1; i < l.size(); ++i) {
        toprint[0] += ".";
        if ((i + 1) % 3 == 0) {
            toprint[0] += "*";
        } else {
            toprint[0] += "#";
        }
        toprint[0] += "..";
    }
    // second row
    string normal = ".#.#", special = ".*.*";
    for (int i = 0; i < l.size(); ++i) {
        if ((i + 1) % 3 == 0) {
            toprint[1] += special;
        } else {
            toprint[1] += normal;
        }
    }
    toprint[1] += ".";
    // middle row
    for (int i = 0; i < l.size(); ++i) {
        if ((i + 1) % 3 == 0 || (i != 0 && i % 3 == 0)) {
            toprint[2] += "*";
        } else {
            toprint[2] += "#";
        }
        toprint[2] += ".";
        toprint[2].push_back(l[i]);
        toprint[2] += ".";
    }
    if (l.size() % 3 == 0) {
        toprint[2] += "*";
    } else {
        toprint[2] += "#";
    }
    // fourth row
    for (int i = 0; i < l.size(); ++i) {
        if ((i + 1) % 3 == 0) {
            toprint[3] += special;
        } else {
            toprint[3] += normal;
        }
    }
    toprint[3] += ".";
    // fifth row
    toprint[4] += "..#..";
    for (int i = 1; i < l.size(); ++i) {
        toprint[4] += ".";
        if ((i + 1) % 3 == 0) {
            toprint[4] += "*";
        } else {
            toprint[4] += "#";
        }
        toprint[4] += "..";
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < toprint[0].size(); ++j) {
            cout << toprint[i][j];
        }
        cout << endl;
    }
    return 0;
}
