#include <bits/stdc++.h>
using namespace std;

struct Person {
    string name;
    int s1;
    int s2;
    int s3;
    Person(string nm, int o, int t, int th) {
        name = nm;
        s1 = o;
        s2 = t;
        s3 = th;
    }
};

struct cmp1 {
    bool operator()(const Person* p1, const Person* p2) const {
        return p1->s1 != p2->s1 ? p1->s1 > p2->s1 : p1->name < p2->name;
    }
};

struct cmp2 {
    bool operator()(const Person* p1, const Person* p2) const {
        return p1->s2 != p2->s2 ? p1->s2 > p2->s2 : p1->name < p2->name;
    }
};

struct cmp3 {
    bool operator()(const Person* p1, const Person* p2) const {
        return p1->s3 != p2->s3 ? p1->s3 > p2->s3 : p1->name < p2->name;
    }
};

int main() {
    int n; 
    cin >> n;
    unordered_map<string, Person*> pl;
    set<Person*, cmp1> ss1;
    set<Person*, cmp2> ss2;
    set<Person*, cmp3> ss3;
    for (int i = 0; i < n; ++i) {
        string name;
        int s1, s2, s3;
        cin >> name >> s1 >> s2 >> s3;
        Person* currp = new Person(name, s1, s2, s3);
        pl[name] = currp;
        ss1.insert(currp);
        ss2.insert(currp);
        ss3.insert(currp);
    }
    int numteams = n / 3;
    for (int i = 0; i < numteams; ++i) {
        set<string> names;
        // take s1
        Person* p1 = *ss1.begin();
        ss1.erase(pl[p1->name]);
        ss2.erase(pl[p1->name]);
        ss3.erase(pl[p1->name]);
        Person* p2 = *ss2.begin();
        ss1.erase(pl[p2->name]);
        ss2.erase(pl[p2->name]);
        ss3.erase(pl[p2->name]);
        Person* p3 = *ss3.begin();
        ss1.erase(pl[p3->name]);
        ss2.erase(pl[p3->name]);
        ss3.erase(pl[p3->name]);
        names.insert(p1->name);
        names.insert(p2->name);
        names.insert(p3->name);
        for (string nm : names) {
            cout << nm << " ";
        }
        cout << endl;
    }
    return 0;
}

