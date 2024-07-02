#include <bits/stdc++.h>
using namespace std;

int tonum(char cc) {
    return cc == '_'
        ? 0
        : cc == '.'
        ? 27
        : cc - 'a' + 1;
}

char decode(int idx) {
    return idx == 0
        ? '_'
        : idx == 27
        ? '.'
        : idx - 1 + 'a';
}

int main() {
    while (true) {
        int k;
        cin >> k;
        if (k == 0) {
            break;
        }
        string msg;
        cin >> msg;
        int n = msg.size();
        // convert the ciphertext into ciphercode
        vector<int> code(n);
        for (int i = 0; i < n; ++i) {
            code[i] = tonum(msg[i]);
        }
        vector<char> pt(n);
        // convert ciphercode into plaincode. note that 0th char in ciphercode always equals to 0th char of plaincode
        for (int i = 0; i < n; ++i) {
            // get inner index
            int innerindex = (k * i) % n;
            for (int chr = 0;; ++chr) {
                int a = ((chr - i) / 28) * 28 + code[i];
                int b = chr - i;
                if (a == b) {
                    pt[innerindex] = decode(chr % 28);
                    break;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << pt[i];
        }
        cout << endl;
    }
    return 0;
}
