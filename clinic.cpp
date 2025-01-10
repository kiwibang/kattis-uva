#include <bits/stdc++.h>
using namespace std;

struct appt {
    long long s;
    long long k;
    long long arrival;
    string name;
};

struct cmp {
    bool operator()(const appt& a, const appt& b) {
        long long n1 = a.s + a.k * (20000000 - a.arrival);
        long long n2 = b.s + b.k * (20000000 - b.arrival);
        return n1 == n2 ? a.name > b.name : n1 < n2; 
    }
};

int main() {
    long long n, k, q, t, s;
    string m;
    cin >> n >> k;
    priority_queue<appt, vector<appt>, cmp> pq;
    set<string> removednames;
    for (int i = 0; i < n; ++i) {
        cin >> q;
        if (q == 1) {
            cin >> t >> m >> s;
            appt temp = {s, k, t, m};
            pq.push(temp);
        } else if (q == 2) {
            cin >> t;
            // remove all names that have been removed
            while (!pq.empty() && removednames.find(pq.top().name) != removednames.end()) {
                removednames.erase(pq.top().name);
                pq.pop();
            }
            if (pq.empty()) {
                cout << "doctor takes a break" << endl;
            } else {
                appt curr = pq.top();
                cout << curr.name << endl;
                pq.pop();
            }
        } else if (q == 3) {
            cin >> t >> m;
            removednames.insert(m);
        }        
    }
    return 0;
}

