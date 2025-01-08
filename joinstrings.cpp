#include <bits/stdc++.h>
using namespace std;

void hp(vector<string>& words, vector<vector<int> >& idxs, int idx) {
    cout << words[idx];
    for (int id : idxs[idx]) {
        hp(words, idxs, id);
    }
}
int main() {
    int n, a, b, last = 0;
    cin >> n;
    vector<string> words(n);
    vector<vector<int> > idxs(n, vector<int>());
    for (int i = 0; i < n; ++i) cin >> words[i];
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        idxs[a].push_back(b);
        last = a;
    } 
    hp(words, idxs, last);
    cout << endl;
    return 0;
}

