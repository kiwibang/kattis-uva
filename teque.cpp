#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, idx, sz = 0;
    cin >> n;
    string curr;
    deque<int> d1, d2;
    for (int i = 0; i < n; ++i) {
        cin >> curr >> idx;
        if (curr == "push_back") {
            ++sz;
            // push into d2
            d2.push_back(idx);
            // adjust elements if needed
            if (d2.size() != d1.size()) {
                if (sz % 2 == 0) {
                    while (d2.size() != d1.size()) {
                        d1.push_back(d2.front());
                        d2.pop_front();
                    }
                } else {
                    while (d2.size() + 1 != d1.size()) {
                        d1.push_back(d2.front());
                        d2.pop_front();
                    }
                }
            }
        } else if (curr == "push_front") {
            ++sz;
            // push into d1
            d1.push_front(idx);
            if (d2.size() != d1.size()) {
                if (sz % 2 == 0) {
                    while (d2.size() != d1.size()) {
                        d2.push_front(d1.back());
                        d1.pop_back();
                    }
                } else {
                    while (d2.size() + 1 != d1.size()) {
                        d2.push_front(d1.back());
                        d1.pop_back();
                    }
                }
            }
        } else if (curr == "push_middle") {
            if (sz % 2 == 0) {
                d1.push_back(idx);
            } else {
                d2.push_front(idx);
            }
            ++sz;
        } else if (curr == "get") {
            int lim = sz % 2 == 0 ? sz / 2 : ((sz + 1) / 2);
            if (idx < lim) {
                cout << d1.at(idx) << endl;
            } else {
                cout << d2.at(idx - d1.size()) << endl;
            }
        }
    }
    return 0;
}

