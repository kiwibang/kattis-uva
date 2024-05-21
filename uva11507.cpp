#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, map<string, string> > bs;
	bs["+x"]["+y"] = "+y";
	bs["+x"]["-y"] = "-y";
	bs["+x"]["+z"] = "+z";
	bs["+x"]["-z"] = "-z";
	bs["-x"]["+y"] = "-y";
	bs["-x"]["-y"] = "+y";
	bs["-x"]["+z"] = "-z";
	bs["-x"]["-z"] = "+z";
	bs["+y"]["+y"] = "-x";
	bs["+y"]["-y"] = "+x";
	bs["+y"]["+z"] = "+y";
	bs["+y"]["-z"] = "+y";
	bs["-y"]["+y"] = "+x";
	bs["-y"]["-y"] = "-x";
	bs["-y"]["+z"] = "-y";
	bs["-y"]["-z"] = "-y";
	bs["+z"]["+y"] = "+z";
	bs["+z"]["-y"] = "+z";
	bs["+z"]["+z"] = "-x";
	bs["+z"]["-z"] = "+x";
	bs["-z"]["+y"] = "-z";
	bs["-z"]["-y"] = "-z";
	bs["-z"]["+z"] = "+x";
	bs["-z"]["-z"] = "-x";
    while (true) {
        int l;
        cin >> l;
        if (l == 0) {
            return 0;
        }
        string w = "+x";
        string d;
        for (long long i = 0; i < l - 1; ++i) {
            cin >> d;
            if (d != "No") {
                w = bs[w][d];
            }
        }
        cout << w << endl;
    }
    return 0;
}
