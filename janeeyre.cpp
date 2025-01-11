#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(pair<string, int>& a, pair<string, int>& b) {
        return a.first > b.first;
    }
};

bool cmp2(tuple<int, string, int>& a, tuple<int, string, int>& b) {
    return get<0>(a) < get<0>(b);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    cin.ignore();
    string curr;
    priority_queue<pair<string, int>, vector<pair<string, int> >, cmp> pq;
    for (int i = 0; i < n; ++i) {
        getline(cin, curr);
        string book = "", temp = "";
        int idx = 1;
        while (curr[idx] != '\"') {
            book += curr[idx++];
        }
        idx += 2;
        while (idx < curr.size()) {
            temp += curr[idx++];
        }
        int time = stoi(temp);
        pq.push(pair<string, int>(book, time));
    }
    pair<string, int> je("Jane Eyre", k);
    pq.push(je);
    vector<tuple<int, string, int> > addedbooks;
    for (int i = 0; i < m; ++i) {
        getline(cin, curr);
        int idx = 0, t;
        string temp = "", book = "";
        while (curr[idx] != ' ') {
            temp += curr[idx++];
        }
        t = stoi(temp);
        idx += 2;
        while (curr[idx] != '\"') {
            book += curr[idx++];
        }
        idx += 2;
        temp = "";
        while (idx < curr.size()) {
            temp += curr[idx++];
        }
        int time = stoi(temp);
        if (book < "Jane Eyre") addedbooks.push_back(tuple<int, string, int>(t, book, time));
    }
    sort(addedbooks.begin(), addedbooks.end(), cmp2);
    int idx = 0;
    long long currtime = 0;
    while (!pq.empty()) {
        // finish reading the current book
        pair<string, int> currbook = pq.top();
        pq.pop();
        currtime += currbook.second;
        if (currbook == je) {
            cout << currtime << endl;
            return 0;
        }
        // add any books that have arrived
        while (idx < addedbooks.size() && get<0>(addedbooks[idx]) <= currtime) {
            pq.push(pair<string, int>(get<1>(addedbooks[idx]), get<2>(addedbooks[idx])));
            ++idx;
        }
    }
    return 0;
}

