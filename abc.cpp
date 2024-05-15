#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, mx, mn, md;
    string line;
    cin >> a >> b >> c;
    cin.ignore();
    getline(cin, line);
    mx = max(a, max(b, c));
    mn = min(a, min(b, c));
    md = a != mn && a != mx ? a : b != mn && b != mx ? b : c != mn && c != mx ? c : -1;
    if (line[0] == 'A') {
        cout << mn << " ";
    } else if (line[0] == 'B') {
        cout << md << " ";
    } else {
        cout << mx << " ";
    }
    if (line[1] == 'A') {
        cout << mn << " ";
    } else if (line[1] == 'B') {
        cout << md << " ";
    } else {
        cout << mx << " ";
    }
    if (line[2] == 'A') {
        cout << mn << endl;
    } else if (line[2] == 'B') {
        cout << md << endl;
    } else {
        cout << mx << endl;
    }
    return 0;
}
