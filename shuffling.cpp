#include <bits/stdc++.h>
using namespace std;

int shuffleCards(int n, bool isOut);
bool isEqual(int a[], int a1, int b[], int a2);
int main() {
    int n;
    string cmd;
    cin >> n >> cmd;
    if (cmd == "in") {
        cout << shuffleCards(n, false) << endl;
    } else if (cmd == "out") {
        cout << shuffleCards(n, true) << endl;
    }
    return 0;
}

bool isEqual(int a[], int a1, int b[], int a2) {
    if (a1 != a2) {
        return false;
    }
    for (int i = 0; i < a1; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int shuffleCards(int n, bool isOut) {
    // create array for comparison
    int original[n];
    for (int i = 1; i <= n; ++i) {
        original[i - 1] = i;
    }
    // create array to shuffle
    int cards[n];
    int fl, sl;
    // split the deck
    // if the card deck has an odd number of cards
    if ((n & 1) == 1) {
        if (isOut) {
            fl = (n / 2) + 1;
            sl = n / 2;
        } else {
            fl = n / 2;
            sl = (n / 2) + 1;
        }
    } else { // if the card deck has an even number of cards
        fl = n / 2;
        sl = n / 2;
    }
    int firstHalf[fl];
    int secondHalf[sl];
    // fill the arrays
    for (int i = 1; i <= n; ++i) {
        if (i <= fl) {
            firstHalf[i - 1] = i;
        } else {
            secondHalf[i - fl - 1] = i;
        }
    }
    int res = 0;
    // simulate shuffles
    while (!isEqual(original, n, cards, n)) {
        // then shuffle based on in and out 
        int fidx = 0;
        int sidx = 0;
        int idx = 0;
        bool firstTurn = isOut;
        // 1 shuffle
        while (idx < n && (fidx < fl || sidx < sl)) {
            if (fidx >= fl) {
                cards[idx++] = secondHalf[sidx++];
                continue;
            }
            if (sidx >= sl) {
                cards[idx++] = firstHalf[fidx++];
                continue;
            }
            if (firstTurn) {
                cards[idx++] = firstHalf[fidx++];
            } else {
                cards[idx++] = secondHalf[sidx++];
            }
            firstTurn = !firstTurn;
        }
        // update firsthalf and secondhalf for the next shuffle
        for (int i = 1; i <= n; ++i) {
            if (i <= fl) {
                firstHalf[i - 1] = cards[i - 1];
            } else {
                secondHalf[i - fl - 1] = cards[i - 1];
            }
        }
        ++res;
    }
    return res;
}
