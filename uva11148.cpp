#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // read the number of testcases
    int t;
    cin >> t;
    cin.ignore();
    // main program logic
    while (t--) {
        // get the current line
        string line;
        getline(cin, line);
        // track the numbers, first one: whole number, second one: numer, third one: denom 
        vector<vector<int> > numbers;
        // loop over the line
        int i = 0;
        while (i < line.size()) {
            // case where encounter a whole number/numer
            if (isdigit(line[i])) {
                vector<int> currnum(3, -1);
                int num = 0;
                // get the whole number
                while (i < line.size() && isdigit(line[i])) {
                    num = num * 10 + (line[i++] - '0');
                }
                // after number, break down into 3 cases: just whole number, numer, or whole number + fraction
                if (line[i] == ' ') { // just whole number
                    currnum[0] = num;
                    ++i;
                } else if (line[i] == '/') { // just fraction
                    currnum[1] = num;
                    // get denom
                    ++i; // shift to denom first digit
                    num = 0;
                    while (i < line.size() && isdigit(line[i])) {
                        num = num * 10 + (line[i++] - '0');
                    }
                    currnum[2] = num;
                } else if (line[i] == '-') { // whole number with fraction
                    currnum[0] = num;
                    // get the numer
                    ++i; // shift to the numer first digit
                    num = 0;
                    while (i < line.size() && isdigit(line[i])) {
                        num = num * 10 + (line[i++] - '0');
                    }
                    // set numer
                    currnum[1] = num;
                    ++i; // shift to denom first digit
                    // get and set denom
                    num = 0;
                    while (i < line.size() && isdigit(line[i])) {
                        num = num * 10 + (line[i++] - '0');
                    }
                    currnum[2] = num;
                } else { // other case - program should not enter this else block
                    ++i;
                }
                numbers.push_back(currnum);
            } else { // normal char
                ++i;
            }
        }
        int numer = 1, denom = 1;
        // loop over the numbers, and get the result
        for (int j = 0; j < numbers.size(); ++j) {
            vector<int> currnum = numbers[j];
            int currint = currnum[0], currnumer = currnum[1], currdenom = currnum[2];
            // case where just whole number
            if (currnumer == -1 && currdenom == -1) {
                numer *= currint;
            } else if (currint != -1 && currnumer != -1 && currdenom != -1) { // whole number with fraction
                numer *= ((currint * currdenom) + currnumer);
                denom *= currdenom;
            } else { // just fraction
                numer *= currnumer;
                denom *= currdenom;
            }
        }
        // simplify the fraction
        double div = gcd(numer, denom);
        numer /= div;
        denom /= div;
        // case where whole number
        if ((double) numer / denom == numer / denom) {
            cout << (numer / denom) << endl;
        } else { // case where not whole number or whole number with fraction
            if (numer < denom) { // just fraction
                cout << numer << "/" << denom << endl;
            } else { // whole number with fraction
                cout << (int) (numer) / (int) denom << "-" << ((int) numer % (int) denom) << "/" << denom << endl;
            }
        }
    }
    return 0;
}
