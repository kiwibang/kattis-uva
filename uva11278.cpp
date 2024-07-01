#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, char> qwertytodvorak;
    // normal keyboard
    // first row
    qwertytodvorak['`'] = '`';
    qwertytodvorak['1'] = '1';
    qwertytodvorak['2'] = '2';
    qwertytodvorak['3'] = '3';
    qwertytodvorak['4'] = 'q';
    qwertytodvorak['5'] = 'j';
    qwertytodvorak['6'] = 'l';
    qwertytodvorak['7'] = 'm';
    qwertytodvorak['8'] = 'f';
    qwertytodvorak['9'] = 'p';
    qwertytodvorak['0'] = '/';
    qwertytodvorak['-'] = '[';
    qwertytodvorak['='] = ']';
    // second row
    qwertytodvorak['q'] = '4';
    qwertytodvorak['w'] = '5';
    qwertytodvorak['e'] = '6';
    qwertytodvorak['r'] = '.';
    qwertytodvorak['t'] = 'o';
    qwertytodvorak['y'] = 'r';
    qwertytodvorak['u'] = 's';
    qwertytodvorak['i'] = 'u';
    qwertytodvorak['o'] = 'y';
    qwertytodvorak['p'] = 'b';
    qwertytodvorak['['] = ';';
    qwertytodvorak[']'] = '=';
    qwertytodvorak['\\'] = '\\';
    // third row
    qwertytodvorak['a'] = '7';
    qwertytodvorak['s'] = '8';
    qwertytodvorak['d'] = '9';
    qwertytodvorak['f'] = 'a';
    qwertytodvorak['g'] = 'e';
    qwertytodvorak['h'] = 'h';
    qwertytodvorak['j'] = 't';
    qwertytodvorak['k'] = 'd';
    qwertytodvorak['l'] = 'c';
    qwertytodvorak[';'] = 'k';
    qwertytodvorak['\''] = '-';
    // fourth row
    qwertytodvorak['z'] = '0';
    qwertytodvorak['x'] = 'z';
    qwertytodvorak['c'] = 'x';
    qwertytodvorak['v'] = ',';
    qwertytodvorak['b'] = 'i';
    qwertytodvorak['n'] = 'n';
    qwertytodvorak['m'] = 'w';
    qwertytodvorak[','] = 'v';
    qwertytodvorak['.'] = 'g';
    qwertytodvorak['/'] = '\'';

    // shift-modified
    // first row
    qwertytodvorak['~'] = '~';
    qwertytodvorak['!'] = '!';
    qwertytodvorak['@'] = '@';
    qwertytodvorak['#'] = '#';
    qwertytodvorak['$'] = 'Q';
    qwertytodvorak['%'] = 'J';
    qwertytodvorak['^'] = 'L';
    qwertytodvorak['&'] = 'M';
    qwertytodvorak['*'] = 'F';
    qwertytodvorak['('] = 'P';
    qwertytodvorak[')'] = '?';
    qwertytodvorak['_'] = '{';
    qwertytodvorak['+'] = '}';
    // second row
    qwertytodvorak['Q'] = '$';
    qwertytodvorak['W'] = '%';
    qwertytodvorak['E'] = '^';
    qwertytodvorak['R'] = '>';
    qwertytodvorak['T'] = 'O';
    qwertytodvorak['Y'] = 'R';
    qwertytodvorak['U'] = 'S';
    qwertytodvorak['I'] = 'U';
    qwertytodvorak['O'] = 'Y';
    qwertytodvorak['P'] = 'B';
    qwertytodvorak['{'] = ':';
    qwertytodvorak['}'] = '+';
    qwertytodvorak['|'] = '|';
    // third row
    qwertytodvorak['A'] = '&';
    qwertytodvorak['S'] = '*';
    qwertytodvorak['D'] = '(';
    qwertytodvorak['F'] = 'A';
    qwertytodvorak['G'] = 'E';
    qwertytodvorak['H'] = 'H';
    qwertytodvorak['J'] = 'T';
    qwertytodvorak['K'] = 'D';
    qwertytodvorak['L'] = 'C';
    qwertytodvorak[':'] = 'K';
    qwertytodvorak['\"'] = '_';
    // fourth row
    qwertytodvorak['Z'] = ')';
    qwertytodvorak['X'] = 'Z';
    qwertytodvorak['C'] = 'X';
    qwertytodvorak['V'] = '<';
    qwertytodvorak['B'] = 'I';
    qwertytodvorak['N'] = 'N';
    qwertytodvorak['M'] = 'W';
    qwertytodvorak['<'] = 'V';
    qwertytodvorak['>'] = 'G';
    qwertytodvorak['?'] = '\"';

    string line;
    while (true) {
        getline(cin, line);
        if (cin.eof()) {
            break;
        }
        for (int i = 0; i < line.size(); ++i) {
            if (isspace(line[i])) {
                cout << line[i];
                continue;
            }
            cout << qwertytodvorak[line[i]];
        }
        cout << endl;
    }
    return 0;
}
