#include <bits/stdc++.h>
using namespace std;

int main() {
    int j = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            return 0;
        }
        // get the secret code
        vector<int> code;
        vector<int> fmap = vector<int>(11, 0);
        int t;
        for (int i = 0; i < n; ++i) {
            cin >> t;
            code.push_back(t);
            ++fmap[t];
        }
        // print the game #
        cout << "Game " << j << ":" << endl; 
        // go through the guesses for the current game
        bool hasGuess = true;
        while (true) {
            // get the current guess
            vector<int> currGuess;
            for (int i = 0; i < n; ++i) {
                cin >> t;
                currGuess.push_back(t);
                hasGuess = t != 0; 
            }
            if (!hasGuess) {
                break;
            }
            int strong = 0, weak = 0;
            vector<int> fmapcopy = fmap;
            vector<bool> isStrong(n, false);
            for (int i = 0; i < n; ++i) {
                if (currGuess[i] == code[i]) {
                    isStrong[i] = true;
                    --fmapcopy[currGuess[i]];
                    ++strong;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (!isStrong[i] && fmapcopy[currGuess[i]] > 0) {
                    ++weak;
                    --fmapcopy[currGuess[i]];
                }
            }
            cout << "    (" << strong << "," << weak << ")" << endl;
        }
        ++j;
    }
    return 0;
}
