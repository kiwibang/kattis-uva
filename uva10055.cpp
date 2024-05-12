#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

int main() {
    long long a, b;
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        if (ss >> a >> b) {
            cout << abs(a - b) << endl;
        } else {
            break;
        }
    }
    return 0;
}
