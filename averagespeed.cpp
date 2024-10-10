#include <bits/stdc++.h>
using namespace std;

int gett(string prev, string curr) {
    return stoi(curr.substr(0, 2)) * 3600 + stoi(curr.substr(3, 5)) * 60 + stoi(curr.substr(6)) - (stoi(prev.substr(0, 2)) * 3600 + stoi(prev.substr(3, 5)) * 60 + stoi(prev.substr(6)));
}

int main () {
    // track the current speed
    double currspeed = 0.0, totald = 0.0;
    // track the previous time
    string prevtime = "00:00:00";
    // read in the lines
    while (true) {
        string curr, line;
        getline(cin, curr);
        if (curr.empty()) break;
        // break up the line
        istringstream iss(curr);
        vector<string> info;
        while (iss >> line) {
            info.push_back(line);
        }
        int timeelspased = gett(prevtime, info[0]);
        totald += timeelspased * currspeed / 3600;
        // case where 2 strings obtained => update current speed & prev time
        if (info.size() == 2) {
            currspeed = stod(info[1]);
            prevtime = info[0];
        } else if (info.size() == 1) { // case where 1 string => update the distance travelled
            // print the current time along with the total distance travelled
            cout << info[0] << " " << fixed << setprecision(2) << totald << " km" << endl;
            prevtime = info[0];
        }
    }
    return 0;
}