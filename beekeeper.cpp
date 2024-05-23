#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int mx = -1;
        string res;
        for (int j = 0; j < n; ++j) {
            string word;
            cin >> word;
            int count = 0;
            for (int i = 0; i < word.length() - 1; ++i) {
                if (word[i] == word[i + 1] && (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || word[i] == 'y')) {
                    ++count;
                }
            }
            if (count > mx) {
                mx = count;
                res = word;
            }
        }
        cout << res << endl;
    }
    return 0;
}
