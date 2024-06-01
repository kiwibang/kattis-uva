#include <bits/stdc++.h>
using namespace std;

// try all configurations
void hp(vector<int>& guess, vector<int>& possible, int idx, int &res, int f1, int f2) {
    if (idx >= possible.size()) { // if we have finished building a possible configuration
        int f1c = 0, f2c = 0; // count the number of correct pos and wrong pos
        // count the number of correct position
        map<int, int> mp;
        for (int i = 0; i < possible.size(); ++i) {
            if (possible[i] == guess[i]) { // in the exact same position
                ++f1c;
                continue;
            }
            ++mp[possible[i]];
        }
        // count the number of wrong position
        for (int i = 0; i < possible.size(); ++i) {
            if (guess[i] != possible[i] && mp.find(guess[i]) != mp.end()) { // not the same and inside
                ++f2c;
                --mp[guess[i]];
                if (mp[guess[i]] == 0) {
                    mp.erase(guess[i]);
                }
            }
        }
        // check if it is an ok configuration
        if (f1c == f1 && f2c == f2) {
            ++res;
        }
        return;
    }
    // build the configuration
    for (int i = 1; i <= 9; ++i) {
        possible[idx] = i;
        hp(guess, possible, idx + 1, res, f1, f2);
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        // read each input
        string guess;
        int f1, f2;
        cin >> guess >> f1 >> f2;
        // process the guess into vector
        vector<int> gues;
        for (int j = 0; j < guess.size(); ++j) {
            gues.push_back(guess[j] - '0');
        }
        vector<int> possibul(guess.size());
        int res = 0;
        // count the number of possible configurations
        hp(gues, possibul, 0, res, f1, f2);
        // print the res
        cout << res << endl;
    }
    return 0;
}
