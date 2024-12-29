#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums(5);
    for (int i = 0; i < 5; ++i) cin >> nums[i];
    for (int i = 0; i < 4; ++i) {
        bool swap = false;
        for (int j = 0; j < 4; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap = true;
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                for (int j = 0; j < 5; ++j) {
                    cout << nums[j];
                    if (j < 4) cout << " ";
                }
                cout << endl;
            }
        }
        if (!swap) {
            break;
        }
    }
    return 0;
}

