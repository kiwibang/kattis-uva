#include <stdio.h>
#include <cmath>

int main() {
    int n = 0;
    long long curr = 0;
    // get the number of testcases
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        // get the current number 
        scanf("%lld", &curr);
        long long temp = -0.5 + sqrt(0.25 - 2 * -curr);
        printf("%lld\n", temp);
    }
    return 0;
}