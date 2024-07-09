#include <bits/stdc++.h>
using namespace std;

void printancestors(string name, string prefix, map<string, vector<string> >& personinfo, map<string, vector<string> >& parentinfo, map<string, vector<string> >& childinfo) {
    // base case: no info on parents
    if (parentinfo.find(name) == parentinfo.end()) {
        return;
    }
    // recursively print the ancestors
    vector<string> parents = parentinfo[name];
    sort(parents.begin(), parents.end());
    string newprefix = prefix + "  ";
    for (int i = 0; i < parents.size(); ++i) {
        // print the prefix
        cout << newprefix;
        // print the name
        cout << parents[i];
        // print the birth
        if (personinfo[parents[i]].size() == 0) {
            cout << endl;
        }
        if (personinfo[parents[i]].size() >= 1) {
            cout << " " << personinfo[parents[i]][0] << " -";
            if (personinfo[parents[i]].size() == 1) {
                cout << endl;
            }
        }
        // print the death
        if (personinfo[parents[i]].size() == 2) {
            cout << " " << personinfo[parents[i]][1] << endl;
        }
        printancestors(parents[i], newprefix, personinfo, parentinfo, childinfo);
    }
}

void printdescendants(string name, string prefix, map<string, vector<string> >& personinfo, map<string, vector<string> >& parentinfo, map<string, vector<string> >& childinfo) {
    // base case: no info on parents
    if (childinfo.find(name) == childinfo.end()) {
        return;
    }
    // recursively print the ancestors
    vector<string> children = childinfo[name];
    sort(children.begin(), children.end());
    string newprefix = prefix + "  ";
    for (int i = 0; i < children.size(); ++i) {
        // print the prefix
        cout << newprefix;
        // print the name
        cout << children[i];
        // print the birth
        if (personinfo[children[i]].size() == 0) {
            cout << endl;
        }
        if (personinfo[children[i]].size() >= 1) {
            cout << " " << personinfo[children[i]][0] << " -";
            if (personinfo[children[i]].size() == 1) {
                cout << endl;
            }
        }
        // print the death
        if (personinfo[children[i]].size() == 2) {
            cout << " " << personinfo[children[i]][1] << endl;
        }
        printdescendants(children[i], newprefix, personinfo, parentinfo, childinfo);
    }
}

int main() {
    // record the information of each person (i.e. birth and death date (if any))
    map<string, vector<string> > personinfo;
    // record the parent information of each person (i.e. mother and father)
    map<string, vector<string> > parentinfo;
    // record the children that each person has
    map<string, vector<string> > childinfo;
    // loop over the lines
    string line, commandtype, temp, name, dob, mother, father, dod;
    int numqueries = 0;
    while (true) {
        // read in the input
        getline(cin, line);
        istringstream iss(line);

        // handle the input
        // get the command type
        iss >> commandtype;
        // handle the cases separately
        if (commandtype == "QUIT") {
            break;
        }

        if (commandtype == "BIRTH") {
            // get the name of the child
            name = "";
            temp = "";
            while (temp != ":") {
                iss >> temp;
                if (temp == ":") {
                    break;
                }
                name += temp;
                name += " ";
            }
            name.resize(name.size() - 1);
            // get the date of birth of the child
            dob = "";
            temp = "";
            while (temp != ":") {
                iss >> temp;
                if (temp == ":") {
                    break;
                }
                dob += temp;
                dob += " ";
            }
            dob.resize(dob.size() - 1);
            // get the mother
            mother = "";
            temp = "";
            while (temp != ":") {
                iss >> temp;
                if (temp == ":") {
                    break;
                }
                mother += temp;
                mother += " ";
            }
            mother.resize(mother.size() - 1);
            // get the father
            father = "";
            temp = "";
            while (iss >> temp) {
                father += temp;
                father += " ";
            }
            father.resize(father.size() - 1);
            
            // add to the personinfo maps for all three people
            if (personinfo.find(name) == personinfo.end()) {
                personinfo[name] = vector<string>();
            }
            personinfo[name].push_back(dob);
            if (personinfo.find(mother) == personinfo.end()) {
                personinfo[mother] = vector<string>();
            }
            if (personinfo.find(father) == personinfo.end()) {
                personinfo[father] = vector<string>();
            }
            // add to the parentinfo maps for the child
            if (parentinfo.find(name) == parentinfo.end()) {
                parentinfo[name] = vector<string>();
            }
            if (father > mother) {
                parentinfo[name].push_back(mother);
                parentinfo[name].push_back(father);
            } else {
                parentinfo[name].push_back(father);
                parentinfo[name].push_back(mother);
            }
            // add to the childinfo maps for the parents
            if (childinfo.find(mother) == childinfo.end()) {
                childinfo[mother] = vector<string>();
            }
            childinfo[mother].push_back(name);
            if (childinfo.find(father) == childinfo.end()) {
                childinfo[father] = vector<string>();
            }
            childinfo[father].push_back(name);
        } else if (commandtype == "DEATH") {
            // get the name
            name = "";
            while (temp != ":") {
                iss >> temp;
                if (temp == ":") {
                    break;
                }
                name += temp;
                name += " ";
            }
            name.resize(name.size() - 1);
            // get the date of death
            dod = "";
            temp = "";
            while (iss >> temp) {
                dod += temp;
                dod += " ";
            }
            dod.resize(dod.size() - 1);
            // update the personinfo map
            personinfo[name].push_back(dod);
        } else if (commandtype == "ANCESTORS") {
            // get the name
            name = "";
            temp = "";
            while (iss >> temp) {
                name += temp;
                name += " ";
            }
            name.resize(name.size() - 1);
            if (numqueries++ > 0) {
                cout << endl;
            }
            cout << "ANCESTORS of " << name << endl;
            // print all the ancestors
            printancestors(name, "", personinfo, parentinfo, childinfo);
        } else if (commandtype == "DESCENDANTS") {
            // get the name
            name = "";
            temp = "";
            while (iss >> temp) {
                name += temp;
                name += " ";
            }
            name.resize(name.size() - 1);
            if (numqueries++ > 0) {
                cout << endl;
            }
            cout << "DESCENDANTS of " << name << endl;
            // print all the decendants
            printdescendants(name, "", personinfo, parentinfo, childinfo);
        }
    }
    return 0;
}
