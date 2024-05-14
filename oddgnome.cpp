#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, g, prevNome, currNome;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> g;
        bool kingFound = false;
        prevNome = -1;
        currNome = -1;
        // loop over remaining nomes
        for (int j = 1; j <= g; ++j) {
            if (prevNome == -1) {
                cin >> prevNome;
                continue;
            }
            cin >> currNome;
            if (kingFound) {
                continue;
            }
            if (abs(currNome - prevNome) > 1 || currNome < prevNome) {
                cout << j << endl;
                kingFound = true;
            }
            prevNome = currNome;
        } 
    }
    return 0;
}
