#include <bits/stdc++.h>
using namespace std;

bool isslump(string& slump) {
    // empty string
    if (slump.empty()) {
        return false;
    }
    // first char not D or E
    if (slump[0] != 'D' && slump[0] != 'E') {
        return false;
    }
    int idx = 1;
    // loop over the Fs of the slump
    while (idx < slump.size() && slump[idx] == 'F') {
        ++idx;
    }
    // check if not a slump
    if (idx == 1) {
        return false;
    }
    // else, check if G
    if (idx == slump.size() - 1 && slump[idx] == 'G') {
        return true;
    }
    if (slump[slump.size() - 1] == 'G') {
        string temp = slump.substr(idx);
        return isslump(temp);
    }
    return false;
}

bool isslimp(string& slimp) {
    // empty string
    if (slimp.empty()) {
        return false;
    }
    // rule 2
    if (slimp == "AH") {
        return true;
    }
    string temp;
    // check rule 3a
    if (slimp.substr(0, 2) == "AB" && slimp[slimp.size() - 1] == 'C') {
        temp = slimp.substr(2, slimp.size() - 3);
        // cout << "temp1: " << temp << endl;
        return isslimp(temp);        
    } else if (slimp[0] == 'A' && slimp[slimp.size() - 1] == 'C') { // rule 3b
        temp = slimp.substr(1, slimp.size() - 2);
        // cout << "temp2: " << temp << endl;
        return isslump(temp);
    }
    return false;
}

int main() {
    // read in the number of testcases
    int n;
    cin >> n;
    cout << "SLURPYS OUTPUT" << endl;
    // loop over the testcases
    while (n--) {
        // read in the current string
        string curr, slimp, slump;
        cin >> curr;
        // get the slimp (if any)
        if (curr.substr(0, 2) == "AH") {
            slimp = "AH";
            slump = curr.substr(2);
        } else {
            int idx = curr.size() - 1;
            while (idx >= 0 && curr[idx] != 'C') {
                --idx;
            }
            if (idx < 0) { // no slimp found
                cout << "NO" << endl;
                continue;
            }
            slimp = curr.substr(0, idx + 1);
            slump = curr.substr(idx + 1);
        }
        // cout << slimp << " " << slump << endl;
        bool lmao1 = isslimp(slimp), lmao2 = isslump(slump);
        if (lmao1 && lmao2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}
