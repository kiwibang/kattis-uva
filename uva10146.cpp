// i give up; credits: https://github.com/evandrix/UVa/blob/master/10146.cpp
#include <bits/stdc++.h>
using namespace std;

void run() {
    char temp[11], in[11];
    int space, i, mn;
    gets(temp);
    puts(temp);
    for (space = 0; gets(in);) {
        if (!strlen(in)) {
            break;
        }
        mn = strlen(temp);
        mn = mn < strlen(in) ? mn : strlen(in);
        for (i = 0; i < mn; ++i) {
            if (temp[i] != in[i]) {
                break;
            }
        }
        if (i > space) {
            ++space;
        } else {
            space = i;
        }
        for (i = 0; i < space; ++i) {
            putchar(' ');
        }
        puts(in);
        strcpy(temp, in);
    }
}

int main() {
    int n;
    scanf("%d\n\n", &n);
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            putchar('\n');
        }
        run();
    }
    return 0;
}
