#include <bits/stdc++.h>
using namespace std;

vector<string> maketriangle(int m) {
    vector<string> res(m, "");
    // build the base first
    res[m - 1].push_back('/');
    for (int i = 0; i < 2 * (m - 1); ++i) {
        res[m - 1].push_back('_');
    }
    res[m - 1].push_back('\\');
    // build from the bottom, from the m - 1th row to the 1st row
    int prefixspaces = 1;
    for (int i = m - 2; i >= 0; --i) {
        // add prefix spaces first
        for (int j = 0; j < prefixspaces; ++j) {
            res[i].push_back(' ');
        }
        ++prefixspaces;
        // then add the current level of the triangle
        res[i].push_back('/');
        for (int j = 0; j < 2 * i; ++j) {
            res[i].push_back(' ');
        }
        res[i].push_back('\\');
    }
    return res;
}

int main() {
    int m, n, tc = 1;
    while (true) {
        cin >> m >> n;
        if (m == 0 && n == 0) {
            break;
        }
        // set up the vector to print
        vector<string> toprint(m * n, "");
        // build the base triangle
        vector<string> basetriangle = maketriangle(m);
        // add the required number of prefix spaces
        for (int i = 0; i < n; ++i) {
            // calculate the number of spaces needed
            int spacesneeded = (n - i - 1) * m;
            for (int j = i * m; j < (i + 1) * m; ++j) {
                for (int k = 0; k < spacesneeded; ++k) {
                    toprint[j].push_back(' ');
                }
            }
        }
        // add the triangles; loop over the rows
        for (int i = 0; i < n; ++i) {
            // loop over the rows of the triangle
            for (int j = i * m; j < (i + 1) * m; ++j) {
                // loop over the current row, and print the required number of triangles
                for (int k = 0; k < i + 1; ++k) {
                    toprint[j] += basetriangle[j - i * m];
                    // pad with spaces if needed
                    if (k < i) {
                        int def = basetriangle[basetriangle.size() - 1].size() - basetriangle[j - i * m].size();
                        for (int l = 0; l < def; ++l) {
                            toprint[j].push_back(' ');
                        }
                    }
                }
            }
        }
        cout << "Triangular Museum " << tc++ << endl;
        for (int i = 0; i < toprint.size(); ++i) {
            cout << toprint[i] << endl;
        }
        cout << endl;
    }
    return 0;
}
