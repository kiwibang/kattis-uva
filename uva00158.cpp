#include <bits/stdc++.h>
using namespace std;

map<int, int> daysinmonth;

bool isleapyr(int y) {
    return y % 4 == 0;
}

int getday(int d, int m, int y) {
    int res = d;
    // loop over months
    for (int mnth = 1; mnth < m; ++mnth) {
        // handle februrary
        if (mnth == 2) {
            res += daysinmonth[mnth];
            // if leap year, feb 29th is added to the total day count
            if (isleapyr(y)) {
                ++res;
            }
            continue;
        }
        res += daysinmonth[mnth];
    }
    return res;
}

bool cmp(pair<string, pair<int, int> > a, pair<string, pair<int, int> > b) {
    if (a.second.first == b.second.first) { // same date => tiebreak by number of stars
        // descending order comparator. note that if equal will tiebreak by order of input appearance
        return a.second.second > b.second.second;
    }
    // else, sort in ascending order
    return a.second.first < b.second.first; 
}

vector<int> getdate(int day, int y) {
    vector<int> res;
    res.push_back(1); // start month
    res.push_back(day); // initial amount of days
    while (true) {
        if (res[0] == 2) { // if feb, need to be careful of leap year
            if (isleapyr(y)) {
                // check break condition
                if (res[1] <= 29) {
                    break;
                } else {
                    res[1] -= 29;
                    // skip to next month, since this month fully handled
                    ++res[0];
                }
            } else {
                if (res[1] <= 28) {
                    break;
                } else {
                    res[1] -= 28;
                    // skip to next month, since this month fully handled
                    ++res[0];
                }
            }
            continue;
        }
        // normal case break condition
        if (res[1] <= daysinmonth[res[0]]) {
            break;
        }
        res[1] -= daysinmonth[res[0]];
        ++res[0];
    }
    return res;
}

int main() {
    daysinmonth[1] = 31;
    daysinmonth[2] = 28; // assume non-leap year
    daysinmonth[3] = 31;
    daysinmonth[4] = 30;
    daysinmonth[5] = 31;
    daysinmonth[6] = 30;
    daysinmonth[7] = 31;
    daysinmonth[8] = 31;
    daysinmonth[9] = 30;
    daysinmonth[10] = 31;
    daysinmonth[11] = 30;
    daysinmonth[12] = 31;
    
    int year, d, m, p;
    char type;
    string l;
    // read in the year
    cin >> year;
    cin.ignore(); // using getline, so need to do this or kaboom
    // keep vectors for the events of type 'A'
    vector<pair<string, pair<int, int> > > events;
    int dcount = 1;
    // then loop over the lines
    while (true) {
        // read in the type
        getline(cin, l);
        istringstream iss(l);
        iss >> type;
        // case where end of input
        if (type == '#') {
            break;
        }
        // read in d, m regardless of 'A' or 'D'
        iss >> d >> m;
        // convert the date into a day depending on leap year or not
        int day = getday(d, m, year);
        // read in the importance p if current line is an event
        if (type == 'A') {
            iss >> p;
            // find the start index of the event string
            int j = 1;
            for (int i = 0; i < 3; ++i) {
                while (isspace(l[j])) {
                    ++j;
                }
                while (isdigit(l[j])) {
                    ++j;
                }
            }
            while(isspace(l[j]))	{
                j++;
            }
            // read in the event
            string currevent = l.substr(j, l.size());
            events.push_back(pair<string, pair<int, int> >(currevent, pair<int, int>(day, p)));
            // skip cos no action required on A types, only need to store the information
            continue;
        }
        // else, means D type
        // keep the events that are happening either today or over the next P days
        vector<pair<string, pair<int, int> > > relevants;
        // loop over all the events
        for (int i = 0; i < events.size(); ++i) {
            // get the current event
            pair<string, pair<int, int> > currevent = events[i];
            // case where the current event is today
            if (currevent.second.first == day) {
                currevent.second.second = 99999;
                relevants.push_back(currevent);
            } else if (currevent.second.first > day && (currevent.second.first - day - 1) < currevent.second.second) { // past today
                currevent.second.second = currevent.second.second - (currevent.second.first - day) + 1;
                relevants.push_back(currevent);
            } else { // before today
                // might be next year's event, so check accordingly
                if (isleapyr(year) && (currevent.second.first + 366 - day - 1) < currevent.second.second) {
                    currevent.second.second = currevent.second.second - (currevent.second.first + 366 - day - 1);
                    relevants.push_back(currevent);
                } else if (!isleapyr(year) && (currevent.second.first + 365 - day - 1) < currevent.second.second) {
                    currevent.second.second = currevent.second.second - (currevent.second.first + 365 - day - 1);
                    relevants.push_back(currevent);
                }
            }
        }
        // sort the events in descending order. i assume built in sort() uses a stable sorting algo
        sort(relevants.begin(), relevants.end(), cmp);
        // print the results
        if (dcount++ > 1) {
            printf("\n");
        }
        // first line of the block
        printf("Today is:%3d%3d\n", d, m);
        // next few lines, loop over output to extract information
        // print the TODAYS
        for (int i = 0; i < relevants.size(); ++i) {
            if (relevants[i].second.second == 99999) {
                printf("%3d%3d *TODAY* %s\n", d, m, relevants[i].first.c_str());
            }
        }
        // print out the next relevant days
        for (int i = 0; i < relevants.size(); ++i) {
            if (relevants[i].second.second != 99999) {
                vector<int> date = getdate(relevants[i].second.first, year);
                string starzstring(relevants[i].second.second, '*');
                printf("%3d%3d %-7s %s\n", date[1], date[0], starzstring.c_str(), relevants[i].first.c_str());
            }
        }
    }
    return 0;
}
