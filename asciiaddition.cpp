#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, char> asciitochar;
    asciitochar["xxxxxx...xx...xx...xx...xx...xxxxxx"] = '0';
    asciitochar["....x....x....x....x....x....x....x"] = '1';
    asciitochar["xxxxx....x....xxxxxxx....x....xxxxx"] = '2';
    asciitochar["xxxxx....x....xxxxxx....x....xxxxxx"] = '3';
    asciitochar["x...xx...xx...xxxxxx....x....x....x"] = '4';
    asciitochar["xxxxxx....x....xxxxx....x....xxxxxx"] = '5';
    asciitochar["xxxxxx....x....xxxxxx...xx...xxxxxx"] = '6';
    asciitochar["xxxxx....x....x....x....x....x....x"] = '7';
    asciitochar["xxxxxx...xx...xxxxxxx...xx...xxxxxx"] = '8';
    asciitochar["xxxxxx...xx...xxxxxx....x....xxxxxx"] = '9';
    asciitochar[".......x....x..xxxxx..x....x......."] = '+';
    map<char, string> chartoascii;
    chartoascii['0'] = "xxxxxx...xx...xx...xx...xx...xxxxxx";
    chartoascii['1'] = "....x....x....x....x....x....x....x";
    chartoascii['2'] = "xxxxx....x....xxxxxxx....x....xxxxx";
    chartoascii['3'] = "xxxxx....x....xxxxxx....x....xxxxxx";
    chartoascii['4'] = "x...xx...xx...xxxxxx....x....x....x";
    chartoascii['5'] = "xxxxxx....x....xxxxx....x....xxxxxx";
    chartoascii['6'] = "xxxxxx....x....xxxxxx...xx...xxxxxx";
    chartoascii['7'] = "xxxxx....x....x....x....x....x....x";
    chartoascii['8'] = "xxxxxx...xx...xxxxxxx...xx...xxxxxx";
    chartoascii['9'] = "xxxxxx...xx...xxxxxx....x....xxxxxx";
    // get the lines
    string curr;
    cin >> curr;
    vector<string> lines((curr.size() + 1) / 6, "");
    for (int i = 0; i < curr.size(); i += 6) {
        lines[i / 6] += curr.substr(i, 5);
    }
    for (int i = 1; i < 7; ++i) {
        cin >> curr;
        for (int j = 0; j < curr.size(); j += 6) {
            lines[j / 6] += curr.substr(j, 5);
        }
    }
    int op1 = 0, op2 = 0, res;
    // get first operator
    int i;
    for (i = 0; i < lines.size(); ++i) {
        if (asciitochar[lines[i]] == '+') {
            break;
        }
        op1 = op1 * 10 + (asciitochar[lines[i]] - '0');
    }
    ++i;
    for (; i < lines.size(); ++i) {
        op2 = op2 * 10 + (asciitochar[lines[i]] - '0');
    }
    res = op1 + op2;
    vector<string> toprint(7, "");
    string t = to_string(res);
    for (int i = 0; i < t.size(); ++i) {
        string asc = chartoascii[t[i]];
        for (int j = 0; j < asc.size(); j += 5) {
            toprint[j / 5] += asc.substr(j, 5);
            if (i < t.size() - 1) {
                toprint[j / 5] += ".";
            }
        }
    }
    for (int i = 0; i < 7; ++i) {
        cout << toprint[i] << endl;
    }
    return 0;
}
