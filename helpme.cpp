#include <bits/stdc++.h>
using namespace std;

int compareWhite(string a, string b) {
    if (a == b) {
        return false;
    }
    map<char, int> mp;
    mp['K'] = 0;
    mp['Q'] = 1;
    mp['R'] = 2;
    mp['B'] = 3;
    mp['N'] = 4;

    if (a.size() > b.size()) { // a is not pawn, b is pawn
        return true;
    }
    if (a.size() < b.size()) { // a is pawn, b is not pawn
        return false;
    } 
    if (a.size() == 2) { // a and b both pawns
        if (a[1] == b[1]) { // on same row
            return a[0] < b[0];
        } 
        // smaller row number wins
        return a[1] < b[1];
    }
    if (mp[a[0]] == mp[b[0]]) { // same rank
        if (a[2] == b[2]) { // on same row
            return a[1] < b[1];
        }
        // smaller row number wins
        return a[2] < b[2];
    }
    // higher priority suit wins
    return mp[a[0]] < mp[b[0]];
}

int compareBlack(string a, string b) {
    if (a == b) {
        return false;
    }
    map<char, int> mp;
    mp['K'] = 0;
    mp['Q'] = 1;
    mp['R'] = 2;
    mp['B'] = 3;
    mp['N'] = 4;

    if (a.size() > b.size()) { // a is not pawn, b is pawn
        return true;
    }
    if (a.size() < b.size()) { // a is pawn, b is not pawn
        return false;
    } 
    if (a.size() == 2) { // a and b both pawns
        if (a[1] == b[1]) { // on same row
            // smaller col number wins
            return a[0] < b[0];
        } 
        // different row, larger row number wins
        return a[1] > b[1];
    }
    if (mp[a[0]] == mp[b[0]]) { // same suit
        if (a[2] == b[2]) { // same row
            // smaller col number wins
            return a[1] < b[1];
        }
        // different row => larger row number wins
        return a[2] > b[2];
    }
    // higher priority suit wins
    return mp[a[0]] < mp[b[0]];
}

int main() {
    map<int, char> inv;
    inv[0] = 'a';
    inv[1] = 'b';
    inv[2] = 'c';
    inv[3] = 'd';
    inv[4] = 'e';
    inv[5] = 'f';
    inv[6] = 'g';
    inv[7] = 'h';
    string line;
    cin >> line;
    vector<string> whitePieces, blackPieces;
    for (int i = 0; i < 8; ++i) {
        cin >> line;
        for (int j = 0; j < line.size(); j += 4) {
            // get the char
            char piece = line[j + 2];
            if (!isalpha(piece)) {
                continue;
            }
            // convert coordinates to the chess notation
            char row = (8 - i) + '0';
            char col = inv[j / 4];
            string currPiece = "";
            // convert to string
            if (piece != 'p' && piece != 'P') {
                currPiece.push_back(toupper(piece));
            }
            currPiece.push_back(col);
            currPiece.push_back(row);
            if (isupper(piece)) { // white player
                whitePieces.push_back(currPiece);
            } else {
                blackPieces.push_back(currPiece);
            }
        }
        cin >> line;
    }
    sort(whitePieces.begin(), whitePieces.end(), compareWhite);
    sort(blackPieces.begin(), blackPieces.end(), compareBlack);
    cout << "White: ";
    for (int i = 0; i < whitePieces.size(); ++i) {
        cout << whitePieces[i];
        if (i != whitePieces.size() - 1) {
            cout << ",";
        }
    }
    cout << endl;
    cout << "Black: ";
    for (int i = 0; i < blackPieces.size(); ++i) {
        cout << blackPieces[i];
        if (i != blackPieces.size() - 1) {
            cout << ",";
        }
    }
    cout << endl;
    return 0;
}
