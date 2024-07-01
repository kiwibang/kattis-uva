#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    cin >> input;
    string ref = "PER";
    int idx = 0, res = 0;;
    for (int i = 0; i < input.size(); ++i) {
        if (ref[idx] != input[i]) {
            ++res;
        }
        idx = (idx + 1) % 3;
    }
    cout << res << endl;
    return 0;
}
