#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// Terminal colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void printHistogram(const vector<string>& labels, const vector<int>& values) {
    cout << BOLD << "\n=========== HISTOGRAM ===========\n" << RESET;

    int maxVal = *max_element(values.begin(), values.end());

    for (size_t i = 0; i < labels.size(); ++i) {
        cout << CYAN << setw(15) << left << labels[i] << RESET << " | ";

        int barLength = (values[i] * 50) / maxVal;
        string color;

        switch (i % 5) {
            case 0: color = GREEN; break;
            case 1: color = YELLOW; break;
            case 2: color = BLUE; break;
            case 3: color = MAGENTA; break;
            case 4: color = RED; break;
        }

        cout << color;
        for (int j = 0; j < barLength; ++j)
            cout << "*";    // <<< now using ASTERISKS '*'
        cout << RESET << " " << values[i] << endl;
    }

    cout << BOLD << "==================================\n" << RESET;
}

int main() {
    vector<string> categories = {
        "Solar Power", "Wind Power", "Hydro Power", "Geothermal", "Bioenergy"
    };

    vector<int> energyOutput = {
        80, 65, 40, 30, 50
    };

    printHistogram(categories, energyOutput);

    return 0;
}
