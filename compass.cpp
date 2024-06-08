#include <bits/stdc++.h>
using namespace std;

int main () {
    int curr, target;
    cin >> curr >> target;
    // get clockwise 
    int clockwise = target < curr ? 360 - curr + target : target - curr;
    // get anticlockwise
    int anticlockwise = target <= curr ? curr - target : curr + 360 - target;
    // print the ideal direction
    if (clockwise <= anticlockwise) {
        cout << clockwise << endl;
    } else {
        cout << '-' << anticlockwise << endl;
    }
}
