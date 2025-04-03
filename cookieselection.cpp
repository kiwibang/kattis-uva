#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    string curr;
    int num, cnt = 0;
    ordered_multiset<int> s;
    while (true) {
        cin >> curr;
        if (cin.eof()) break;
        if (curr == "#") {
            // get and return the median cookie
            pair<int, int> md = *s.find_by_order((s.size() >> 1));
            cout << md.first << "\n";
            s.erase(md);
        } else {
            num = stoi(curr);
            s.insert({num, cnt++});
        }
    }
    return 0;
}

