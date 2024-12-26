#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int> > grid(4, vector<int>(4));
    vector<vector<int> > res(4, vector<int>(4, 0));
    for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) cin >> grid[i][j];
    int action;
    cin >> action;
    if (action == 0) { // left
        for (int i = 0; i < 4; ++i) {
            vector<int> nums;
            for (int j = 0; j < 4; ++j) {
                if (grid[i][j] != 0) nums.push_back(grid[i][j]);
            }
            int j = 0, idx = 0;
            while (j < nums.size()) {
                if (j == nums.size() - 1) { // case where last num
                    res[i][idx] = nums[j];
                    break;
                }
                if (nums[j] == nums[j + 1]) { // next num the same as current
                    // set res to 2 times of current
                    res[i][idx++] = (nums[j] << 1);
                    // set j to j + 2 (we skip the next num
                    j += 2;
                } else { // next num diff from current
                    // set res to current
                    res[i][idx++] = nums[j];
                    // update j
                    ++j;
                }
            }
        }
    } else if (action == 1) { // up
        for (int j = 0; j < 4; ++j) {
            vector<int> nums;
            for (int i = 0; i < 4; ++i) {
                if (grid[i][j] != 0) nums.push_back(grid[i][j]);
            }
            int i = 0, idx = 0;
            while (i < nums.size()) {
                if (i == nums.size()) { // case where last num
                    res[idx][j] = nums[i];
                    break;
                }
                if (nums[i] == nums[i + 1]) { // case where current same as num
                    res[idx++][j] = (nums[i] << 1);
                    i += 2;
                } else { // case where current different as num
                    res[idx++][j] = nums[i];
                    ++i;
                }
            }
        }
    } else if (action == 2) { // right
        for (int i = 0; i < 4; ++i) {
            vector<int> nums;
            for (int j = 0; j < 4; ++j) {
                if (grid[i][j] != 0) nums.push_back(grid[i][j]);
            }
            int j = nums.size() - 1, idx = 3;
            while (j < nums.size()) {
                if (j == 0) { // case where last num
                    res[i][idx] = nums[j];
                    break;
                }
                if (nums[j] == nums[j - 1]) { // next num the same as current
                    // set res to 2 times of current
                    res[i][idx--] = (nums[j] << 1);
                    // set j to j - 2 (we skip the next num
                    j -= 2;
                } else { // next num diff from current
                    // set res to current
                    res[i][idx--] = nums[j];
                    // update j
                    --j;
                }
            }
        }
    } else if (action == 3) { // down
        for (int j = 0; j < 4; ++j) {
            vector<int> nums;
            for (int i = 0; i < 4; ++i) {
                if (grid[i][j] != 0) nums.push_back(grid[i][j]);
            }
            int i = nums.size() - 1, idx = 3;
            while (i >= 0) {
                if (i == 0) { // case where last num
                    res[idx][j] = nums[i];
                    break;
                }
                if (nums[i] == nums[i - 1]) { // case where current same as num
                    res[idx--][j] = (nums[i] << 1);
                    i -= 2;
                } else { // case where current different as num
                    res[idx--][j] = nums[i];
                    --i;
                }
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << res[i][j];
            if (j < 3) cout << " ";
        }
        cout << endl;
    }
    return 0;
}

