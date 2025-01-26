#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string word;
    vector<int> charton = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
    unordered_map<string, int> f;
    // read in the words
    for (int i = 0; i < n; ++i) {
        cin >> word;
        string num = "";
        for (char c : word) {
            num += (charton[c - 'a'] + '0');
        }
        if (f.find(num) == f.end()) f[num] = 0;
        ++f[num];
    }
    string number;
    cin >> number;
    cout << (f.find(number) == f.end() ? 0 : f[number]) << endl;
    return 0;
}

