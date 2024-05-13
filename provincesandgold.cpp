#include <iostream>
using namespace std;

int main() {
    int g, s, c;
    scanf("%d %d %d", &g, &s, &c);
    // get the total buying power that the man has
    int bp = g * 3 + s * 2 + c;
    if (bp >= 2) {
        if (bp >= 8) {
            cout << "Province or ";
        } else if (bp >= 5) {
            cout << "Duchy or ";
        } else {
            cout << "Estate or ";
        }
    }
    if (bp >= 6) {
        cout << "Gold" << endl;
    } else if (bp >= 3) {
        cout << "Silver" << endl;
    } else {
        cout << "Copper" << endl;
    }
    return 0;
}
