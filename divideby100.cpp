#include <bits/stdc++.h>
using namespace std;

int main() {
        string n, m, res = "";
        cin >> n >> m;
        int numzeros = m.size() - 1;
        // case where number of zeros in m is as large as the number of digits of n
        if (numzeros >= n.size()) { // quotient is less than 1
            res = "0."; // add 0 and the decimal place
            // append the appropriate number of zeros
            int numz = numzeros - n.size();
            for (int i = 0; i < numz; ++i) res += '0';
            // get the index with the last significant digit in string n
            int idx = n.size() - 1;
            while (idx >= 0 && n[idx] == '0') --idx;
            // append the number to the result, ignoring any trailing zeros
            for (int i = 0; i <= idx; ++i) res += n[i];
        } else { // quotient is more than 1
            // find the index to place the decimal point after
            int limidx = n.size() - numzeros;
            // place the quotient
            for (int i = 0; i < limidx; ++i) res += n[i];
            if (limidx == n.size()) goto p;
            // get the index with the last significant digit in string n
            int idx = n.size() - 1;
            while (idx >= 0 && n[idx] == '0') --idx;
            if (idx <= limidx) goto p;
            res += '.';
            for (int i = limidx; i <= idx; ++i) res += n[i];
        }
        p: cout << res << endl; // print the result
        return 0;
}
