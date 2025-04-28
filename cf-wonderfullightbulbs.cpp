#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        unordered_map<long long,bool> rp, dp;
        rp.reserve(n*2);
        dp.reserve(n*2);

        for(int i = 0; i < n; i++){
            long long x,y;
            cin >> x >> y;
            rp[x] = !rp[x];
            dp[x + y] = !dp[x + y];
        }

        long long s = 0;
        for(auto &kv : rp){
            if (kv.second) { 
                s = kv.first;
                break;
            }
        }
        long long D = 0;
        for(auto &kv : dp){
            if (kv.second) {
                D = kv.first;
                break;
            }
        }

        long long t = D - s;
        cout << s << " " << t << "\n";
    }
    return 0;
}

