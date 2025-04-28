#include <bits/stdc++.h>
using namespace std;
const long long INF = 9e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<long long>> h(n, vector<long long>(n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> h[i][j];

        vector<long long> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int j = 0; j < n; j++) cin >> b[j];

        vector<array<array<bool,2>,2>> allowX(n-1);
        for(int i = 0; i < n-1; i++)
            for(int p=0;p<2;p++) for(int q=0;q<2;q++)
                allowX[i][p][q] = true;

        vector<array<array<bool,2>,2>> allowY(n-1);
        for(int j = 0; j < n-1; j++)
            for(int p=0;p<2;p++) for(int q=0;q<2;q++)
                allowY[j][p][q] = true;

        // Fill allowX from vertical constraints
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < n; j++){
                long long d = h[i][j] - h[i+1][j];
                if (d == 0) {
                    allowX[i][0][0] = false;
                    allowX[i][1][1] = false;
                } else if (d == 1) {
                    allowX[i][0][1] = false;
                } else if (d == -1) {
                    allowX[i][1][0] = false;
                }
            }
        }
        // Fill allowY from horizontal constraints
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n-1; j++){
                long long d = h[i][j] - h[i][j+1];
                if (d == 0) {
                    allowY[j][0][0] = false;
                    allowY[j][1][1] = false;
                } else if (d == 1) {
                    allowY[j][0][1] = false;
                } else if (d == -1) {
                    allowY[j][1][0] = false;
                }
            }
        }

        // DP over rows: dpX[i][p] = min cost to assign x[0..i], with x[i]=p
        vector<array<long long,2>> dpX(n, {INF, INF});
        dpX[0][0] = 0;
        dpX[0][1] = a[0];
        for(int i = 1; i < n; i++){
            for(int q = 0; q < 2; q++){
                long long best = INF;
                for(int p = 0; p < 2; p++){
                    if (allowX[i-1][p][q]) {
                        long long cost = dpX[i-1][p] + (q ? a[i] : 0LL);
                        if (cost < best) best = cost;
                    }
                }
                dpX[i][q] = best;
            }
        }
        long long ansX = min(dpX[n-1][0], dpX[n-1][1]);
        if (ansX >= INF) {
            cout << -1 << "\n";
            continue;
        }

        // DP over columns: dpY[j][q] = min cost to assign y[0..j], y[j]=q
        vector<array<long long,2>> dpY(n, {INF, INF});
        dpY[0][0] = 0;
        dpY[0][1] = b[0];
        for(int j = 1; j < n; j++){
            for(int q = 0; q < 2; q++){
                long long best = INF;
                for(int p = 0; p < 2; p++){
                    if (allowY[j-1][p][q]) {
                        long long cost = dpY[j-1][p] + (q ? b[j] : 0LL);
                        if (cost < best) best = cost;
                    }
                }
                dpY[j][q] = best;
            }
        }
        long long ansY = min(dpY[n-1][0], dpY[n-1][1]);
        if (ansY >= INF) {
            cout << -1 << '\n';
            continue;
        }

        cout << ansX + ansY << '\n';
    }
    return 0;
}


