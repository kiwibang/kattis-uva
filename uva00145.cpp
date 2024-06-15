#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, vector<double> > costs;
    costs['A'] = vector<double>();
    costs['A'].push_back(0.10);
    costs['A'].push_back(0.06);
    costs['A'].push_back(0.02);
    costs['B'] = vector<double>();
    costs['B'].push_back(0.25);
    costs['B'].push_back(0.15);
    costs['B'].push_back(0.05);
    costs['C'] = vector<double>();
    costs['C'].push_back(0.53);
    costs['C'].push_back(0.33);
    costs['C'].push_back(0.13);
    costs['D'] = vector<double>();
    costs['D'].push_back(0.87);
    costs['D'].push_back(0.47);
    costs['D'].push_back(0.17);
    costs['E'] = vector<double>();
    costs['E'].push_back(1.44);
    costs['E'].push_back(0.80);
    costs['E'].push_back(0.30);

    while (true) {
        // read in the input
        char step;
        string number;
        int hrst, mnst, hrend, mnend;
        cin >> step;
        if (step == '#') {
            return 0;
        }
        cin >> number >> hrst >> mnst >> hrend >> mnend;
		if (hrend < hrst or (hrst == hrend and mnend <= mnst)) {
            hrend += 24;
        }
        // process the input
        double day, evn, nt, total;
        int dayt = 0, evnt = 0, ntt = 0;
        int stt = hrst * 60 + mnst, ent = hrend * 60 + mnend;
        // case where time spent is less than 1 min
        if (hrst == hrend && mnend - mnst < 1) {
            goto prnt;
        }
        // compute the time for each category
		for (int t = 0; t <= 2880; ++t) {
			if (stt < t and t <= ent) {
				if ((t >= 0 and  t <= 480) or (t >= 1321 and t <= 1920) or (t >= 2761 and t <= 3360))
					++ntt;
				else if ((t >= 1081 and  t <= 1320) or (t >= 2521 and t <= 2760))
					++evnt;
				else
					++dayt;
			}
		}
        // compute the fees for each category
        day = dayt * costs[step][0];
        evn = evnt * costs[step][1];
        nt = ntt * costs[step][2];
        total = day + evn + nt;
        // print the result in the specified format
        prnt:
        cout << setfill(' ') << setw(10) << number;
        cout << setfill(' ') << setw(6) << dayt;
        cout << setfill(' ') << setw(6) << evnt;
        cout << setfill(' ') << setw(6) << ntt;
        cout << "  " << step << setfill(' ') << setw(8) << fixed << setprecision(2) << total << endl;
    }
   return 0;
}
