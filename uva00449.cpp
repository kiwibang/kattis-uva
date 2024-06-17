#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> C;
    C.push_back("C");
    C.push_back("D");
    C.push_back("E");
    C.push_back("F");
    C.push_back("G");
    C.push_back("A");
    C.push_back("B");
    
    vector<string> Db;
    Db.push_back("Db");
    Db.push_back("Eb");
    Db.push_back("F");
    Db.push_back("Gb");
    Db.push_back("Ab");
    Db.push_back("Bb");
    Db.push_back("C");

    vector<string> D;
    D.push_back("D");
    D.push_back("E");
    D.push_back("F#");
    D.push_back("G");
    D.push_back("A");
    D.push_back("B");
    D.push_back("C#");

    vector<string> Eb;
    Eb.push_back("Eb");
    Eb.push_back("F");
    Eb.push_back("G");
    Eb.push_back("Ab");
    Eb.push_back("Bb");
    Eb.push_back("C");
    Eb.push_back("D");

    vector<string> E;
    E.push_back("E");
    E.push_back("F#");
    E.push_back("G#");
    E.push_back("A");
    E.push_back("B");
    E.push_back("C#");
    E.push_back("D#");

    vector<string> F;
    F.push_back("F");
    F.push_back("G");
    F.push_back("A");
    F.push_back("Bb");
    F.push_back("C");
    F.push_back("D");
    F.push_back("E");

    vector<string> Gb;
    Gb.push_back("Gb");
    Gb.push_back("Ab");
    Gb.push_back("Bb");
    Gb.push_back("Cb");
    Gb.push_back("Db");
    Gb.push_back("Eb");
    Gb.push_back("F");

    vector<string> G;
    G.push_back("G");
    G.push_back("A");
    G.push_back("B");
    G.push_back("C");
    G.push_back("D");
    G.push_back("E");
    G.push_back("F#");

    vector<string> Ab;
    Ab.push_back("Ab");
    Ab.push_back("Bb");
    Ab.push_back("C");
    Ab.push_back("Db");
    Ab.push_back("Eb");
    Ab.push_back("F");
    Ab.push_back("G");

    vector<string> A;
    A.push_back("A");
    A.push_back("B");
    A.push_back("C#");
    A.push_back("D");
    A.push_back("E");
    A.push_back("F#");
    A.push_back("G#");

    vector<string> Bb;
    Bb.push_back("Bb");
    Bb.push_back("C");
    Bb.push_back("D");
    Bb.push_back("Eb");
    Bb.push_back("F");
    Bb.push_back("G");
    Bb.push_back("A");

    vector<string> B;
    B.push_back("B");
    B.push_back("C#");
    B.push_back("D#");
    B.push_back("E");
    B.push_back("F#");
    B.push_back("G#");
    B.push_back("A#");

    map<string, vector<string> > notetoscale;
    notetoscale["C"] = C;
    notetoscale["Db"] = Db;
    notetoscale["D"] = D;
    notetoscale["Eb"] = Eb;
    notetoscale["E"] = E;
    notetoscale["F"] = F;
    notetoscale["Gb"] = Gb;
    notetoscale["G"] = G;
    notetoscale["Ab"] = Ab;
    notetoscale["A"] = A;
    notetoscale["Bb"] = Bb;
    notetoscale["B"] = B;

    map<string, int> dirtodelta;
    dirtodelta["SECOND"] = 1;
    dirtodelta["THIRD"] = 2;
    dirtodelta["FOURTH"] = 3;
    dirtodelta["FIFTH"] = 4;
    dirtodelta["SIXTH"] = 5;
    dirtodelta["SEVENTH"] = 6;
    dirtodelta["OCTAVE"] = 0;

    while (true) {
        // read in the first line
        string l;
        getline(cin, l);
        // no more lines, terminate
        if (cin.eof()) {
            return 0;
        }
        // get the note
        string note = l;
        // then get the intervals
        getline(cin, l);
        // process the intervals
        vector<vector<string> > intervals;
        while (!l.empty()) {
            // get the current interval
            size_t pos = l.find(';');
            string currinterval = l.substr(0, pos);
            string nt, dir, num;
            if (pos == string::npos) {
                istringstream iss(l);
                iss >> nt >> dir >> num;
            } else {
                istringstream iss(currinterval);
                iss >> nt >> dir >> num;
            }
            vector<string> interval;
            interval.push_back(nt);
            interval.push_back(dir);
            interval.push_back(num);
            intervals.push_back(interval);
            // delete the current interval
            if (pos == string::npos) {
                l = "";
            }
            l.erase(0, pos + 1);
        }
        // get the scale
        vector<string> currscale = notetoscale[note];

        cout << "Key of " << note << endl;
        for (int i = 0; i < intervals.size(); ++i) {
            vector<string> curr = intervals[i];
            // get the note
            string note = curr[0];
            // get the direction
            string dir = curr[1];
            // get the number
            int movecount = dirtodelta[curr[2]];
            // check if the current note is inside the scale
            // get the pos
            int startidx = -1;
            for (int j = 0; j < currscale.size(); ++j) {
                if (currscale[j] == note) {
                    startidx = j;
                    break;
                }
            }
            cout << note << ": ";
            if (startidx == -1) {
                cout << "invalid note for this key" << endl;
                continue;
            }
            cout << curr[1] << " " << curr[2] << " > ";
            for (int j = 0; j < movecount; ++j) {
                if (dir == "UP") {
                    startidx = (startidx + 1) % 7;
                } else { // decrease
                    --startidx;
                    startidx = startidx < 0 ? 6 : startidx;
                }
            }
            cout << currscale[startidx] << endl;
        }
        cout << endl;
    }
    return 0;
}
