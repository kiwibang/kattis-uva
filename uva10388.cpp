#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    int n;
    iss >> n;
    getline(cin, line);
    for (int i = 1; i <= n; ++i) {
        if (i > 1) {
            cout << endl;
        }
        // get the line
        string janedown, johndown, janeup = "", johnup = "";
        getline(cin, janedown);
        getline(cin, johndown);
        // simulate the game
        int total = (janedown.length() << 1);
        int rounds = 0;
        bool haveWinner = false;
        while (rounds++ <= 1000) {
            // check if no card
            if (janedown.length() == 0) {
                for (int i = janeup.length() - 1; i >= 0; --i) {
                    janedown.push_back(janeup[i]);
                }
                janeup = "";
            }
            if (johndown.length() == 0) {
                for (int i = johnup.length() - 1; i >= 0; --i) {
                    johndown.push_back(johnup[i]);
                }
                johnup = "";
            }
            // get the current card from the facedown deck
            char janecard = janedown[0];
            char johncard = johndown[0];
            janedown.erase(0, 1);
            johndown.erase(0, 1);
            // place the card in the faceup file
            janeup.insert(janeup.begin(), janecard);
            johnup.insert(johnup.begin(), johncard);
            // if same
            if (janecard == johncard) {
                // see who calls snap! first
                int turn = random() / 141 % 2;
                cout << "Snap! for ";
                // jane calls
                if (turn == 0) {
                    // take john's face up cards
                    janeup = johnup + janeup;
                    johnup = "";
                    cout << "Jane: " << janeup << endl;
                } else { // john calls
                    // take jane's face up
                    johnup = janeup + johnup;
                    janeup = "";
                    cout << "John: " << johnup << endl;
                }
            }
            // check if have a winner
            if (janeup.length() + janedown.length() == 0) {
                cout << "John wins." << endl;
                haveWinner = true;
                break;
            } 
            if (johnup.length() + johndown.length() == 0) {
                cout << "Jane wins." << endl;
                haveWinner = true;
                break;
            }
        }
        if (!haveWinner) {
            cout << "Keeps going and going ..." << endl;
        }
        // ignore blank line
        getline(cin, line);
    }
    return 0;
}
