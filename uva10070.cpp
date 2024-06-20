#include <bits/stdc++.h>
using namespace std;

int func(string nm,int b)
{
    int len,a,mod,i;
    len = nm.size();
    mod = nm[0] - '0';
    for(i = 0; i < len - 1; i++)
    {
        a = nm[i] - '0';
        a = mod * 10 + (nm[i + 1] - '0');
        mod = a % b;
    }
    if(mod == 0)
        return 1;
    else return 0;
}

int main() {
    int t = 1;
    while (true) {
        string year;
        cin >> year;
        if (cin.eof()) {
            break;
        }
        if (t++ > 1) {
            cout << endl;
        }
        // print accordingly
        int lr = (func(year,4)==1 && func(year,100)==0)|| func(year,400)==1;
        int hulu = func(year, 15) == 1;
        int buluk = lr & func(year, 55);
        if (lr == 0 && hulu == 0 && buluk == 0) {
            cout << "This is an ordinary year." << endl;
            continue;
        }
        if (lr) {
            cout << "This is leap year." << endl;
        }
        if (hulu) {
            cout << "This is huluculu festival year." << endl;
        }
        if (buluk) {
            cout << "This is bulukulu festival year." << endl;
        }
    }
    return 0;
}
