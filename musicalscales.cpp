#include <bits/stdc++.h> 
using namespace std;

int main() { 
    string notes[] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
    int deltas[] = {0, 2, 2, 1, 2, 2, 2, 1};
    // read in the inputs
    int n; 
    cin >> n;
    set<string> nts;
    for (int i = 0; i < n; ++i) {
        string cn;
        cin >> cn;
        nts.insert(cn);
    }
    // check for valid scales, in lexicographical order
    string res = "";
    for (int i = 0; i < 12; ++i) {
        set<string> seen;
        int idx = i;
        for (int j = 0; j < 8; ++j) {
            // get the index
            idx = (idx + deltas[j]) % 12;
            // get the note
            string cnote = notes[idx];
            // insert into the set of notes
            seen.insert(cnote);
        }
        // if seen and the notes set are equals, means can be played in that major
        if (includes(seen.begin(), seen.end(), nts.begin(), nts.end())) {
            res += notes[i];
            res += " ";
        }
    }
    if (res.size() == 0) {
        res += "none ";
    }
    cout << res.substr(0, res.size() - 1) <<endl;
    return 0;
}
