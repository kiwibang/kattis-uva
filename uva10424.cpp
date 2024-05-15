#include <bits/stdc++.h>
using namespace std;

int computeName(string name);

int main() {
    string name1;
    string name2;
    double n1, n2;
    while (!cin.eof()) {
        getline(cin, name1);
        if (cin.eof()) {
            return 0;
        }
        getline(cin, name2);
        n1 = computeName(name1);
        n2 = computeName(name2);
        cout << fixed << setprecision(2) << min(n1 * 100 / n2, n2 * 100 / n1) << " %" << endl;
    }
    return 0;
}

int computeName(string name) {
    int sum = 0;
    for (int i = 0; i < name.length(); ++i) {
        char c = name[i];
        if (!isalpha(c)) {
            continue;
        }
        sum += (tolower(c) - 'a' + 1);
    }
    while (sum >= 10) {
        int temp = 0;
        while (sum > 0) {
            temp += (sum % 10);
            sum /= 10;
        }
        sum = temp;
    }
    return sum;
}
