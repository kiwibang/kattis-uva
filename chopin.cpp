#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, string> alts;
    alts["A#"] = "Bb";
    alts["Bb"] = "A#";
    alts["C#"] = "Db";
    alts["Db"] = "C#";
    alts["D#"] = "Eb";
    alts["Eb"] = "D#";
    alts["F#"] = "Gb";
    alts["Gb"] = "F#";
    alts["G#"] = "Ab";
    alts["Ab"] = "G#";
    int i = 1;
    while (true) {
        string a, b;
        cin >> a >> b;
        if (cin.eof()) {
            return 0;
        }
        cout << "Case " << i << ": ";
        if (alts.find(a) != alts.end()) {
            cout << alts[a] << " " << b << endl;
        } else {
            cout << "UNIQUE" << endl;
        }
        ++i;
    }
    return 0;
}
