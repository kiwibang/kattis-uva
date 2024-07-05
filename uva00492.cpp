#include <bits/stdc++.h>
using namespace std;

bool isvowel(char cc) {
    char t = tolower(cc);
    return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u';
}

int main() {
    string currline;
    while (true) {
        getline(cin, currline);
        if (cin.eof()) {
            break;
        }
        string currword = "";
        for (int i = 0; i < currline.size(); ++i) {
            if (!isalpha(currline[i])) {
                // check the word if not empty
                if (currword != "") {
                    if (isvowel(currword[0])) {
                        cout << currword << "ay";
                    } else {
                        cout << currword.substr(1) << currword[0] << "ay";
                    }
                }
                currword = "";
                // print the current line as is
                cout << currline[i];
            } else {
                currword.push_back(currline[i]);
            }
        }
        cout << endl;
    }
    return 0;
}
