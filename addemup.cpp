#include <bits/stdc++.h>
using namespace std;

map<int, int> df;

int flip(int num) {
    int orig = num, flip = 0, d;
    while (num > 0) {
        d = num % 10;
        if (df[d] == -1) return -1;
        flip = flip * 10 + df[d];
        num /= 10;
    }
    return orig == flip ? -1 : flip;
}

int main() {
    df[1] = 1;
    df[2] = 2;
    df[3] = -1;
    df[4] = -1;
    df[5] = 5;
    df[6] = 9;
    df[7] = -1;
    df[8] = 8;
    df[9] = 6;
    df[0] = 0;
    int n, s;
    cin >> n >> s;
    set<int> added;
    vector<int> nums;
    map<int, set<int> > inttoidx;
    for (int i = 0; i < n; ++i) {
        // read in the current number, and add to the list
        // if not added already
        int num;
        cin >> num;
        if (added.find(num) == added.end()) {
            added.insert(num); 
            nums.push_back(num);
        }
        // add the current index to the map
        if (inttoidx.find(num) == inttoidx.end()) inttoidx[num] = set<int>();
        inttoidx[num].insert(i);
        // then flip the number
        int flippednum = flip(num);
        if (flippednum != -1) { // case where we can flip the current num
            if (added.find(flippednum) == added.end()) {
                added.insert(flippednum);
                nums.push_back(flippednum);
            } 
            // add the current index to the map
            if (inttoidx.find(flippednum) == inttoidx.end()) inttoidx[flippednum] = set<int>();
            inttoidx[flippednum].insert(i);
        }
        //cout << num << " " << flippednum << endl;
    }
    // sort the nums
    sort(nums.begin(), nums.end());
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int leftnum = nums[l], rightnum = nums[r], sum = nums[l] + nums[r];
        if (sum == s) {
            if ((inttoidx[leftnum].size() != 1 || inttoidx[rightnum].size() != 1) || (*(inttoidx[leftnum].begin()) != *(inttoidx[rightnum].begin()))) {
                cout << "YES" << endl;
                return 0;
            }
        }
        if (sum < s) {
            ++l;
        } else {
            --r;
        }
    }
    cout << "NO" << endl;
    return 0;
}

