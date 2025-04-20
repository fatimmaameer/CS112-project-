#include <iostream>
#include <string>
using namespace std;

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"

// Struct to hold zone data
struct ZoneData {
    int airPollution, waterPollution, noisePollution;
    int fossilEnergy, renewableEnergy;
    int wastePerMonth;
    string ecoActivities;
};

// Base Class
class CityZone {
protected:
    string name;
    ZoneData data;
public:
    CityZone(string n) : name(n) {}
    virtual void loadData() = 0;
    virtual void displayData() = 0;
    virtual ~CityZone() {}
};

// Derived Classes
class Residential : public CityZone {
public:
    Residential() : CityZone("Residential") {
        loadData();
    }
    void loadData() override {
        data = { 30, 25, 40, 50, 80, 100, "Tree plantation, Solar panels on rooftops" };
    }
    void displayData() override {
        cout << CYAN << BOLD << "\n========== " << name << " Zone Overview ==========" << RESET << endl;
        cout << BOLD << "Pollution: " << RESET
             << YELLOW << "Air: " << data.airPollution
             << " | Water: " << data.waterPollution
             << " | Noise: " << data.noisePollution << RESET << endl;
        cout << BOLD << "Energy:    " << RESET
             << GREEN << "Fossil: " << data.fossilEnergy
             << " | Renewable: " << data.renewableEnergy << RESET << endl;
        cout << BOLD << "Waste:     " << RESET
             << RED << data.wastePerMonth << " tons per month" << RESET << endl;
        cout << BOLD << "Eco-Activities: " << RESET
             << GREEN << data.ecoActivities << RESET << endl;
        cout << CYAN << "==========================================\n" << RESET;
    }
};

class Industrial : public CityZone {
public:
    Industrial() : CityZone("Industrial") {
        loadData();
    }
    void loadData() override {
        data = { 80, 70, 90, 200, 50, 500, "Waste recycling, Emission controls" };
    }
    void displayData() override {
        cout << CYAN << BOLD << "\n========== " << name << " Zone Overview ==========" << RESET << endl;
        cout << BOLD << "Pollution: " << RESET
             << RED << "Air: " << data.airPollution
             << " | Water: " << data.waterPollution
             << " | Noise: " << data.noisePollution << RESET << endl;
        cout << BOLD << "Energy:    " << RESET
             << YELLOW << "Fossil: " << data.fossilEnergy
             << " | Renewable: " << data.renewableEnergy << RESET << endl;
        cout << BOLD << "Waste:     " << RESET
             << RED << data.wastePerMonth << " tons per month" << RESET << endl;
        cout << BOLD << "Eco-Activities: " << RESET
             << GREEN << data.ecoActivities << RESET << endl;
        cout << CYAN << "==========================================\n" << RESET;
    }
};

class Commercial : public CityZone {
public:
    Commercial() : CityZone("Commercial") {
        loadData();
    }
    void loadData() override {
        data = { 50, 45, 60, 100, 70, 200, "LED lighting, Green rooftops" };
    }
    void displayData() override {
        cout << CYAN << BOLD << "\n========== " << name << " Zone Overview ==========" << RESET << endl;
        cout << BOLD << "Pollution: " << RESET
             << YELLOW << "Air: " << data.airPollution
             << " | Water: " << data.waterPollution
             << " | Noise: " << data.noisePollution << RESET << endl;
        cout << BOLD << "Energy:    " << RESET
             << GREEN << "Fossil: " << data.fossilEnergy
             << " | Renewable: " << data.renewableEnergy << RESET << endl;
        cout << BOLD << "Waste:     " << RESET
             << RED << data.wastePerMonth << " tons per month" << RESET << endl;
        cout << BOLD << "Eco-Activities: " << RESET
             << GREEN << data.ecoActivities << RESET << endl;
        cout << CYAN << "==========================================\n" << RESET;
    }
};

class Transport : public CityZone {
public:
    Transport() : CityZone("Transport") {
        loadData();
    }
    void loadData() override {
        data = { 60, 30, 85, 150, 90, 300, "Electric buses, Carpool lanes" };
    }
    void displayData() override {
        cout << CYAN << BOLD << "\n========== " << name << " Zone Overview ==========" << RESET << endl;
        cout << BOLD << "Pollution: " << RESET
             << RED << "Air: " << data.airPollution
             << " | Water: " << data.waterPollution
             << " | Noise: " << data.noisePollution << RESET << endl;
        cout << BOLD << "Energy:    " << RESET
             << YELLOW << "Fossil: " << data.fossilEnergy
             << " | Renewable: " << data.renewableEnergy << RESET << endl;
        cout << BOLD << "Waste:     " << RESET
             << RED << data.wastePerMonth << " tons per month" << RESET << endl;
        cout << BOLD << "Eco-Activities: " << RESET
             << GREEN << data.ecoActivities << RESET << endl;
        cout << CYAN << "==========================================\n" << RESET;
    }
};

// Utility function
void handleInvalidInput() {
    cout << RED << BOLD << "\n[!] Invalid input! Please enter a valid option.\n" << RESET;
    cin.clear();
    cin.ignore(10000, '\n');
}

// City Zones Menu
void cityZonesMenu() {
    Residential residential;
    Industrial industrial;
    Commercial commercial;
    Transport transport;

    int choice;
    do {
        system("clear");
        cout << BLUE << BOLD << "\n=========== City Zones Overview ===========\n" << RESET;
        cout << "1. " << GREEN << "Residential Zone" << RESET << endl;
        cout << "2. " << RED << "Industrial Zone" << RESET << endl;
        cout << "3. " << YELLOW << "Commercial Zone" << RESET << endl;
        cout << "4. " << CYAN << "Transport Zone" << RESET << endl;
        cout << "5. " << BOLD << "Return to Main Menu" << RESET << endl;
        cout << BOLD << "\nSelect a zone to view details: " << RESET;
        cin >> choice;

        if (cin.fail()) {
            handleInvalidInput();
            continue;
        }

        switch (choice) {
            case 1:
                system("clear");
                residential.displayData();
                break;
            case 2:
                system("clear");
                industrial.displayData();
                break;
            case 3:
                system("clear");
                commercial.displayData();
                break;
            case 4:
                system("clear");
                transport.displayData();
                break;
            case 5:
                cout << GREEN << "\nReturning to Main Menu...\n" << RESET;
                break;
            default:
                handleInvalidInput();
        }

        if (choice != 5) {
            cout << BOLD << "\nPress Enter to return to the zone menu..." << RESET;
            cin.ignore();
            cin.get();
        }

    } while (choice != 5);
}

// Main Menu
int main() {
    int mainChoice;
    do {
        system("clear");
        cout << BLUE << BOLD << "\n============== Smart Eco City Simulation ==============\n" << RESET;
        cout << "1. " << CYAN << "City Zones Overview" << RESET << endl;
        cout << "2. " << RED << "Exit Simulation" << RESET << endl;
        cout << BOLD << "\nSelect an option: " << RESET;
        cin >> mainChoice;

        if (cin.fail()) {
            handleInvalidInput();
            continue;
        }

        switch (mainChoice) {
            case 1:
                cityZonesMenu();
                break;
            case 2:
                cout << GREEN << "\nThank you for exploring the Smart Eco City Simulation!\nExiting Simulation...\n" << RESET;
                break;
            default:
                handleInvalidInput();
        }

    } while (mainChoice != 2);

    return 0;
}
