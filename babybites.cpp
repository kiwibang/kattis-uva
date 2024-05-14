#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, currCount = 1;
    cin >> n;
    cin.ignore();
    string line;
    getline(cin, line);
    istringstream iss(line);
    string curr;
    bool isFishy = false;
    while (iss >> curr) {
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
