#include <bits/stdc++.h>
using namespace std;

int main() {
    string currline;
    vector<string> words;
    while (true) {
        getline(cin, currline);
        if (currline == "0") {
            break;
        }
        if (currline.empty()) {
            cout << endl;
            continue;
        }
        int i = 0;
        while (i < currline.size()) {
            // get the current word
            string currword = "";
            while (i < currline.size() && isalpha(currline[i])) {
                currword.push_back(currline[i]);
                ++i;
            }
            // check if word is inside the words vector
            if (currword != "") {
                words.push_back(currword);
                cout << currword;
            }
            // check for digit
            int idx = 0;
            while (i < currline.size() && isdigit(currline[i])) {
                idx = idx * 10 + (currline[i] - '0');
                ++i;
            }
            // case where index is found
            if (idx > 0) {
                string temp = words[words.size() - idx];
                // means repeated word, so print out the word at the postion
                cout << temp;
                // then move the word to the front of the list
                words.erase(words.end() - idx);
                words.push_back(temp);
            }
            // then move the pointer and print any non-alphabetic chars
            while (i < currline.size() && !isalpha(currline[i]) && !isdigit(currline[i])) {
                cout << currline[i];
                ++i;
            }
        }
        cout << endl;
    }
    return 0;
}
