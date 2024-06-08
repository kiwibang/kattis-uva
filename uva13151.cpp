#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        string temp;
        int ival, t;
        cin >> temp >> t;
        if (temp[0] == '0' && temp[1] == 'x') {
            ival = stoi(temp, nullptr, 16);
        } else if (temp[0] == '0') {
            ival = stoi(temp, nullptr, 8);
        } else {
            ival = stoi(temp, nullptr, 10);
        }

        if (ival == 0 && t == 0) {
            return 0;
        }
        int prevexp = ival, currexp;
        int marks = 0;
        for (int i = 0; i < t; ++i) {
            string instr;
            int v;
            cin >> instr >> v;
            if (instr == "++i") {
                // not first one
                // get the expected value
                currexp = prevexp + 1;
                // if the same
                if (currexp == v) {
                    // increase marks
                    ++marks;
                    // increase the base
                    ++prevexp;
                } else {
                    // else, change the base
                    prevexp = v;
                }
            } else if (instr == "i++") {
                currexp = prevexp;
                if (currexp == v) {
                    ++marks;
                    // post-increment
                    ++prevexp;
                } else {
                    prevexp = v + 1;
                }
            } else if (instr == "i--") {
                currexp = prevexp;
                if (currexp == v) {
                    ++marks;
                    // post-decrement
                    --prevexp;
                } else {
                    prevexp = v - 1;
                }
            } else if (instr == "--i") {
                // get the expected value
                currexp = prevexp - 1;
                // if the same
                if (currexp == v) {
                    // increase marks
                    ++marks;
                    // decrease the base
                    --prevexp;
                } else {
                    // else, change the base
                    prevexp = v;
                }
            } else if (instr == "i") {
                // get the expected value
                currexp = prevexp;
                if (currexp == v) {
                    ++marks;
                } else {
                    prevexp = v;
                }
            }
        }
        cout << marks << endl;
    }
    return 0;
}
