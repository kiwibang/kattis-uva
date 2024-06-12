#include <bits/stdc++.h>
using namespace std;

int w(char c) {
    return c == '-' ? 10 : isdigit(c) ? (int) (c - '0') : -1;
}

int getc(string code) {
    int sum = 0, n = code.size() - 2;
    for (int i = 1; i <= n; ++i) {
        sum += ((((n - i) % 10) + 1) * w(code[i - 1]));
    }
    return sum % 11;
}

int getk(string code) {
    int sum = 0, n = code.size() - 2;
    for (int i = 1; i <= n + 1; ++i) {
        sum += ((((n - i + 1) % 9) + 1) * w(code[i - 1]));
    }
    return sum % 11;
}

int main() {
    map<string, char> entochar;
    entochar["00001"] = '0';
    entochar["10001"] = '1';
    entochar["01001"] = '2';
    entochar["11000"] = '3';
    entochar["00101"] = '4';
    entochar["10100"] = '5';
    entochar["01100"] = '6';
    entochar["00011"] = '7';
    entochar["10010"] = '8';
    entochar["10000"] = '9';
    entochar["00100"] = '-';
    entochar["00110"] = '*';
    int tc = 0;
    while (true) {
        // read in the barcode length
        int n;
        cin >> n;
        if (n == 0) {
            return 0;
        }
        cout << "Case " << ++tc << ": ";
        // read in the actual barcode
        vector<int> barcode;
        int mn = 999;
        for (int i = 0; i < n; ++i) {
            int temp;
            cin >> temp;
            barcode.push_back(temp);
            mn = min(mn, temp);
        }
        if (((n + 1) % 6) != 0 || ((n + 1) / 6) < 5) {
            cout << "bad code" << endl;
            continue;
        }
        // check whether all barcodes are in the allowable range
        double sp = mn * 1.5;
        int mn2 = 999, mx = 0;
        for (int i = 0; i < n; ++i) {
            int t2 = barcode[i];
            if (t2 < sp) {
                t2 *= 2;
            }
            mn2 = min(mn2, t2);
            mx = max(mx, t2);
        } 
        if (!(mn2 >= (95.0 * mx / 105.0))) {
            cout << "bad code" << endl;
            continue;
        }
        // now barcodes guaranteed to have valid start/stop codes
        // reverse the message if supposed to be read backwards
        if (barcode[1] >= sp) {
            reverse(barcode.begin(), barcode.end());
        }

        int ss = 0;
        bool ok = true;
        // get the current code
        string code = "";
        for (int i = 0; i < n; i += 6) {
            string curr = "";
            for (int j = i; j < i + 5; ++j) {
                curr = barcode[j] < sp ? curr + "0" : curr + "1";
            }
            if (entochar.find(curr) == entochar.end()) {
                ok = false;
                break;
            }
            if (curr == "00110") {
                ++ss;
            }
            char cc = entochar[curr]; 
            code.push_back(cc);
            if (i + 5 < barcode.size() && barcode[i + 5] >= sp) {
                ok = false;
                break;
            }
        }
        if (!(ss == 2 && code[0] == '*' && code[code.size() - 1] == '*')) {
            ok = false;
        }
        if (!ok) {
            cout << "bad code" << endl;
            continue;
        }

        code.erase(0, 1);
        code = code.substr(0, code.size() - 1);
        // check C
        // compute expected C
        int expc = getc(code);
        // cross-check with actual C, if not, print incorrect and move on
        if (expc != w(code[code.size() - 2])) {
            cout << "bad C" << endl;
            continue;
        }
        // check K
        // compute expected K
        int expk = getk(code);
        // cross-check with actual K, if not, print incorrect and move on
        if (expk != w(code[code.size() - 1])) {
            cout << "bad K" << endl;
            continue;
        }
        // else, all ok, print the code, and move on to the next testcase
        cout << code.substr(0, code.size() - 2) << endl;
    }
    return 0;
}
