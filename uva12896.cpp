#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<char> > buttons(10, vector<char>());
    buttons[1].push_back('.');
    buttons[1].push_back(',');
    buttons[1].push_back('?');
    buttons[1].push_back('\"');

    buttons[2].push_back('a');
    buttons[2].push_back('b');
    buttons[2].push_back('c');

    buttons[3].push_back('d');
    buttons[3].push_back('e');
    buttons[3].push_back('f');

    buttons[4].push_back('g');
    buttons[4].push_back('h');
    buttons[4].push_back('i');

    buttons[5].push_back('j');
    buttons[5].push_back('k');
    buttons[5].push_back('l');

    buttons[6].push_back('m');
    buttons[6].push_back('n');
    buttons[6].push_back('o');

    buttons[7].push_back('p');
    buttons[7].push_back('q');
    buttons[7].push_back('r');
    buttons[7].push_back('s');

    buttons[8].push_back('t');
    buttons[8].push_back('u');
    buttons[8].push_back('v');

    buttons[9].push_back('w');
    buttons[9].push_back('x');
    buttons[9].push_back('y');
    buttons[9].push_back('z');

    buttons[0].push_back(' ');
    int t;
    cin >> t;
    while (t--) {
        int l;
        cin >> l;
        vector<pair<int, int> > p;
        for (int i = 0; i < l; ++i) {
            int temp;
            cin >> temp;
            p.push_back(pair<int, int>(temp, -1));
        }
        for (int i = 0; i < l; ++i) {
            int temp;
            cin >> temp;
            p[i].second = temp;
        }
        for (int i = 0; i < l; ++i) {
            cout << buttons[p[i].first][p[i].second - 1];
        }
        cout << endl;
    }
    return 0;
}
