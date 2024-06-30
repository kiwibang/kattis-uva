// another defeat. credits: https://blog.csdn.net/kl28978113/article/details/38786235
#include <bits/stdc++.h>
using namespace std;

int yes, len, cont, change[200], vis[10] = {0};
char str[100], letter[8] = {"IVXLCDM"}, record[8];

bool judge() {
    int rec[200] = {0}, num[3] = {0}, cnt = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] != '+' && str[i] != '=') {
            num[cnt] += (change[str[i]] >= change[str[i + 1]]) ? change[str[i]] : -change[str[i]];
            if (rec[str[i]]++ == 0) {
                record[cont++] = str[i];
            }
        } else {
            ++cnt;
        }
    }
    return num[0] + num[1] == num[2];
}

int dfs(int cur) {
    if (cur == cont) {
        int num[3] = {0}, cnt = 0;
        for (int i = 0; i < len; ++i) {
            str[i] != '+' && str[i] != '=' ? num[cnt] = num[cnt] * 10 + change[str[i]] : cnt++;
        }
        if (num[0] + num[1] == num[2]) {
            ++yes;
        }
    } else {
        for (int i = 0; i < 10; ++i) {
            change[record[cur]] = i;
            if (vis[i] || change[str[0]] == 0) {
                continue;
            }
            vis[i] = i;
            dfs(cur + 1);
            vis[i] = 0;
        }
    }
    return yes;
}

int main() {
    while (cin >> str && str[0] != '#') {
        yes = cont = 0;
        len = strlen(str);
        change['I'] = 1;
        for (int i = 1; i < 7; ++i) {
            change[letter[i]] = change[letter[i - 1]] * (i % 2 ? 5 : 2);
        }
        printf(judge() ? "Correct " : "Incorrect ");
        printf(dfs(0) ? yes > 1 ? "ambiguous\n" : "valid\n" : "impossible\n");
    }
    return 0;
}