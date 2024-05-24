#include <bits/stdc++.h>
using namespace std;

int getVal(string card);
int main() {
    int n;
    cin >> n;
    // loop over testcases
    for (int tc = 1; tc <= n; ++tc) {
        // obtain the card deck
        vector<string> cards;
        for (int i = 0; i < 52; ++i) {
            string card;
            cin >> card;
            cards.push_back(card);
        }
        // shuffle the cards
        int cardIdx = 27;
        int y = 0;
        // execute the given steps 3 times
        for (int i = 0; i < 3; ++i) {
            // take the top card of the pile
            string topCard = cards[cardIdx - 1];
            // get its value, call it x
            int x = getVal(topCard);
            // add x to y
            y += x;
            // put away this card and the top (10 - x) cards of the pile away
            for (int j = 0; j < 11 - x; ++j) {
                --cardIdx;
            }
        }
        int idx = 1;
        // get the yth card of the pile, starting from the bottom
        if (y <= cardIdx) {
            cout << "Case " << tc << ": " << cards[y - 1] << endl;
        } else {
            cout << "Case " << tc << ": " << cards[y - cardIdx + 26] << endl;
        }
    }
    return 0;
}

int getVal(string card) {
    int fc = (int) (card[0] - '0');
    if (2 <= fc && fc <= 9) {
        return fc;
    } else {
        return 10;
    }
}
