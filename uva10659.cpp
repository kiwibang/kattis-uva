#include <bits/stdc++.h>
using namespace std;

bool ok(int x, int y, vector<vector<string> >& paras, int fontsz) {
    int totallines = 0;
    // try to fit all words in the paragraph into the slide
    for (int i = 0; i < paras.size(); ++i) {
        // lay the first word
        int numlines = 1;
        int cw = paras[i][0].size() * fontsz; // represents the current width of the current line
        // if the first word cannot fit the current width
        if (cw > x) {
            return false;
        }
        // check whether we need to lay a space
        if (paras[i].size() > 1) {
            if (cw + fontsz <= x) {
                cw += fontsz; // lay the space if possible
            } else {
                ++numlines; // else, move to the next line
                cw = 0;
            }
        }
        // loop over the remaining lines of the paragraph
        for (int j = 1; j < paras[i].size(); ++j) {
            // if current word cannot fit the width
            if (paras[i][j].size() * fontsz > x) {
                return false;
            }
            // can fit the current line
            if (cw + paras[i][j].size() * fontsz <= x) {
                cw += paras[i][j].size() * fontsz;
            } else { // cannot fir the current line, start new line
                ++numlines;
                cw = paras[i][j].size() * fontsz;
            }
            // add space if needed
            if (j < paras[i].size() - 1) {
                // can fit the space
                if (cw + fontsz <= x) {
                    cw += fontsz;
                } else { // cannot fit the space
                    ++numlines;
                    cw = 0;
                }
            }
        }
        // add the number of lines needed for the current paragraph
        totallines += numlines;
    }
    // cout << fontsz << " " << th << " " << y << endl;
    return totallines * fontsz <= y;
}

int main() {
    // get the number of slides
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // get the number of paragraphs to fit
        int paracount;
        string l;
        getline(cin, l);
        istringstream iss(l);
        iss >> paracount;
        // read the paragraphs
        vector<vector<string> > paragraphs;
        for (int i = 0; i < paracount; ++i) {
            getline(cin, l);
            istringstream iss2(l);
            vector<string> currpara;
            string currword;
            while (iss2 >> currword) {
                currpara.push_back(currword);
            }
            paragraphs.push_back(currpara);
        }
        // get the dimensions of each slide
        int x, y;
        getline(cin, l);
        istringstream iss3(l);
        iss3 >> x >> y;
        // try values from 8 to 28, starting from 8
        int res = 28;
        for (; res >= 8; --res) {
            if (ok(x, y, paragraphs, res)) {
                break;
            }
        }
        // print the res
        if (res == 7) {
            cout << "No solution" << endl;
        } else {
            cout << res << endl;
        }
    }
    return 0;
}
