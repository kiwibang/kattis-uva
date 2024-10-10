#include <bits/stdc++.h>
using namespace std;

int main() {
    // read in P and D
    int p, d;
    cin >> p >> d;
    // then get the info for the P precincts
    vector<int> avotes(d, 0);
    vector<int> bvotes(d, 0);
    int id, av, bv;
    for (int i = 0; i < p; ++i) {
        // read in the district number, votes for A, votes for B
        cin >> id >> av >> bv;
        avotes[id - 1] += av;
        bvotes[id - 1] += bv;
    }
    // loop over the distrcts, determine the winner, and print the wasted votes
    int atw = 0, btw = 0, tv = 0;
    for (int i = 0; i < d; ++i) {
        // get the winner
        char winner = avotes[i] > bvotes[i] ? 'A' : 'B';
        // get the total number of votes
        int total = avotes[i] + bvotes[i];
        // get the wasted votes 
        int awasted, bwasted;
        if (winner == 'A') { // A wins
            awasted = avotes[i] - (total / 2) - 1;
            bwasted = bvotes[i];
        } else { // B wins
            bwasted = bvotes[i] - (total / 2) - 1;
            awasted = avotes[i];
        }
        // update the total votes for A, B and overall
        atw += awasted, btw += bwasted, tv += total;
        // print the results for the current district
        cout << winner << " " << awasted << " " << bwasted << endl;
    }
    // get the efficiency gap and print it
    cout << fixed << setprecision(10) << (double) abs(atw - btw) / tv << endl;
    return 0;
}
