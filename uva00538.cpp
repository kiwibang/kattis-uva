#include <bits/stdc++.h>
using namespace std;

int main() {
    int caseno = 1;
    while (true) {
        // get the number of travellers and the number of transactions
        string l;
        getline(cin, l);
        istringstream iss(l);
        int n, t;
        iss >> n >> t;
        if (n == 0 && t == 0) {
            return 0;
        }
        map<string, int> bank;
        vector<string> travellers;
        // get the names of the n people
        for (int i = 0; i < n; ++i) {
            string name;
            getline(cin, name);
            bank[name] = 0;
            travellers.push_back(name);
        }
        // get the transactions, and update bank balances accordingly
        for (int i = 0; i < t; ++i) {
            string giver, receiver;
            int amt;
            getline(cin, l);
            istringstream iss(l);
            iss >> giver >> receiver >> amt;
            bank[giver] -= amt;
            bank[receiver] += amt;
        }
        // get a list of positive and negative bank balances
        vector<string> pos, neg;
        for (int i = 0; i < n; ++i) {
            if (bank[travellers[i]] < 0) {
                neg.push_back(travellers[i]);
            } else if (bank[travellers[i]] > 0) {
                pos.push_back(travellers[i]);
            }
        }
        cout << "Case #" << caseno++ << endl;
        // keep doing transactions
        while (true) {
            int mx = 0, mn = 999999999;
            int idx1, idx2;
            for (int i = 0; i < n; ++i) {
                if (bank[travellers[i]] > mx) {
                    mx = bank[travellers[i]];
                    idx1 = i;
                }
                if (bank[travellers[i]] < mn) {
                    mn = bank[travellers[i]];
                    idx2 = i;
                }
            }
            // check if fully paid for
            if (mx == 0) {
                break;
            }
            // use richest traveller to pay for poorest traveller
            if (mx >= -mn) {
                cout << travellers[idx1] << " " << travellers[idx2] << " " << -mn << endl;
                int temp = -mn;
                bank[travellers[idx1]] -= temp;
                bank[travellers[idx2]] += temp;
            } else {
                cout << travellers[idx1] << " " << travellers[idx2] << " " << mx << endl;
                int temp = mx;
                bank[travellers[idx1]] -= temp;
                bank[travellers[idx2]] += temp;
            }
        }
        // print a blank line after every test case
        cout << endl;
    }
    return 0;
}
