#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<bool> pmissing(13, false);
    vector<bool> kmissing(13, false);
    vector<bool> hmissing(13, false);
    vector<bool> tmissing(13, false);
    string cards;
    cin >> cards;
    for (int i = 0; i < cards.length(); i += 3) {
        char suit = cards[i];
        int val = (int) (cards[i + 1] - '0') * 10 + (int) (cards[i + 2] - '0');
        switch (suit) {
            case 'P':
                if (pmissing[val - 1]) {
                    cout << "GRESKA" << endl;
                    return 0;
                }
                pmissing[val - 1] = true;
                break;
            case 'K':
                if (kmissing[val - 1]) {
                    cout << "GRESKA" << endl;
                    return 0;
                }
                kmissing[val - 1] = true;
                break;
            case 'H':
                if (hmissing[val - 1]) {
                    cout << "GRESKA" << endl;
                    return 0;
                }
                hmissing[val - 1] = true;
                break;
            case 'T':
                if (tmissing[val - 1]) {
                    cout << "GRESKA" << endl;
                    return 0;
                }
                tmissing[val - 1] = true;
                break;
        }
    }
    int pcount = 0, kcount = 0, hcount = 0, tcount = 0;
    for (int i = 0; i < 13; ++i) {
        if (!pmissing[i]) {
            ++pcount;
        }
        if (!kmissing[i]) {
            ++kcount;
        }
        if (!hmissing[i]) {
            ++hcount;
        }
        if (!tmissing[i]) {
            ++tcount;
        }
    }
    cout << pcount << " " << kcount << " " << hcount << " " << tcount << endl;
    return 0;
}
