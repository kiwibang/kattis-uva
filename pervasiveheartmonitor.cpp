#include <bits/stdc++.h>
using namespace std;

int main() {
    string curr;
    while (true) {
        getline(cin, curr);
        if (cin.eof()) {
            break;
        }
        istringstream iss(curr);
        string temp;
        vector<string> name;
        double avg = 0.0;
        int count = 0;
        while (iss >> temp) {
            // if name
            if (isalpha(temp[0])) {
                name.push_back(temp);
                continue;
            }
            // if number
            avg += stod(temp);
            ++count;
        }
        // print the avg and name
        cout << fixed << setprecision(6) << avg / count << " ";
        for (int i = 0; i < name.size(); ++i) {
            cout << name[i];
            if (i < name.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
