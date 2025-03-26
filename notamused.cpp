#include <bits/stdc++.h>
using namespace std;

int main() {
    string l;
    int day = 1;
    while (true) {
        // read in an open
        getline(cin, l);
        if (cin.eof()) break;
        // record down the total time spent at the amusement park for each person, sorted in lexicographical order
        map<string, int> ntot;
        // record down the entry time
        unordered_map<string, int> ntoe;
        // loop over the entry and exit logs
        while (true) {
            getline(cin, l);
            if (l == "CLOSE") break;
            istringstream iss(l);
            string act, name;
            int t;
            iss >> act;
            iss >> name;
            iss >> t;
            if (act == "ENTER") { // enter
                // add to the entry map
                ntoe[name] = t;
            } else { // exit
                // add the time taken at the park
                if (ntot.find(name) == ntot.end()) ntot[name] = 0;
                ntot[name] += t - ntoe[name];
            } 
        }
        // print out the results for the current day
        cout << "Day " << day++ << endl;
        for (auto& p : ntot) {
            cout << fixed << setprecision(2) << p.first << " $" << p.second / 10.0 << endl;
        }
        cout << endl;
    }
    return 0;
}

