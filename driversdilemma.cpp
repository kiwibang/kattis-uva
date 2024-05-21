#include <bits/stdc++.h>
using namespace std;

int main() {
    double cap, fuelLeak, toGasStation;
    cin >> cap >> fuelLeak >> toGasStation;
    int highestSpeed = -1;
    for (int i = 0; i < 6; ++i) {
        // get the speed and mpg
        int sp;
        double mpg;
        cin >> sp >> mpg;   
        if ((fuelLeak + sp / mpg) * (toGasStation / sp) <= cap * 0.5) {
            highestSpeed = max(highestSpeed, sp);
        }
    }
    if (highestSpeed == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES " << highestSpeed << endl;
    }
    return 0;
}
