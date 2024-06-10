#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc = 1;
    while (true) {
        // read in the max width and the number of words to read
        int w, n;
        cin >> w >> n;
        if (w == 0 && n == 0) {
            return 0;
        }
        // read the words and their frequency
        vector<pair<string, int> > words;
        int maxf = 0;
        for (int i = 0; i < n; ++i) {
            string s;
            int c;
            cin >> s >> c;
            maxf = max(maxf, c);
            words.push_back(pair<string, int>(s, c));
        }
        // sort the words in lexicographical order
        // sort(words.begin(), words.end(), cmp);
        // track the total height of the cloud
        int totalHeight = 0, currHeight = 0, currWidth = -10;
        bool cannotfit = false;
        // simulate building the word cloud
        for (int i = 0; i < words.size(); ++i) {
            // get the current font size
            int p = 8 + (int) ceil((40.000 * (words[i].second - 4)) / (maxf - 4));
            // get the current width
            int cw = (int) ceil(((double) (9 * words[i].first.size() * p) / 16));
            // cout << p << " " << cw << endl;
            // case where current line has no space
            if (currWidth + cw + 10 > w) {
                // update the total height by adding the height of the current row
                totalHeight += currHeight;
                // move to a new empty row
                currHeight = 0;
                currWidth = -10;
            }
            // update the current width
            currWidth += (10 + cw);
            // update the current height of the current row
            currHeight = max(currHeight, p);
        }
        // update total height one last time
        if (currHeight != -10) {
            totalHeight += currHeight;
        }
        cout << "CLOUD" << " " << tc++ << ": " << totalHeight << endl;
    }
    return 0;
}
