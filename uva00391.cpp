#include <bits/stdc++.h>
using namespace std;

int main() {
    string currline;
    bool markuptoggled = true;
    // loop over the lines
    while (getline(cin, currline)) {
        // loop over the characters of the current line
        int i = 0;
        while (i < currline.size()) {
            // case where no markup, and the current symbol is not a \\*, then just print out the char as is
            if (!markuptoggled && ((i < currline.size() - 1 && currline.substr(i, 2) != "\\*") || i == currline.size() - 1)) {
                cout << currline[i++];
                continue;
            }
            // case where the current character is a slash
            if (currline[i] == '\\') {
                // go over the cases
                if (i < currline.size() - 1 && (currline[i + 1] == 'b' || currline[i + 1] == 'i' || currline[i + 1] == 's' || currline[i + 1] == '*' || currline[i + 1] == '\\')) { // character after is recognized
                    if (currline[i + 1] == 'b') {
                        i += 2;
                    } else if (currline[i + 1] == 'i') {
                        i += 2;
                    } else if (currline[i + 1] == 's') {
                        i += 2;
                        // else need to skip over the number; dont print these
                        while (i < currline.size() && isdigit(currline[i])) {
                            ++i;
                        }
                        if (currline[i] == '.') {
                            ++i;
                            while (i < currline.size() && isdigit(currline[i])) {
                                ++i;
                            }
                        }
                    } else if (currline[i + 1] == '*') {
                        i += 2;
                        markuptoggled = !markuptoggled;
                    } else if (currline[i + 1] == '\\') {
                        i += 2;
                        cout << "\\";
                    }
                } else { // char after not recognized
                    ++i; // shift index to the next char
                    // edge case: next char is slash
                    if (i < currline.size() && currline[i] == '\\') {
                        cout << "\\";
                        ++i;
                    }
                }
            } else { // normal char, print as is
                cout << currline[i++];
            }
        }
        cout << endl;
    }
    return 0;
}
