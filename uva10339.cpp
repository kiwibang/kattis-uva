#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int k, m;
        cin >> k >> m;
        if (cin.eof()) {
            break;
        }
        // print k and m
        cout << k << " " << m << " ";
        // compute the next time that they will be the same
		unsigned int gap = max(m, k) - min(m, k);

		unsigned int seconds = (43200 * (86400 - k) / gap) % 43200 + 30;
		// Seconds converted to hours.
		int hour = seconds / 3600 % 12;
		// Seconds converted to minutes.
		int minutes = seconds / 60 % 60;
        cout << setfill('0') << setw(2) << (hour ? hour : 12) << ":" << setfill('0') << setw(2) << minutes << endl;
    }
    return 0;
}
