// adapted from https://github.com/mpfeifer1/Kattis/blob/master/sabor.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // read in the number of MPs
    int n;
    cin >> n;
    // build the adjacency list
    vector<vector<int> > adj(n, vector<int>());
    string res(n, 'A');
    for (int i = 0; i < 5; ++i) {
        int p;
        cin >> p;
        for (int j = 0; j < p; ++j) {
            int k, l;
            cin >> k >> l;
            --k, --l;
            adj[k].push_back(l);
            adj[l].push_back(k);
        }
    } 
    // use a queue to iteratively check each MP for constraint violation
    queue<int> q;
    // add all MPs to the queue since we need all MPs to satisfy the constraints
    for (int i = 0; i < n; ++i) {
        q.push(i);
    }
    // process each MP
    while (!q.empty()) {
        int curr = q.front(), samec = 0;
        q.pop();
        // count the number of same party member's as the current MP
        for (int nb : adj[curr]) if (res[curr] == res[nb]) ++samec;
        // case where there is a violation
        if (samec > 2) {
            // since we have max 5 edges for every MP, flipping the current MP's 
            // party ensures that constraints are satisfied
            res[curr] = res[curr] ^ 'A' ^ 'B';
            // since flipping the current MP might cause neighbours to violate 
            // constraints, add them to the queue for rechecking
            for (int nb : adj[curr]) q.push(nb);
        }
    }
    // simulation is finite, so we know the algorithm will terminate. print result
    cout << res << endl;
}
