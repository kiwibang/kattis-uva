#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    int i = 1;
    while (getline(cin, line)) {
        if (line == "#") {
            return 0;
        }
        cout << "Case " << i << ": ";
        if (line == "HELLO") {
            cout << "ENGLISH" << endl;
        } else if (line == "HOLA") {
            cout << "SPANISH" << endl;
        } else if (line == "HALLO") {
            cout << "GERMAN" << endl;
        } else if (line == "BONJOUR") {
            cout << "FRENCH" << endl;
        } else if (line == "CIAO") {
            cout << "ITALIAN" << endl;
        } else if (line == "ZDRAVSTVUJTE") {
            cout << "RUSSIAN" << endl;
        } else {
            cout << "UNKNOWN" << endl;
        }
        ++i;
    }
    return 0;
}
