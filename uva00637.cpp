#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        // read in the number of pages
        int pages;
        cin >> pages;
        if (pages == 0) {
            return 0;
        }
        // get the number of sheets
        int sn = ceil((double) pages / 4);
        // setup a page vector to populate
        vector<pair<pair<int, int>, pair<int, int> > > sheets;
        for (int i = 0; i < sn; ++i) {
            sheets.push_back(pair<pair<int, int>, pair<int, int> >(pair<int, int>(-1, -1), pair<int, int>(-1, -1)));
        }
        int currSheet = 1;
        // then populate the sheets with the pages
        for (int i = 1; i <= pages; ++i) {
            // case where we are still allocating the first group of pages
            if (i <= sn * 2) {
                // case where allocating on a front page
                if ((i & 1) == 1) {
                    sheets[currSheet - 1].first.second = i;
                } else { // case where allocating on a back page
                    sheets[currSheet - 1].second.first = i;
                    // update the sheet number
                    if (i != sn * 2) {
                        ++currSheet;
                    }
                }
            } else { // if we allocating the second group of pages
                if ((i & 1) == 1) { // case where allocating on a back page
                    sheets[currSheet - 1].second.second = i;
                } else { // case where allocating on a front page
                    sheets[currSheet - 1].first.first = i;
                    // update the current sheet
                    --currSheet;
                }
            }
        }
        // then print out the result
        cout << "Printing order for " << pages << " pages:" << endl;
        // loop over the sheets
        for (int i = 0; i < sn; ++i) {
            // get the current sheet
            pair<pair<int, int>, pair<int, int> > cs = sheets[i];
            // print the front page
            string f1 = cs.first.first == -1 ? "Blank" : to_string(cs.first.first);
            string f2 = cs.first.second == -1 ? "Blank" : to_string(cs.first.second);
            if (f1 != "Blank" || f2 != "Blank") 
                cout << "Sheet " << i + 1 << ", front: " << f1 << ", " << f2 << endl;
            // print the back page
            string s1 = cs.second.first == -1 ? "Blank" : to_string(cs.second.first);
            string s2 = cs.second.second == -1 ? "Blank" : to_string(cs.second.second);
            if (s1 != "Blank" || s2 != "Blank")
                cout << "Sheet " << i + 1 << ", back : " << s1 << ", " << s2 << endl;
        }
    }
    return 0;
}
