#include <bits/stdc++.h>
using namespace std;

int main() {
    string curr;
    vector<string> records;
    int id = 0;
    while (getline(cin, curr)) {
        if (curr == "") {   
            if (id++ > 0) cout << endl;
            vector<string> temp;
            for (int j = 0; j < records[0].size(); ++j) {
                string cs = "";
                for (int i = records.size() - 1; i >= 0; --i) {
                    cs += records[i][j];
                }
                temp.push_back(cs);
            }
            sort(temp.begin(), temp.end());
            for (int i = 0; i < temp.size(); ++i) {
                for (int j = 0; j < temp[0].size(); ++j) {
                    records[j][i] = temp[i][temp[0].size() - j- 1];
                }
            }
            for (int i = 0; i < records.size(); ++i) {
                for (int j = 0; j < records[0].size(); ++j) {
                    cout << records[i][j];
                }
                cout << endl;
            }
            records.clear();
            continue;
        }
        records.push_back(curr);
    }
    vector<string> temp;
    for (int j = 0; j < records[0].size(); ++j) {
        string cs = "";
        for (int i = records.size() - 1; i >= 0; --i) {
            cs += records[i][j];
        }
        temp.push_back(cs);
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); ++i) {
        for (int j = 0; j < temp[0].size(); ++j) {
            records[j][i] = temp[i][temp[0].size() - j- 1];
        }
    }
    for (int i = 0; i < records.size(); ++i) {
        for (int j = 0; j < records[0].size(); ++j) {
            cout << records[i][j];
        }
        cout << endl;
    }
    records.clear();
    return 0;
}

