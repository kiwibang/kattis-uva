:include <bits/stdc++.h>
using namespace std;

int main() {
    string curr, ori, fore;
    unordered_map<string, string> dict;
    while (true) {
        getline(cin, curr);
        if (curr == "") break;
        istringstream iss(curr);
        iss >> ori >> fore;
        dict[fore] = ori;
    }
    while (getline(cin, curr)) {
        if (dict.find(curr) == dict.end()) {
            cout << "eh" << endl;
        } else {
            cout << dict[curr] << endl;
        }
    }
    return 0;
}

