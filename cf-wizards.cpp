#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        vector<long long> inversions(n, 0);
        for (int i = 0; i < n; ++i) cin >> nums[i];
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] > nums[j]) {
                    ++inversions[i];
                }
            }
        }
        int lres = 1, rres = 1, inversionsreduced = 0;
        for (int i = 0; i < n; ++i) {
            int curr = 0;
            for (int j = i; j < n; ++j) {
                if (nums[i] > nums[j]) {
                    ++curr;
                } else if (nums[i] < nums[j]) {
                    --curr;
                }
                if (curr > inversionsreduced) {
                    inversionsreduced = curr;
                    lres = i + 1, rres = j + 1;
                }
            }
        }
        cout << lres << " " << rres << endl;
    }
    return 0;
}

