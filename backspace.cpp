#include <bits/stdc++.h>
using namespace std;

int main() {
    string curr, res = "";
    cin >> curr;
    for (int i = 0; i < curr.size(); ++i) {
        if (curr[i] == '<') {
            if (res.size()) res.pop_back();
            continue;
        }
        res.push_back(curr[i]);
    }
    cout << res << endl;
    return 0;
}

