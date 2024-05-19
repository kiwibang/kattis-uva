#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string res = "";
    // loop over restaurants
    while (n--) {
        // get the number of items on the menu
        int k;
        cin >> k;
        cin.ignore();
        // get the name of the restaurant
        string name;
        getline(cin, name);
        // loop over the menu items
        bool hp = false, hpc = false;
        for (int i = 0; i < k; ++i) {
            string item;
            getline(cin, item);
            if (item == "pea soup") {
                hp = true;
            } else if (item == "pancakes") {
                hpc = true;
            }
        }
        // update the restaurant name if needed
        if (hp && hpc && res == "") {
            res = name;
        }
    }
    if (res != "") {
        cout << res << endl;
    } else {
        cout << "Anywhere is fine I guess" << endl;
    }
    return 0;
}
