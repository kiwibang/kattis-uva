#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, curr, top = -1;
    cin >> n;
    vector<int> s(n);
    while (n--) {
        cin >> curr;
        if (top != -1 && !((s[top] + curr) & 1)) {
            --top;
        } else {
            s[++top] = curr;
        }
    }
    cout << top + 1 << endl;
    return 0;
}

