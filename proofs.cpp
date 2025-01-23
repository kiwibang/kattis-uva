#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, wrongl = -1;
    cin >> n;
    cin.ignore();
    string curr, temp;
    unordered_set<string> axioms;
    for (int i = 1; i <= n; ++i) {
        getline(cin, curr);
        istringstream iss(curr);
        // read in the assumptions
        if (wrongl != -1) continue; // case where one line is wrong => just read line and skip
        while (true) {
            iss >> temp;
            if (temp == "->") break;
            if (axioms.find(temp) == axioms.end()) { // case where assumption is false (i.e. not an axiom)
                wrongl = i;
                break;
            } 
            // else, ok, current assumption is an axiom
        }
        // then read in the conclusions
        if (wrongl != -1) continue;
        // add the conclusions to the set of axioms
        while (iss >> temp) axioms.insert(temp);
    }
    if (wrongl == -1) {
        cout << "correct" << endl;
    } else {
        cout << wrongl << endl;
    }
    return 0;
}

