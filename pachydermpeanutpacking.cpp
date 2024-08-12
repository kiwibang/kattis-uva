#include <bits/stdc++.h>
using namespace std;

double getsz(string sz) {
    return sz == "small" ? 0.0 : sz == "medium" ? 1.0 : sz == "large" ? 2.0 : -1.0; 
}

string getid(double id) {
    return id == 0.0 ? "small" : id == 1.0 ? "medium" : id == 2.0 ? "large" : "lmao";
}

int main() {
    int n, tc = 0;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        if (tc++ > 0) {
            cout << endl;
        }
        // vectors of vectors that are size 5. element 0 and 1 are the start coords, element 2 and 3 are the end coords, element 4 is the type of box (0.0 = small, 1.0 = medium, 2.0 = large)
        vector<vector<double> > boxes(n, vector<double>(5, 0.0));
        string size;
        for (int i = 0; i < n; ++i) {
            cin >> boxes[i][0] >> boxes[i][1] >> boxes[i][2] >> boxes[i][3];
            cin >> size;
            boxes[i][4] = getsz(size);
        }
        // get the peanuts
        int m;
        cin >> m;
        double x, y;
        string peanutsize;
        for (int i = 0; i < m; ++i) {
            // get the current peanut
            cin >> x >> y >> peanutsize;
            double szid = getsz(peanutsize);
            // track the size of the box that the peanut belongs in (if any)
            double szbox = -1.0;
            // see if it belongs in any box
            for (int j = 0; j < n; ++j) {
                // case where current peanut belongs in the current box
                if ((boxes[j][0] <= x && x <= boxes[j][2]) && (boxes[j][1] <= y && y <= boxes[j][3])) {
                    szbox = boxes[j][4];
                    break;
                }
            }
            // then print the result for the current peanut
            cout << peanutsize << " ";
            if (szbox == szid) {
                cout << "correct" << endl;
            } else {
                if (szbox == -1.0) {
                    cout << "floor" << endl;
                } else {
                    cout << getid(szbox) << endl;
                }
            }
        }
    }
    return 0;
}
