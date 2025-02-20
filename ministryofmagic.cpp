#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(const pair<int, long long>& a, const pair<int, long long>& b) const {
        // beginning of set should be smallest vote, else, smaller candidate ID is first
        return a.second != b.second ? a.second < b.second : a.first < b.first;
    }
};

int main() {
    int c, p;
    cin >> c >> p;
    // track number of votes that each party has
    vector<long long> pv(p);
    // track total sum of votes and majority
    long long tv = 0, mj;
    // vector of queues to simulate party preferences
    vector<queue<int>> cds(c + 1);
    for (int i = 0; i < p; ++i) {
        cin >> pv[i];
        tv += pv[i];
        for (int j = 0; j < c; ++j) {
            int ccd;
            cin >> ccd;
            cds[i].push(ccd);
        }
    }
    // calculate the number of votes required to reach majority
    mj = (tv >> 1);
    // then simulate the runoff voting process
    unordered_map<int, long long> cdtov; // candidates to votes
    set<pair<int, long long>, cmp> rem; // remaining candidates ordered by votes
    for (int i = 1; i <= c; ++i) {
        cdtov[i] = 0;
        rem.insert({i, 0});
    }
    vector<bool> elim(c + 1, false); // eliminated candidate tracker
    vector<bool> voted(p, false); // track parties that have voted
    vector<unordered_set<int>> cdstopartyvoted(c + 1);
    for (int j = 0; j < c - 1; ++j) {
        
        for (int i = 0; i < p; ++i) {
            // for every party, find the first candidate that is not eliminated
            while (!cds[i].empty() && elim[cds[i].front()]) {
                cds[i].pop();
            }
            // then if the current party has not voted, vote for the candidate
            if (!voted[i] && !cds[i].empty()) {
                voted[i] = true;
                rem.erase({cds[i].front(), cdtov[cds[i].front()]});    
                cdtov[cds[i].front()] += pv[i];
                rem.insert({cds[i].front(), cdtov[cds[i].front()]});
                cdstopartyvoted[cds[i].front()].insert(i);
                cds[i].pop();
            }
        }
        // remove the worst party
        pair<int, long long> worst = *rem.begin();
        pair<int, long long> best = *rem.rbegin();
        // case where have winner already
        if (best.second > mj) {
            cout << best.first << endl;
            return 0;
        }
        elim[worst.first] = true;
        rem.erase(worst);
        cdtov[worst.first] = 0;
        // reset votes for parties that voted for the worst candidates
        for (int ps : cdstopartyvoted[worst.first]) {
            voted[ps] = false;
        }
        cdstopartyvoted[worst.first].clear();
    }
    pair<int, long long> wn = *rem.rbegin();
    cout << wn.first << endl;
    return 0;
}

