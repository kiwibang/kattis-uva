#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, sal;
    cin >> m >> n;
    unordered_map<string, int> dict;
    string word;
    for (int i = 0; i < m; ++i) {
        cin >> word >> sal;
        dict[word] = sal;
    }
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        while (true) {
            cin >> word;
            if (word == ".") goto pr;
            if (dict.find(word) != dict.end()) {
                sum += dict[word];
            } 
        }
        pr: cout << sum << endl;
    }
    return 0;
}

