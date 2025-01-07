#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    stack<string> s;
    map<string, int> indices;
    string type, event, temp;
    int numevents;
    cin >> n;
    while (n--) {
        cin >> type;
        if (type == "E") {
            cin >> event;
            indices[event] = s.size();
            s.push(event);
        } else if (type == "S") {
            bool ploterror = false;
            cin >> numevents;
            int mxdream = s.size(), valid = -1; 
            for (int i = 0; i < numevents; ++i) {
                cin >> temp;
                if (temp[0] == '!') { // should be a dream
                    event = temp.substr(1);
                    if (indices.find(event) != indices.end()) { // no such event
                        mxdream = min(mxdream, indices[event]);
                    }     
                } else {
                    event = temp;
                    if (indices.find(event) == indices.end()) { // no such event
                        ploterror = true;
                    } else {
                        valid = max(valid, indices[event]);
                    }
                }
            }
            if (ploterror || mxdream <= valid) {
                cout << "Plot Error" << endl;
            } else if (!ploterror && mxdream == s.size()) {
                cout << "Yes" << endl;
            } else {
                cout << s.size() - mxdream << " Just A Dream" << endl;
            }
        } else if (type == "D") {
            cin >> numevents;
            for (int i = 0; i < numevents; ++i) {
                indices.erase(s.top());
                s.pop();
            }
        }
    }
    return 0;
}

