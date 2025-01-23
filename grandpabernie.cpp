#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string country;
    int year;
    unordered_map<string, vector<int>> trips;
    for (int i = 0; i < n; ++i) {
        cin >> country >> year;
        if (trips.find(country) == trips.end()) trips[country] = vector<int>();
        trips[country].push_back(year);        
    }    
    for (auto& p : trips) {
        sort(p.second.begin(), p.second.end());
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> country >> year;
        cout << trips[country][year - 1] << endl;
    }
    return 0;
}

