#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        // read in the number of bits in a byte, and the number of variables in RAM
        int b, v;
        cin >> b >> v;
        if (cin.eof()) {
            return 0;
        }
        // maps each listed variable to the "memory location"
        vector<string> vars;
        vector<int> space;
        map<string, unsigned long long> contents;
        for (int i = 0; i < v; ++i) {
            string var;
            int ti;
            cin >> var >> ti;
            vars.push_back(var);
            space.push_back(ti);
        }
        // loop over the memory location, and get the value of each variable
        for (int i = 0; i < v; ++i) {
            // get the contents of the current variable
            string var = vars[i];
            int sp = space[i];
            string mem = "";
            for (int j = 0; j < sp; ++j) {
                string curr;
                cin >> curr;
                mem += curr;
            }
            contents[var] = stoull(mem, nullptr, 2);
        }
        int numvar;
        cin >> numvar;
        for (int i = 0; i < numvar; ++i) {
            string currvar;
            cin >> currvar;
            cout << currvar << "=";
            if (contents.find(currvar) != contents.end()) {
                cout << contents[currvar];
            }
            cout << endl;
        }
    }
    return 0;
}
