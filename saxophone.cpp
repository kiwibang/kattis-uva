#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, string> notetofingar;
    notetofingar['c'] = "0111001111";
    notetofingar['d'] = "0111001110";
    notetofingar['e'] = "0111001100";
    notetofingar['f'] = "0111001000";
    notetofingar['g'] = "0111000000";
    notetofingar['a'] = "0110000000";
    notetofingar['b'] = "0100000000";
    notetofingar['C'] = "0010000000";
    notetofingar['D'] = "1111001110";
    notetofingar['E'] = "1111001100";
    notetofingar['F'] = "1111001000";
    notetofingar['G'] = "1111000000";
    notetofingar['A'] = "1110000000";
    notetofingar['B'] = "1100000000";

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string song;
        getline(cin, song);
        if (song.size() == 0) {
            for (int i = 0; i < 10; ++i) {
                cout << 0 << " ";
            }
            cout << endl;
            continue;
        }
        vector<int> fingars(10, 0);
        string init = notetofingar[song[0]];
        for (int i = 0; i < 10; ++i) {
            if (init[i] == '1') {
                ++fingars[i];
            }
        }
        for (int i = 0; i < song.length() - 1; ++i) {
            string prev = notetofingar[song[i]];
            string curr = notetofingar[song[i + 1]];
            for (int j = 0; j < 10; ++j) {
                if (prev[j] == '0' && curr[j] == '1') {
                    ++fingars[j];
                }
            }
        }
        for (int i = 0; i < 10; ++i) {
            cout << fingars[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
