#include <bits/stdc++.h>
using namespace std;

bool allcaps(string& s) {
    for (char c : s) {
        if (c == ' ') continue;
        if (!isalpha(c) || !isupper(c)) return false;
    }
    return true;
}

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second != b.second ? a.second > b.second : a.first < b.first;
}

int main() {
    string s;
    // read in each testcase until no more testcase
    while (true) {
        // read in the current testcase
        // track the students that have already been added to previous projects
        unordered_set<string> added;
        // track the current project's students also
        unordered_set<string> currp;
        // track the frequency of students that signed up for each project
        unordered_map<string, int> mp;
        unordered_map<string, string> prev;
        string proj = "";
        while (true) {
            getline(cin, s);
            if (s == "0") return 0; // case where no more testcase
            if (s == "1") break; // case where end of current testcase => move to the next testcase
            // case where current line is a project
            if (allcaps(s)) {
                // add all students to the set of students that have been added to previous projects
                if (proj != "") mp[proj] = currp.size();
                proj = s;
                for (string stud : currp) {
                    added.insert(stud);
                }
                // clear the set of students for the current project
                currp.clear();
                // start reading in the students of the current project
                continue;
            }
            // current student has already signed up for some previous project
            if (added.find(s) != added.end()) {
                // remove them from all projects
                if (prev.find(s) != prev.end()) {
                    --mp[prev[s]];
                    prev.erase(s);
                }
            } else { // have not signed up
                prev[s] = proj;
                currp.insert(s);
            }
        }
        mp[proj] = currp.size();
        // sort and print the results
        vector<pair<string, int>> res;
        for (auto& p : mp) {
            res.push_back(p);
        }
        sort(res.begin(), res.end(), cmp);
        for (auto& p : res) {
            cout << p.first << " " << p.second << endl;
        }
        cout << endl;
    } 
    return 0;
}

