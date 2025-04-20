#include <iostream>
#include <fstream>
#include <string>
#include <exception>
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

    virtual void loadData(const string& filename) {
        ifstream file(filename.c_str());
       // if (!file) {
         //   throw runtime_error("Could not open file: " + filename);
       // }
        file >> data.airPollution >> data.waterPollution >> data.noisePollution;
        file >> data.fossilEnergy >> data.renewableEnergy;
        file >> data.wastePerMonth;
        file.ignore();
        getline(file, data.ecoActivities);
        file.close();
    }

    virtual void displayData() = 0;
    virtual ~CityZone() {}
};

// Derived Classes
class Residential : public CityZone {
public:
    Residential() : CityZone("Residential") {
        loadData("ResidentialData.txt");
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
        loadData("IndustrialData.txt");
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
        loadData("CommercialData.txt");
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
        loadData("TransportData.txt");
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

// Exception Handling
void handleInvalidInput() {
    cout << RED << BOLD << "\n[!] Invalid input! Please enter a valid option.\n" << RESET;
}

// Main Menu
void cityZonesMenu() {
    Residential residential;
    Industrial industrial;
    Commercial commercial;
    Transport transport;

    int choice;
    do {
        cout << BLUE << BOLD << "\n=========== City Zones Overview ===========\n" << RESET;
        cout << "1. " << GREEN << "Residential" << RESET << endl;
        cout << "2. " << RED << "Industrial" << RESET << endl;
        cout << "3. " << YELLOW << "Commercial" << RESET << endl;
        cout << "4. " << CYAN << "Transport" << RESET << endl;
        cout << "5. " << BOLD << "Exit to Main Menu" << RESET << endl;
        cout << BOLD << "\nSelect a zone to view details: " << RESET;
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    residential.displayData();
                    break;
                case 2:
                    industrial.displayData();
                    break;
                case 3:
                    commercial.displayData();
                    break;
                case 4:
                    transport.displayData();
                    break;
                case 5:
                    cout << GREEN << "\nReturning to Main Menu...\n" << RESET;
                    break;
                default:
                    cout << RED << "\n[!] Invalid option! Please choose from 1-5.\n" << RESET;
            }
        } catch (exception& e) {
            cin.clear();
            cin.ignore(10000, '\n');
            handleInvalidInput();
        }

    } while (choice != 5);
}

int main() {
    int mainChoice;
    do {
        cout << BLUE << BOLD << "\n============== Smart Eco City Simulation ==============\n" << RESET;
        cout << "1. " << CYAN << "City Zones Overview" << RESET << endl;
        cout << "2. " << RED << "Exit Simulation" << RESET << endl;
        cout << BOLD << "\nSelect an option: " << RESET;
        cin >> mainChoice;

        try {
            switch (mainChoice) {
                case 1:
                    cityZonesMenu();
                    break;
                case 2:
                    cout << GREEN << "\nThank you for exploring the Smart Eco City Simulation!\nExiting Simulation...\n" << RESET;
                    break;
                default:
                    cout << RED << "\n[!] Invalid option! Please choose 1 or 2.\n" << RESET;
            }
        } catch (exception& e) {
            cin.clear();
            cin.ignore(10000, '\n');
            handleInvalidInput();
        }

    } while (mainChoice != 2);

    return 0;
}
