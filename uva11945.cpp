#include <bits/stdc++.h>
using namespace std;

class comma_numpunct : public numpunct<char> {
protected:
    virtual char do_thousands_sep() const override {
        return ',';
    }
    virtual string do_grouping() const override {
        return "\3";
    }
};

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        double avg = 0;
        for (int i = 0; i < 12; ++i) {
            double curr;
            cin >> curr;
            avg += curr;
        }
        stringstream ss;
        ss.imbue(locale(locale::classic(), new comma_numpunct));
        ss << fixed << setprecision(2) << avg / 12;
        cout << tc << " " << "$" << ss.str() << endl;
    }
    return 0;
}