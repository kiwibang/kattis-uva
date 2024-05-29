#include <bits/stdc++.h>
using namespace std;

// return 0 for white, 1 for black
int getColour(int x, int y) {
    if ((x & 1) == 1) {
        if ((y & 1) == 1) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if ((y & 1) == 1) {
            return 0;
        } else {
            return 1;
        }
    }
}

int main() {
    // map to translate chars to coordinates
    map<char, int> mp;
    mp['a'] = 0;
    mp['b'] = 1;
    mp['c'] = 2;
    mp['d'] = 3;
    mp['e'] = 4;
    mp['f'] = 5;
    mp['g'] = 6;
    mp['h'] = 7;
    // read in the input
    string white, black;
    getline(cin, white);
    getline(cin, black);
    // process the input
    white.erase(0, 7);
    black.erase(0, 7);
    size_t pos = 0;
    string currPiece;
    vector<vector<char> > board = vector<vector<char> >(8, vector<char>(8, '*'));
    // add the white pieces to the grid
    while ((pos = white.find(",")) != string::npos) {
        currPiece = white.substr(0, pos);
        white.erase(0, pos + 1);
        // get the piece ID
        char piece = currPiece.size() == 2 ? 'P' :currPiece[0];
        // get the col of the current piece
        int col = currPiece.size() == 2 ? mp[currPiece[0]] : mp[currPiece[1]];
        // get the row of the current piece
        int row = currPiece.size() == 2 ? (8 - (currPiece[1] - '0')) : (8 - (currPiece[2] - '0'));
        // update the board
        board[row][col] = piece;
    }
    if (white.size() == 3) {
        board[(8 - (white[2] - '0'))][mp[white[1]]] = white[0];
    } else if (white.size() == 2) {
        board[(8 - (white[1] - '0'))][mp[white[0]]] = 'P';
    }
    // add the black pieces to the grid
    while ((pos = black.find(",")) != string::npos) {
        currPiece = black.substr(0, pos);
        black.erase(0, pos + 1);
        // get the piece ID
        char piece = currPiece.size() == 2 ? 'P' : currPiece[0];
        // get the col of the current piece
        int col = currPiece.size() == 2 ? mp[currPiece[0]] : mp[currPiece[1]];
        // get the row of the current piece
        int row = currPiece.size() == 2 ? (8 - (currPiece[1] - '0')) : (8 - (currPiece[2] - '0'));
        // update the board
        board[row][col] = tolower(piece);
    }
    if (black.size() == 3) {
        board[(8 - (black[2] - '0'))][mp[black[1]]] = tolower(black[0]);
    } else if (black.size() == 2) {
        board[(8 - (black[1] - '0'))][mp[black[0]]] = 'p';
    }
    // then print the board -_-
    cout << "+---+---+---+---+---+---+---+---+" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << "|";
        for (int j = 0; j < 8; ++j) {
            int t = getColour(i, j);
            if (t == 1) {
                if (board[i][j] == '*') {
                    cout << "...|";
                } else {
                    cout << "." << board[i][j] << ".|";
                }   
            } else {
                if (board[i][j] == '*') {
                    cout << ":::|";
                } else {
                    cout << ":" << board[i][j] << ":|";
                } 
            }
        }
        cout << endl;
        cout << "+---+---+---+---+---+---+---+---+" << endl;
    }
    return 0;
}
