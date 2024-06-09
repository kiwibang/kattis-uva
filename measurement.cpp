#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, double> m;
    m["thou"] = 1;
    m["th"] = 1;
    m["inch"] = 1000 * m["thou"];
    m["in"] = 1000 * m["thou"];
    m["foot"] = 12 * m["inch"];
    m["ft"] = 12 * m["inch"];
    m["yard"] = 3 * m["foot"];
    m["yd"] = 3 * m["foot"];
    m["chain"] = 22 * m["yard"];
    m["ch"] = 22 * m["yard"];
    m["furlong"] = 10 * m["chain"];
    m["fur"] = 10 * m["chain"];
    m["mile"] = 8 * m["furlong"];
    m["mi"] = 8 * m["furlong"];
    m["league"] = 3 * m["mile"];
    m["lea"] = 3 * m["mile"];
    double v;
    string source, rubbish, dest;
    cin >> v >> source >> rubbish >> dest;
    cout << setprecision(13) << v * m[source] / m[dest] << endl;
    return 0;
}
