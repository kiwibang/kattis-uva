#include <stdio.h>
using namespace std;

int main() {
    int a, b = 0;
    while (scanf("%d %d", &a, &b) != EOF) {
        printf("%d\n", 2 * a * b);
    }
    return 0;
}