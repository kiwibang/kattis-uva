#include <bits/stdc++.h>
using namespace std;

set<char> validletters;

bool hp(string& curr) {
    int r = 0;
    for (int i = curr.size() - 1; i >= 0; --i) {
        if ('p' <= curr[i] && curr[i] <= 'z') {
            ++r;
        } else if (curr[i] == 'N') {
            if (r < 1) {
                break;
            }
        } else if (curr[i] == 'C' || curr[i] == 'D' || curr[i] == 'E' || curr[i] == 'I') {
            if (r < 2) {
                r = 0;
                break;
            } else {
                --r;
            }
        }
    }
    return r == 1;
}

bool iscorrect(string curr) {
    // check if there are any non-hedonian letters
    for (int i = 0; i < curr.size(); ++i) {
        if (validletters.find(curr[i]) == validletters.end()) {
            return false;
        }
    }
    // else, all hedonian letters, so check the validity of the sentence based on the remaining rules
    return hp(curr);
}

int main() {
    validletters.insert('p');
    validletters.insert('q');
    validletters.insert('r');
    validletters.insert('s');
    validletters.insert('t');
    validletters.insert('u');
    validletters.insert('v');
    validletters.insert('w');
    validletters.insert('x');
    validletters.insert('y');
    validletters.insert('z');
    validletters.insert('N');
    validletters.insert('C');
    validletters.insert('D');
    validletters.insert('E');
    validletters.insert('I');

    string curr;
    while (getline(cin, curr)) {
        if (iscorrect(curr)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
