#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float X;
    scanf("%f", &X);
    cout << static_cast<int>(std::round(X * 1000 * (static_cast<float>(5280) / 4854))) << endl;
    return 0;
}
