#include <bits/stdc++.h>
using namespace std;

int main() {
    char l[100];
    x: while (gets(l)) {
        int i = 0;
        while (l[i] == ' ') ++i;
        char *r = &l[i];
        vector<int> isbn;
        for (int i = strlen(l) - 1; i >= 0 && l[i] == ' '; --i) 
            l[i] = 0;
        for (; l[i]; ++i) {
            if (isdigit(l[i]) || (isbn.size() == 9 && l[i] == 'X')) {
                if (isdigit(l[i])) {
                    isbn.push_back(l[i] - '0');
                } else if (l[i] == 'X') {
                    isbn.push_back(10);
                }
            } else {
                if (l[i] != '-') {
                    cout << r << " is incorrect." << endl;
                    goto x;
                }
            }
        }
        if (isbn.size() != 10) {
            cout << r << " is incorrect." << endl;
            goto x;
        }
        // do checksum
        vector<int> ps;
        ps.push_back(isbn[0]);
        for (int i = 1; i < 10; ++i) {
            ps.push_back(ps[i - 1] + isbn[i]);
        }
        for (int i = 1; i < 10; ++i) {
            ps[i] += ps[i - 1];
        }
        if ((ps[9] % 11) != 0) {
            cout << r << " is incorrect." << endl;
            goto x;
        }
        cout << r << " is correct." << endl;
    }
    return 0;
}
