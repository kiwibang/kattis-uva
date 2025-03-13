#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    map<int, vector<string>> opref;
    // if any preference size less than k, or preference list exhausted, then resort to prev year's ranking
    for (int i = 0; i < n; ++i) {
        int q;
        cin >> q;
        vector<string> pref(q);
        for (int j = 0; j < q; ++j) {
            cin >> pref[j];
        }
        reverse(pref.begin(), pref.end());
        opref[i] = pref;
    }
    // read in the players
    int p;
    cin >> p;
    map<int, string> rtop;
    unordered_map<string, int> pltor;
    for (int i = 0; i < p; ++i) {
        string pl;
        cin >> pl;
        rtop[i] = pl;
        pltor[pl] = i;
    }
    // simulate the process
    vector<vector<string>> res(n, vector<string>());
    // choose k players for each owner
    for (int i = 0; i < k; ++i) {
        // let each owner choose a player for the current round
        for (int j = 0; j < n; ++j) {
            string cpl = "";
            while (opref[j].size()) {
                if (pltor.find(opref[j][opref[j].size() - 1]) == pltor.end()) { // already chosen
                    // remove player from preference and try the next one in the next iteration
                    opref[j].pop_back();
                } else { // not already chosen
                    // then record down the player, and break out of the loop
                    cpl = opref[j][opref[j].size() - 1];
                    break;
                }
            }
            // case where we have a player from the owner's preference list
            if (cpl != "") {
                // then remove the player from the map of unchosen players
                res[j].push_back(cpl);
                rtop.erase(pltor[cpl]);
                pltor.erase(cpl);
            } else { // otherwise, we just fallback on the previous year's ranking
                auto& p = *rtop.begin();
                cpl = p.second;
                rtop.erase(pltor[cpl]);
                pltor.erase(cpl);
                res[j].push_back(cpl);
            }
        }
    }
    // print out the results of the final draft
    for (int i = 0; i < n; ++i) {
        for (string& pl : res[i]) {
            cout << pl << " ";
        }
        cout << endl;
    }
    return 0;
}

