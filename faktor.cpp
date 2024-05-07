#include <iostream>
using namespace std;

int main() {
    int A, I, count;
    // 1 1
    scanf("%d %d", &A, &I);
    count = (I == 1) ? 1 : (A * (I - 1)) + 1;
    cout << count << endl;
    return 0;
}
