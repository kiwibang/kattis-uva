#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // read in the noises made
        vector<string> noises;
        string curr, temp;
        getline(cin, curr);
        istringstream iss(curr);
        while (iss >> temp) {
            noises.push_back(temp);        
        }
        // reaad in the noises that the other animals make
        unordered_set<string> known;
        while (true) {
            getline(cin, curr);
            if (curr == "what does the fox say?") break;
            istringstream iss(curr);
            iss >> temp >> temp >> temp;
            known.insert(temp);
        }
        for (int i = 0; i < noises.size(); ++i) {
            if (known.find(noises[i]) == known.end()) cout << noises[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

