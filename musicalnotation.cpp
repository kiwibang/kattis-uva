#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<char> notes;
    notes.push_back('G');
    notes.push_back('F');
    notes.push_back('E');
    notes.push_back('D');
    notes.push_back('C');
    notes.push_back('B');
    notes.push_back('A');
    notes.push_back('g');
    notes.push_back('f');
    notes.push_back('e');
    notes.push_back('d');
    notes.push_back('c');
    notes.push_back('b');
    notes.push_back('a');
    int n, size = 0;
    cin >> n;
    vector<char> nts;
    vector<int> dur;
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        int d = 1;
        if (temp.size() > 1) {
            d = stoi(temp.substr(1, temp.size() - 1));
        }
        size += d;
        if (i < n - 1) {
            ++size;
        }
        nts.push_back(temp[0]);
        dur.push_back(d);
    }
    map<char, string> res;
    for (int i = 0; i < notes.size(); ++i) {
        if (notes[i] == 'F' || notes[i] == 'D' || notes[i] == 'B' || notes[i] == 'g' || notes[i] == 'e' || notes[i] == 'a') {
            string temp(size, '-');
            res[notes[i]] = temp;
        } else {
            string temp(size, ' ');
            res[notes[i]] = temp;
        }
    }
    int idx = 0;
    for (int i = 0; i < nts.size(); ++i) {
        int duration = dur[i];
        for (int j = 0; j < duration; ++j) {
            res[nts[i]][idx++] = '*';
        }
        if (i < nts.size() - 1) {
            ++idx;
        }
    }
    for (int i = 0; i < notes.size(); ++i) {
        cout << notes[i] << ": " << res[notes[i]] << endl;
    }
    return 0;
}
