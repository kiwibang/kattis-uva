#include <bits/stdc++.h>
using namespace std;

string toroman(int num) {
    const char rcode[13][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    const int val[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string res = "";
    int idx = 0;
    for (int i = 0; i < 13; ++i) {
        while (num >= val[i]) {
            num -= val[i];
            res.push_back(rcode[i][0]);
            if (rcode[i][1] != '\0') {
                res.push_back(rcode[i][1]);
            }
        }
    }
    return res;
}

int getidx(vector<string>& a, string str) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == str) {
            return i;
        }
    }
    return -1;
}

int main() {
    map<string, int> valmap;
    vector<string> inttoroman(1001, "");
    for (int i = 1; i <= 1000; ++i) {
        string temp = toroman(i);
        valmap[temp] = i;
        inttoroman[i] = temp;
    }
    vector<string> temp = inttoroman;
    sort(temp.begin(), temp.end());
    int midx = getidx(temp, "M");
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        // get the current number
        int currnum;
        cin >> currnum;
        // record the result
        int res = -1;
        // count the number of Ms needed
        int first = currnum / 1000;
        // get the last thousands, so we can get the offset
        int lastthousand = currnum % 1000;
        // case where less than equals 1000 => can use currNum by itself
        if (currnum <= 1000) {
            int pos = getidx(temp, inttoroman[currnum]);
            res = pos > midx ? -(temp.size() - pos) : pos;
        } else {
            int pos = getidx(temp, inttoroman[lastthousand]);
            res = pos > midx ? -(temp.size() - pos) - ((1000 - (midx)) * first) : first * midx + pos;
        }
        cout << res << endl;
    }
    return 0;
}
