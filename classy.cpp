#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, vector<string> >& a, pair<string, vector<string> >& b) {
    vector<string> s1 = a.second, s2 = b.second;
    int i = s1.size() - 1, j = s2.size() - 1;
    while (i >= 0 || j >= 0) {
        int one, two;
        if (i == s1.size() - 1 && j == s2.size() - 1) {
            one = s1[i] == "upper class" ? 0 : s1[i] == "middle class" ? 1 : 2;
            two = s2[j] == "upper class" ? 0 : s2[j] == "middle class" ? 1 : 2;
        } else {
            one = i < 0 ? 1 : s1[i] == "upper" ? 0 : s1[i] == "middle" ? 1 : 2;   
            two = j < 0 ? 1 : s2[j] == "upper" ? 0 : s2[j] == "middle" ? 1 : 2;   
        }  
        if (one != two) {
            return one < two;
        }
        --i, --j;
    }
    return a.first < b.first;
}

int main() {
    // read in testcases
    int t;
    cin >> t;
    while (t--) {
        // read in number of people
        int n;
        cin >> n;
        cin.ignore();
        string curr, part;
        vector<pair<string, vector<string> > > people;
        for (int i = 0; i < n; ++i) {
            getline(cin, curr);
            string name = "";
            vector<string> parts;
            int j = 0;
            while (curr[j] != ':') name += curr[j++];
            curr = curr.substr(j + 2);
            stringstream ss(curr);
            while (getline(ss, part, '-')) parts.push_back(part);
            people.push_back(pair<string, vector<string> >(name, parts));
        }
        sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < people.size(); ++i) {
            cout << people[i].first << endl;
        }
        cout << "==============================" << endl;
    }
    return 0;
}

