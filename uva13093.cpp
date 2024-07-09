#include <bits/stdc++.h>
using namespace std;

int main() {
    string authors, name, ainitial, ninitial, temp;
    while (true) {
        getline(cin, authors);
        getline(cin, name);
        if (cin.eof()) {
            break;
        }
        istringstream iss1(authors);
        istringstream iss2(name);
        ainitial = "", ninitial = "";
        while (iss1 >> temp) {
            ainitial.push_back(temp[0]);
        }
        while (iss2 >> temp) {
            ninitial.push_back(temp[0]);
        }
        cout << (ainitial == ninitial ? "yes" : "no") << endl;
    }
}
