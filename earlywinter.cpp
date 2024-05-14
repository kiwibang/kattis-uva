#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, dm, curr, count = 0;
    cin >> n >> dm;
    while (n--) {
        cin >> curr;
        if (curr <= dm) {
            cout << "It hadn't snowed this early in " << count << " years!" << endl;
            return 0;
        }
        count++;
    }
    cout << "It had never snowed this early!" << endl;
    return 0;
}
