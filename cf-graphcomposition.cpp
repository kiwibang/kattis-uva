#include <bits/stdc++.h>
using namespace std;

class dsu {
  public:
	vector<int> parents;
	vector<int> sizes;
    int cc = 0;
	dsu(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { 
            parents[i] = i; 
            ++cc;
        }
	}

	/** @return the "representative" node in x's component */
	int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

	/** @return whether the merge changed connectivity */
	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
        --cc;
		return true;
	}

	/** @return whether x and y are in the same connected component */
	bool connected(int x, int y) { return find(x) == find(y); }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m1, m2, x, y;
        cin >> n >> m1 >> m2;
        // read in the edges
        vector<pair<int, int>> fe(m1), ge(m2);
        for (int i = 0; i < m1; ++i) {
            cin >> x >> y;
            fe[i].first = x - 1;
            fe[i].second = y - 1;;
        }
        for (int i = 0; i < m2; ++i) {
            cin >> x >> y;
            ge[i].first = x - 1;
            ge[i].second = y - 1;;
        }
        dsu f(n), g(n); // create the dsu
        // connect the vertices by the set of given edges for both graphs
        for (auto& e : ge) {
            g.unite(e.first, e.second);
        }
        long long res = 0;
        for (auto& e : fe) {
            if (g.connected(e.first, e.second)) { // case where they are in the same cc
                f.unite(e.first, e.second);
            } else { // else, different
                ++res; // we need to remove an edge to graph f => res increases by 1
            }
        }
        // number of edges u need to remove from f + number of edges u need to add to f
        cout << res + (f.cc - g.cc) << endl;  
    }
}
