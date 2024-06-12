#include <bits/stdc++.h>
using namespace std;

string getabo(string b) {
    if (b == "?") {
        return "";
    }

    if (b.size() == 3) {
        return b.substr(0, 2);
    } else {
        return b.substr(0, 1);
    }
}

char getrh(string b) {
    if (b == "?") {
        return (char) 0;
    }
    return b[b.size() - 1];
}

void printset(set<char>& s) {
    for (const char &cc : s) {
        cout << cc << " ";
    }
    cout << endl;
}

int main() {
    // set up the ABO map: maps the abo type to the possible alleles (e.g. A blood type has A and O as the set of possible alleles)
    map<string, set<char> > abomap;
    // A blood type
    abomap["A"] = set<char>();
    abomap["A"].insert('A');
    abomap["A"].insert('O');
    // B blood type
    abomap["B"] = set<char>();
    abomap["B"].insert('B');
    abomap["B"].insert('O');
    // AB blood type
    abomap["AB"] = set<char>();
    abomap["AB"].insert('A');
    abomap["AB"].insert('B');
    // O blood type
    abomap["O"] = set<char>();
    abomap["O"].insert('O');
    
    // set up the allele map
    map<char, set<char> > alelemap;
    alelemap['-'] = set<char>();
    alelemap['-'].insert('-');
    alelemap['+'] = set<char>();
    alelemap['+'].insert('+');
    alelemap['+'].insert('-');

    map<string, vector<string> > posmap;
    posmap["A"] = vector<string>();
    posmap["A"].push_back("AO");
    posmap["A"].push_back("AA");
    posmap["A"].push_back("OA");
    posmap["B"] = vector<string>();
    posmap["B"].push_back("BO");
    posmap["B"].push_back("BB");
    posmap["B"].push_back("OB");
    posmap["AB"] = vector<string>();
    posmap["AB"].push_back("AB");
    posmap["AB"].push_back("BA");
    posmap["O"] = vector<string>();
    posmap["O"].push_back("OO");

    map<char, vector<string> > rhmap;
    rhmap['-'] = vector<string>();
    rhmap['-'].push_back("--");
    rhmap['+'] = vector<string>();
    rhmap['+'].push_back("-+");
    rhmap['+'].push_back("++");
    rhmap['+'].push_back("+-");
    // set up the possible blood types
    string possible[] = {"A+", "A-", "B+", "B-", "AB-", "AB+", "O-", "O+"};

    // test case id, start from 1 like output specification
    int t = 1;
    while (true) {
        // read in the parents and child blood type
        string l, p1, p2, ch;
        getline(cin, l);
        istringstream iss(l);
        iss >> p1 >> p2 >> ch;
        if (p1 == "E" && p2 == "N" && ch == "D") {
            return 0;
        }
        vector<string> res;
        // case where child is the unknown
        if (ch == "?") {
            // get the parents allele
            set<char> pr1 = abomap[getabo(p1)];
            set<char> pr2 = abomap[getabo(p2)];
            // get the parents rh factor
            set<char> rh1 = alelemap[getrh(p1)];
            set<char> rh2 = alelemap[getrh(p2)];
            // loop over possibilities
            for (int i = 0; i < 8; ++i) {
                string poss = possible[i];
                // get abo list of child
                vector<string> abocurr = posmap[getabo(poss)];
                // get rh list of child
                vector<string> rhcurr = rhmap[getrh(poss)];
                // check if possible
                bool abook = false;
                bool rhok = false;
                for (int j = 0; j < abocurr.size(); ++j) {
                    if (pr1.find(abocurr[j][0]) != pr1.end() && pr2.find(abocurr[j][1]) != pr2.end()) { // ok check
                        abook = true;
                        break;
                    }
                }
                for (int j = 0; j < rhcurr.size(); ++j) {
                    if (rh1.find(rhcurr[j][0]) != rh1.end() && rh2.find(rhcurr[j][1]) != rh2.end()) {
                        rhok = true;
                        break;
                    }
                }
                if (abook && rhok) {
                    res.push_back(poss);
                }
            }
        } else if (p1 == "?") {
            // get the parents allele
            set<char> pr1;
            set<char> pr2 = abomap[getabo(p2)];
            // get the parents rh factor
            set<char> rh1;
            set<char> rh2 = alelemap[getrh(p2)];
            vector<string> abocurr = posmap[getabo(ch)];
            vector<string> rhcurr = rhmap[getrh(ch)];
            // loop over possibilities
            for (int i = 0; i < 8; ++i) {
                string poss = possible[i];
                // get abo
                pr1 = abomap[getabo(poss)];
                // get rh
                rh1 = alelemap[getrh(poss)];
                // check if possible
                bool abook = false;
                bool rhok = false;
                for (int j = 0; j < abocurr.size(); ++j) {
                    if (pr1.find(abocurr[j][0]) != pr1.end() && pr2.find(abocurr[j][1]) != pr2.end()) { // ok check
                        abook = true;
                        break;
                    }
                }
                for (int j = 0; j < rhcurr.size(); ++j) {
                    if (rh1.find(rhcurr[j][0]) != rh1.end() && rh2.find(rhcurr[j][1]) != rh2.end()) {
                        rhok = true;
                        break;
                    }
                }
                if (abook && rhok) {
                    res.push_back(poss);
                }
            }
        } else if (p2 == "?") {
            // get the parents allele
            set<char> pr1 = abomap[getabo(p1)];
            set<char> pr2;
            // get the parents rh factor
            set<char> rh1 = alelemap[getrh(p1)];
            set<char> rh2;
            vector<string> abocurr = posmap[getabo(ch)];
            vector<string> rhcurr = rhmap[getrh(ch)];
            // loop over possibilities
            for (int i = 0; i < 8; ++i) {
                string poss = possible[i];
                // get abo
                pr2 = abomap[getabo(poss)];
                // get rh
                rh2 = alelemap[getrh(poss)];
                // check if possible
                bool abook = false;
                bool rhok = false;
                for (int j = 0; j < abocurr.size(); ++j) {
                    if (pr1.find(abocurr[j][0]) != pr1.end() && pr2.find(abocurr[j][1]) != pr2.end()) { // ok check
                        abook = true;
                        break;
                    }
                }
                for (int j = 0; j < rhcurr.size(); ++j) {
                    if (rh1.find(rhcurr[j][0]) != rh1.end() && rh2.find(rhcurr[j][1]) != rh2.end()) {
                        rhok = true;
                        break;
                    }
                }
                if (abook && rhok) {
                    res.push_back(poss);
                }
            }
        }
        // print the testcase id
        cout << "Case " << t << ": ";
        // make the set string
        string r = "";
        if (res.size() == 0) {
            r = "IMPOSSIBLE";
        } else if (res.size() == 1) {
            r += res[0];  
        } else {
            r += "{";
            for (int i = 0; i < res.size(); ++i) {
                if (i > 0)
                    r += ", ";
                r += res[i];
            }
            r += "}";
        }
        // print the actual res
        if (ch == "?") {
            cout << p1 << " " << p2 << " " << r << endl;
        } else if (p1 == "?") {
            cout << r << " " << p2 << " " << ch << endl;
        } else if (p2 == "?") {
            cout << p1 << " " << r << " " << ch << endl;
        }
        ++t;
    }
    return 0;
}
