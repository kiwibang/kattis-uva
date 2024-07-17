#include <bits/stdc++.h>
using namespace std;

int main() {
    // make map of smallest possible banner
    string toprint = "SAVE HRIDOY"; 
    map<char, string> cmap;
    cmap['S'] = "******....*****....******";
    cmap['A'] = ".***.*...*******...**...*";
    cmap['V'] = "*...**...**...*.*.*...*..";
    cmap['E'] = "******....***..*....*****";
    cmap['H'] = "*...**...*******...**...*";
    cmap['R'] = "******...*******.*..*..**";
    cmap['I'] = "*****..*....*....*..*****";
    cmap['D'] = "***..*..*.*...**..*.***..";
    cmap['O'] = "******...**...**...******";
    cmap['Y'] = "*...*.*.*...*....*....*..";
    int n, absval;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        absval = abs(n);
        if (n > 0) { // horizontal print => print (5|n| * 10 + 11|n|) x 5|n|
            vector<string> temp(5 * absval, "");
            // loop over the chars to print
            for (int i = 0; i < toprint.size(); ++i) {
                if (toprint[i] == ' ') {
                    string spacestr(3 * absval, '.');
                    for (int j = 0; j < temp.size(); ++j) {
                        temp[j] += spacestr;
                    }
                } else {
                    // add space if needed
                    if (i > 0 && toprint[i] != 'H') {
                        string spacestr(absval, '.');
                        for (int j = 0; j < temp.size(); ++j) {
                            temp[j] += spacestr;
                        }
                    }
                    // add the char
                    string charstring = cmap[toprint[i]];
                    int cidx = 0;
                    // make temporary vector
                    vector<string> tv(5 * absval, string(5 * absval, '-'));
                    for (int j = 0; j < tv.size(); j += absval) {
                        for (int k = 0; k < tv[0].size(); k += absval) {
                            tv[j][k] = charstring[cidx++];
                            for (int l = j; l < j + absval; ++l) {
                                for (int m = k; m < k + absval; ++m) {
                                    if (l == j && m == k) {
                                        continue;
                                    }
                                    tv[l][m] = tv[j][k];
                                }
                            }
                        }
                    }
                    for (int j = 0; j < tv.size(); ++j) {
                        temp[j] += tv[j];
                    }
                }
            }
            for (int i = 0; i < temp.size(); ++i) {
                cout << temp[i] << endl;
            }
        } else { // vertical print => print 5|n| x (5|n| * 10 + 11|n|) lines of output
            vector<string> temp;
            // loop over the chars to print
            for (int i = 0; i < toprint.size(); ++i) {
                if (toprint[i] == ' ') {
                    string spacestr(5 * absval, '.');
                    for (int j = 0; j < 3 * absval; ++j) {
                        temp.push_back(spacestr);
                    }
                } else {
                    if (i > 0 && toprint[i] != 'H') {
                        // add space if needed
                        string spacestr(5 * absval, '.');
                        for (int j = 0; j < absval; ++j) {
                            temp.push_back(spacestr);
                        }
                    }
                    // add the char
                    string charstring = cmap[toprint[i]];
                    int cidx = 0;
                    // make temporary vector
                    vector<string> tv(5 * absval, string(5 * absval, '-'));
                    for (int j = 0; j < tv.size(); j += absval) {
                        for (int k = 0; k < tv[0].size(); k += absval) {
                            tv[j][k] = charstring[cidx++];
                            for (int l = j; l < j + absval; ++l) {
                                for (int m = k; m < k + absval; ++m) {
                                    if (l == j && m == k) {
                                        continue;
                                    }
                                    tv[l][m] = tv[j][k];
                                }
                            }
                        }
                    }
                    for (int j = 0; j < tv.size(); ++j) {
                        temp.push_back(tv[j]);
                    }
                }
            }
            for (int i = 0; i < temp.size(); ++i) {
                cout << temp[i] << endl;
            }
        }
        cout << endl;
        cout << endl;
    }
    return 0;
}
