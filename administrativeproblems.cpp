#include <bits/stdc++.h>
using namespace std;

struct car {
    string name;
    int price;
    int pickupcost;
    int costperkm;
    car(string nm, int pr, int puc, int cpk) {
        name = nm;
        price = pr;
        pickupcost = puc;
        costperkm = cpk;
    }
    car() {
        name = "";
        price = -1;
        pickupcost = -1;
        costperkm = -1;
    }
};

struct spy {
    string name;
    string currcar;
    bool pickedup;
    bool inconsistent;
    long long totalcost;
    spy() {
        name = "";
        pickedup = false;
        inconsistent = false;
        totalcost = 0;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        unordered_map<string, car*> carm;
        map<string, spy*> spym;
        for (int i = 0; i < n; ++i) {
            string N;
            int p, q, k;
            cin >> N >> p >> q >> k;
            car* currc = new car(N, p, q, k);
            carm[N] = currc;
        } 
        for (int i = 0; i < m; ++i) {
            int tm;
            string name;
            char e;
            cin >> tm >> name >> e;
            // add into database if not added yet
            if (spym.find(name) == spym.end()) {
                spy* tspy = new spy(); 
                tspy->name = name;
                spym[name] = tspy;
            }
            spy* currspy = spym[name];
            if (e == 'p') {
                string c;
                cin >> c;
                if (currspy->inconsistent) {
                    continue;
                }
                // check inconsistency: car is returned already or has been picked up already 
                if (currspy->pickedup) {
                    currspy->inconsistent = true;
                    continue;
                } 
                currspy->pickedup = true; 
                currspy->currcar = c;
                currspy->totalcost += carm[currspy->currcar]->pickupcost;
            } else if (e == 'r') {
                int d;
                cin >> d;
                // check inconsistent
                if (currspy->inconsistent) {
                    continue;
                }
                // check inconsistent: car has not been picked up
                if (!currspy->pickedup) {
                    currspy->inconsistent = true;
                    continue;
                }
                // otehrwise, compute the total cost
                long long tc = carm[currspy->currcar]->costperkm * d;
                // add to the spy's total cost
                currspy->totalcost += tc;
                // reset the spy's pickup and return bools
                currspy->pickedup = false;
            } else if (e == 'a') {
                double s;
                cin >> s;
                // check inconsistent
                if (currspy->inconsistent) {
                    continue;
                }
                // check inconsistent: spy is not even using a car
                if (!currspy->pickedup) {
                    currspy->inconsistent = true;
                    continue;
                }
                // otherwise, compute the accident cost and add to the spy's total cost
                if (s > 0) currspy->totalcost += (carm[currspy->currcar]->price * s + 99) / 100;
            }
        }
        // then print the results
        for (auto& sp : spym) {
            string spname = sp.first;
            spy* cspy = sp.second;
            cout << spname << " ";
            if (cspy->inconsistent || cspy->pickedup) {
                cout << "INCONSISTENT";
            } else {
                cout << cspy->totalcost;
            }
            cout << endl;
        }
    }
    return 0;
}

