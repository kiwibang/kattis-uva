#include <bits/stdc++.h>
using namespace std;

unordered_map<int, string> mp;
string parsenum(int num) {
    if (num == 0) {
        return "";
    }
    if (mp.find(num) != mp.end()) {
        return mp[num];
    }
    if (num >= 100) {
        return mp[(num / 100) * 100] + parsenum(num % 100);
    } else if (num >= 10) {
        return mp[(num / 10) * 10] + parsenum(num % 10);
    } else {
        return mp[num];
    }
}

int main() {
    mp[1] = "one";
    mp[2] = "two";
    mp[3] = "three";
    mp[4] = "four";
    mp[5] = "five";
    mp[6] = "six";
    mp[7] = "seven";
    mp[8] = "eight";
    mp[9] = "nine";
    mp[10] = "ten";
    mp[11] = "eleven";
    mp[12] = "twelve";
    mp[13] = "thirteen";
    mp[14] = "fourteen";
    mp[15] = "fifteen";
    mp[16] = "sixteen";
    mp[17] = "seventeen";
    mp[18] = "eighteen";
    mp[19] = "nineteen";
    mp[20] = "twenty";
    mp[30] = "thirty";
    mp[40] = "forty";
    mp[50] = "fifty";
    mp[60] = "sixty";
    mp[70] = "seventy";
    mp[80] = "eighty";
    mp[90] = "ninety";
    mp[100] = "onehundred";
    mp[200] = "twohundred";
    mp[300] = "threehundred";
    mp[400] = "fourhundred";
    mp[500] = "fivehundred";
    mp[600] = "sixhundred";
    mp[700] = "sevenhundred";
    mp[800] = "eighthundred";
    mp[900] = "ninehundred";
    string res;
    int n, lettercount = 0;
    cin >> n;
    // read in the words
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        lettercount += words[i].size();
    }
    --lettercount;
    // then print out the results
    for (int i = 0; i < n; ++i) {
        string w = words[i];
        if (w != "$") { // normal word
            cout << w;
        } else { // special word
            string numstr;
            // try all combinations
            for (int num = 1; num < 1000; ++num) {
                string numstr = parsenum(num);
                if (lettercount + numstr.size() == num) {
                    cout << numstr;
                    break;
                }
            }
        }
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    return 0;
}

