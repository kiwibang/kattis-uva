#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, int> suitmap;
    suitmap['S'] = 0;
    suitmap['H'] = 1;
    suitmap['D'] = 2;
    suitmap['C'] = 3;
    map<int, char> suitmap2;
    suitmap[0] = 'S';
    suitmap[1] = 'H';
    suitmap[2] = 'D';
    suitmap[3] = 'C';
    while (true) {
        vector<bool> hvAce(4, false);
        vector<bool> hvKing(4, false);
        vector<bool> hvQueen(4, false);
        vector<bool> hvJack(4, false);
        vector<bool> hvTrump(4, false);
        vector<int> suitCounts(4, 0);
        long long res = 0;
        long long addn = 0;
        for (int i = 0; i < 13; ++i) {
            string card;
            cin >> card;
            int idx = suitmap[card[1]];
            switch(card[0]) {
                case 'A':
                    hvAce[idx] = true;
                    res += 4;
                    break;
                case 'K':
                    hvKing[idx] = true;
                    res += 3;
                    break;
                case 'Q':
                    hvQueen[idx] = true;
                    res += 2;
                    break;
                case 'J':
                    hvJack[idx] = true;
                    res += 1;
                    break;
            }
            ++suitCounts[idx];
        }
        if (cin.eof()) {
            return 0;
        }
        for (int i = 0; i < 4; ++i) {
            if (hvAce[i]) {
                hvTrump[i] = true;
            }
            if (hvKing[i] && suitCounts[i] <= 1) {
                --res;
            } else if (hvKing[i]) {
                hvTrump[i] = true;
            }
            if (hvQueen[i] && suitCounts[i] <= 2) {
                --res;
            } else if (hvQueen[i]) {
                hvTrump[i] = true;
            }
            if (hvJack[i] && suitCounts[i] <= 3) {
                --res;
            }
            if (suitCounts[i] == 2) {
                ++addn;
            } else if (suitCounts[i] < 2) {
                addn += 2;
            }
        }
        // case where all suits stopped and points ≥ 16
        if (hvTrump[0] && hvTrump[1] && hvTrump[2] && hvTrump[3] && res >= 16) {
            cout << "BID NO-TRUMP" << endl;
        } else if (res + addn >= 14) {
            int mx = max(max(suitCounts[0], suitCounts[1]), max(suitCounts[2], suitCounts[3]));
            if (suitCounts[0] == mx) {
                cout << "BID S" << endl;
            } else if (suitCounts[1] == mx) {
                cout << "BID H" << endl;
            } else if (suitCounts[2] == mx) {
                cout << "BID D" << endl;
            } else if (suitCounts[3] == mx) {
                cout << "BID C" << endl;
            }
        } else {
            cout << "PASS" << endl;
        }
    }
    return 0;
}
