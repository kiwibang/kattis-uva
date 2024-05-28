#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        vector<int> hand(3, 0);
        cin >> hand[0] >> hand[1] >> hand[2];
        if (hand[0] == 0 && hand[0] == 0 && hand[0] == 0) {
            return 0;
        }
        sort(hand.begin(), hand.end());
        // if set 
        if (hand[0] == hand[1] && hand[1] == hand[2]) {
            // case where it is a king set (highest hand globally) => no higher ranked hand
            if (hand[0] == 13) {
                cout << "*" << endl;
            } else { // not king set => just find the next highest ranked set
                cout << hand[0] + 1 << " " << hand[0] + 1 << " " << hand[0] + 1 << endl;
            }
        } else if (hand[0] == hand[1] || hand[1] == hand[2]) { // if pair
            // find the unmatched card
            int unmatchedCard = hand[0] == hand[1] ? hand[2] : hand[0];
            // find the matched pair
            int matchedCard = hand[0] == hand[1] ? hand[0] : hand[2];
            // if unmatched card is a king => next higher ranked hand is a pair where the two matched cards is one more than the value of the current matched pair
            if (unmatchedCard == 13) {
                cout << "1 " << matchedCard + 1 << " " << matchedCard + 1 << endl;
            } else { // if unmatched card is not a king => we want to increase the value of the unmatched card
                ++unmatchedCard;
                // edge case: if increasing the unmatched card results in set => increase until not a set
                while (unmatchedCard == matchedCard) {
                    ++unmatchedCard;
                }
                if (unmatchedCard > 13) {
                    cout << "1 1 1" << endl;
                } else if (unmatchedCard > matchedCard) {
                    cout << matchedCard << " " << matchedCard << " " << unmatchedCard << endl;
                } else {
                    cout << unmatchedCard << " " << matchedCard << " " << matchedCard << endl;
                }
            }
        } else { // if no-pair
            // beat with the lowest ranked pair
            cout << "1 1 2" << endl;
        }
    }
    return 0;
}
