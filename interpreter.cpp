#include <bits/stdc++.h>
using namespace std;

int main() {
	string ci;
	vector<string> ram(1000, "000");
	int idx = 0, res = 0;
	while (true) {
		cin >> ci;
		if (cin.eof()) break;
		ram[idx++] = ci;
	}
	vector<int> regs(10, 0);
	idx = 0;
	while (true) {
		string cinst = ram[idx];
		char inst = cinst[0], dx = cinst[1], nas = cinst[2];
		++res;
		switch(inst) {
			case '1':
				cout << res << endl;
				return 0;
			case '2':
				regs[dx - '0'] = nas - '0';
				++idx;
				break;
			case '3':
				regs[dx - '0'] = (regs[dx - '0'] + (nas - '0')) % 1000;
				++idx;
				break;
			case '4':
				regs[dx - '0'] = (regs[dx - '0'] * (nas - '0')) % 1000;
				++idx;
				break;
			case '5':
				regs[dx - '0'] = regs[nas - '0'];
				++idx;
				break;
			case '6':
				regs[dx - '0'] = (regs[dx - '0'] + regs[nas - '0']) % 1000;
				++idx;
				break;
			case '7':
				regs[dx - '0'] = (regs[dx - '0'] * regs[nas - '0']) % 1000;
				++idx;
				break;
			case '8':
				regs[dx - '0'] = stoi(ram[regs[nas - '0']]);
				++idx;
				break;
			case '9':
				ram[regs[nas - '0']] = to_string(regs[dx - '0']);
				while (ram[regs[nas - '0']].size() < 3) {
					ram[regs[nas - '0']] = "0" + ram[regs[nas - '0']];
				}
				++idx;
				break;
			case '0':
				idx = regs[nas - '0'] != 0 ? regs[dx - '0'] : idx + 1;
				break;
		}
	}
	cout << res << endl;
	return 0;
}