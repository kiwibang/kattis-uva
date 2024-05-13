#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string curr;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        getline(cin, curr);
        if (curr == "P=NP") {
            cout << "skipped" << endl;
            continue;
        }
        int a, b;
        char op;
        istringstream iss(curr);
        iss >> a >> op >> b;
        cout << a + b << endl;
    }
    return 0;
}
