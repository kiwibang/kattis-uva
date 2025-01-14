#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, lim;
    cin >> a >> b;
    lim = (b >> 1) + 1;
    // generate the b / 2 words
    vector<string> words;
    string curr = "", temp;
    for (char cc = 'a'; cc <= 'z'; ++cc) {
        temp = curr;
        temp += cc;
        words.push_back(temp);
    }
    while (true) {
        if (words.size() >= lim) break;
        for (int i = 0; i < words.size(); ++i) {
            string currword = words[i];
            for (char cc = 'a'; cc <= 'z'; ++cc) {
                string temp = currword;
                temp.push_back(cc);
                words.push_back(temp);
                if (words.size() == lim) goto write;
            }
        }
    }
    // then write the essay using A words
    write:
    for (int i = 0; i < b; ++i) {
        cout << words[i % words.size()];
        if (i < b - 1) cout << " ";
    }
    cout << endl;
    return 0;
}

