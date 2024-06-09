#include <bits/stdc++.h>
using namespace std;

double getcal(string nutrient, int calpergram) {
    char unit = nutrient[nutrient.size() - 1];
    if (unit == 'g') {
        return stoi(nutrient.substr(0, nutrient.size() - 1)) * calpergram;
    } else if (unit == 'C') {
        return stoi(nutrient.substr(0, nutrient.size() - 1));
    } else {
        return 0;
    }
}

double getPercent(string food) {
    if (food[food.size() - 1] == '%') {
        return stoi(food.substr(0, food.size() - 1));
    }
    return 0;
}

int main() {
    string currfood;
    while (true) {
        // loop over the foods
        double totalcal = 0, fatscal = 0;
        for (int i = 0; ; ++i) {
            // read the curr line
            getline(cin, currfood);
            // check if end of file
            if (i == 0 && currfood == "-") {
                return 0;
            }
            if (currfood == "-") {
                break;
            }
            istringstream iss(currfood);
            string fat, protein, sugar, starch, alcohol;
            iss >> fat >> protein >> sugar >> starch >> alcohol;
            int fatcal = getcal(fat, 9);
            int proteincal = getcal(protein, 4);
            int sugarcal = getcal(sugar, 4);
            int starchcal = getcal(starch, 4);
            int alcoholcal = getcal(alcohol, 7);
            double totalPercentage = getPercent(fat) + getPercent(protein) + getPercent(sugar) + getPercent(starch) + getPercent(alcohol);
            double nonpercentcal = (fatcal + proteincal + sugarcal + starchcal + alcoholcal);
            nonpercentcal = (nonpercentcal / (1 - (totalPercentage / 100)));
            totalcal += nonpercentcal;
            fatscal = fat[fat.size() - 1] == '%' ? fatscal + nonpercentcal * (getPercent(fat) / 100) : fatscal + fatcal;
        }
        cout << round((fatscal * 100) / totalcal) << "%" << endl;
    }
    return 0;
}
