#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int k, n;
        cin >> k >> n;
        if (k == 0 && n == 0) {
            return 0;
        }
        map<int, vector<int> > reviewtoreviewed;
        vector<string> insts(n + 1, "");
        vector<int> receivedcount(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            string inst;
            cin >> inst;
            insts[i] = inst;
            vector<int> reviewed;
            set<int> seen;
            for (int j = 0; j < k; ++j) {
                int cc;
                cin >> cc;
                reviewed.push_back(cc);
                if (seen.find(cc) != seen.end()) { // reviewed the same paper > 1
                    receivedcount[cc] = -1410065407;
                }
                seen.insert(cc);
                ++receivedcount[cc]; // update the number of reviewers for paper with an id of cc
            }
            reviewtoreviewed[i] = reviewed;
        }
        for (int i = 1; i <= n; ++i) {
            vector<int> reviews = reviewtoreviewed[i];
            for (int j = 0; j < reviews.size(); ++j) {
                if (insts[i] == insts[reviews[j]]) {
                    receivedcount[reviews[j]] = -1410065407;
                }
            }
        }
        // scan the number of reviews for each paper, and count number of violations
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (receivedcount[i] != k) {
                ++res;
            }
        }
        if (res == 0) {
            cout << "NO PROBLEMS FOUND" << endl;
        } else if (res == 1) {
            cout << "1 PROBLEM FOUND" << endl;
        } else {
            cout << res << " PROBLEMS FOUND" << endl;
        }
    }
    return 0;
}
