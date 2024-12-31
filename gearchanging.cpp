#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    float p;
    cin >> n >> m >> p;
    p /= 100;
    vector<float> crank(n);
    vector<float> backwheel(m);
    vector<float> gearcombinations;
    for (int i = 0; i < n; ++i) cin >> crank[i]; 
    for (int i = 0; i < m; ++i) cin >> backwheel[i]; 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            gearcombinations.push_back(crank[i] / backwheel[j]);
        }
    }
    sort(gearcombinations.begin(), gearcombinations.end());
    for (int j = 1; j < gearcombinations.size(); ++j) {
        if (gearcombinations[j - 1] + gearcombinations[j - 1] * p < gearcombinations[j]) {
            cout << "Time to change gears!" << endl;
            return 0;
        }
    }
cout << "Ride on!" << endl;
return 0;
}

