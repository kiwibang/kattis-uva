#include <bits/stdc++.h>
using namespace std;

int getScore(vector<int>& hand);

int main() {
    map<char, int> mp;
    mp['A'] = 0;
    mp['2'] = 1;
    mp['3'] = 2;
    mp['4'] = 3;
    mp['5'] = 4;
    mp['6'] = 5;
    mp['7'] = 6;
    mp['8'] = 7;
    mp['9'] = 8;
    mp['T'] = 9;
    mp['J'] = 10;
    mp['Q'] = 11;
    mp['K'] = 12;
    map<int, char> intToChar;
    intToChar[0] = 'A';
    intToChar[1] = '2';
    intToChar[2] = '3';
    intToChar[3] = '4';
    intToChar[4] = '5';
    intToChar[5] = '6';
    intToChar[6] = '7';
    intToChar[7] = '8';
    intToChar[8] = '9';
    intToChar[9] = 'T';
    intToChar[10] = 'J';
    intToChar[11] = 'Q';
    intToChar[12] = 'K';
    char suits[4] = {'S', 'H', 'D', 'C'};
    while (true) {
        // read in the current hand
        vector<string> hand;
        vector<int> vals;
        map<string, bool> used;
        for (int i = 0; i < 5; ++i) {
            string card;
            cin >> card;
            if (card == "#") {
                return 0;
            }
            hand.push_back(card);
            used[card] = true;
            vals.push_back(mp[card[0]]);
        }
        // calculate the best score for the current hand
        int initialScore = getScore(vals) * 47;
        int bestScore = initialScore;
        string toSwap = "";
        for (int i = 0; i < 5; ++i) {
            int score = -47;
            // try all cards
            for (int j = 0; j < 13; ++j) {
                for (int k = 0; k < 4; ++k) {
                    string curr = "";
                    curr.push_back(intToChar[j]);
                    curr.push_back(suits[k]);
                    // if used already
                    if (used[curr]) {
                        continue;
                    }
                    int t = vals[i];
                    vals[i] = j;
                    score += getScore(vals);
                    vals[i] = t;
                }
            }
            if (score > bestScore) {
                bestScore = score;
                toSwap = hand[i];
            }
        }
        if (bestScore > initialScore) {
            cout << "Exchange " << toSwap << endl;
        } else {
            cout << "Stay" << endl;
        }
    }
    return 0;
}

int getScore(vector<int>& hand) {
    vector<int> fmap = vector<int>(13, 0);
    for (int i = 0; i < 5; ++i) {
        ++fmap[hand[i]];
    }
    // check Straight
    for (int i = 0; i < 13; ++i) {
        // count the number of consecutive
        int consec = 0;
        for (int j = 0; j < 5; ++j) {
            consec += fmap[(i + j) % 13] > 0;
        }
        if (consec == 5) {
            return 100;
        }
    }
    // check Invite-the-Neighbours 
    for (int i = 0; i < 13; ++i) {
        // count the number of consecutive
        int consec = 0;
        for (int j = 0; j < 4; ++j) {
            consec += fmap[(i + j) % 13] > 0;
        }
        if (consec == 4) {
            return 10;
        }
    }
    // check Bed-and-Breakfast
    vector<int> temp;
    for (int i = 0; i < 13; ++i) {
        temp.push_back(fmap[i]);
    }
    bool have3 = false;
    for (int i = 0; i < 13; ++i) {
        // count the number of consecutive
        int consec = 0;
        for (int j = 0; j < 3; ++j) {
            consec += temp[(i + j) % 13] > 0;
        }
        if (consec == 3) {
            have3 = true;
            for (int j = 0; j < 3; ++j) {
                --temp[(i + j) % 13];
            }
            break;
        }
    }
    if (have3) {
        for (int i = 0; i < 13; ++i) {
            // count the number of consecutive
            int consec = 0;
            for (int j = 0; j < 2; ++j) {
                consec += temp[(i + j) % 13] > 0;
            }
            if (consec == 2) {
                return 5;
            }
        }
    }
    // check Menage-a-Trois
    for (int i = 0; i < 13; ++i) {
        // count the number of consecutive
        int consec = 0;
        for (int j = 0; j < 3; ++j) {
            consec += fmap[(i + j) % 13] > 0;
        }
        if (consec == 3) {
            return 3;
        }
    }
    // check Double Dutch
    vector<int> temp2;
    for (int i = 0; i < 13; ++i) {
        temp2.push_back(fmap[i]);
    }
    bool have2 = false;
    for (int i = 0; i < 13; ++i) {
        // count the number of consecutive
        int consec = 0;
        for (int j = 0; j < 2; ++j) {
            consec += temp2[(i + j) % 13] > 0;
        }
        if (consec == 2) {
            have2 = true;
            for (int j = 0; j < 2; ++j) {
                --temp2[(i + j) % 13];
            }
            break;
        }
    }
    if (have2) {
        for (int i = 0; i < 13; ++i) {
            // count the number of consecutive
            int consec = 0;
            for (int j = 0; j < 2; ++j) {
                consec += temp2[(i + j) % 13] > 0;
            }
            if (consec == 2) {
                return 1;
            }
        }
    }
    // else, dummy, value is 0
    return 0;
}