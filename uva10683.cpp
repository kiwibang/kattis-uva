#include <bits/stdc++.h>
using namespace std;

int parseint(string t) {
    int res;
    istringstream is(t);
    is >> res;
    return res;
}

int main() {
    string time;
    while (cin >> time) {
        int h = parseint(time.substr(0, 2));
        int m = parseint(time.substr(2, 2));
        int s = parseint(time.substr(4, 2));
        int c = parseint(time.substr(6, 2));
        // cout << hh << " " << mm << " " << ss << " " << cc << endl;
        long long milliseconds = h * 3600000LL + m * 60000LL + s * 1000LL + c * 10;
		h = milliseconds / 8640000LL;
		milliseconds %= 8640000LL;

		m = milliseconds / 86400LL;
		milliseconds %= 86400LL;

		s = milliseconds / 864;
		milliseconds %= 864;

		c = milliseconds * 100 / 864;

        cout << h << setw(2) << setfill('0') << m << setw(2) << setfill('0') << s << setw(2) << setfill('0') << c << endl;
    }
    return 0;
}
