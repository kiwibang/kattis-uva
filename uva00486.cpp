#include <bits/stdc++.h>
using namespace std;

// i give up. credits: https://github.com/mazedrupok/uva/blob/master/486%20uva-English-Number%20Translator.cpp
int main() {
    string word[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
    int number[] =  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 90 };

    string curr;
    while (getline(cin, curr)) {
        istringstream iss(curr);
        int sign = 0;
        long long mil = 0, thou = 0, temp = 0;
        while (iss >> curr) {
            for (int i = 0; i < 28; ++i) {
                if (curr == word[i]) {
                    temp += number[i];
                    break;
                } else if (curr == "million") {
                    mil = temp * 1000000;
                    temp = 0;
                    break;
                } else if (curr == "thousand") {
                    thou = temp * 1000;
                    temp = 0;
                    break;
                } else if (curr == "hundred") {
                    temp = temp * 100;
                    break;
                } else if (curr == "negative") {
                    cout << "-";
                    break;
                }
            }
        }
        cout << mil + thou + temp << endl;
    }
    return 0;
}
