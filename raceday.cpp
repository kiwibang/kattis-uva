#include <bits/stdc++.h>
using namespace std;

// compare based on the time
struct cmp1 {
    bool operator()(const vector<string>& a, const vector<string>& b) const {
        string t1 = a[3], t2 = b[3];
        int h1 = stoi(t1.substr(0, t1.find(':')));
        int m1 = stoi(t1.substr(t1.find(':') + 1));
        int h2 = stoi(t2.substr(0, t2.find(':')));
        int m2 = stoi(t2.substr(t2.find(':') + 1));
        return h1 != h2 ? h1 < h2 : m1 != m2 ? m1 < m2 : a[1] + " " + a[0] < b[1] + " " + b[0];
    }
};

struct cmp2 {
    bool operator()(const vector<string>& a, const vector<string>& b) const {
        string t1 = a[4], t2 = b[4];
        int h1 = stoi(t1.substr(0, t1.find(':')));
        int m1 = stoi(t1.substr(t1.find(':') + 1));
        int h2 = stoi(t2.substr(0, t2.find(':')));
        int m2 = stoi(t2.substr(t2.find(':') + 1));
        return h1 != h2 ? h1 < h2 : m1 != m2 ? m1 < m2 : a[1] + " " + a[0] < b[1] + " " + b[0];
    }
};

struct cmp3 {
    bool operator()(const vector<string>& a, const vector<string>& b) const {
        string t1 = a[5], t2 = b[5];
        int h1 = stoi(t1.substr(0, t1.find(':')));
        int m1 = stoi(t1.substr(t1.find(':') + 1));
        int h2 = stoi(t2.substr(0, t2.find(':')));
        int m2 = stoi(t2.substr(t2.find(':') + 1));
        return h1 != h2 ? h1 < h2 : m1 != m2 ? m1 < m2 : a[1] + " " + a[0] < b[1] + " " + b[0];
    }
};

struct cmp4 {
    bool operator()(const vector<string>& a, const vector<string>& b) const {
        return a[1] != b[1] ? a[1] < b[1] : a[0] < b[0];
    }
};

int main() {
    int n;
    while (true) {
        cin >> n;
        if (!n) break;
        unordered_map<string, vector<string>> bibtorn;
        unordered_map<string, int> bibtork1, bibtork2, bibtorkf;
        for (int i = 0; i < n; ++i) {
            string first, last, bib;
            cin >> first >> last >> bib;
            bibtorn[bib] = {first, last, bib, "", "", ""};
        }
        for (int i = 0; i < 3 * n; ++i) {
            string bib, split, time;
            cin >> bib >> split >> time;
            if (split == "S1") {
                bibtorn[bib][3] = time;
            } else if (split == "S2") {
                bibtorn[bib][4] = time;
            } else if (split == "F") {
                bibtorn[bib][5] = time;
            }
        }
        // get the order of the participants
        set<vector<string>, cmp1> s1;
        set<vector<string>, cmp2> s2;
        set<vector<string>, cmp3> s3;
        set<vector<string>, cmp4> order;
        for (auto& p : bibtorn) {
            vector<string> curr = p.second;
            s1.insert(curr);
            s2.insert(curr);
            s3.insert(curr);
            order.insert(curr);
        }
        // get the ranks for each split 
        int r1 = 1;
        auto it = s1.begin();
        while (it != s1.end()) {
            string time = (*it)[3];
            int cnt = 0;
            while (it != s1.end() && time == (*it)[3]) {
                ++cnt;
                vector<string> curr = *it;
                bibtork1[curr[2]] = r1;
                ++it;
            }
            r1 += cnt;
        }
        int r2 = 1;
        it = s2.begin();
        while (it != s2.end()) {
            string time = (*it)[4];
            int cnt = 0;
            while (it != s2.end() && time == (*it)[4]) {
                ++cnt;
                vector<string> curr = *it;
                bibtork2[curr[2]] = r2;
                ++it;
            }
            r2 += cnt;
        }
        int r3 = 1;
        it = s3.begin();
        while (it != s3.end()) {
            string time = (*it)[5];
            int cnt = 0;
            while (it != s3.end() && time == (*it)[5]) {
                ++cnt;
                vector<string> curr = *it;
                bibtorkf[curr[2]] = r3;
                ++it;
            }
            r3 += cnt;
        }
        cout << "NAME                       BIB    SPLIT1      RANK    SPLIT2      RANK    FINISH      RANK" << endl;
        for (auto p : order) {
            // print the last name, first name
            cout << left << setw(20) << p[1] + ", " + p[0];
            cout << right << setw(10) << p[2];
            cout << right << setw(10) << p[3];
            cout << right << setw(10) << bibtork1[p[2]];
            cout << right << setw(10) << p[4];
            cout << right << setw(10) << bibtork2[p[2]];
            cout << right << setw(10) << p[5];
            cout << right << setw(10) << bibtorkf[p[2]];
            cout << endl; 
        }
        cout << endl;
    }
    return 0;
}

