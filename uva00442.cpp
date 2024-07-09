#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<char, pair<int, int> > matrixmap;
    for (int i = 0; i < n; ++i) {
        char cm;
        int r, c;
        cin >> cm >> r >> c;
        matrixmap[cm] = pair<int, int>(r, c);
    }
    cin.ignore();
    string currexp;
    // loop over the expressions
    while (getline(cin, currexp)) {
        map<char, pair<int, int> > matrixmapcopy(matrixmap);
        stack<char> s;
        long long res = 0;
        bool ok = true;
        for (int i = 0; i < currexp.size(); ++i) {
            if (currexp[i] == '(') {
                s.push(currexp[i]);
            } else if (currexp[i] == ')') {
                vector<char> mp;
                while (!s.empty()) {
                    char cc = s.top();
                    s.pop();
                    if (cc == '(') {
                        break;
                    }
                    mp.push_back(cc);
                }
                // process the current set 
                for (int j = mp.size() - 2; j >= 0; --j) {
                    // get the dimensions of the previous matrix and the current matrix
                    pair<int, int> p1 = matrixmapcopy[mp[j + 1]];
                    pair<int, int> p2 = matrixmapcopy[mp[j]];
                    // gc: dimensions dont match
                    if (p1.second != p2.first) {
                        ok = false;
                        break;
                    }
                    // else, add the number of multiplications to res
                    res += (p1.first * p1.second * p2.second);
                    // update the dimensions
                    matrixmapcopy[mp[j]].first = p1.first;
                }
                // add the final matrix to the stack
                s.push(mp[0]);
            } else {
                s.push(currexp[i]);
            }
        }
        if (!ok) {
            cout << "error" << endl;
        } else {
            vector<char> mp;
            while (!s.empty()) {
                mp.push_back(s.top());
                s.pop();
            }
            char prev = mp[mp.size() - 1];
            for (int j = mp.size() - 2; j >= 0; --j) {
                // get the dimensions of the previous matrix and the current matrix
                pair<int, int> p1 = matrixmapcopy[prev];
                pair<int, int> p2 = matrixmapcopy[mp[j]];
                // gc: dimensions dont match
                if (p1.second != p2.first) {
                    ok = false;
                    break;
                }
                // else, add the number of multiplications to res
                res += (p1.first * p1.second * p2.second);
                // update the dimensions
                matrixmapcopy[mp[j]].first = p1.first;
                // update prev
                prev = mp[j];
            }
            if (!ok) {
                cout << "error" << endl;
            } else {
                cout << res << endl;
            }
        }
    }
    return 0;
}
