#include <cstdio>

int main() {
    int t, ptr;
    char line[100001];
    int mem[100];

    scanf("%d", &t);

    for (int i = 1; i <= t; ++i) {
        // reset the memory and the ptr at the start of every testcase
        for (int j = 0; j < 100; ++j) {
            mem[j] = 0;
        }
        ptr = 0;

        scanf("%s", &line);

        for (int j = 0; line[j]; ++j) {
            switch (line[j]) {
                case '>':
                    ++ptr;
                    if (ptr == 100)
                        ptr = 0;
                    break;
                case '<':
                    --ptr;
                    if (ptr == -1)
                        ptr = 99;
                    break;
                case '+':
                    ++mem[ptr];
                    if (mem[ptr] == 256)
                        mem[ptr] = 0;
                    break;
                case '-':
                    --mem[ptr];
                    if (mem[ptr] == -1)
                        mem[ptr] = 255;
                    break;
            }
        }
        printf("Case %d:", i);
        for (int j = 0; j < 100; ++j) {
            printf(" %02X", mem[j]);
        }
        printf("\n");
    }
    return 0;
}
