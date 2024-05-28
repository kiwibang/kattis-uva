#include <bits/stdc++.h>
using namespace std;

double getValue(string card);
bool isOudler(string card);

// function that returns the value of a card
double getValue(string card) {
    if (isOudler(card) || card.substr(0, 4) == "king") {
        return 4.5;
    } else if (card.substr(0, 5) == "queen") {
        return 3.5;
    } else if (card.substr(0, 6) == "knight") {
        return 2.5;
    } else if (card.substr(0, 4) == "jack") {
        return 1.5;
    } else {
        return 0.5;
    }
}

// function that returns whether the card is an oudler or not
bool isOudler(string card) {
    return card == "fool" || card == "twenty-one of trumps" || card == "one of trumps";
}

int main() {
    // read in the number of testcases
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        if (i > 1) {
            cout << endl;
        }
        int m;
        cin >> m;
        cin.ignore();
        double val = 0;
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            string card;
            getline(cin, card);
            if (isOudler(card)) {
                ++cnt;
            }
            val += getValue(card);
        }
        int target = cnt == 3 ? 36 : cnt == 2 ? 41 : cnt == 1 ? 51 : 56;
        cout << "Hand #" << i << endl;
        cout << "Game ";
        if ((int) val >= target) {
            cout << "won by " << (int) val - target << " point(s)." << endl;
        } else {
            cout << "lost by " << target - (int) val << " point(s)." << endl;
        }
    }
    return 0;
}
