#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, currchild = 0, dx;
    cin >> n >> k;
    string curr;
    // contains a list of changes due to first type of throw
    stack<pair<int, int> > s;
    for (int i = 0; i < k; ++i) {
        cin >> curr;
        if (curr == "undo") {
            cin >> curr;
            dx = stoi(curr);
            for (int j = 0; j < dx; ++j) {
                currchild = s.top().first;
                s.pop();
            }
        } else {
            dx = stoi(curr);
            int newchild = (((currchild + dx) % n) + n) % n;
            s.push(pair<int, int>(currchild, newchild));
            currchild = newchild;
        }
    }
     cout << currchild << endl;
    return 0;
}

