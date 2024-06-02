#include <bits/stdc++.h>
using namespace std;

int main() {
    // go through the game
    while (true) {
        // go through the current game
        vector<bool> guessed(11, true);
        int guess = 11;
        string judgement;
        string rubbish;
        while (true) {
            // read the input
            cin >> guess;
            if (guess == 0) {
                return 0;
            }
            cin >> rubbish;
            cin >> judgement;
            // check game end
            if (judgement == "on") {
                if (guessed[guess]) {
                    cout << "Stan may be honest" << endl;
                } else {
                    cout << "Stan is dishonest" << endl;
                }
                break;
            }
            if (judgement == "low") {
                for (int i = 1; i <= guess; ++i) {
                    guessed[i] = false;
                }
            } else if (judgement == "high") {
                for (int i = guess; i <= 10; ++i) {
                    guessed[i] = false;
                }
            }
        }
    }
    return 0;
}
