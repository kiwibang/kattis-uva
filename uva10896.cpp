#include <bits/stdc++.h>
using namespace std;

int main() {
    // get the number of word pairs
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        // get the encrypted sentence, and the decrypted word
        string enc, dec, currword;
        getline(cin, enc);
        getline(cin, dec);
        // split the sentence by spaces
        istringstream iss(enc);
        vector<string> words;
        while (iss >> currword) {
            words.push_back(currword);
        }
        // loop over the words
        vector<char> res; 
        for (int j = 0; j < words.size(); ++j) {
            // if there is a possible match
            if (words[j].size() == dec.size()) {
                // check if there is a possible match
                // get the difference between the encrypted and decrypted word
                int encchar = (words[j][0] - 'a'), decchar = (dec[0] - 'a');
                int diff = encchar - decchar;
                if (diff < 0) {
                    diff += 26;
                }
                bool allsame = true;
                // loop over the remaining chars, and see if the difference is the same
                for (int k = 1; k < words[j].size(); ++k) {
                    // get the diff
                    int ecc = (words[j][k] - 'a'), dcc = (dec[k] - 'a');
                    int currdiff = ecc - dcc;
                    if (currdiff < 0) {
                        currdiff += 26;
                    }
                    // case where not the same
                    if (currdiff != diff) {
                        allsame = false;
                        break;
                    }
                }
                // case where valid translation
                if (allsame) {
                    res.push_back((char) (diff + 'a'));
                }
            }
        }
        sort(res.begin(), res.end());
        for (int j = 0; j < res.size(); ++j) {
            cout << res[j];
        }
        cout << endl;
    }
    return 0;
}
