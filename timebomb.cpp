#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> asciitoint;
    asciitoint["*** * * * * * * *** "] = 0;
    asciitoint["  *   *   *   *   * "] = 1;
    asciitoint["***   * *** *   *** "] = 2;
    asciitoint["***   * ***   * *** "] = 3;
    asciitoint["* * * * ***   *   * "] = 4;
    asciitoint["*** *   ***   * *** "] = 5;
    asciitoint["*** *   *** * * *** "] = 6;
    asciitoint["***   *   *   *   * "] = 7;
    asciitoint["*** * * *** * * *** "] = 8;
    asciitoint["*** * * ***   * *** "] = 9;
    // read in the input
    vector<string> input;
    string curr;
    for (int i = 0; i < 5; ++i) {
        getline(cin, curr);
        curr += " ";
        input.push_back(curr);
    } 
    vector<string> strdigits(input[0].size() / 4, "");
    for (int i = 0; i < input.size(); ++i) {
        for (int j = 0; j < input[i].size(); j += 4) {
            strdigits[j / 4] += input[i].substr(j, 4);
        }
    }
    // get the input
    int num = 0;
    bool valid = true;
    for (int i = 0; i < strdigits.size(); ++i) {
        if (asciitoint.find(strdigits[i]) == asciitoint.end()) {
            valid = false;
            break;
        }
        num = num * 10 + asciitoint[strdigits[i]];
    }
    if (!valid || num % 6 != 0) {
        cout << "BOOM!!" << endl;
    } else {
        cout << "BEER!!" << endl;
    }
    return 0;
}
