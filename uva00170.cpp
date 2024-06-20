#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        // read in first card
        string curr;
        cin >> curr;
        // if end of input
        if (curr == "#") {
            break;
        }
        // read in the deck
        vector<string> deck;
        deck.push_back(curr);
        for (int i = 0; i < 51; ++i) {
            cin >> curr;
            deck.push_back(curr);
        }
        // deal the cards from top to bottom
        vector<vector<string> > clock(13, vector<string>());
        int idx = 0;
        for (int i = deck.size() - 1; i >= 0; --i) {
            clock[idx].push_back(deck[i]);
            idx = (idx + 1) % 13;
        }
        // simulate the game
        idx = 12;
        int res = 0;
        string lastcard;
        while (true) {
            // check game end
            if (clock[idx].empty()) {
                break;
            }
            // get the card
            lastcard = clock[idx][clock[idx].size() - 1];
            // update the number of cards exposed
            ++res;
            // update the number of cards
            clock[idx].pop_back();
            // get the next index
            char rank = lastcard[0];
            if (isdigit(rank)) {
                idx = rank - '0' - 1;
            } else if (rank == 'A') {
                idx = 0;
            } else if (rank == 'Q') {
                idx = 11;
            } else if (rank == 'J') {
                idx = 10;
            } else if (rank == 'T') {
                idx = 9;
            } else if (rank == 'K') {
                idx = 12;
            }
            // place the card on the new deck (do nothing)
        }
        cout << fixed << setfill('0') << setw(2) << res << "," << lastcard << endl;
    }
    return 0;
}
