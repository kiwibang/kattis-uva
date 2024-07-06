// i give up; credits: https://github.com/morris821028/UVa/blob/master/volume006/632%20-%20Compression%20(II).cpp
#include <bits/stdc++.h>
using namespace std;

char s[2048];
int a[2048], len;
bool cmp(int a, int b) {
    int i;
    for(i = 0; i < len; i++)
        if(s[(a+i)%len] != s[(b+i)%len])
            return s[(a+i)%len] < s[(b+i)%len];
    return false;
}

int main() {
    int t, i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &len);
        int idx = 0;
        while (getchar() != '\n');
        while (gets(s + idx)) {
            idx += strlen(s + idx);
            if (idx == len) break;
        }
        for (int i = 0; i < len; ++i) {
            a[i] = i;
        }
        sort(a, a + len, cmp);
        int S1 = 0;
        for (int i = 0; i < len; ++i) {
            if (a[i] == 1) {
                S1 = i;
            }
        }
        printf("%d\n", S1);
        for (int i = 0; i < len; ++i) {
            if (i % 50 == 0 && i) puts("");
            printf("%c", s[(a[i] + len - 1) % len]);
        }
        puts("");
        if (t) {
            puts("");
        }
    }
    return 0;
}


// runtime error :( probs 0 length string but the problem does not state how to handle so i give up
// int main() {
//     int tc;
//     cin >> tc;
//     for (int t = 0; t < tc; ++t) {
//         // read in the current input
//         int n;
//         cin >> n;
//         if (t > 0) {
//             cout << endl;
//         }
//         string curr = "";
//         char cc;
//         while (curr.size() != n) {
//             cin >> cc;
//             curr.push_back(cc);
//         }
//         vector<string> ss;
//         ss.push_back(curr);
//         // execute the bwt algo
//         for (int i = 0; i < n - 1; ++i) {
//             string prev = ss[ss.size() - 1];
//             string news = prev.substr(1, prev.size());
//             news.push_back(prev[0]);
//             ss.push_back(news);
//         }
//         string s1 = ss[1];
//         // sort the string
//         sort(ss.begin(), ss.end());
//         // get the index of s1 after sorting
//         int residx = 0;
//         for (; residx < ss.size(); ++residx) {
//             if (ss[residx] == s1) {
//                 break;
//             }
//         }
//         // get the encrypted string
//         string resstring = "";
//         for (int i = 0; i < ss.size(); ++i) {
//             resstring.push_back(ss[i][n - 1]);
//         }
//         cout << residx << endl;
//         cout << resstring << endl;
//     }
//     return 0;
// }
