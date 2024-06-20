#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> monthstoint;
    monthstoint["pop"] = 0;
    monthstoint["no"] = 1;
    monthstoint["zip"] = 2;
    monthstoint["zotz"] = 3;
    monthstoint["tzec"] = 4;
    monthstoint["xul"] = 5;
    monthstoint["yoxkin"] = 6;
    monthstoint["mol"] = 7;
    monthstoint["chen"] = 8;
    monthstoint["yax"] = 9;
    monthstoint["zac"] = 10;
    monthstoint["ceh"] = 11;
    monthstoint["mac"] = 12;
    monthstoint["kankin"] = 13;
    monthstoint["muan"] = 14;
    monthstoint["pax"] = 15;
    monthstoint["koyab"] = 16;
    monthstoint["cumhu"] = 17;
    monthstoint["uayet"] = 18;

    vector<string> tzolkin;
    tzolkin.push_back("imix");
    tzolkin.push_back("ik");
    tzolkin.push_back("akbal");
    tzolkin.push_back("kan");
    tzolkin.push_back("chicchan");
    tzolkin.push_back("cimi");
    tzolkin.push_back("manik");
    tzolkin.push_back("lamat");
    tzolkin.push_back("muluk");
    tzolkin.push_back("ok");
    tzolkin.push_back("chuen");
    tzolkin.push_back("eb");
    tzolkin.push_back("ben");
    tzolkin.push_back("ix");
    tzolkin.push_back("mem");
    tzolkin.push_back("cib");
    tzolkin.push_back("caban");
    tzolkin.push_back("eznab");
    tzolkin.push_back("canac");
    tzolkin.push_back("ahau");
    int n;
    cin >> n;
    cout << n << endl;
    while (n--) {
        string month;
        int dayt, y;
        
        cin >> dayt;
        cin.ignore(1, '.');
        cin >> month >> y;
        // convert the date into days
        long days = y * 365 + monthstoint[month] * 20 + dayt;
        cout << days % 13 + 1 << " " << tzolkin[days % 20] << " " << days / 260 << endl;
    }
    return 0;
}
