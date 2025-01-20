#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct pokenom {
    ll a, d, h;
};

bool cmp1(pokenom& a, pokenom& b) {
    return a.a > b.a;
}

bool cmp2(pokenom& a, pokenom& b) {
    return a.d > b.d;
}

bool cmp3(pokenom& a, pokenom& b) {
    return a.h > b.h;
}

bool operator<(const pokenom& a, const pokenom& b) {
    return tie(a.a, a.d, a.h) < tie(b.a, b.d, b.h);
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<pokenom> pokenoms(n);
    for (ll i = 0; i < n; ++i) {
        cin >> pokenoms[i].a >> pokenoms[i].d >> pokenoms[i].h;
    }
    set<pokenom> added;
    sort(pokenoms.begin(), pokenoms.end(), cmp1);
    for (ll i = 0; i < k; ++i) {
        added.insert(pokenoms[i]);
    }
    sort(pokenoms.begin(), pokenoms.end(), cmp2);
    for (ll i = 0; i < k; ++i) {
        added.insert(pokenoms[i]);
    }
    sort(pokenoms.begin(), pokenoms.end(), cmp3);
    for (ll i = 0; i < k; ++i) {
        added.insert(pokenoms[i]);
    }
    cout << added.size() << endl;
    return 0;
}

