#include <bits/stdc++.h>
using namespace std;

int main() {
    // read input
    string pref;
    cin >> pref;
    int n = pref.size();
    // try policy 1
    char prev = pref[0];
    int count = 0;
    for (int i = 1; i < n; ++i) {
        if (prev != pref[i]) {
            ++count;
            prev = pref[i];
        }
        if (pref[i] == 'D') {
            prev = 'U';
            ++count;
        }
    }
    cout << count << endl;
    prev = pref[0];
    count = 0;
    // try policy 2
    for (int i = 1; i < n; ++i) {
        if (prev != pref[i]) {
            ++count;
            prev = pref[i];
        }
        if (pref[i] == 'U') {
            prev = 'D';
            ++count;
        }
    }
    cout << count << endl;
    prev = pref[0];
    // try policy 3
    count = 0;
    for (int i = 1; i < n; ++i) {
        // person needs to adjust the toilet seat once
        if (prev != pref[i]) {
            ++count; 
        }
        // update the prev
        prev = pref[i];
    }
    cout << count << endl;
    return 0;
}
