#include <bits/stdc++.h>
using namespace std;

// return 0 for white, 1 for black
int getColour(int x, int y) {
    if ((x & 1) == 1) {
        if ((y & 1) == 1) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if ((y & 1) == 1) {
            return 0;
        } else {
            return 1;
        }
    }
}

int getPath(int x1, int y1, int x2, int y2, vector<int>& res, vector<vector<bool> >& vs) {
    if (vs[x1][y1] || x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || (res.size() / 2) > 4) {
        return 1;
    }
    if (x1 == x2 && y1 == y2) {
        res.push_back(x2);
        res.push_back(y2);
        return 0;
    }
    int r, c;
    vs[x1][y1] = true;
    res.push_back(x1);
    res.push_back(y1);
    // upper left
    r = x1 - 1;
    c = y1 - 1;
    while (r >= 0 && c >= 0) {
        if(getPath(r, c, x2, y2, res, vs) == 0) {
            return 0;
        }
        --r;
        --c;
    }
    // upper right
    r = x1 - 1;
    c = y1 + 1;
    while (r >= 0 && c <= 7) {
        if(getPath(r, c, x2, y2, res, vs) == 0) {
            return 0;
        }
        --r;
        ++c;
    }
    // bottom left
    r = x1 + 1;
    c = y1 - 1;
    while (r <= 7 && c >= 0) {
        if(getPath(r, c, x2, y2, res, vs) == 0) {
            return 0;
        }
        ++r;
        --c;
    }
    // bottom right
    r = x1 + 1;
    c = y1 + 1;
    while (r <= 7 && c <= 7) {
        if(getPath(r, c, x2, y2, res, vs) == 0) {
            return 0;
        }
        ++r;
        ++c;
    }
    res.pop_back();
    res.pop_back();
    vs[x1][y1] = false;
    return 1;
}

int main() {
    map<char, int> mp;
    mp['A'] = 0;
    mp['B'] = 1;
    mp['C'] = 2;
    mp['D'] = 3;
    mp['E'] = 4;
    mp['F'] = 5;
    mp['G'] = 6;
    mp['H'] = 7;
    map<int, char> inv;
    inv[0] = 'A';
    inv[1] = 'B';
    inv[2] = 'C';
    inv[3] = 'D';
    inv[4] = 'E';
    inv[5] = 'F';
    inv[6] = 'G';
    inv[7] = 'H';
    int n;
    cin >> n;
    while (n--) {
        // get the inputs
        int x1, y1, x2, y2;
        char t1, t2;
        int t3, t4;
        cin >> t1 >> t3 >> t2 >> t4;
        x1 = mp[t1];
        y1 = 8 - t3;
        x2 = mp[t2];
        y2 = 8 - t4;
        if (t1 == t2 && t3 == t4) {
            cout << 0 << " " << t1 << " " << t3 << endl;
            continue;
        }
        int startColour = getColour(x1, y1);
        int endColour = getColour(x2, y2);
        if (startColour != endColour) {
            cout << "Impossible" << endl;
            continue;
        }
        vector<int> res;
        vector<vector<bool> > vs = vector<vector<bool> >(8, vector<bool>(8, false));
        if(getPath(x1, y1, x2, y2, res, vs) == 0) {
            // print out the length of the path
            cout << (res.size() / 2) - 1 << " ";
            for (int i = 0; i < res.size(); i += 2) {
                cout << inv[res[i]] << " " << 8 - res[i + 1];
                if (i != res.size() - 1) {
                    cout << " ";
                }
            }
            cout << endl;
            continue;
        }
        cout << "Impossible" << endl;
    }
    return 0;
}
