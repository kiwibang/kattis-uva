// credits: https://github.com/mpfeifer1/Kattis/blob/master/minorsetback.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> notes;
    while (n--) {
        long double currnote;
        cin >> currnote;
        currnote /= 440;
        while (currnote >= 2) currnote /= 2;
        while (currnote < 1) currnote *= 2;
        notes.push_back((int) (log2(currnote + 0.00001) * 12));
    }
    map<string, map<int, string>> mp;
    mp["G major"] = {{10,"G"}, {0,"A"}, {2,"B"}, {3,"C"}, {5,"D"}, {7,"E"}, {9,"F#"}};
    mp["C major"] = {{3,"C"}, {5,"D"}, {7,"E"}, {8,"F"}, {10,"G"}, {0,"A"}, {2,"B"}};
    mp["Eb major"] = {{6,"Eb"}, {8,"F"}, {10,"G"}, {11,"Ab"}, {1,"Bb"}, {3,"C"}, {5,"D"}};
    mp["F# minor"] = {{9,"F#"}, {11,"G#"}, {0,"A"}, {2,"B"}, {4,"C#"}, {5,"D"}, {7,"E"}};
    mp["G minor"] = {{10,"G"}, {0,"A"}, {1,"Bb"}, {3,"C"}, {5,"D"}, {6,"Eb"}, {8,"F"}};
    int keys = 0;
    string key = "";
    for (auto i : mp) {
        bool ok = true;
        for (auto j : notes) {
            if (i.second.count(j) == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ++keys;
            key = i.first;
        }
    }
    if (keys == 1) {
        cout << key << endl;
        for (auto i : notes) {
            cout << mp[key][i] << endl;
        }
    } else {
        cout << "cannot determine key" << endl;
    }   
    return 0;
}

