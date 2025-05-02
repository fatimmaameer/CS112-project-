
#include <iostream>
#include <string>

using namespace std;

#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

struct ZoneInfo {
    string name;
    int area;
    int population;
};

class Zone {
protected:
    ZoneInfo info;
    string status;
    int numBuildings; // NEW ATTRIBUTE

public:
    Zone(string name, int area, int pop)
        : numBuildings(0) {
        info.name = name;
        info.area = area;
        info.population = pop;
        status = "Standard";
    }

    virtual void displayDetails() {
        cout << CYAN << "Zone Type: " << info.name << "\n"
             << "Area: " << info.area << " sq.km\n"
             << "Population: " << info.population << "\n"
             << "Buildings: " << numBuildings << "\n"
             << "Status: " << status << "\n" << RESET;
    }

    virtual void upgradeZone() = 0;
    virtual void extendZone(int areaIncrease, int populationIncrease) = 0;
    virtual void maintenanceCheck() = 0;

    friend void mayorInspection(Zone* zone);
    virtual ~Zone() {}
};

class ResidentialZone : public Zone {
    bool solarRoofsInstalled;

public:
    ResidentialZone(int area, int pop)
        : Zone("Residential", area, pop), solarRoofsInstalled(false) {
        numBuildings = 100; // Initial building count
    }

    void upgradeZone() override {
        if (!solarRoofsInstalled) {
            cout << (GREEN "Installing solar panel roofs...\n");
            solarRoofsInstalled = true;
            status = "Upgraded with Solar Roofs";
        } else {
            cout << CYAN "Already upgraded.\n" RESET;
        }
    }

    void extendZone(int area, int pop) override {
        info.area += area;
        info.population += pop;
        numBuildings += area * 2; // Example logic
        cout << CYAN "Residential zone extended.\n" RESET;
    }

    void maintenanceCheck() override {
        cout << "Maintaining Residential Roads, Parks, and Water Systems...\n";
    }
};

class CommercialZone : public Zone {
    bool smartRetail;

public:
    CommercialZone(int area, int pop)
        : Zone("Commercial", area, pop), smartRetail(false) {
        numBuildings = 50;
    }

    void upgradeZone() override {
        if (!smartRetail) {
            cout << (GREEN "Activating Smart Retail Systems...\n");
            smartRetail = true;
            status = "Smart Commercial Zone";
        } else {
            cout << CYAN "Already upgraded.\n" RESET;
        }
    }

    void extendZone(int area, int pop) override {
        info.area += area;
        numBuildings += area;
        cout << CYAN "Commercial zone expanded.\n" RESET;
    }

    void maintenanceCheck() override {
        cout << "Maintaining Shops, Parking, and Lights...\n";
    }
};

class IndustrialZone : public Zone {
    bool wasteMgmt;

public:
    IndustrialZone(int area, int pop)
        : Zone("Industrial", area, pop), wasteMgmt(false) {
        numBuildings = 30;
    }

    void upgradeZone() override {
        if (!wasteMgmt) {
            cout << (GREEN "Installing Industrial Waste Management...\n");
            wasteMgmt = true;
            status = "Eco-Industrial Zone";
        } else {
            cout << CYAN "Already upgraded.\n" RESET;
        }
    }

    void extendZone(int area, int pop) override {
        info.area += area;
        info.population += pop;
        numBuildings += area;
        cout << CYAN "Industrial zone expanded.\n" RESET;
    }

    void maintenanceCheck() override {
        cout << "Inspecting Emissions and Robot Systems...\n";
    }
};

void mayorInspection(Zone* zone) {
    cout << GREEN "\n--- MAYOR'S REPORT ---\n" RESET;
    zone->displayDetails();
    cout << GREEN "----------------------\n" RESET;
}

void showCityMap() {
    cout << GREEN "\n\n====================== SMART CITY MAP ======================" << RESET << "\n";
    cout << CYAN << " [RESIDENTIAL ZONE]   " << RESET << " -----------\n";
    cout << CYAN << "                          |              \n";
    cout << CYAN << "      [COMMERCIAL ZONE]   " << RESET << " -----------\n";
    cout << CYAN << "                          |              \n";
    cout << CYAN << "     [INDUSTRIAL ZONE]    " << RESET << " -----------\n";
    cout << GREEN "===========================================================\n" RESET;
}

int main() {
    const int totalZones = 3;
    Zone* zones[totalZones] = {
        new ResidentialZone(15, 9000),
        new CommercialZone(10, 700),
        new IndustrialZone(25, 3000)
    };

    int choice, zoneChoice;
    bool run = true;

    cout << (GREEN "\n\nWELCOME MAYOR TO THE SMART ECO CITY SIMULATION\n" RESET);
    showCityMap();

    while (run) {
        cout << GREEN "\n\n========== MAYOR'S CONTROL PANEL ==========\n" RESET;
        cout << "1. View Zone Details\n";
        cout << "2. Upgrade Zone\n";
        cout << "3. Extend Zone\n";
        cout << "4. Maintenance Check\n";
        cout << "5. Mayor's Report\n";
        cout << "6. View City Map\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5) {
            cout << CYAN "\nChoose a Zone:\n"
                 << "0. Residential\n"
                 << "1. Commercial\n"
                 << "2. Industrial\n"
                 << "Enter: " << RESET;
            cin >> zoneChoice;

            if (zoneChoice < 0 || zoneChoice >= totalZones) {
                cout << "Invalid zone number!\n";
                continue;
            }
        }

        switch (choice) {
            case 1:
                zones[zoneChoice]->displayDetails();
                break;
            case 2:
                zones[zoneChoice]->upgradeZone();
                break;
            case 3: {
                int area, pop;
                cout << "Area to extend (sq.km): ";
                cin >> area;
                cout << "Population increase: ";
                cin >> pop;
                zones[zoneChoice]->extendZone(area, pop);
                break;
            }
            case 4:
                zones[zoneChoice]->maintenanceCheck();
                break;
            case 5:
                mayorInspection(zones[zoneChoice]);
                break;
            case 6:
                showCityMap();
                break;
            case 7:
                cout << (GREEN "\nThank you, Mayor. Exiting Simulation...\n");
                run = false;
                break;
            default:
                cout << "Invalid input.\n";
        }
    }

    for (int i = 0; i < totalZones; ++i)
        delete zones[i];

    return 0;
}

