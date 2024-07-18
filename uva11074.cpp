#include <bits/stdc++.h>
using namespace std;

void printdline(string& l, int d) {
    for (int i = 0; i < d; ++i) {
        cout << l << endl;
    }
}

int main() {
    int tc = 1;
    while (true) {
        int s, t, n;
        cin >> s >> t >> n;
        if (s == 0 && t == 0 && n == 0) {
            break;
        }
        // calculate the width of a string
        // width of a square * number of squares + thickness of drawing line * (number of squares + 1)
        int width = s * n + t * (n + 1);
        // construct the drawing line
        string drawingline(width, '*');
        // construct the squares line
        string vdline(t, '*'), sqline(s, '.'), mline = vdline;
        for (int i = 0; i < n; ++i) {
            mline += sqline;
            mline += vdline;
        }
        // cout << vdline << endl;
        // print the first drawing lines
        cout << "Case " << tc++ << ":" << endl;
        printdline(drawingline, t);
        // then print the remaining lines
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < s; ++j) {
                cout << mline << endl;
            }
            printdline(drawingline, t);
        }
        // blank line after every testcase
        cout << endl;
    }
    return 0;
}
