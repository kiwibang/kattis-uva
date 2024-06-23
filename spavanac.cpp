#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, m;
    cin >> h >> m;
    m = m - 45;
    if (m < 0) {
        --h;
        m += 60;
        if (h < 0) {
            h = 23;
        }
    }
    cout << h << " " << m << endl; 
    return 0;
}
