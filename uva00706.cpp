#include <bits/stdc++.h>
using namespace std;

void printdigit(string n, int s){
    // build the horizontal cap
    string cap = " ";
    string empty = " ";
    for (int i = 0; i < s; ++i) {
        cap += "-";
        empty += " ";
    }
    cap += " ";
    empty += " ";
    for (int i = 0; i < n.size(); ++i) {
        char c = n[i];
        // top cap
        if (c == '0' || c == '2' || c == '3' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
            cout << cap;
        } else {
            cout << empty;
        }
        if (i != n.size() - 1) {
            cout << ' ';
        }
    }
    cout << endl;
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < n.size(); ++j) {
            char c = n[j];
            // top left
            if (c == '0' || c == '4' || c == '5' || c == '6' || c == '8' || c == '9') {
                cout << '|';
            } else {
                cout << ' '; 
            }
            for (int i = 0; i < s; ++i) {
                cout << ' ';
            }
            // top right
            if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '7' || c =='8' || c == '9') {
                cout << '|';
            } else {
                cout << ' ';
            }
            if (j != n.size() - 1) {
                cout << ' ';
            }
        }
        cout << endl;
    }
    for (int i = 0; i < n.size(); ++i) {
        char c = n[i];
        // mid cap
        if (c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '8' || c == '9') {
            cout << cap;
        } else {
            cout << empty;
        }
        if (i != n.size() - 1) {
            cout << ' ';
        }
    }
    cout << endl;
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < n.size(); ++j) {
            char c = n[j];
            // bottom left
            if (c == '2' || c == '6' || c == '8' || c == '0') {
                cout << '|';
            } else {
                cout << ' ';
            }
            for (int i = 0; i < s; ++i) {
                cout << ' ';
            }
            // bottom right
            if (c == '0' || c == '1' || c == '3' || c == '4' || c == '5' || c == '6' || c =='7' || c == '8' || c == '9') {
                cout << '|';
            } else {
                cout << ' ';
            }
            if (j != n.size() - 1) {
                cout << ' ';
            }
        }
        cout << endl;
    }
    for (int i = 0; i < n.size(); ++i) {
        char c = n[i];
        // bottom cap
        if (c == '2' || c == '3' || c == '5' || c =='6' || c == '8' || c == '9' || c == '0') {
            cout << cap;
        } else {
            cout << empty;
        }
        if (i != n.size() - 1) {
            cout << ' ';
        }
    }
    cout << endl;
}

int main() {
    int t = 1;
    while (true) {
        int s;
        string n;
        cin >> s >> n;
        if (s == 0 && n == "0") {
            return 0;
        }
        printdigit(n, s);
        cout << endl;
        ++t;
    }
    return 0;
}
