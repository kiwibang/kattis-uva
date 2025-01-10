#include <bits/stdc++.h>
using namespace std;

struct pqcomp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second; 
    }
};

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first;
}

int main() {
    int k, n, curry, currstr;
    cin >> k >> n;
    cin >> curry >> currstr;
    pair<int, int> karl = pair<int, int>(curry, currstr);
    vector<pair<int, int> > moose;
    moose.push_back(karl);
    for (int i = 0; i < n + k - 2; ++i) {
        cin >> curry >> currstr;
        moose.push_back(pair<int, int>(curry, currstr));
    }
    sort(moose.begin(), moose.end(), cmp);
    priority_queue<pair<int, int>, vector<pair<int, int> >, pqcomp> pq;
    int curryear = 2010;
    for (int i = 0; i < moose.size(); ++i) {
        // if have not entered all contestants for 2011's contest, then we keep adding
        if (pq.size() < k) {
            pq.push(moose[i]);
            continue;
        }
        ++curryear;
        // else, we find the winner first
        pair<int, int> winner = pq.top();
        // case where the winner is karl
        if (winner == karl) {
            cout << curryear << endl;
            return 0;
        }
        // remove the winner
        pq.pop();
        // add the current moose
        pq.push(moose[i]);
    }
    ++curryear;
    if (pq.top() == karl) {
        cout << curryear << endl;
        return 0;
    }
    cout << "unknown" << endl;
    return 0;
}

