#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e, numv, songid = 0;
    cin >> n >> e;
    vector<unordered_set<int>> vl(n, unordered_set<int>());
    for (int i = 0; i < e; ++i) {
        // read in the villagers
        cin >> numv;
        vector<int> attended(numv);
        unordered_set<int> knownsongs;
        bool havebard = false;
        for (int j = 0; j < numv; ++j) {
            cin >> attended[j];
            if (attended[j] == 1) havebard = true;
            // add the songs that are known
            for (int song : vl[attended[j] - 1]) knownsongs.insert(song);
        }
        // then simulate the singing process depending on whether the bard is present or not
        if (havebard) { // bard present
            // add the new song to the collection of songs the villagers know
            for (int person : attended) {
                vl[person - 1].insert(songid);
            }
            // update the songid
            ++songid;
        } else { // bard not present
            // exchange all the songs that they know with each other
            for (int person : attended) {
                for (int song : knownsongs) vl[person - 1].insert(song); 
            }
        }
    }
    // print out all the villagers who know the same number of songs as the bard
    for (int i = 1; i <= n; ++i) {
        if (vl[i - 1].size() == songid) cout << i << endl; 
    }
    return 0;
}

