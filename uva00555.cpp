#include <bits/stdc++.h>
using namespace std;

void sortDeck(vector<string>& deck) {
    map<char, map<char, int> > mp;
    mp['C'] = map<char, int>();
    mp['D'] = map<char, int>();
    mp['S'] = map<char, int>();
    mp['H'] = map<char, int>();
    for (int i = 0; i < deck.size(); ++i) {
        string card = deck[i];
        if (mp[card[0]].find(card[1]) != mp[card[0]].end()) {
            mp[card[0]][card[1]] = 0;
        }
        ++mp[card[0]][card[1]];
    }
    char suitordering[] = {'C', 'D', 'S', 'H'};
    char ordering[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    vector<string> temp;
    for (int i = 0; i < 4; ++i) {
        char currSuit = suitordering[i];
        for (int j = 0; j < 13; ++j) {
            char curr = ordering[j];
            while (mp[currSuit][curr] > 0) {
                string card = "";
                card.push_back(currSuit);
                card.push_back(curr);
                temp.push_back(card);
                --mp[currSuit][curr];
            }
        }
    }
    for (int i = 0; i < deck.size(); ++i) {
        deck[i] = temp[i];
    }
}

int main() {
    while (true) {
       map<string, int> dealerToId;
        dealerToId["N"] = 0;
        dealerToId["E"] = 1;
        dealerToId["S"] = 2;
        dealerToId["W"] = 3;
        string players[] = {"N", "E", "S", "W"};
        // follows the ID
        vector<vector<string> > dealt;
        for (int i = 0; i < 4; ++i) {
            dealt.push_back(vector<string>());
        }
        string dealer;
        cin >> dealer;
        if (dealer == "#") {
            return 0;
        }
        string firsthalf, secondhalf;
        cin >> firsthalf >> secondhalf;
        vector<string> deck;
        for (int i = 0; i < firsthalf.length(); i += 2) {
            string card = "";
            card.push_back(firsthalf[i]);
            card.push_back(firsthalf[i + 1]);
            deck.push_back(card);
        }
        for (int i = 0; i < secondhalf.length(); i += 2) {
            string card = "";
            card.push_back(secondhalf[i]);
            card.push_back(secondhalf[i + 1]);
            deck.push_back(card);
        }
        // start with dealer's left
        int idx = (dealerToId[dealer] + 1) % 4;
        // start dealing
        for (int i = 0; i < deck.size(); ++i) {
            dealt[idx].push_back(deck[i]);
            idx = (idx + 1) % 4;
        }
        sortDeck(dealt[0]);
        sortDeck(dealt[1]);
        sortDeck(dealt[2]);
        sortDeck(dealt[3]);
        cout << "S: ";
        for (int i = 0; i < 13; ++i) {
            cout << dealt[2][i];
            if (i != 12) {
                cout << " ";
            }
        }
        cout << endl;
        cout << "W: ";
        for (int i = 0; i < 13; ++i) {
            cout << dealt[3][i];
            if (i != 12) {
                cout << " ";
            }
        }
        cout << endl;
        cout << "N: ";
        for (int i = 0; i < 13; ++i) {
            cout << dealt[0][i];
            if (i != 12) {
                cout << " ";
            }
        }
        cout << endl;
        cout << "E: ";
        for (int i = 0; i < 13; ++i) {
            cout << dealt[1][i];
            if (i != 12) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
