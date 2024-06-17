#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, char> codetochar;
    codetochar[".-"] = 'A';
    codetochar["-..."] = 'B';
    codetochar["-.-."] = 'C';
    codetochar["-.."] = 'D';
    codetochar["."] = 'E';
    codetochar["..-."] = 'F';
    codetochar["--."] = 'G';
    codetochar["...."] = 'H';
    codetochar[".."] = 'I';
    codetochar[".---"] = 'J';
    codetochar["-.-"] = 'K';
    codetochar[".-.."] = 'L';
    codetochar["--"] = 'M';
    codetochar["-."] = 'N';
    codetochar["---"] = 'O';
    codetochar[".--."] = 'P';
    codetochar["--.-"] = 'Q';
    codetochar[".-."] = 'R';
    codetochar["..."] = 'S';
    codetochar["-"] = 'T';
    codetochar["..-"] = 'U';
    codetochar["...-"] = 'V';
    codetochar[".--"] = 'W';
    codetochar["-..-"] = 'X';
    codetochar["-.--"] = 'Y';
    codetochar["--.."] = 'Z';
    codetochar["-----"] = '0';
    codetochar[".----"] = '1';
    codetochar["..---"] = '2';
    codetochar["...--"] = '3';
    codetochar["....-"] = '4';
    codetochar["....."] = '5';
    codetochar["-...."] = '6';
    codetochar["--..."] = '7';
    codetochar["---.."] = '8';
    codetochar["----."] = '9';
    codetochar[".-.-.-"] = '.';
    codetochar["--..--"] = ',';
    codetochar["..--.."] = '?';
    codetochar[".----."] = '\'';
    codetochar["-.-.--"] = '!';
    codetochar["-..-."] = '/';
    codetochar["-.--."] = '(';
    codetochar["-.--.-"] = ')';
    codetochar[".-..."] = '&';
    codetochar["---..."] = ':';
    codetochar["-.-.-."] = ';';
    codetochar["-...-"] = '=';
    codetochar[".-.-."] = '+';
    codetochar["-....-"] = '-';
    codetochar["..--.-"] = '_';
    codetochar[".-..-."] = '\"';
    codetochar[".--.-."] = '@';
    int t;
    string l;
    getline(cin, l);
    istringstream iss(l);
    iss >> t;
    for (int tc = 1; tc <= t; ++tc) {
        if (tc > 1) {
            cout << endl;
        }
        cout << "Message #" << tc << endl;
        string temp;
        getline(cin, temp);
        string currchar = "";
        int consecspaces = 0;
        for (int i = 0; i < temp.size(); ++i) {
            if (temp[i] == ' ') { 
                ++consecspaces;
            } else { // normal char
                if (consecspaces == 1 || consecspaces == 2) {
                    cout << codetochar[currchar];
                    currchar = "";
                }
                if (consecspaces == 2) {
                    cout << " ";
                }
                consecspaces = 0;
                currchar.push_back(temp[i]);
            }
        }
        // print out the last char
        cout << codetochar[currchar] << endl;
    }
    return 0;
}
