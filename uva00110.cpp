#include <bits/stdc++.h>
using namespace std;

int n; 

void backtrack(int idx, string str)
{
    if(idx == n) {
        printf("%swriteln(", string(idx*2, ' ').c_str());

        for(int i = 0; i < idx-1; ++i)
            printf("%c,", str[i]);

        printf("%c)\n", str[idx-1]);

        return;
    }

    string tmpStr;

    for(int i = idx-1; i >= 0; --i) {
        printf("%s", string(idx*2, ' ').c_str());

        if(i != idx-1) printf("else ");
        printf("if %c < %c then\n", str[i], 'a'+idx);

        tmpStr = str;

        if(i+1 > idx-1) tmpStr.push_back('a'+idx);
        else tmpStr.insert(i+1, 1, 'a'+idx);

        backtrack(idx+1, tmpStr);
    }

    printf("%s", string(idx*2, ' ').c_str());

    puts("else");
    backtrack(idx+1, char('a'+idx) + str);
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        // print first two lines regardless of value of n
        cout << "program sort(input,output);" << endl;
        cout << "var" << endl;
        // print out the variables
        for (int i = 0; i < n - 1; ++i) {
            cout << (char) ('a' + i) << ",";
        }
        cout << (char) ('a' + n - 1) << " : integer;" << endl;
        cout << "begin" << endl;
        cout << "  readln(";
        for (int i = 0; i < n - 1; ++i) {
            cout << (char) ('a' + i) << ",";
        }
        cout << (char) ('a' + n - 1) << ");" << endl;
        backtrack(1, string("a"));

        cout << "end." << endl;

        if(tc) putchar('\n');
    }
    return 0;
}
