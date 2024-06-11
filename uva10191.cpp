#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int tc = 1;
    while (true) {
        // read in the input
        int s;
        string l;
        getline(cin, l);
        istringstream iss(l);
        if (cin.eof()) {
            return 0;
        }
        s = stoi(l);
        // read the schedules
        vector<pair<int, int> > time;
        for (int i = 0; i < s; ++i) {
            string start, end;
            getline(cin, l);
            start = l.substr(0, 5);
            end = l.substr(6, 6);
            pair<int, int> currtime(-1, -1);
            currtime.first = ((start[0] - '0') * 10 + (start[1] - '0')) * 60 + (start[3] - '0') * 10 + (start[4] - '0');
            currtime.second = ((end[0] - '0') * 10 + (end[1] - '0')) * 60 + (end[3] - '0') * 10 + (end[4] - '0');
            time.push_back(currtime);
        }
        time.push_back(pair<int, int>(1080, 1080));
        sort(time.begin(), time.end(), cmp);
        int st = 600, en = 600, last = 0;
        for (int i = 0; i < time.size(); ++i) {
            while (time[i].first < en) {
                en = max(en, time[i].second);
                ++i;
            }
            if (time[i].first - en> last) {
                st = en;
                last = time[i].first - en;
            }
            en = time[i].second;
        }
        cout << "Day #" << tc << ": the longest nap starts at " << st / 60 << ":" << setw(2) << setfill('0') << st % 60 << " and will last for ";
        if (last >= 60) {
            cout << last / 60 << " hours and ";
        }
        cout << last % 60 << " minutes." << endl;
        ++tc;
    }
    return 0;
}
