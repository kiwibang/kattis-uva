#include <bits/stdc++.h>
using namespace std;

int main() {
    int p;
    cin >> p;
    while (p--) {
        int id, res = 0;
        cin >> id;
        vector<int> nums(20);
        for (int i = 0; i < 20; ++i) cin >> nums[i];
        for (int i = 1; i < 20; ++i) {
            int num = nums[i];
            int j = i - 1;
            for (; j >= 0; --j) {
                if (nums[j] <= num) {
                    break;
                }
                nums[j + 1] = nums[j];
                ++res;
            }
            nums[j + 1] = num;
        }
        cout << id << " " << res << endl;
    }
    return 0;
}

