#include <bits/stdc++.h>
using namespace std;

int main() {
    int s0, s1, r0, r1;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        iss >> s0 >> s1 >> r0 >> r1;
        if (s0 == 0 && s1 == 0 && r0 == 0 && r1 == 0) {
            return 0;
        }
        int p1 = s0 > s1 ? s0 * 10 + s1 : s1 * 10 + s0;
        int p2 = r0 > r1 ? r0 * 10 + r1 : r1 * 10 + r0;
        if (p1 == 21 && p2 == 21) {
            cout << "Tie." << endl;
        } else if (!(p1 == 21) && p2 == 21) {
            cout << "Player 2 wins." << endl;
        } else if (p1 == 21 && !(p2 == 21)) {
            cout << "Player 1 wins." << endl;
        } else {
            if (s0 == s1 && r0 == r1) {
                if (p1 == p2) {
                    cout << "Tie." << endl; 
                } else if (p1 > p2) {
                    cout << "Player 1 wins." << endl;
                } else {
                    cout << "Player 2 wins." << endl;
                }
            } else if (s0 != s1 && r0 == r1) {
                cout << "Player 2 wins." << endl;
            } else if (s0 == s1 && r0 != r1) {
                cout << "Player 1 wins." << endl;
            } else {
                if (p1 == p2) {
                    cout << "Tie." << endl; 
                } else if (p1 > p2) {
                    cout << "Player 1 wins." << endl;
                } else {
                    cout << "Player 2 wins." << endl;
                }
            }
        }
    }
    return 0;
}
