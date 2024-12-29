#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second < b.second;
}   

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<pair<string, int> > cups;
    for (int i = 0; i < n; ++i) {
        string temp, a, b;
        getline(cin, temp);
        istringstream iss(temp);
        iss >> a >> b;
        pair<string, int> curr;
        if (isdigit(a[0])) {
            curr.first = b;
            curr.second = stoi(a) / 2;
        } else {
            curr.first = a;
            curr.second = stoi(b);
        }
        cups.push_back(curr);
    }
    sort(cups.begin(), cups.end(), cmp);
    for (int i = 0; i < n; ++i) cout << cups[i].first << endl;
    return 0;
}

