#include <bits/stdc++.h>
using namespace std;

int main() {
    // input-line variables
    string line, action = "";
    int shares;
    double price;

    // program variables
    int shareCount = 0;
    double currAvg = 1;
    while (action != "die") {
        getline(cin, line);
        istringstream iss(line);
        iss >> action;
        if (action == "buy") {
            iss >> shares >> price;
            // compute the new average
            double newAvg = (shareCount * currAvg) + (shares * price);
            newAvg /= (shareCount + shares);
            shareCount += shares;
            currAvg = newAvg;
        } else if (action == "sell") {
            iss >> shares >> price;
            shareCount -= shares;
        } else if (action == "split") {
            iss >> shares;
            shareCount *= shares;
            currAvg /= shares;
        } else if (action == "merge") {
            iss >> shares;
            // sell the remainder shares, and update the total price paid
            shareCount /= shares;
            currAvg *= shares;
        } else { // die
            iss >> price;
            cout << fixed;
            cout.precision(3);
            cout << shareCount * (price - max(0.0, 0.3 * (price - currAvg))) << endl;
            return 0;
        }
    }
    return 0;
}
