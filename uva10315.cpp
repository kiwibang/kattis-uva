#include <bits/stdc++.h>
using namespace std;

vector<int> getRank(vector<string> hand) {
    vector<int> res;
    int n = hand.size();
    map<char, int> mp;
    mp['2'] = 0;
    mp['3'] = 1;
    mp['4'] = 2;
    mp['5'] = 3;
    mp['6'] = 4;
    mp['7'] = 5;
    mp['8'] = 6;
    mp['9'] = 7;
    mp['T'] = 8;
    mp['J'] = 9;
    mp['Q'] = 10;
    mp['K'] = 11;
    mp['A'] = 12;
    // count the number of consecutive cards
    vector<int> vals(13, 0);
    for (int i = 0; i < n; ++i) {
        ++vals[mp[hand[i][0]]];
    }
    int consec = 1;
    int maxConsec = 0;
    for (int i = 1; i < 13; ++i) {
        // previous is the same => consective sequence so far increases by 1
        if (vals[i - 1] > 0 && vals[i] > 0) {
            ++consec;
        } else { // else, consecutive sequence ends (if any)
            maxConsec = max(maxConsec, consec);
            consec = 1;
        }
    }
    maxConsec = max(maxConsec, consec);
    // check straight flush
    if (maxConsec == 5 && hand[0][1] == hand[1][1] && hand[0][1] == hand[2][1] && hand[0][1] == hand[3][1] && hand[0][1] == hand[4][1]) {
        res.push_back(9);
        res.push_back(max(max(mp[hand[0][0]], mp[hand[1][0]]), max(mp[hand[2][0]], max(mp[hand[3][0]], mp[hand[4][0]]))));
        return res;
    }
    // check four of a kind
    for (int i = 0; i < 13; ++i) {
        if (vals[i] == 4) {
            res.push_back(8);
            res.push_back(i);
            return res;
        }
    }
    // check full house
    int triplesCount = 0, pairsCount = 0, tripleVal;
    vector<int> doubleVal;
    for (int i = 0; i < 13; ++i) {
        if (vals[i] == 3) {
            ++triplesCount;
            tripleVal = i;
        } else if (vals[i] == 2) {
            ++pairsCount;
            doubleVal.push_back(i);
        }
    }
    if (triplesCount == 1 && pairsCount == 1) {
        res.push_back(7);
        res.push_back(tripleVal);
        return res;
    }
    // check flush
    if (hand[0][1] == hand[1][1] && hand[0][1] == hand[2][1] && hand[0][1] == hand[3][1] && hand[0][1] == hand[4][1]) {
        res.push_back(6);
        res.push_back(max(max(mp[hand[0][0]], mp[hand[1][0]]), max(mp[hand[2][0]], max(mp[hand[3][0]], mp[hand[4][0]]))));
        return res;
    }
    // check straight
    if (maxConsec == 5) {
        res.push_back(5);
        res.push_back(max(max(mp[hand[0][0]], mp[hand[1][0]]), max(mp[hand[2][0]], max(mp[hand[3][0]], mp[hand[4][0]]))));
        return res;
    }
    // check three of a kind
    if (triplesCount == 1) {
        res.push_back(4);
        res.push_back(tripleVal);
        return res;
    }
    // check two pairs
    if (pairsCount == 2) {
        res.push_back(3);
        res.push_back(max(doubleVal[0], doubleVal[1]));
        res.push_back(min(doubleVal[0], doubleVal[1]));
        for (int i = 0; i < 5; ++i) {
            if (mp[hand[i][0]] != doubleVal[0] && mp[hand[i][0]] != doubleVal[1]) {
                res.push_back(mp[hand[i][0]]);
                return res;
            }
        }
        return res;
    }
    // check pair
    if (pairsCount == 1) {
        res.push_back(2);
        res.push_back(doubleVal[0]);
        return res;
    }
    // else, means high card
    res.push_back(1);
    res.push_back(max(max(mp[hand[0][0]], mp[hand[1][0]]), max(mp[hand[2][0]], max(mp[hand[3][0]], mp[hand[4][0]]))));
    return res;
}

