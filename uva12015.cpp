#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int c = 1;
    while (c <= t) {
        string line;
        string websites[10];
        int relevance[10];
        int mx = 0;
        for (int i = 0; i < 10; ++i) {
            int p;
            char str[110];
            scanf("%s %d", str, &p);
            websites[i] = str;
            relevance[i] = p; 
            mx = max(mx, relevance[i]);
        }
        cout << "Case #" << c << ":" << endl;
        for (int i = 0; i < 10; ++i) {
            if (relevance[i] == mx) {
                cout << websites[i] << endl;
            }
        }
        ++c;
    }
    return 0;
}
