#include <bits/stdc++.h>
using namespace std;

int main() {
    string curr;
    unordered_map<string, int> votes;
    while (getline(cin, curr)) {
        if (curr == "***") break;
        if (votes.find(curr) == votes.end()) votes[curr] = 0;
        ++votes[curr];
    }
    int mx = 0, mxc = 0;
    string name;
    for (auto& p : votes) {
        if (p.second == mx) {
            ++mxc;
        } else if (p.second > mx) {
            mx = p.second;
            mxc = 1;
            name = p.first;
        }
    }
    if (mxc == 1) {
        cout << name << endl;
    } else {
        cout << "Runoff!" << endl;
    }
    return 0;
}

