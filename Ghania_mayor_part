#include <iostream>
#include <string>
using namespace std;

struct ZoneInfo {
    string name;
    int area;
    int population;
    bool emergencyReady;
    bool communityProgramRunning;
    bool safetyChecked;
};

class Zone {
protected:
    ZoneInfo info;

public:
    Zone(string name, int area, int population) {
        info.name = name;
        info.area = area;
        info.population = population;
        info.emergencyReady = false;
        info.communityProgramRunning = false;
        info.safetyChecked = false;
    }

    void prepareEmergencyPlan() {
        if (!info.emergencyReady) {
            info.emergencyReady = true;
            cout << "Emergency plan activated in " << info.name << " zone.\n";
        } else {
            cout << "Emergency plan already ready in " << info.name << ".\n";
        }
    }

    void launchCommunityProgram() {
        if (!info.communityProgramRunning) {
            info.communityProgramRunning = true;
            cout << "Community wellness program launched in " << info.name << " zone.\n";
        } else {
            cout << "Community program is already active.\n";
        }
    }

    void performSafetyCheck() {
        info.safetyChecked = true;
        cout << "Safety check completed in " << info.name << " zone.\n";
    }

    void expandZone(int areaIncrease, int populationIncrease) {
        info.area += areaIncrease;
        info.population += populationIncrease;
        cout << "Zone " << info.name << " expanded by " << areaIncrease << " sq.km and "
             << populationIncrease << " people added.\n";
    }

    void showDetails() {
        cout << "\n--- Zone Details ---\n";
        cout << "Zone Type: " << info.name << endl;
        cout << "Area: " << info.area << " sq.km" << endl;
        cout << "Population: " << info.population << endl;
        cout << "Emergency Plan: " << (info.emergencyReady ? "Ready" : "Not Ready") << endl;
        cout << "Community Program: " << (info.communityProgramRunning ? "Running" : "Inactive") << endl;
        cout << "Safety Check: " << (info.safetyChecked ? "Done" : "Pending") << endl;
        cout << "---------------------\n";
    }
};

int main() {
    Zone residential("Residential", 15, 10000);
    Zone commercial("Commercial", 10, 3000);
    Zone industrial("Industrial", 20, 5000);

    Zone* zones[] = { &residential, &commercial, &industrial };

    cout << "========================================\n";
    cout << "WELCOME MAYOR! Take charge of your zones.\n";
    cout << "Plan wisely and grow your city smartly.\n";
    cout << "========================================\n";

    int choice;
    bool active = true;

    while (active) {
        cout << "\nSelect an action:\n";
        cout << "1. Prepare Emergency Plan\n";
        cout << "2. Launch Community Program\n";
        cout << "3. Perform Safety Check\n";
        cout << "4. Show Zone Details\n";
        cout << "5. Expand Area and Population\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5) {
            int z;
            cout << "Select zone (0 = Residential, 1 = Commercial, 2 = Industrial): ";
            cin >> z;

            if (z < 0 || z > 2) {
                cout << "Invalid zone selection.\n";
                continue;
            }

            switch (choice) {
                case 1:
                    zones[z]->prepareEmergencyPlan();
                    break;
                case 2:
                    zones[z]->launchCommunityProgram();
                    break;
                case 3:
                    zones[z]->performSafetyCheck();
                    break;
                case 4:
                    zones[z]->showDetails();
                    break;
                case 5: {
                    int a, p;
                    cout << "Enter area increase (sq.km): ";
                    cin >> a;
                    cout << "Enter population increase: ";
                    cin >> p;
                    zones[z]->expandZone(a, p);
                    break;
                }
            }
        } else if (choice == 6) {
            cout << "\nGoodbye Mayor. Simulation ended.\n";
            active = false;
        } else {
            cout << "Invalid option.\n";
        }
    }

    return 0;
}
