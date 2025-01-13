#include <bits/stdc++.h>
using namespace std;

void updatefreq(int num, vector<int>& f) {
    while (num > 0) {
        ++f[num % 10];
        num /= 10;
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        string streetname, addresscount;
        getline(cin, streetname);
        cout << streetname << endl;
        getline(cin, addresscount);
        cout << addresscount << endl;
        istringstream iss0(addresscount);
        int housecount = 0, lim;
        iss0 >> lim;
        vector<int> f(10, 0);
        while (housecount < lim) {
            string first;
            getline(cin, first);
            istringstream iss(first);
            if (first[0] == '+') {
                char dump;
                int st, en, interval;
                iss >> dump >> st >> en >> interval;
                for (int i = st; i <= en; i += interval) {
                    updatefreq(i, f);
                    ++housecount;
                }
            } else {
                int num;
                iss >> num;
                updatefreq(num, f);
                ++housecount;
            }
        }
        // print digits
        int total = 0;
        for (int i = 0; i < 10; ++i) {
            cout << "Make " << f[i] << " digit " << i << endl;
            total += f[i]; 
        }
        cout << "In total " << total; 
        if (total == 1) {
            cout << " digit" << endl;
        } else {
            cout << " digits" << endl;
        }
    }
    return 0;
}

