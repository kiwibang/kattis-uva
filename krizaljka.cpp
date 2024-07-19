#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    // determine the first char that both a and b have
    int commonr = -1, commonc = -1;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            if (a[i] == b[j]) {
                commonr = j;
                commonc = i;
                break;
            }
        }
        if (commonr != -1) {
            break;
        }
    }
    // then prepare the output for printing
    vector<vector<char> > toprint(b.size(), vector<char>(a.size(), '.'));
    // lay out a
    for (int j = 0; j < a.size(); ++j) {
        toprint[commonr][j] = a[j];
    }
    // lay out b
    for (int i = 0; i < b.size(); ++i) {
        toprint[i][commonc] = b[i];
    }
    // print the final vector
    for (int i = 0; i < b.size(); ++i) {
        for (int j = 0; j < a.size(); ++j) {
            cout << toprint[i][j];
        }
        cout << endl;
    }
    return 0;
}
