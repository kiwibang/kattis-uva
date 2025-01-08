#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    string curr;
    while (tc--) {
        getline(cin, curr);
        list<char> res;
        list<char>::iterator it = res.begin();
        int i = 0;
        while (i < curr.size()) {
            if (curr[i] == '<') {
                if (it != res.begin()) it = res.erase(--it);
                ++i;
                continue;
            }
            if (curr[i] == '[') {
                it = res.begin();
                ++i;
                continue;
            }
            if (curr[i] == ']') {
                it = res.end();
                ++i;
                continue;
            }
            it = res.insert(it, curr[i]);
            ++it;
            ++i;
        }   
        for (char c : res) {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}

