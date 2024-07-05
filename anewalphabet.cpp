#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, string> tmap;
    tmap['a'] = "@";
    tmap['b'] = "8";
    tmap['c'] = "(";
    tmap['d'] = "|)";
    tmap['e'] = "3";
    tmap['f'] = "#";
    tmap['g'] = "6";
    tmap['h'] = "[-]";
    tmap['i'] = "|";
    tmap['j'] = "_|";
    tmap['k'] = "|<";
    tmap['l'] = "1";
    tmap['m'] = "[]\\/[]";
    tmap['n'] = "[]\\[]";
    tmap['o'] = "0";
    tmap['p'] = "|D";
    tmap['q'] = "(,)";
    tmap['r'] = "|Z";
    tmap['s'] = "$";
    tmap['t'] = "']['";
    tmap['u'] = "|_|";
    tmap['v'] = "\\/";
    tmap['w'] = "\\/\\/";
    tmap['x'] = "}{";
    tmap['y'] = "`/";
    tmap['z'] = "2";
    string l;
    getline(cin, l);
    for (int i = 0; i < l.size(); ++i) {
        if (!isalpha(l[i]) || tmap.find(tolower(l[i])) == tmap.end()) {
            cout << l[i];
        }
        cout << tmap[tolower(l[i])];
    }
    cout << endl;
    return 0;
}
