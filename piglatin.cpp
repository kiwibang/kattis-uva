#include <bits/stdc++.h>
using namespace std;

bool isvowel(char cc) {
    char t = tolower(cc);
    return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u' || t == 'y';
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
                        cout << currword << "yay";
                    } else { // starts with consonant
                        string temp = "";
                        int j = 0;
                        for (; j < currword.size(); ++j) {
                            if (isvowel(currword[j])) {
                                break;
                            }
                            temp.push_back(currword[j]);
                        }
                        cout << currword.substr(j) << temp << "ay";
                    }
                }
                currword = "";
                // print the current line as is
                cout << currline[i];
            } else {
                currword.push_back(currline[i]);
                if (i == currline.size() - 1) {
                    if (isvowel(currword[0])) {
                        cout << currword << "yay";
                    } else { // starts with consonant
                        string temp = "";
                        int j = 0;
                        for (; j < currword.size(); ++j) {
                            if (isvowel(currword[j])) {
                                break;
                            }
                            temp.push_back(currword[j]);
                        }
                        cout << currword.substr(j) << temp << "ay";
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}
