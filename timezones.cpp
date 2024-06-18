#include <bits/stdc++.h>
using namespace std;

int hp(int hr, int mn, double src, double tg, string tod) {
    // compute the delta to add on to the current timing
    double delta = -src + tg;
    int mins = 0;
    if (hr == 12 && mn == 0) {
        mins = 12 * 60;
    } else if (hr == 0 && mn == 0) {
        mins = 0;
    } else {
        mins = hr * 60 + mn;
        if (hr == 12 && tod == "a.m.") {
            mins = mn;
        } else if (hr < 12 && tod == "p.m.") {
            mins += 12 * 60;
        }
    }
    mins += delta * 60.0;
    mins = (mins + 24 * 60) % (24 * 60);
    return mins;
}

// idea: convert the source time into utc, then from utc into second time zone
// conversion: delta = - source buffer + target buffer; time + delta
int main() {
    // create a mapping of timezones to adjustments
    map<string, double> timeztobuffer;
    timeztobuffer["UTC"] = 0.0;
    timeztobuffer["GMT"] = 0.0;
    timeztobuffer["BST"] = 1.0;
    timeztobuffer["IST"] = 1.0;
    timeztobuffer["WET"] = 0.0;
    timeztobuffer["WEST"] = 1.0;
    timeztobuffer["CET"] = 1.0;
    timeztobuffer["CEST"] = 2.0;
    timeztobuffer["EET"] = 2.0;
    timeztobuffer["EEST"] = 3.0;
    timeztobuffer["MSK"] = 3.0;
    timeztobuffer["MSD"] = 4.0;
    timeztobuffer["AST"] = -4.0;
    timeztobuffer["ADT"] = -3.0;
    timeztobuffer["NST"] = -3.5;
    timeztobuffer["NDT"] = -2.5;
    timeztobuffer["EST"] = -5.0;
    timeztobuffer["EDT"] = -4.0;
    timeztobuffer["CST"] = -6.0;
    timeztobuffer["CDT"] = -5.0;
    timeztobuffer["MST"] = -7.0;
    timeztobuffer["MDT"] = -6.0;
    timeztobuffer["PST"] = -8.0;
    timeztobuffer["PDT"] = -7.0;
    timeztobuffer["HST"] = -10.0;
    timeztobuffer["AKST"] = -9.0;
    timeztobuffer["AKDT"] = -8.0;
    timeztobuffer["AEST"] = 10.0;
    timeztobuffer["AEDT"] = 11.0;
    timeztobuffer["ACST"] = 9.5;
    timeztobuffer["ACDT"] = 10.5;
    timeztobuffer["AWST"] = 8.0;

    // read the number of testcases
    int n;
    cin >> n;
    while (n--) {
        string time, typ, t1, t2;
        double sourceb, targetb;
        int hr, mn, ct;
        cin >> time;
        // case where noon (12 p.m.)
        if (time == "noon") {
            cin >> t1 >> t2;
            hr = 12;
            mn = 0;
            typ = "p.m.";
        } else if (time == "midnight") { // case where midnight (0.00 a.m.)
            cin >> t1 >> t2;
            hr = 0;
            mn = 0;
            typ = "a.m.";
        } else { // case where any other time
            cin >> typ >> t1 >> t2;
            hr = stoi(time.substr(0, time.find(':')));
            mn = stoi(time.substr(time.find(':') + 1, time.size()));
        }
        // get source and target buffers
        sourceb = timeztobuffer[t1];
        targetb = timeztobuffer[t2];
        // cout << hr << " " << mn << endl;
        // convert using helper function 
        ct = hp(hr, mn, sourceb, targetb, typ);
        if (ct == 0) {
            cout << "midnight" << endl;
        } else if (ct == 12 * 60) {
            cout << "noon" << endl;
        } else {
            int ch = ct / 60;
            int cm = ct % 60;
            string tod;
            // 12am
            if (ch == 0) {
                ch = 12;
                tod = "a.m.";
            } else if (ch < 12) {
                tod = "a.m.";
            } else if (ch == 12) {
                tod = "p.m.";
            } else {
                ch -= 12;
                tod = "p.m.";
            }
            cout << ch << ":" << fixed << setfill('0') << setw(2) << cm << " " << tod << endl;
        }
    }
    return 0;
}
