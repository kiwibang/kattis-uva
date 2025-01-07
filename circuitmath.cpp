#include <bits/stdc++.h>
using namespace std;

void evaland(stack<char>& s, vector<bool>& vals) {
    bool op1 = s.top() == 't' ? true : s.top() == 'f' ? false : vals[s.top() - 'A'];
    s.pop();
    bool op2 = s.top() == 't' ? true : s.top() == 'f' ? false : vals[s.top() - 'A'];
    s.pop();
    if (op1 && op2) {
        s.push('t');
    } else {
        s.push('f');
    }
}

void evalor(stack<char>& s, vector<bool>& vals) {
    bool op1 = s.top() == 't' ? true : s.top() == 'f' ? false : vals[s.top() - 'A'];
    s.pop();
    bool op2 = s.top() == 't' ? true : s.top() == 'f' ? false : vals[s.top() - 'A'];
    s.pop();
    if (op1 || op2) {
        s.push('t');
    } else {
        s.push('f');
    }
}

void evalnot(stack<char>& s, vector<bool>& vals) {
    bool op1 = s.top() == 't' ? true : s.top() == 'f' ? false : vals[s.top() - 'A'];
    s.pop();
    if (op1) {
        s.push('f');
    } else {
        s.push('t');
    }
}

int main() {
    int n;
    cin >> n;
    vector<bool> vals(26, false);
    char cc;
    for (int i = 0; i < n; ++i) {
        cin >> cc;
        vals[i] = cc == 'T';
    }
    stack<char> s;
    cin.ignore();
    string l;
    getline(cin, l);
    for (int i = 0; i < l.size(); ++i) {
        if (l[i] == ' ') continue;
        // alphabet
        if (isalpha(l[i])) {
            s.push(l[i]);
            continue;
        }
        // else, operator. separate into cases
        if (l[i] == '*') {
            evaland(s, vals);
        } else if (l[i] == '+') {
            evalor(s, vals);
        } else if (l[i] == '-') {
            evalnot(s, vals);
        }
    }
    if (s.top() != 't' && s.top() != 'f' && isalpha(s.top())) {
        if (vals[s.top() - 'A']) {
            cout << 'T' << endl;
        } else {
            cout << 'F' << endl;
        }
        return 0;
    }
    if (s.top() == 't') {
        cout << 'T' << endl;
    } else {
        cout << 'F' << endl;
    }
    return 0;
}

