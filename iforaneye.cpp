#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string curr;
    unordered_map<string, char> dict;
    dict["at"] = '@';
    dict["and"] = '&';
    dict["one"] = '1';
    dict["won"] = '1';
    dict["to"] = '2';
    dict["too"] = '2';
    dict["two"] = '2';
    dict["for"] = '4';
    dict["four"] = '4';
    dict["bea"] = 'b';
    dict["be"] = 'b';
    dict["bee"] = 'b';
    dict["sea"] = 'c';
    dict["see"] = 'c';
    dict["eye"] = 'i';
    dict["oh"] = 'o';
    dict["owe"] = 'o';
    dict["are"] = 'r';
    dict["you"] = 'u';
    dict["why"] = 'y';
    while (n--) {
        getline(cin, curr);
        string topr = "", temp = "";
        for (int i = 0; i < curr.size(); ++i) {
            char c = curr[i];
            temp += c;
            while (temp.size() > 4) {
                topr += temp[0];
                temp.erase(0, 1);
            }
            if (temp.size() == 4) {
                string lowercased = "";
                for (char c : temp) {
                    if (isalpha(c) && isupper(c)) {
                        lowercased += tolower(c);
                    } else {
                        lowercased += c;
                    }
                }
                // case where four
                if (dict.find(lowercased) != dict.end()) {
                    if (isupper(temp[0])) {
                        topr += toupper(dict[lowercased]);
                    } else {
                        topr += toupper(dict[lowercased]);
                    }
                    temp = "";
                } if (dict.find(lowercased.substr(0, 3)) != dict.end()) {
                    if (isupper(temp[0])) {
                        topr += toupper(dict[lowercased.substr(0, 3)]);
                    } else {
                        topr += dict[lowercased.substr(0, 3)];
                    }
                    temp = temp.substr(3);
                } else if (dict.find(lowercased.substr(0, 2)) != dict.end()) {
                    if (isupper(temp[0])) {
                        topr += toupper(dict[lowercased.substr(0, 2)]);
                    } else {
                        topr += dict[lowercased.substr(0, 2)];
                    }
                    temp = temp.substr(2);
                } 
            }
            if (i == curr.size() - 1) {
                string lowercased = "";
                for (char c : temp) {
                    if (isalpha(c) && isupper(c)) {
                        lowercased += tolower(c);
                    } else {
                        lowercased += c;
                    }
                }
                if (temp.size() == 4) {
                    if (dict.find(lowercased) != dict.end()) { // size 4
                        if (isupper(temp[0])) {
                            topr += toupper(dict[lowercased]);
                        } else {
                            topr += dict[lowercased];
                        }
                    } else if (dict.find(lowercased.substr(0, 3)) != dict.end()) { // substr begin size 3
                        if (isupper(temp[0])) {
                            topr += toupper(dict[lowercased.substr(0, 3)]);
                        } else {
                            topr += dict[lowercased.substr(0, 3)];
                        }
                        topr += temp[3];
                    } else if (dict.find(lowercased.substr(1)) != dict.end()) { // substr end size 3
                        topr += temp[0];
                        if (isupper(temp[1])) {
                            topr += toupper(dict[lowercased.substr(1)]);
                        } else {
                            topr += dict[lowercased.substr(1)];
                        }
                    } else if (dict.find(lowercased.substr(0, 2)) != dict.end()) { // substr begin size 2
                        if (isupper(temp[0])) {
                            topr += toupper(dict[lowercased.substr(0, 2)]);
                        } else {
                            topr += dict[lowercased.substr(0, 2)];
                        }
                        topr += temp.substr(2);
                    } else if (dict.find(lowercased.substr(1, 2)) != dict.end()) { // substr 1, 2 size 2
                        topr += temp[0];
                        if (isupper(temp[1])) {
                            topr += toupper(dict[lowercased.substr(1, 2)]);
                        } else {
                            topr += dict[lowercased.substr(1, 2)];
                        }
                        topr += temp[3];
                    } else if (dict.find(lowercased.substr(2)) != dict.end()) { // substr 2, 3 size 2
                        topr += temp.substr(0, 2);
                        if (isupper(temp[2])) {
                            topr += toupper(dict[lowercased.substr(2)]);
                        } else {
                            topr += dict[lowercased.substr(2)];
                        }
                    } else { // none
                        topr += temp;
                    }
                } else if (temp.size() == 3) {
                    if (dict.find(lowercased) != dict.end()) {
                        if (isupper(temp[0])) {
                            topr += toupper(dict[lowercased]);
                        } else {
                            topr += dict[lowercased];
                        }
                    } else if (dict.find(lowercased.substr(0, 2)) != dict.end()) {
                        if (isupper(temp[0])) {
                            topr += toupper(dict[lowercased.substr(0, 2)]);
                        } else {
                            topr += dict[lowercased.substr(0, 2)];
                        }
                        topr += temp[2];
                    } else if (dict.find(lowercased.substr(1)) != dict.end()) {
                        topr += temp[0];
                        if (isupper(temp[1])) {
                            topr += toupper(dict[lowercased.substr(1)]);
                        } else {
                            topr += dict[lowercased.substr(1)];
                        }
                    } else {
                        topr += temp;
                    }
                } else if (temp.size() == 2) {
                    if (dict.find(lowercased) != dict.end()) {
                        if (isupper(temp[0])) {
                            topr += toupper(dict[lowercased.substr(1)]);
                        } else {
                            topr += dict[lowercased.substr(1)];
                        }
                    } else {
                        topr += temp;
                    }
                } else if (temp.size() == 1) {
                    topr += temp[0];
                }
            }
        }
        cout << topr << endl;
    }
    return 0;
}

