#include <bits/stdc++.h>
using namespace std;

bool cmp2(vector<int>& a, vector<int>& b) {
    return a[4] < b[4];
}

bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] != b[0]) return a[0] > b[0];
    if (a[1] != b[1]) return a[1] < b[1];
    return a[2] < b[2];
}

bool samescore(vector<int>& a, vector<int>& b) {
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
}

int main() {
    // read in the inputs
    int n;
    cin >> n;
    vector<vector<int> > contestants;
    for (int i = 0; i < n; ++i) {
        vector<int> curr(6);
        for (int j = 0; j < 4; ++j) cin >> curr[j];
        curr[4] = i;
        contestants.push_back(curr);
    }
    stable_sort(contestants.begin(), contestants.end(), cmp);
    // then process the input
    vector<int> scores = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int i = 0;
    while (i < n) {
        int j = i + 1;
        float points = i < 30 ? scores[i] : 0;
        while (j < n && samescore(contestants[i], contestants[j])) {
            points = j < 30 ? points + scores[j] : points; // add the positive score if rank no greater than 30, else 0 points and hence dont add anything
            ++j; // move the pointer to the right
        }
        // calculate points for the current group of tied candidates
        points = ceil(points / (j - i));
        // then tally scores for this group
        for (int k = i; k < j; ++k) {
            contestants[k][5] = (int) (points) + contestants[k][3];
        }
        i = j; // then shift i to j pointer's position
    }
    // sort based on order given in the input
    sort(contestants.begin(), contestants.end(), cmp2); 
    // then print the results
    for (int k = 0; k < n; ++k) cout << contestants[k][5] << endl;
    return 0;
}

