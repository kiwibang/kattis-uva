#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int w, l;
        cin >> w >> l;
        if (w == 0 && l == 0) {
            return 0;
        }
        int ax = 0, ay = 0;
        int tx = 0, ty = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            char dir;
            int mag;
            cin >> dir >> mag;
            if (dir == 'u') {
                // update robo coords
                ty += mag;
                // update actual coords
                ay = min(l - 1, ay + mag);
            } else if (dir == 'd') {
                // update robo coords
                ty -= mag;
                // update actual coords
                ay = max(0, ay - mag);
            } else if (dir == 'l') {
                // update robo coords
                tx -= mag;
                // update actual coords
                ax = max(0, ax - mag);
            } else {
                // update robo coords
                tx += mag;
                // update actual coords
                ax = min(w - 1, ax + mag);
            }
        }
        // print the res
        cout << "Robot thinks " << tx << " " << ty << endl;
        cout << "Actually at " << ax << " " << ay << endl;
        cout << "\n" << endl;
    }
    return 0;
}
