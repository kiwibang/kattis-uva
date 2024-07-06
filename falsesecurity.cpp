#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, string> chartocode;
    chartocode['A'] = ".-";
    chartocode['B'] = "-...";
    chartocode['C'] = "-.-.";
    chartocode['D'] = "-..";
    chartocode['E'] = ".";
    chartocode['F'] = "..-.";
    chartocode['G'] = "--.";
    chartocode['H'] = "....";
    chartocode['I'] = "..";
    chartocode['J'] = ".---";
    chartocode['K'] = "-.-";
    chartocode['L'] = ".-..";
    chartocode['M'] = "--";
    chartocode['N'] = "-.";
    chartocode['O'] = "---";
    chartocode['P'] = ".--.";
    chartocode['Q'] = "--.-";
    chartocode['R'] = ".-.";
    chartocode['S'] = "...";
    chartocode['T'] = "-";
    chartocode['U'] = "..-";
    chartocode['V'] = "...-";
    chartocode['W'] = ".--";
    chartocode['X'] = "-..-";
    chartocode['Y'] = "-.--";
    chartocode['Z'] = "--..";
    chartocode['_'] = "..--";
    chartocode['.'] = "---.";
    chartocode[','] = ".-.-";
    chartocode['?'] = "----";

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
    codetochar["..--"] = '_';
    codetochar["---."] = '.';
    codetochar[".-.-"] = ',';
    codetochar["----"] = '?';

    string curr;
    while (true) {
        cin >> curr;
        if (cin.eof()) {
            break;
        }
        string morsecode = "";
        string lengths = "";
        // make the morse code based on the input
        for (int i = 0; i < curr.size(); ++i) {
            morsecode += chartocode[curr[i]];
            lengths += (chartocode[curr[i]].size() + '0');
        }
        // reverse the numbers string
        reverse(lengths.begin(), lengths.end());
        // then translate
        int morseidx = 0, lenidx = 0;
        while (morseidx < morsecode.size()) {
            // get the length of the current code
            int currl = lengths[lenidx++] - '0';
            // get the code
            string currcode = morsecode.substr(morseidx, currl);
            // print the char
            cout << codetochar[currcode];
            // update the index
            morseidx += currl;
        }
        cout << endl;
    }
    return 0;
}
