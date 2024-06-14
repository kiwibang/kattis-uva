#include <bits/stdc++.h>
using namespace std;

bool ok(string number, int len) {
    int diff = number.size() - len;
    if (number[0] == '0' && diff >= 4 && diff <= 7 && len <= 6) {
        return true;
    }
    if (number[0] == '0' && number[1] == '0' && diff >= 4 && diff <= 10 && len <= 5) {
        return true;
    }
    return false;
}

int main() {
    vector<string> codes;
    vector<string> places;
    vector<double> prices;
    // read the table
    while (true) {
        string code = "", place = "", l;
        getline(cin, l);
        double price = 0.00;
        int idx = 0;
        // read in the code
        for (; idx < l.size(); ++idx) {
            if (l[idx] == ' ') {
                break;
            }
            code.push_back(l[idx]);
        }
        ++idx;
        if (code == "000000") {
            break;
        }
        // read in the place
        for (; idx < l.size(); ++idx) {
            if (l[idx] == '$') {
                break;
            }
            place.push_back(l[idx]);
        }
        ++idx;
        // read in the price
        for (; idx < l.size(); ++idx) {
            price = (price * 10) + (l[idx] - '0');
        }
        // add to vectors
        codes.push_back(code);
        places.push_back(place);
        prices.push_back(price);
    }
    // read the numbers, and output as specified
    lmao: while (true) {
        string number, l;
        getline(cin, l);
        istringstream iss(l);
        iss >> number;
        int mins;
        if (number == "#") {
            break;
        }
        iss >> mins;
        // case where local
        if (number[0] != '0') {
            printf("%-15s %-5s%30s%5d%6.2lf%7.2lf\n", number.c_str(), "Local", number.c_str(), mins, 0.0, 0.0);
            continue;
        }
        for (int i = 0; i < codes.size(); ++i) {
            if (number.substr(0, codes[i].length()) == codes[i]) {
                int len = number.substr(codes[i].length()).length();
                if (ok(number, codes[i].length())) {
                    printf("%-15s %-25s%10s%5d%6.2lf%7.2lf\n", number.c_str(), places[i].c_str(),
                           number.substr(codes[i].length()).c_str(), mins, prices[i] / 100.0, prices[i] * mins / 100.0);
                    goto lmao;   
                }
            }
        }
        printf("%-15s %-35s%5d%13.2f\n", number.c_str(), "Unknown", mins, -1.00);
    }
    return 0;
}
