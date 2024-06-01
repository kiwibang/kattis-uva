#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int round;
        cin >> round;
        if (round == -1) {
            return 0;
        }
        map<char, bool> mp;
        string l;
        cin >> l;
        for (int i = 0; i < l.size(); ++i) {
            mp[l[i]] = false;
        }
        string guess;
        cin >> guess;
        set<char> guesses;
        int guessedCount = 0;
        int wrongCount = 0;
        int outcome = 0;
        for (int i = 0; i < guess.size(); ++i) {
            // if correct character and not guessed already
            if (mp.find(guess[i]) != mp.end() && !mp[guess[i]]) {
                mp[guess[i]] = true;
                ++guessedCount;
                if (guessedCount == mp.size()) { // if guessed all characters
                    outcome = 1;
                    break;
                }
            } else if (mp.find(guess[i]) == mp.end() && guesses.find(guess[i]) == guesses.end()) { // if wrong character and not guessed before
                ++wrongCount;
                guesses.insert(guess[i]);
                if (wrongCount == 7) { // if guessed too many wrongs
                    outcome = -1;
                    break;
                }
            }
        }
        cout << "Round " << round << endl;
        if (outcome == 1) {
            cout << "You win." << endl;
        } else if (outcome == -1) {
            cout << "You lose." << endl;
        } else {
            cout << "You chickened out." << endl;
        }
    }
    return 0;
}
