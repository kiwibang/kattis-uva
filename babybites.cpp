#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, currCount = 1;
    string line;
    cin >> n;
    cin.ignore();
    getline(cin, line);
    istringstream iss(line);
    vector<string> words;
    string curr;
    bool isFishy = false;
    while (iss >> curr) {
        words.push_back(curr);
        if (curr != "mumble" && stoi(curr) != currCount) {
            cout << "something is fishy" << endl;
            return 0;
        }
        currCount++;
        n--;
    }
    cout << "makes sense" << endl;
    return 0;
}
