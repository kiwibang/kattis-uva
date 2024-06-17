#include <bits/stdc++.h>
using namespace std;

map<char, string> hextobin;
map<string, string> modemap;

string getoperand(string op) {
    string oper;
    oper = hextobin[op[0]] + hextobin[op[1]] + hextobin[op[2]] + hextobin[op[3]];
    // get the mode
    string mode = modemap[oper.substr(0, 2)];
    // get the value
    int val = stoi(oper.substr(2, 14), nullptr, 2);
    return mode + to_string(val);
}

int main() {
    // create a mapping of hexa to binary digits
    hextobin['0'] = "0000";
    hextobin['1'] = "0001";
    hextobin['2'] = "0010";
    hextobin['3'] = "0011";
    hextobin['4'] = "0100";
    hextobin['5'] = "0101";
    hextobin['6'] = "0110";
    hextobin['7'] = "0111";
    hextobin['8'] = "1000";
    hextobin['9'] = "1001";
    hextobin['A'] = "1010";
    hextobin['B'] = "1011";
    hextobin['C'] = "1100";
    hextobin['D'] = "1101";
    hextobin['E'] = "1110";
    hextobin['F'] = "1111";
    // create mapping of opcode to actual instr
    map<char, string> opcodetoinstr;
    opcodetoinstr['0'] = "ADD";
    opcodetoinstr['1'] = "SUB";
    opcodetoinstr['2'] = "MUL";
    opcodetoinstr['3'] = "DIV";
    opcodetoinstr['4'] = "MOV";
    opcodetoinstr['5'] = "BREQ";
    opcodetoinstr['6'] = "BRLE";
    opcodetoinstr['7'] = "BRLS";
    opcodetoinstr['8'] = "BRGE";
    opcodetoinstr['9'] = "BRGR";
    opcodetoinstr['A'] = "BRNE";
    opcodetoinstr['B'] = "BR";
    opcodetoinstr['C'] = "AND";
    opcodetoinstr['D'] = "OR";
    opcodetoinstr['E'] = "XOR";
    opcodetoinstr['F'] = "NOT";

    modemap["00"] = "R";
    modemap["01"] = "$";
    modemap["10"] = "PC+";
    modemap["11"] = "";

    // read in the entire hexadecimal listing
    string listing = "", l;
    while (getline(cin, l)) {
        listing += l; 
    }
    // process the hexadecimal
    int idx = 0;
    while (idx < listing.length()) {
        // read in the instruction type
        char opcode = listing[idx++];
        string instr = opcodetoinstr[opcode];
        cout << instr << " ";
        // case where 1 operand only
        if (opcode == '5' || opcode == '6' || opcode == '7' || opcode == '8' || opcode == '9' || opcode == 'A' || opcode == 'B' || opcode == 'F') {
            string op1 = getoperand(listing.substr(idx, 4));
            idx += 4;
            cout << op1 << endl;
        } else if (opcode == 'C' || opcode == 'D' || opcode == 'E') { // case where 3 operand
            string op1 = getoperand(listing.substr(idx, 4));
            idx += 4;
            string op2 = getoperand(listing.substr(idx, 4));
            idx += 4;
            string op3 = getoperand(listing.substr(idx, 4));
            idx += 4;
            cout << op1 << "," << op2 << "," << op3 << endl;
        } else { // case where 2 operand
            string op1 = getoperand(listing.substr(idx, 4));
            idx += 4;
            string op2 = getoperand(listing.substr(idx, 4));
            idx += 4;
            cout << op1 << "," << op2 << endl;
        }
    }
    return 0;
}
