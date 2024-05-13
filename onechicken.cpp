#include <iostream>
using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    if (N < M) {
        if (M - N == 1) {
            cout << "Dr. Chaz will have 1 piece of chicken left over!" << endl;
        } else {
            cout << "Dr. Chaz will have " << (M - N) << " pieces of chicken left over!" << endl;
        }
    } else {
        if (N - M == 1) {
            cout << "Dr. Chaz needs 1 more piece of chicken!" << endl;
        } else {
            cout << "Dr. Chaz needs " << (N - M) << " more pieces of chicken!" << endl;
        }
    }
    return 0;
}
