#include <bits/stdc++.h>
using namespace std;

int main() {
    string currline, maxline, temp = "";
    int maxl = 0;
    while (getline(cin, currline)) {
        for (int i = 0; i < currline.size(); ++i) {
            if (isalpha(currline[i]) || currline[i] == '-') {
                temp.push_back(currline[i]);
            } else { // non alphabet
                if (temp.size() > maxl) {
                    maxl = temp.size();
                    maxline = temp;
                }
                temp = "";
            }
        }
        if (temp.size() > maxl) {
            maxl = temp.size();
            maxline = temp;
        }
        temp = "";
    }
    for (int i = 0; i < maxline.size(); ++i) {
        cout << (char) tolower(maxline[i]);
    }
    cout << endl;
    return 0;
}
