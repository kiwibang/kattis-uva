#include <bits/stdc++.h>
using namespace std;

void printnote(vector<int>& nt) {
    for (int i = 0; i < nt.size(); ++i) {
        cout << nt[i];
        if (i < nt.size() - 1) {
            cout << " "; 
        }
    }
    cout << endl;
}

int main() {
    while (true) {
        int n, code, note, m, b, t;
        cin >> n;
        if (n == -1) {
            cout << -1 << endl;
            return 0;
        }
        vector<vector<int> > notes;
        for (int i = 0; i < n; ++i) {
            cin >> code >> note >> m >> b >> t;
            t = ((t + 30) / 60) * 60;
            if (t == 480) {
                t = 0;
                ++b;
                if (b == 5) {
                    b = 1;
                    ++m;
                }
            }
            vector<int> ce;
            ce.push_back(code);
            ce.push_back(note);
            ce.push_back(m);
            ce.push_back(b);
            ce.push_back(t);
            notes.push_back(ce);
        }
        vector<bool> toprint(n, true);
        vector<vector<int> > top;
        for (int i = 0; i < n; ++i) {
            // case where the current note is not to be printed
            if (!toprint[i]) {
                continue;
            }
            // get the current note
            vector<int> ce = notes[i];
            if (ce[0] == 0) {
                top.push_back(ce);
                continue;
            }
            // get the closing note
            for (int j = i + 1; j < n; ++j) {
                vector<int> cn = notes[j];
                if (cn[0] == 0 && ce[1] == cn[1]) {
                    if (ce[2] == cn[2] && ce[3] == cn[3] && ce[4] == cn[4]) {
                        toprint[i] = false;
                        toprint[j] = false;
                    }
                    break;
                }
            }
            if (toprint[i]) {
                top.push_back(ce);
            }
        }
        cout << top.size() << endl;
        for (int i = 0; i < top.size(); ++i) {
            printnote(top[i]);
        }
    }
    return 0;
}
