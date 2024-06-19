#include <bits/stdc++.h>
using namespace std;

int main() {
    int hrc, mnc, scc;
    int hre, mne, sce;
    int secsc, secse;
    string ct, et;
    cin >> ct >> et;
    hrc = (ct[0] - '0') * 10 + (ct[1] - '0');
    mnc = (ct[3] - '0') * 10 + (ct[4] - '0');
    scc = (ct[6] - '0') * 10 + (ct[7] - '0');
    hre = (et[0] - '0') * 10 + (et[1] - '0');
    mne = (et[3] - '0') * 10 + (et[4] - '0');
    sce = (et[6] - '0') * 10 + (et[7] - '0');
    // convert to secs
    secsc = hrc * 3600 + mnc * 60 + scc;
    secse = hre * 3600 + mne * 60 + sce;
    // case where 24 hours
    if (secsc == secse) {
        cout << "24:00:00" << endl;
        return 0;
    }
    // else, get diff
    int d = secsc < secse ? secse - secsc : 86400 - secsc + secse;
    // get hours, minutes, seconds
    hre = d / 3600;
    mne = (d / 60) % 60;
    sce = d % 60;
    cout << fixed << setfill('0') << setw(2) << hre << ":";
    cout << fixed << setfill('0') << setw(2) << mne << ":"; 
    cout << fixed << setfill('0') << setw(2) << sce << endl; 
    return 0;
}
