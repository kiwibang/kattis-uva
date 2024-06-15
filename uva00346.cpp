#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> notetoid;
    notetoid["A"] = 0;
    notetoid["A#"] = 1;
    notetoid["Bb"] = 1;
    notetoid["B"] = 2;
    notetoid["C"] = 3;
    notetoid["C#"] = 4;
    notetoid["Db"] = 4;
    notetoid["D"] = 5;
    notetoid["D#"] = 6;
    notetoid["Eb"] = 6;
    notetoid["E"] = 7;
    notetoid["F"] = 8;
    notetoid["F#"] = 9;
    notetoid["Gb"] = 9;
    notetoid["G"] = 10;
    notetoid["G#"] = 11;
    notetoid["Ab"] = 11;
    map<int, string> idtonote;
    idtonote[0] = "A";
    idtonote[1] = "A#";
    idtonote[2] = "B";
    idtonote[3] = "C";
    idtonote[4] = "C#";
    idtonote[5] = "D";
    idtonote[6] = "D#";
    idtonote[7] = "E";
    idtonote[8] = "F";
    idtonote[9] = "F#";
    idtonote[10] = "G";
    idtonote[11] = "G#";
    x: while (true) {
        string a, b, c, ar = "", br = "", cr = "";
        cin >> a >> b >> c;
        if (cin.eof()) {
            return 0;
        }
        if (isalpha(a[0])) {
            ar.push_back(toupper(a[0]));
            ar += a.substr(1);
        }
        if (isalpha(b[0])) {
            br.push_back(toupper(b[0]));
            br += b.substr(1);
        }
        if (isalpha(c[0])) {
            cr.push_back(toupper(c[0]));
            cr += c.substr(1);
        }
        // cout << ar << " " << br << " " << cr << endl;
        if (notetoid.find(ar) == notetoid.end() || notetoid.find(br) == notetoid.end() || notetoid.find(cr) == notetoid.end()) {
            cout << a << " " << b << " " << c << "  is unrecognized." << endl;
            goto x;
        }
        vector<int> notes;
        notes.push_back(notetoid[ar]);
        notes.push_back(notetoid[br]);
        notes.push_back(notetoid[cr]);
        // cout << "original notes id: " << notes[0] << " " << notes[1] << " " << notes[2] << endl;
        sort(notes.begin(), notes.end());
        // check major/minor chord
        // get the gap between the first and second note
        int firstc = notes[1] - notes[0] - 1;
        // get the gap between the second and third note
        int secondc = notes[2] - notes[1] - 1;
        // get the gap between the third and first note
        int thirdc = (11 - notes[2]) + notes[0];
        // get the max gap
        int maxgap = max(firstc, max(secondc, thirdc));
        // cout << "new order: " << notes[0] << " " << notes[1] << " " << notes[2] << endl;
        // cout << "gaps: " << firstc << " " << secondc << " " << thirdc << endl;
        // look for the two smallest gaps
        if (maxgap == thirdc) { // first note is the start note
            // major 
            if (firstc == 3 && secondc == 2) {
                cout << a << " " << b << " " << c << " is a " << idtonote[notes[0]] << " Major chord." << endl;
            } else if (firstc == 2 && secondc == 3) { // minor
                cout << a << " " << b << " " << c << " is a " << idtonote[notes[0]] << " Minor chord." << endl;
            } else { // unrecognized
                cout << a << " " << b << " " << c << " is unrecognized." << endl;
            }
        } else if (maxgap == firstc) { // second note is the start note
            // major 
            if (secondc == 3 && thirdc == 2) {
                cout << a << " " << b << " " << c << " is a " << idtonote[notes[1]] << " Major chord." << endl;
            } else if (secondc == 2 && thirdc == 3) { // minor
                cout << a << " " << b << " " << c << " is a " << idtonote[notes[1]] << " Minor chord." << endl;
            } else { // unrecognized
                cout << a << " " << b << " " << c << " is unrecognized." << endl;
            }
        } else if (maxgap == secondc) {
            // major 
            if (thirdc == 3 && firstc == 2) {
                cout << a << " " << b << " " << c << " is a " << idtonote[notes[2]] << " Major chord." << endl;
            } else if (thirdc == 2 && firstc == 3) { // minor
                cout << a << " " << b << " " << c << " is a " << idtonote[notes[2]] << " Minor chord." << endl;
            } else { // unrecognized
                cout << a << " " << b << " " << c << " is unrecognized." << endl;
            }
        } else {
            cout << a << " " << b << " " << c << "  is unrecognized." << endl;
        }
    }
    return 0;
}
