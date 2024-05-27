#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        if (i > 1) {
            cout << endl;
        }
        // initial deck
        vector<string> cards;
        // constructors
        char suits[] = {'C', 'D', 'H', 'S'};
        char vals[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
        map<char, string> printMap;
        printMap['2'] = "2";
        printMap['3'] = "3";
        printMap['4'] = "4";
        printMap['5'] = "5";
        printMap['6'] = "6";
        printMap['7'] = "7";
        printMap['8'] = "8";
        printMap['9'] = "9";
        printMap['T'] = "10";
        printMap['J'] = "Jack";
        printMap['Q'] = "Queen";
        printMap['K'] = "King";
        printMap['A'] = "Ace";
        printMap['C'] = "Clubs";
        printMap['D'] = "Diamonds";
        printMap['H'] = "Hearts";
        printMap['S'] = "Spades";
        // make initial deck
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 13; ++j) {
                string curr = "";
                curr.push_back(suits[i]);
                curr.push_back(vals[j]);
                cards.push_back(curr);
            }
        }
        int n;
        cin >> n;
        vector<vector<int> > shuffles;
        for (int i = 0; i < n; ++i) {
            vector<int> currShuffle;
            for (int i = 0; i < 52; ++i) {
                int curr;
                cin >> curr;
                currShuffle.push_back(curr);
            }
            shuffles.push_back(currShuffle);
        }
        // perform the series of shuffles
        cin.ignore();
        string line;
        while (getline(cin, line) && line.length()) {
            istringstream iss(line);
            int currShuffle;
            iss >> currShuffle;
            // get the current shuffle
            vector<int> shuffle = shuffles[currShuffle - 1];
            vector<string> shuffledDeck(52, "");
            for (int i = 0; i < 52; ++i) {
                shuffledDeck[i] = cards[shuffle[i] - 1];
            }
            // update the cards deck
            for (int i = 0; i < 52; ++i) {
                cards[i] = shuffledDeck[i];
                shuffledDeck[i] = "";
            }
        }
        // then print the cards deck after the shuffles
        for (int i = 0; i < 52; ++i) {
            cout << printMap[cards[i][1]] << " of " << printMap[cards[i][0]] << endl;
        }
    }
    return 0;
}
