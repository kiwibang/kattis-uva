#include <bits/stdc++.h>
using namespace std;

int main() {
    // write down the coords of each position of the cipher key (up, right, down, left)
    vector<pair<int, int> > up;
    up.push_back(pair<int, int>(0, 1));
    up.push_back(pair<int, int>(0, 3));
    up.push_back(pair<int, int>(0, 5));
    up.push_back(pair<int, int>(1, 4));
    up.push_back(pair<int, int>(2, 2));
    up.push_back(pair<int, int>(3, 1));
    up.push_back(pair<int, int>(3, 4));
    up.push_back(pair<int, int>(4, 5));
    up.push_back(pair<int, int>(5, 3));
    vector<pair<int, int> > right;
    right.push_back(pair<int, int>(1, 2));
    right.push_back(pair<int, int>(1, 5));
    right.push_back(pair<int, int>(2, 3));
    right.push_back(pair<int, int>(3, 0));
    right.push_back(pair<int, int>(3, 5));
    right.push_back(pair<int, int>(4, 2));
    right.push_back(pair<int, int>(4, 4));
    right.push_back(pair<int, int>(5, 1));
    right.push_back(pair<int, int>(5, 5));
    vector<pair<int, int> > down;
    down.push_back(pair<int, int>(0, 2));
    down.push_back(pair<int, int>(1, 0));
    down.push_back(pair<int, int>(2, 1));
    down.push_back(pair<int, int>(2, 4));
    down.push_back(pair<int, int>(3, 3));
    down.push_back(pair<int, int>(4, 1));
    down.push_back(pair<int, int>(5, 0));
    down.push_back(pair<int, int>(5, 2));
    down.push_back(pair<int, int>(5, 4));
    vector<pair<int, int> > left;
    left.push_back(pair<int, int>(0, 0));
    left.push_back(pair<int, int>(0, 4));
    left.push_back(pair<int, int>(1, 1));
    left.push_back(pair<int, int>(1, 3));
    left.push_back(pair<int, int>(2, 0));
    left.push_back(pair<int, int>(2, 5));
    left.push_back(pair<int, int>(3, 2));
    left.push_back(pair<int, int>(4, 0));
    left.push_back(pair<int, int>(4, 3));
    int tc = 0;
    while (true) {
        if (cin.eof()) {
            break;
        }
        if (tc++ > 0) {
            cout << endl;
        }
        string currline = "lol", total = "";
        vector<string> lines;
        while (true) {
            getline(cin, currline);
            if (currline.empty()) {
                break;
            }
            lines.push_back(currline);
            total += currline;
        }
        int idx = 0;
        string res = "";
        while (idx < total.size()) {
            vector<vector<char> > grid(6, vector<char>(6, '\0'));
            // place the characters on the grid
            for (int i = 0; i < 6; ++i) {
                for (int j = 0; j < 6; ++j) {
                    grid[i][j] = total[idx++];
                }
            }
            // go thru the grid and decode
            for (int i = 0; i < 9; ++i) {
                res.push_back(grid[up[i].first][up[i].second]);
            }
            for (int i = 0; i < 9; ++i) {
                res.push_back(grid[right[i].first][right[i].second]);
            }
            for (int i = 0; i < 9; ++i) {
                res.push_back(grid[down[i].first][down[i].second]);
            }
            for (int i = 0; i < 9; ++i) {
                res.push_back(grid[left[i].first][left[i].second]);
            }
        }
        // print the res
        idx = 0;
        for (int i = 0; i < lines.size(); ++i) {
            // recreate the original message
            string curr = "";
            for (int j = 0; j < lines[i].size(); ++j) {
                curr.insert(curr.begin(), res[idx++]);
            }
            // remove the trailing #
            while (curr[curr.size() - 1] == '#') {
                curr.resize(curr.size() - 1);
            }
            // print the original message
            cout << curr << endl;
        }
        ++tc;
    }
    return 0;
}
