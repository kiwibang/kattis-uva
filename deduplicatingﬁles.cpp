#include <bits/stdc++.h>
using namespace std;

int get_hash(string& s) {
    int res = 0;
    for (char c : s) {
        res ^= (char) c;
    }
    return res;
}

int main() {
    int n, hash;
    string curr;
    while (true) {
        cin >> n;
        cin.ignore();
        if (!n) return 0;
        unordered_map<int, unordered_map<string, int>> hashtostr;
        unordered_set<string> uf;
        int coll = 0;
        for (int i = 0; i < n; ++i) {
            getline(cin, curr);
            int hash = get_hash(curr);
            // entry of the current hash does not exist yet
            if (hashtostr.find(hash) == hashtostr.end()) {
                hashtostr[hash] = unordered_map<string, int>();
                hashtostr[hash][""] = 0; // store the total number of strs
            }
            // entry of the current str does not exist yet
            if (hashtostr[hash].find(curr) == hashtostr[hash].end()) {
                hashtostr[hash][curr] = 0;
            }
            // update frequency of the str
            ++hashtostr[hash][curr];
            // update the total number of strings with the same hash value
            ++hashtostr[hash][""];
            coll += hashtostr[hash][""] - hashtostr[hash][curr];
            // insert the str into the set of strings seen so far
            uf.insert(curr);
        }
        // by termination, it is guaranteed that the number of the set of unique file names is equal to the cardinality of the set uf 
        cout << uf.size() << " " << coll << endl;
    }   
    return 0;
}

