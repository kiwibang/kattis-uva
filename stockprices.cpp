#include <bits/stdc++.h>
using namespace std;

int main() {
    long long tc, n; 
    cin >> tc;
    string cmd, t1, t2;
    long long qty, price;
    while (tc--) {
        cin >> n;
        // keep track of the number of stock
        vector<long long> askf(1001, 0), bidf(1001, 0);
        // keep track of the lowest ask price and the highest sell price
        priority_queue<int, vector<int>, greater<int> > askprice; // track lowest price with min-heap
        priority_queue<int> bidprice; // track highest price with max-heap
        long long currprice = -1, mn;
        for (int i = 0; i < n; ++i) {
            // update the relevant DS for later processing
            cin >> cmd >> qty >> t1 >> t2 >> price;
            if (cmd == "sell") {
                if (!askf[price]) askprice.push(price);
                askf[price] += qty;
            } else if (cmd == "buy") {
                if (!bidf[price]) bidprice.push(price);
                bidf[price] += qty;
            }
            // establish any deals
            while (!askprice.empty() && !bidprice.empty() && askf[askprice.top()] && bidf[bidprice.top()] && bidprice.top() >= askprice.top()) {
                long long mn = min(askf[askprice.top()], bidf[bidprice.top()]);
                currprice = askprice.top();
                askf[askprice.top()] -= mn, bidf[bidprice.top()] -= mn;
                if (!askf[askprice.top()]) askprice.pop();
                
                if (!bidf[bidprice.top()]) bidprice.pop();
            }
            string temp = currprice == -1 ? "- " : to_string(currprice);
            // no sell orders or buy orders (should not happen)
            if (bidprice.empty() && askprice.empty()) {
                cout << "- - " << temp << endl;
            } else if (bidprice.empty()) { // no sell orders
                // print buy price, then no sell price, then stock price
                cout << askprice.top() << " - " << temp << endl;
            } else if (askprice.empty()) { // no buy orders
                cout << "- " << bidprice.top() << " " << temp << endl;
            } else { // have both sell and buy orders
                cout << askprice.top() << " " << bidprice.top() << " " << temp << endl;
            }
        }   
    }
    return 0;
}

