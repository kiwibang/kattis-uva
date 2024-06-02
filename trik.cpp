#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    cin >> line;
    // 0, 1. or 2
    int ballPos = 0;
    for (int i = 0; i < line.size(); ++i) {
        if (line[i] == 'A') {
            ballPos = ballPos == 2 ? ballPos : ballPos ^ 1;
        } else if (line[i] == 'B') {
            ballPos = ballPos == 0 ? ballPos : ballPos == 1 ? 2 : 1;
        } else if (line[i] == 'C') {
            ballPos = ballPos == 1 ? ballPos : ballPos == 0 ? 2 : 0;
        }
    }
    cout << ballPos + 1 << endl;
    return 0;
}
