#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<string> g(r);
    for (int i = 0; i < r; ++i) cin >> g[i];
    string curr = "", smallest = "";
    // check rows    
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (g[i][j] == '#') {
                if (curr.size() >= 2 && (smallest == "" || curr < smallest)) {
                    smallest = curr;
                }
                curr = "";
                continue;
            }
            curr += g[i][j];
        }
        if (curr.size() >= 2 && (smallest == "" || curr < smallest)) {
            smallest = curr;
        }
        curr = "";
    } 
    for (int j = 0; j < c; ++j) {
        for (int i = 0; i < r; ++i) {
            if (g[i][j] == '#') {
                if (curr.size() >= 2 && (smallest == "" || curr < smallest)) {
                    smallest = curr;
                }
                curr = "";
                continue;
            }
            curr += g[i][j];
        }
        if (curr.size() >= 2 && (smallest == "" || curr < smallest)) {
            smallest = curr;
        }
        curr = "";
    }
    cout << smallest << endl;
    return 0;
}

