#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string name, study, dob;
    int numCourses;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> name;
        cin >> study;
        cin >> dob;
        cin >> numCourses;
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
    }
    return 0;
}
