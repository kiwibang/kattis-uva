#include <bits/stdc++.h>
using namespace std;

int main() {
    string curr;
    while (cin >> curr) {
        // print the first part of the string for the output
        cout << curr << ": ";
        // check invalid # of balls
        int sum = 0, n = curr.size();
        for (char ball : curr) {
            sum += ball - '0';
        }
        if (sum % n) {
            cout << "invalid # of balls" << endl;
            continue;
        }
        // else, store the number of balls in sum 
        sum /= curr.size();
        // then check if we can do a valid juggle
        // track the balls that we have thrown in terms of their fall time
        priority_queue<int, vector<int>, greater<int> > pq;
        bool ok = true;
        for (int currtime = 0; currtime < (n << 2); ++currtime) {
            // case where no ball is thrown
            if (!(curr[currtime % n] - '0')) {
                // we check if we catch a ball in this beat, denoted by currenttime
                if (!pq.empty() && pq.top() == currtime) {
                    ok = false;
                    goto cont;
                }
                continue;
            }
            // else, we throw a ball. check that we do not catch more than 1 ball 
            int ballscaught = 0;
            while (!pq.empty() && pq.top() == currtime) {
                ++ballscaught;
                pq.pop();
            }
            // case where we catch more than 1 ball
            if (ballscaught > 1) {
                ok = false;
                goto cont;
            }
            pq.push(currtime + curr[currtime % n] - '0');
        }
        cont: 
        if (ok) {
            cout << "valid with " << sum << " balls" << endl;
        } else {
            cout << "invalid pattern" << endl;
        }
    }
    return 0;
}

