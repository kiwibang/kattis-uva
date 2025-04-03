#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    ordered_set<string> m, f;
    int gs, cnt; 
    string nm, st, en;
    while (true) {
        int cmd;
        cin >> cmd;
        if (cmd == 0) { // end of input, break out and return
            break;
        } else if (cmd == 1) { // add a suggestions
            cin >> nm >> gs;
            gs == 1 ? m.insert(nm) : f.insert(nm);
        } else if (cmd == 2) { // remove a suggestion
            cin >> nm;
            if (m.find(nm) != m.end()) m.erase(nm);
            else f.erase(nm); 
        } else if (cmd == 3) { // return query
            cin >> st >> en >> gs;
            if (gs == 0) { // both  
                cnt = m.order_of_key(en) + f.order_of_key(en) - f.order_of_key(st) - m.order_of_key(st);
                
            } else if (gs == 1) { // male only query
                cnt = m.order_of_key(en) - m.order_of_key(st);
            } else if (gs == 2) { // female only query
                cnt = f.order_of_key(en) - f.order_of_key(st);
            }
            cout << cnt << "\n";
        }
    } 
    return 0;
}


