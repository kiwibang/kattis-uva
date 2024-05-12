#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    if (line == "OCT 31" || line == "DEC 25") {
        cout << "yup" << endl;
    } else {
        cout << "nope" << endl;
    }
    return 0;
}
