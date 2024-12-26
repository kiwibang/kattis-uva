#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<vector<int> > image(h, vector<int>(w));
    vector<vector<int> > kernel(n, vector<int>(m));
    vector<vector<int> > res(h - n + 1, vector<int>(w - m + 1, 0));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> image[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> kernel[i][j];
        }
    }
    for (int i = 0; i < h - n + 1; ++i) {
        for (int j = 0; j < w - m + 1; ++j) {
            for (int k = i; k < i + n; ++k) {
                for (int l = j; l < j + m; ++l) {
                    res[i][j] += image[k][l] * kernel[n - k + i - 1][m - l + j - 1];
                }
            }
            cout << res[i][j];
            if (j < w - m) cout << " ";
        }
        cout << endl;
    }
    return 0;
}

