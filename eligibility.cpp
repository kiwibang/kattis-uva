#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int n;
    string line, name, study, dob;
    int numCourses;
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) {
        getline(cin, line);
        istringstream ss(line);
        ss >> name >> study >> dob >> numCourses;
        try {
            // eligible
            if (stoi(study.substr(0, 4)) >= 2010 || stoi(dob.substr(0, 4)) >= 1991) {
                cout << name << " eligible" << endl;
            } else { // maybe ineligible
                // ineligible
                if (numCourses > 40) {
                    cout << name << " ineligible" << endl;
                } else { // coach petition
                    cout << name << " coach petitions" << endl;
                }
            }
        } catch (const invalid_argument& e) {}
    }
    return 0;
}
