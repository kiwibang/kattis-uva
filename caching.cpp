#include <bits/stdc++.h>
using namespace std;

struct Compare {
    // compare on the second value, which is the time
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second == b.second)
            return a.first < b.first; // Higher second value first
        return a.second > b.second; // Higher first value first
    }
};

int main() {
    // read in the given inputs
    int c, n, a, mem; // cache capacity, object size, number of accesses
    cin >> c >> n >> a;

    // data structures
    // track the access times for each object
    unordered_map<int, set<int>> objtoint;
    // store the cache objects with their next access time, ordered in 
    // decreasing order by their next access time
    set<pair<int, int>, Compare> cache; 
    unordered_map<int, int> memtoaccess; // save the current next access time of mem objects in the stack
    vector<int> accesses(a);

    // get the memory accesses
    for (int i = 0; i < a; ++i) {
        cin >> mem;
        if (objtoint.find(mem) == objtoint.end()) objtoint[mem] = set<int>();
        objtoint[mem].insert(i);
        accesses[i] = mem;
    }

    // simulate the accesses
    long long res = 0;
    for (int i = 0; i < a; ++i) {
        // get the current memory access
        int ac = accesses[i];
        // get the next access time
        int curraccess = objtoint[ac].size() ? *objtoint[ac].begin() : INT_MAX;
        // access time has been "consumed", so remove it
        objtoint[ac].erase(curraccess);
        // cache hit, mem page in cache
        if (memtoaccess.find(ac) != memtoaccess.end()) {
            // update access time in cache
            cache.erase({ac, memtoaccess[ac]});
            int nextaccess = objtoint[ac].size() ? *objtoint[ac].begin() : INT_MAX;
            cache.insert({ac, nextaccess});
            memtoaccess[ac] = nextaccess; // update next access time
        } else { // cache miss
            // cache not full yet
            if (cache.size() < c) {
                // insert mem page into cache
                int nextaccess = objtoint[ac].size() ? *objtoint[ac].begin() : INT_MAX;
                cache.insert({ac, nextaccess});
                memtoaccess[ac] = nextaccess; // update next access time
            } else {
                // evict the page that will be accessed the farthest in 
                // the future
                pair<int, int> cc = *cache.begin();
                cache.erase(cc);
                memtoaccess.erase(cc.first);
                // replace with current page and next access
                int nextaccess = objtoint[ac].size() ? *objtoint[ac].begin() : INT_MAX;
                cache.insert({ac, nextaccess});
                memtoaccess[ac] = nextaccess; // update next access time
            }
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}

