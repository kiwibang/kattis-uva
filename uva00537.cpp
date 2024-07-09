#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    for (int tc = 1; tc <= t; ++tc) {
        string curr;
        getline(cin, curr);
        map<char, double> data;
        data['P'] = -1.00;
        data['U'] = -1.00;
        data['I'] = -1.00;
        int i = 0;
        while (i < curr.size()) {
            if ((curr[i] == 'P' || curr[i] == 'U' || curr[i] == 'I') && (i < curr.size() - 1 && curr[i + 1] == '=')) {
                char unit = curr[i];
                i += 2;
                string num = "";
                while (i < curr.size() && isdigit(curr[i])) {
                    num.push_back(curr[i++]);
                }
                if (i < curr.size() && curr[i] == '.') {
                    num.push_back(curr[i++]);
                    while (i < curr.size() && isdigit(curr[i])) {
                        num.push_back(curr[i++]);
                    }
                }
                double tempres = stod(num);
                if (i < curr.size()) {
                    if (unit == 'P' && curr[i] != 'W') {
                        tempres = curr[i] == 'm' ? tempres * 0.001 : curr[i] == 'k' ? tempres * 1000 : curr[i] == 'M' ? tempres * 1000000 : tempres;
                        ++i;
                    } else if (unit == 'U' && curr[i] != 'V') {
                        tempres = curr[i] == 'm' ? tempres * 0.001 : curr[i] == 'k' ? tempres * 1000 : curr[i] == 'M' ? tempres * 1000000 : tempres;;
                        ++i;
                    } else if (unit == 'I' && curr[i] != 'A') {
                        tempres = curr[i] == 'm' ? tempres * 0.001 : curr[i] == 'k' ? tempres * 1000 : curr[i] == 'M' ? tempres * 1000000 : tempres;;
                        ++i;
                    }
                }
                data[unit] = tempres; 
                ++i;
            } else {
                ++i;
            }
        }
        cout << "Problem #" << tc << endl;
        if (data['P'] == -1.00) {
            cout << "P=" << fixed << setprecision(2) << data['U'] * data['I'] << "W" << endl;;
        } else if (data['U'] == -1.00) {
            cout << "U=" << fixed << setprecision(2) << data['P'] / data['I'] << "V" << endl;
        } else if (data['I'] == -1.00) {
            cout << "I=" << fixed << setprecision(2) << data['P'] / data['U'] << "A" << endl;
        }
        cout << endl;
    }
    return 0;
}
