#include <bits/stdc++.h>
using namespace std;

vector<string> splitstr(string str) {
    string delimiter = ", ";
    vector<string> result;
    size_t start = 0;
    size_t end = str.find(delimiter);
    while (end != string::npos) {
        result.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
        end = str.find(delimiter, start);
    }
    // Add the last substring
    result.push_back(str.substr(start));
    return result;
}

int getc(vector<string>& a, vector<string>& b) {
    int res = 0;
    for (int i = 0; i < a.size(); ++i) if (a[i] != b[i]) ++res;
    return res;
}

int main() {
    string qn, curr;
    getline(cin, qn);
    getline(cin, curr);
    int n = stoi(curr);
    vector<vector<string> > ans;
    vector<string> anss;
    for (int i = 0; i < n; ++i) {
        getline(cin, curr);
        anss.push_back(curr);
        ans.push_back(splitstr(curr));
    }

    vector<int> costs(n, 0);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) costs[i] = max(costs[i], getc(ans[i], ans[j])); 
    int mc = INT_MAX;
    for (int i = 0; i < n; ++i) mc = min(mc, costs[i]);
    for (int i = 0; i < n; ++i) if (costs[i] == mc) cout << anss[i] << endl;
    return 0;
}

