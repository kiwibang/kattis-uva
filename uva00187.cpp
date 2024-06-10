#include <bits/stdc++.h> 
using namespace std;

int main() {
    // read in the accounts
    map<string, string> m;
    while (true) {
        string curr;
        getline(cin, curr);
        string id = curr.substr(0, 3);
        string name = curr.substr(3, curr.size());
        if (id == "000") {
            break;
        }
        m[id] = name;
    }
    // read the journal entries
    // key is the sequence number, value is the list of accounts and money out/in
    map<string, vector<pair<string, double> > > m2;
    string curracc = "---";
    double currbal = 0; // holds the value of account 999 (if current account is unbalanced)
    while (true) {
        // read the current journal entry
        string t, seqnum, account;
        int amt;
        cin >> t >> amt;
        seqnum = t.substr(0, 3);
        if (seqnum == "000") {
            break;
        }
        account = t.substr(3, t.size());
        // if changed to new account
        if (seqnum != curracc) {
            // check whether the account balances
            if (currbal != 0) {
                // print the unbalanced account in the specified format
                printf("*** Transaction %3s is out of balance ***\n", curracc.c_str());
                // print all the accounts that are out of balance due to the transaction
                vector<pair<string, double> > accounts = m2[curracc];
                for (int i = 0; i < accounts.size(); ++i) {
                    printf("%3s %-30s %10.2lf\n", accounts[i].first.c_str(), m[accounts[i].first].c_str(), accounts[i].second / 100.0);
                }
                // print account 999
                printf("999 Out of Balance                 %10.2lf\n", -currbal / 100.0);
                puts("");
            }
            // update the previous account to the current account
            curracc = seqnum;
            // set the current balance to 0
            currbal = 0.00;
        }
        // if first entry of the journal entry
        if (m2.find(seqnum) == m2.end()) {
            m2[seqnum] = vector<pair<string, double> >();
        }
        m2[seqnum].push_back(pair<string, int>(account, amt));
        // update the account balance
        currbal += amt;
    }
    return 0;
}
