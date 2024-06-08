#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc = 1;
    while (true) {
        // read in the filesize
        int filesize;
        cin >> filesize;
        if (filesize == 0) {
            return 0;
        }
        int secondselapsed = 0, t5s = 0;
        queue<int> transfers;
        vector<int> avgrate;
        int tmp = filesize;
        // read in the transfer rates 
        while (filesize > 0) {
            // read in the current transfer rate
            int currtransfer;
            cin >> currtransfer;
            // increment the number of seconds elapsed
            ++secondselapsed;
            // add the current transfers to the transfer queue
            transfers.push(currtransfer);
            t5s += currtransfer;
            // pop the oldest transfer from the transfer queue
            if (transfers.size() > 5) {
                t5s -= transfers.front();
                transfers.pop();
            }
            // update the transfer size
            filesize -= currtransfer;
            // case where multiple of 5 seconds have elapsed and total is 0
            if (secondselapsed % 5 == 0 && t5s == 0) {
                avgrate.push_back(-1);
            } else if (secondselapsed % 5 == 0) { // case where multiple of 5 seconds elapsed and transfer rate is more than 0
                avgrate.push_back((int) ceil((double) filesize * 5 / (double) t5s));
            }
        }
        // print the data file transfer
        cout << "Output for data set " << tc << ", " << tmp << " bytes:" << endl;
        for (int i = 0; i < avgrate.size(); ++i) {
            if (avgrate[i] == -1) {
                cout << "   Time remaining: " << "stalled" << endl;
                continue;
            }
            cout << "   Time remaining: " << avgrate[i] << " seconds" << endl;
        }
        cout << "Total time: " << secondselapsed << " seconds" << endl;
        cout << endl;
        ++tc;
    }
    return 0;
}
