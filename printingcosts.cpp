#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, int> costs;
    costs[' '] = 0;
    costs['&'] = 24;
    costs[','] = 7;
    costs['2'] = 22;
    costs['8'] = 23;
    costs['>'] = 10;
    costs['D'] = 26;
    costs['J'] = 18;
    costs['P'] = 23;
    costs['V'] = 19;
    costs['\\'] = 10;
    costs['b'] = 25;
    costs['h'] = 21;
    costs['n'] = 18;
    costs['t'] = 17;
    costs['z'] = 19;

    costs['!'] = 9;
    costs['\''] = 3;
    costs['-'] = 7;
    costs['3'] = 23;
    costs['9'] = 26;
    costs['?'] = 15;
    costs['E'] = 26;
    costs['K'] = 21;
    costs['Q'] = 31;
    costs['W'] = 26;
    costs[']'] = 18;
    costs['c'] = 17;
    costs['i'] = 15;
    costs['o'] = 20;
    costs['u'] = 17;
    costs['{'] = 18;

    costs['\"'] = 6;
    costs['('] = 12;
    costs['.'] = 4;
    costs['4'] = 21;
    costs[':'] = 8;
    costs['@'] = 32;
    costs['F'] = 20;
    costs['L'] = 16;
    costs['R'] = 28;
    costs['X'] = 18;
    costs['^'] = 7;
    costs['d'] = 25;
    costs['j'] = 20;
    costs['p'] = 25;
    costs['v'] = 13;
    costs['|'] = 12;

    costs['#'] = 24;
    costs[')'] = 12;
    costs['/'] = 10;
    costs['5'] = 27;
    costs[';'] = 11;
    costs['A'] = 24;
    costs['G'] = 25;
    costs['M'] = 28;
    costs['S'] = 25;
    costs['Y'] = 14;
    costs['_'] = 8;
    costs['e'] = 23;
    costs['k'] = 21;
    costs['q'] = 25;
    costs['w'] = 19;
    costs['}'] = 18;

    costs['$'] = 29;
    costs['*'] = 17;
    costs['0'] = 22;
    costs['6'] = 26;
    costs['<'] = 10;
    costs['B'] = 29;
    costs['H'] = 25;
    costs['N'] = 25;
    costs['T'] = 16;
    costs['Z'] = 22;
    costs['`'] = 3;
    costs['f'] = 18;
    costs['l'] = 16;
    costs['r'] = 13;
    costs['x'] = 13;
    costs['~'] = 9;

    costs['%'] = 22;
    costs['+'] = 13;
    costs['1'] = 19;
    costs['7'] = 16;
    costs['='] = 14;
    costs['C'] = 20;
    costs['I'] = 18;
    costs['O'] = 26;
    costs['U'] = 23;
    costs['['] = 18;
    costs['a'] = 23;
    costs['g'] = 30;
    costs['m'] = 22;
    costs['s'] = 21;
    costs['y'] = 24;

    string curr;
    while (true) {
        getline(cin, curr);
        if (cin.eof()) {
            break;
        }
        long long res = 0;
        for (int i = 0; i < curr.size(); ++i) {
            res += costs[curr[i]];
        }
        cout << res << endl;
    }
    return 0;
}
