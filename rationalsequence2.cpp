#include <bits/stdc++.h>
using namespace std;

int getn(int numer, int denom) {
    if (numer == 1 && denom == 1) return 1;
    return numer > denom ? (getn(numer - denom, denom) << 1) + 1 : (getn(numer, denom - numer) << 1);
}

int main() {
    int p, id;
    cin >> p;
    string num;
    for (int i = 0; i < p; ++i) {
        cin >> id >> num;
        int numer, denom, idx = 0;
        string temp = "";
        while (num[idx] != '/') {
            temp += num[idx++];
        }
        numer = stoi(temp);
        temp = "";
        ++idx;
        while (idx < num.size()) {
            temp += num[idx++];
        }
        denom = stoi(temp);
        cout << id << " " << getn(numer, denom) << endl;
    }
    return 0;
}

