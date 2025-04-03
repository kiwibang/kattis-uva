#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t, n, num;
    long long sum;
    cin >> t;
    while (t--) {
        ordered_multiset<int> s;
        cin >> n;
        sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            s.insert({num, i});
            // get median and add to res
            if (s.size() & 1) {
                sum += s.find_by_order(s.size() >> 1)->first;
            } else {
                sum += (s.find_by_order((s.size() >> 1) - 1)->first + s.find_by_order((s.size() >> 1))->first) >> 1;
            }
        }        
        cout << sum << "\n";
    }
    return 0;
}

