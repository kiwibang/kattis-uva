#include <bits/stdc++.h>
using namespace std;

// its raining WA - i give up; credits: https://github.com/victormarcilio/competitive-programming/blob/main/uva327.cpp
int main() {
    // char arrays that act as strings. set to 200 to prevent out of bounds
    char input[200], trimmed[200];
    while (gets(input)) {
        map<char, int> m;
        printf("Expression: %s\n", input);
        int k = 0;
        for (int i = 0; input[i]; ++i) {
            if (!isspace(input[i]))
                trimmed[k++] = input[i];
        }
        trimmed[k] = 0;
        vector<int> vals;
        int sign = 1;
        for (int i = 0; trimmed[i]; ++i) {
            if (trimmed[i] == '-' && trimmed[i + 1] == '-') { // pre-decrement
                m[trimmed[i + 2]] = trimmed[i + 2] - 'a';
                vals.push_back(sign * m[trimmed[i + 2]]);
                i += 2;
            } else if (trimmed[i] == '+' && trimmed[i + 1] == '+') { // pre-increment
                m[trimmed[i + 2]] = trimmed[i + 2] - 'a' + 2;
                vals.push_back(sign * m[trimmed[i + 2]]);
                i += 2;
            } else if (trimmed[i] == '+') { // binary add
                sign = 1;
            } else if (trimmed[i] == '-') { // binary subtract
                sign = -1;
            } else if (trimmed[i + 1] == '-' && trimmed[i + 2] == '-') { // post-decrement
                vals.push_back(sign * (trimmed[i] - 'a' + 1));
                m[trimmed[i]] = trimmed[i] - 'a';
                i += 2;
            } else if (trimmed[i + 1] == '+' && trimmed[i + 2] == '+') { // post-increment
                vals.push_back(sign * (trimmed[i] - 'a' + 1));
                m[trimmed[i]] = trimmed[i] - 'a' + 2;
                i += 2;
            } else { // normal
                m[trimmed[i]] = trimmed[i] - 'a' + 1;
                vals.push_back(sign * m[trimmed[i]]);
            }
        }
        int res = 0;
        for (int i : vals) {
            res += i;
        }
        printf("    value = %d\n", res);
        for (auto it : m) {
            printf("    %c = %d\n", it.first, it.second);
        }
    }
    return 0;
}

// WA code: cant find the error so i give up 
// int main() {
//     // loop over the testcases
//     string curr;
//     while (getline(cin, curr)) {
//         // prepare a map that holds the value of the variables used in the current expression
//         map<char, int> varandval;
//         // remove spaces
//         string tt = "";
//         for (int i = 0; i < curr.size(); ++i) {
//             if (curr[i] == ' ') {
//                 continue;
//             }
//             tt.push_back(curr[i]);
//         }
//         vector<int> vals;
//         int sign = 1;
//         for (int i = 0; i < tt.size(); ++i) {
//             if (i < tt.size() - 1 && tt[i] == '-' && tt[i] == '-') {
//                 varandval[tt[i + 2]]
//             }
//         }
//         cout << "Expression: " << curr << endl;
//         cout << "    value = " << ops.top() << endl; 
//         for (char i = 'a'; i <= 'z'; ++i) {
//             if (varandval.find(i) != varandval.end()) {
//                 cout << "    " << i << " = " << varandval[i] << endl;
//             }
//         }
//     }
//     return 0;
// }
