#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    while (true) {
        // read in the two lines. a is the encrypted text, b is the decrypted text
        cin >> a >> b;
        if (cin.eof()) {
            break;
        }
        // then count the frequency of the letters using frequency vectors
        vector<int> fa(26, 0);
        vector<int> fb(26, 0);
        for (int i = 0; i < a.size(); ++i) {
            ++fa[a[i] - 'A'];
            ++fb[b[i] - 'A'];
        }
        // sort the frequencty vectors in O(26log26) = O(1), and check whether equals
        sort(fa.begin(), fa.end());
        sort(fb.begin(), fb.end());
        // then check equality
        bool ok = true;
        for (int i = 0; i < 26; ++i) {
            if (fa[i] != fb[i]) {
                cout << "NO" << endl;
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}
