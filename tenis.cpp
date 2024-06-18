#include <bits/stdc++.h>
using namespace std;

bool check(int p1, int p2, int idx, string player1, string player2, vector<int>& sc) {
    if (p1 == p2) {
        return false;
    }
    if (p1 < p2) {
        int temp;
        string ptemp;
        temp = p1;
        p1 = p2;
        p2 = temp;
        ptemp = player1;
        player1 = player2;
        player2 = ptemp;
        ++sc[1];
    } else {
        ++sc[0];
    }
    if (player2 == "federer") {
        return false;
    }
    if (p1 < 6) {
        return false;
    }
    if (p1 == 6) {
        return p2 <= 4;
    }
    if (p1 == 7 && idx < 3) {
        return p2 == 5 || p2 == 6;
    }
    if (p1 >= 7 && idx == 3) {
        return p1 == (p2 + 2);
    }
    return false;
}

int main() {
    // read in the player names
    string player1, player2;
    int n;
    cin >> player1 >> player2 >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        // read all the matches
        string match;
        getline(cin, match);
        istringstream iss(match);
        string cur;
        int p1, p2;
        vector<pair<int, int> > scores;
        vector<int> sc(2, 0);
        bool ok = true;
        int id = 1;
        while (iss >> cur) {
            p1 = stoi(cur.substr(0, cur.find(':')));
            p2 = stoi(cur.substr(cur.find(':') + 1, cur.size()));
            ok = ok && (sc[0] < 2 && sc[1] < 2);
            ok = ok && check(p1, p2, id++, player1, player2, sc);
        }
        ok = ok && (sc[0] == 2 || sc[1] == 2);
        string res = ok ? "da" : "ne";
        cout << res << endl;
    }
    return 0;
}
