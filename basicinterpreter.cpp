#include <bits/stdc++.h>
using namespace std;

int getval(string& token, vector<int>& variables) {
    return isalpha(token[0]) ? variables[token[0] - 'A'] : stoi(token);
}

int getexprval(vector<string>& tokens, vector<int>& variables) {
    if (tokens.size() == 1) {
        return getval(tokens[0], variables);    
    } else {
        int a = getval(tokens[0], variables);
        int b = getval(tokens[2], variables);
        if (tokens[1] == "+") {
            return a + b;
        } else if (tokens[1] == "-") {
            return a - b;
        } else if (tokens[1] == "*") {
            return a * b;
        } else if (tokens[1] == "/") {
            return a / b;
        } else {
            return 0;
        }
    }
}

bool evalcond(string& a, string& cond, string& b, vector<int>& variables) {
    int v1 = getval(a, variables), v2 = getval(b, variables);
    if (cond == "=") {
        return v1 == v2;
    } else if (cond == ">") {
        return v1 > v2;
    } else if (cond == "<") {
        return v1 < v2;
    } else if (cond == "<>") {
        return v1 != v2;
    } else if (cond == "<=") {
        return v1 <= v2;
    } else if (cond == ">=") {
        return v1 >= v2;
    } else {
        return false;
    }
}

int main() {
    // read in the commands, and sort them
    vector<int> labels;
    unordered_map<int, string> labeltocmd;
    string rawcmd, cmd;
    int label;
    while (true) {
        getline(cin, rawcmd);
        if (cin.eof()) break;
        istringstream iss(rawcmd);
        label = stoi(rawcmd.substr(0, rawcmd.find(' ')));
        cmd = rawcmd.substr(rawcmd.find(' ') + 1);
        labels.push_back(label);
        labeltocmd[label] = cmd;
    }
    sort(labels.begin(), labels.end());
    // process the commands in increasing order of label value
    unordered_map<int, int> labeltoidx;
    for (int i = 0; i < labels.size(); ++i) {
        labeltoidx[labels[i]] = i;
    }
    // unless there is a goto statement
    int currlabel = 0, endlabel = labels.size();
    vector<int> variables(26, 0);
    while (currlabel < endlabel) {
        // get the command
        string ccmd = labeltocmd[labels[currlabel]], type;
        // parse the command
        istringstream iss(ccmd);
        iss >> type; // get the type of command
        // break down into cases
        if (type == "LET") {
            // consists of <variable> = <ARITHMETIC_STATEMENT>
            string var, eq;
            string temp;
            vector<string> arthtokens;
            iss >> var >> eq;
            while (iss >> temp) {
                arthtokens.push_back(temp);
            }
            variables[var[0] - 'A'] = getexprval(arthtokens, variables);
        } else if (type == "IF") {
            string var1, var2, cond, temp;
            int label;
            iss >> var1 >> cond >> var2 >> temp >> temp >> label;
            if (evalcond(var1, cond, var2, variables)) {
                currlabel = labeltoidx[label];
                goto skip;
            }
        } else if (type == "PRINT") {
            string topr = ccmd.substr(ccmd.find(' ') + 1);
            if (topr[0] == '\"') {
                cout << topr.substr(1, topr.size() - 2);
            } else {
                cout << variables[topr[0] - 'A'];
            }
        } else if (type == "PRINTLN") {
            string topr = ccmd.substr(ccmd.find(' ') + 1);
            if (topr[0] == '\"') {
                cout << topr.substr(1, topr.size() - 2) << endl;
            } else {
                cout << variables[topr[0] - 'A'] << endl;
            }
        }
        // update label
        ++currlabel;
        skip:
    }
    return 0;
}

