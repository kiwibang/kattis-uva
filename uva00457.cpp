#include <bits/stdc++.h>
using namespace std;

int main() {
    // read in the number of testcases
    int t;
    cin >> t;
    // loop over the testcases
    for (int tc = 1; tc <= t; ++tc) {
        // print a blank line between each testcase
        if (tc > 1) {
            cout << endl;
        }
        // read in the dna
        vector<int> dna;
        for (int i = 0; i < 10; ++i) {
            int curr;
            cin >> curr;
            dna.push_back(curr);
        }
        // build initial configuration
        vector<int> dishes(40, 0);
        dishes[19] = 1;
        // simulate
        // print the current day first
        for (int i = 0; i < 40; ++i) {
            char c = dishes[i] == 0 ? ' ' : dishes[i] == 1 ? '.' : dishes[i] == 2 ? 'x' : 'W';
            cout << c;
        }
        cout << endl;
        for (int day = 1; day < 50; ++day) {
            vector<int> temp(40, 0);
            // then update the sum
            for (int i = 0; i < 40; ++i) {
                int left = i == 0 ? 0 : dishes[i - 1];
                int right = i == 39 ? 0 : dishes[i + 1];
                temp[i] = dishes[i] + left + right;
                temp[i] = dna[temp[i]];
            }
            // print the current day first
            for (int i = 0; i < 40; ++i) {
                char c = temp[i] == 0 ? ' ' : temp[i] == 1 ? '.' : temp[i] == 2 ? 'x' : 'W';
                cout << c;
            }
            cout << endl;
            dishes = temp;
        }
    }
    return 0;
}