int main() {
    map<char, int> mp;
    mp['2'] = 0;
    mp['3'] = 1;
    mp['4'] = 2;
    mp['5'] = 3;
    mp['6'] = 4;
    mp['7'] = 5;
    mp['8'] = 6;
    mp['9'] = 7;
    mp['T'] = 8;
    mp['J'] = 9;
    mp['Q'] = 10;
    mp['K'] = 11;
    mp['A'] = 12;
    // read in the lines
    while (true) {
        // read in the current hand
        vector<string> hand1, hand2;
        for (int i = 0; i < 10; ++i) {
            string card;
            cin >> card;
            if (i <= 4) {
                hand1.push_back(card);
            } else {
                hand2.push_back(card);
            }
        }
        if (cin.eof()) {
            return 0;
        }
        // then get the rank of the hand
        vector<int> rank1 = getRank(hand1);
        vector<int> rank2 = getRank(hand2);
        if (rank1[0] > rank2[0]) {
            cout << "Black wins." << endl;
        } else if (rank1[0] < rank2[0]) {
            cout << "White wins." << endl;
        } else { // tiebreak
            if (rank1[0] == 9) {
                // get max hand
                if (rank1[1] > rank2[1]) {
                    cout << "Black wins." << endl;
                } else if (rank1[1] < rank2[1]) {
                    cout << "White wins." << endl;
                } else {
                    cout << "Tie." << endl;
                }
            } else if (rank1[0] == 8) {
                // get max hand
                if (rank1[1] > rank2[1]) {
                    cout << "Black wins." << endl;
                } else if (rank1[1] < rank2[1]) {
                    cout << "White wins." << endl;
                } else {
                    cout << "Tie." << endl;
                }
            } else if (rank1[0] == 7) {
                // get max hand
                if (rank1[1] > rank2[1]) {
                    cout << "Black wins." << endl;
                } else if (rank1[1] < rank2[1]) {
                    cout << "White wins." << endl;
                } else {
                    cout << "Tie." << endl;
                }
            } else if (rank1[0] == 6) {
                // get max hand
                if (rank1[1] > rank2[1]) {
                    cout << "Black wins." << endl;
                } else if (rank1[1] < rank2[1]) {
                    cout << "White wins." << endl;
                } else {
                    vector<int> h1, h2;
                    for (int i = 0; i < 5; ++i) {
                        h1.push_back(mp[hand1[i][0]]);
                        h2.push_back(mp[hand2[i][0]]);
                    }
                    sort(h1.begin(), h1.end());
                    sort(h2.begin(), h2.end());
                    int winner = 0;
                    for (int i = 4; i >= 0; --i) {
                        if (h1[i] > h2[i]) {
                            winner = 1;
                            break;
                        } else if (h1[i] < h2[i]) {
                            winner = -1;
                            break;
                        }
                    }
                    if (winner == 1) {
                        cout << "Black wins." << endl;
                    } else if (winner == -1) {
                        cout << "White wins." << endl;
                    } else {
                        cout << "Tie." << endl;
                    }
                }
            } else if (rank1[0] == 5) {
                // get max hand
                if (rank1[1] > rank2[1]) {
                    cout << "Black wins." << endl;
                } else if (rank1[1] < rank2[1]) {
                    cout << "White wins." << endl;
                } else {
                    cout << "Tie." << endl;
                }
            } else if (rank1[0] == 4) {
                // get max hand
                if (rank1[1] > rank2[1]) {
                    cout << "Black wins." << endl;
                } else if (rank1[1] < rank2[1]) {
                    cout << "White wins." << endl;
                } else {
                    cout << "Tie." << endl;
                }
            } else if (rank1[0] == 3) {
                // get max hand
                if (rank1[1] > rank2[1]) {
                    cout << "Black wins." << endl;
                } else if (rank1[1] < rank2[1]) {
                    cout << "White wins." << endl;
                } else {
                    if (rank1[2] > rank2[2]) {
                        cout << "Black wins." << endl;
                    } else if (rank1[2] < rank2[2]) {
                        cout << "White wins." << endl;
                    } else {
                        if (rank1[3] > rank2[3]) {
                            cout << "Black wins." << endl;
                        } else if (rank1[3] < rank2[3]) {
                            cout << "White wins." << endl;
                        } else {
                            cout << "Tie." << endl;
                        }
                    }
                }
            } else if (rank1[0] == 2) {
                // get max hand
                if (rank1[1] > rank2[1]) {
                    cout << "Black wins." << endl;
                } else if (rank1[1] < rank2[1]) {
                    cout << "White wins." << endl;
                } else {
                    vector<int> h1, h2;
                    for (int i = 0; i < 5; ++i) {
                        int c1 = mp[hand1[i][0]];
                        int c2 = mp[hand2[i][0]];
                        if (c1 != rank1[1]) {
                            h1.push_back(c1);
                        }
                        if (c2 != rank2[1]) {
                            h2.push_back(c2);
                        }
                    }
                    sort(h1.begin(), h1.begin());
                    sort(h2.begin(), h2.begin());
                    int winner = 0;
                    for (int i = 2; i >= 0; --i) {
                        if (h1[i] > h2[i]) {
                            winner = 1;
                            break;
                        } else if (h1[i] < h2[i]) {
                            winner = -1;
                            break;
                        }
                    }
                    if (winner == 1) {
                        cout << "Black wins." << endl;
                    } else if (winner == -1) {
                        cout << "White wins." << endl;
                    } else {
                        cout << "Tie." << endl;
                    }
                }
            } else if (rank1[0] == 1) {
                vector<int> h1, h2;
                for (int i = 0; i < 5; ++i) {
                    h1.push_back(mp[hand1[i][0]]);
                    h2.push_back(mp[hand2[i][0]]);
                }
                sort(h1.begin(), h1.end());
                sort(h2.begin(), h2.end());
                int winner = 0;
                for (int i = 4; i >= 0; --i) {
                    if (h1[i] > h2[i]) {
                        winner = 1;
                        break;
                    } else if (h1[i] < h2[i]) {
                        winner = -1;
                        break;
                    }
                }
                if (winner == 1) {
                    cout << "Black wins." << endl;
                } else if (winner == -1) {
                    cout << "White wins." << endl;
                } else {
                    cout << "Tie." << endl;
                }
            }
        }
    }
    return 0;
}
