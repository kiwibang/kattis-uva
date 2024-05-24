#include <bits/stdc++.h>
using namespace std;

long long getVal(string card, char dom);
int main() {
    int n;
    char b;
    cin >> n >> b;
    long long res = 0;
    for (int i = 0; i < 4 * n; ++i) {
        string card;
        cin >> card;
        res += getVal(card, b);
    }
    cout << res << endl;
    return 0;
}

long long getVal(string card, char dom) {
    char num = card[0];
    char suit = card[1];
    if (suit == dom) {
        switch(num) {
            case 'A':
                return 11;
            case 'K':
                return 4;
            case 'Q':
                return 3;
            case 'J':
                return 20;
            case 'T':
                return 10;
            case '9':
                return 14;
            case '8':
                return 0;
            case '7':
                return 0;
            default:
                return 0;
        }
    } else {
        switch(num) {
            case 'A':
                return 11;
            case 'K':
                return 4;
            case 'Q':
                return 3;
            case 'J':
                return 2;
            case 'T':
                return 10;
            case '9':
                return 0;
            case '8':
                return 0;
            case '7':
                return 0;
            default:
                return 0;
        }
    }
}
