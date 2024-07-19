#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        long long a, b, pdt, n = 0, m = 0;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }
        // do the multiplication
        pdt = a * b;
        // get the digits of the operands
        vector<int> digitsa, digitsb, digitspdt;
        // get the number of digits of a and b
        int tempa = a;
        while (tempa > 0) {
            ++n;
            digitsa.push_back(tempa % 10); // insert in reverse order
            tempa /= 10;
        }
        int tempb = b;
        while (tempb > 0) {
            ++m;
            digitsb.push_back(tempb % 10); // insert in reverse order
            tempb /= 10;
        }
        int temppdt = pdt;
        while (temppdt > 0) {
            digitspdt.insert(digitspdt.begin(), temppdt % 10);
            temppdt /= 10;
        }
        // get the values of each cell of the lattice
        vector<vector<long long> > latticevals(m, vector<long long>(n));
        tempa = a, tempb = b;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                latticevals[i][j] = (tempa % 10) * (tempb % 10);
                tempa /= 10;
            }
            tempa = a;
            tempb /= 10;
        }
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << latticevals[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // set up the template strings
        string topbotborders(4 * n + 3, '-');
        topbotborders = "+" + topbotborders + "+";
        string latticetopbot = "+";
        for (int i = 0; i < n; ++i) {
            latticetopbot += "---+";
        }
        // print the top row
        cout << topbotborders << endl;
        // print the first operand (labelled a)
        string operand1 = "|   ";
        for (int i = n - 1; i >= 0; --i) {
            operand1 += to_string(digitsa[i]);
            operand1 += "   ";
        }
        operand1 += "|";
        cout << operand1 << endl;
        // print the top of the lattice, which should have the same number of +---+ as the number of digits of a 
        cout << "| " << latticetopbot << " |" << endl;
        // print the lattice, which should be of dimension n x m, where n is the number of digits in a, and m is the number of digits in b
        int spaceleft = m + n;
        // get the start index
        int startindex = spaceleft - digitspdt.size();
        int digitsidx = 0;
        for (int i = 0; i < m; ++i) {
            // first row
            cout << "|";
            if (digitsidx > 0) {
                cout << "/";
            } else {
                cout << " ";
            }
            cout << "|";
            for (int j = 0; j < n; ++j) {
                cout << to_string(latticevals[i][j] / 10) << " /|";
            }
            cout << " |" << endl;
            // mid row
            cout << "| |";
            for (int j = 0; j < n; ++j) {
                cout << " / |";
            }
            cout << digitsb[m - i - 1] << "|" << endl;
            // last row
            cout << "|";
            if (i >= startindex) {
                cout << digitspdt[digitsidx++];
            } else {
                cout << " ";
            }
            cout << "|";
            for (int j = 0; j < n; ++j) {
                cout << "/ " << to_string(latticevals[i][j] % 10) << "|";
            }
            cout << " |" << endl;
            // bottom lattice
            cout << "| " << latticetopbot << " |" << endl;
        }
        // print the second last row
        cout << "|";
        if (digitsidx > 0) {
            cout << "/";
        } else {
            cout << " ";
        }
        for (int j = 0; j < n; ++j) {
            cout << " " << digitspdt[digitsidx++] << " ";
            if (j < n - 1) {
                cout << "/";
            } else {
                cout << " ";
            }
        }
        cout << "  |" << endl;
        // print the bottom border
        cout << topbotborders << endl;
    }
    return 0;
}
