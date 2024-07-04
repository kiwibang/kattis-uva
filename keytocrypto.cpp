#include <bits/stdc++.h>
using namespace std;

int main() {
    string ciphertext, secretword;
    cin >> ciphertext >> secretword;
    int i = 0;
    while (i < ciphertext.size()) {
        // decrypt the current chunk with the current secredtword
        int j = 0;
        while (i < ciphertext.size() && j < secretword.size()) {
            int rot = secretword[j] - 'A';
            int pos = ciphertext[i] - rot - 'A';
            if (pos < 0) {
                pos += 26;
            }
            ciphertext[i] = pos + 'A';
            ++i;
            ++j;
        }
        secretword = ciphertext.substr(max(0, (int) (i - secretword.size())), min(secretword.size(), ciphertext.size() - i + 1));
    }
    cout << ciphertext << endl;
    return 0;
}
