#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <limits>
#include <conio.h> // for getch()
using namespace std;

// Color codes
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define WHITE   "\033[97m"
#define MAGENTA "\033[35m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define RED     "\033[31m"

// Utility functions
void delay(int ms = 30) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void printLine(const string& line) {
    for (char c : line) {
        cout << c << flush;
        delay();
    }
    cout << endl;
}

void clearScreen() {
    system("cls||clear");
}

void pressToContinue() {
    cout << "\nPress any key to continue...";
    getch();
}

// City information displays
void showHeader() {
    cout << BOLD << CYAN << "\n===== SMART CITY ATHENS SIMULATION =====" << RESET << endl;
}

void cityOverview() {
    cout << BOLD << GREEN;
    printLine("\nWELCOME TO THE FUTURE OF URBAN LIVING");
    cout << "+***********************************************************************+\n";
    cout << "| Attribute                              ||  Value                       |\n";
    cout << "+***********************************************************************+" << RESET << endl;

    cout << YELLOW;
    cout << "| Country                                || " << WHITE << "Greece                     " << YELLOW << "|\n";
    cout << "| City                                   || " << WHITE << "Athens (Eco Simulation)    " << YELLOW << "|\n";
    cout << "| Energy Source                          || " << WHITE << "Solar, Wind, Hydro         " << YELLOW << "|\n";
    cout << "| Emission Status                        || " << WHITE << "Carbon Neutral             " << YELLOW << "|\n";
    cout << "| Smart Infrastructure                   || " << WHITE << "Yes                        " << YELLOW << "|\n";
    cout << "| Sustainable Transport                  || " << WHITE << "Electric Buses, Bikes      " << YELLOW << "|\n";
    cout << "+***********************************************************************+" << RESET << endl;
}

void generalInfo() {
    cout << BOLD << GREEN;
    printLine("\nGENERAL INFORMATION");
    cout << "+**********************************************************************+\n";
    cout << "| Attribute                              ||  Value                       |\n";
    cout << "+***********************************************************************+" << RESET << endl;

    cout << YELLOW;
    cout << "| Country                                || " << WHITE << "Greece                     " << YELLOW << "|\n";
    cout << "| Region                                 || " << WHITE << "Attica                     " << YELLOW << "|\n";
    cout << "| Coordinates                            || " << WHITE << "37.9838 N, 23.7275 E       " << YELLOW << "|\n";
    cout << "| Founding Year                          || " << WHITE << "c. 3000 BC                 " << YELLOW << "|\n";
    cout << "| Time Zone                              || " << WHITE << "UTC+2 (EET)                " << YELLOW << "|\n";
    cout << "| Climate                                || " << WHITE << "Mediterranean              " << YELLOW << "|\n";
    cout << "| Elevation (Min - Max)                  || " << WHITE << "70 - 338 meters            " << YELLOW << "|\n";
    cout << "+***********************************************************************+" << RESET << endl;
}

void populationArea() {
    cout << BOLD << GREEN;
    printLine("\nPOPULATION & AREA");
    cout << "+***********************************************************************+\n";
    cout << "| Attribute                              || Value                       |\n";
    cout << "+***********************************************************************+" << RESET << endl;

    cout << YELLOW;
    cout << "| Population (City Proper)               || " << WHITE << "Approx. 650,000            " << YELLOW << "|\n";
    cout << "| Population (Metropolitan Area)         || " << WHITE << "Approx. 3,150,000          " << YELLOW << "|\n";
    cout << "| Area (City Proper)                     || " << WHITE << "39 km^2                    " << YELLOW << "|\n";
    cout << "| Area (Metropolitan Area)               || " << WHITE << "2,928.7 km^2               " << YELLOW << "|\n";
    cout << "+**********************************************************************+" << RESET << endl;
}

void economicCultural() {
    cout << BOLD << GREEN;
    printLine("\nECONOMIC & CULTURAL HIGHLIGHTS");
    cout << "+**********************************************************************+\n";
    cout << "| Attribute                              || Value                       |\n";
    cout << "+**********************************************************************+" << RESET << endl;

    cout << YELLOW;
    cout << "| GDP (Metro Area, est.)                 || " << WHITE << "€109.65 billion (2023)     " << YELLOW << "|\n";
    cout << "| GDP per Capita                         || " << WHITE << "€29,000                    " << YELLOW << "|\n";
    cout << "| Famous Landmark                        || " << WHITE << "Acropolis of Athens        " << YELLOW << "|\n";
    cout << "| Known For                              || " << WHITE << "Philosophy, Democracy      " << YELLOW << "|\n";
    cout << "+**********************************************************************+" << RESET << endl;

    cout << BOLD << MAGENTA;
    printLine("\n        A city rooted in history, wisdom, and resilience.");
    cout << RESET << endl;
}

void displayCityInformation() {
    clearScreen();
    showHeader();
    cityOverview();
    generalInfo();
    populationArea();
    economicCultural();
    pressToContinue();
}

// Zone classes
class Building {
protected:
    int numberOfBuildings;
    int numberOfWaterPlants;
    int gallonsOfWaterProvided;
    int gallonsOfWaterConsumed;
    int gallonsOfWaterWasted;
    int gallonsOfWaterRecycled;
    
    int percentOfEnergyUsedFromCoal;
    int percentOfEnergyUsedFromWind;
    int percentOfEnergyUsedFromSolar;
    int percentOfEnergyUsedFromWater;
    
    int amountOfWasteProduced;
    int airQualityIndex;
    int ecoPoints;

public:
    virtual void displayZoneInformation() = 0;
    void printDetails() {
        cout << "Number of Buildings: " << numberOfBuildings << endl;
        cout << "Number of Water Plants: " << numberOfWaterPlants << endl;
        cout << "Gallons of Water Provided: " << gallonsOfWaterProvided << endl;
        cout << "Gallons of Water Consumed: " << gallonsOfWaterConsumed << endl;
        cout << "Gallons of Water Wasted: " << gallonsOfWaterWasted << endl;
        cout << "Gallons of Water Recycled: " << gallonsOfWaterRecycled << endl;
        cout << "Energy Usage (Coal): " << percentOfEnergyUsedFromCoal << "%" << endl;
        cout << "Energy Usage (Wind): " << percentOfEnergyUsedFromWind << "%" << endl;
        cout << "Energy Usage (Solar): " << percentOfEnergyUsedFromSolar << "%" << endl;
        cout << "Energy Usage (Water): " << percentOfEnergyUsedFromWater << "%" << endl;
        cout << "Amount of Waste Produced: " << amountOfWasteProduced << " kg" << endl;
        cout << "Air Quality Index: " << airQualityIndex << endl;
        cout << "Eco Points: " << ecoPoints << endl;
    }
    
    virtual void setgoals() {
        clearScreen();
        cout << BOLD << "\nSetting new goals for this zone..." << RESET << endl;
        pressToContinue();
    }
    
    virtual void buildnewbuildings() {
        clearScreen();
        cout << BOLD << "\nConstructing new buildings in this zone..." << RESET << endl;
        pressToContinue();
    }
    
    virtual void upgradebuildings() {
        clearScreen();
        cout << BOLD << "\nUpgrading existing buildings in this zone..." << RESET << endl;
        pressToContinue();
    }
    
    virtual void seefullreportafterchanges() {
        clearScreen();
        cout << BOLD << "\nGenerating full zone report..." << RESET << endl;
        displayZoneInformation();
        pressToContinue();
    }
};

class IndustrialZone : public Building {
public:
    void displayZoneInformation() override {
        numberOfBuildings = 20;
        numberOfWaterPlants = 3;
        gallonsOfWaterProvided = 100000;
        gallonsOfWaterConsumed = 85000;
        gallonsOfWaterWasted = 10000;
        gallonsOfWaterRecycled = 5000;
        
        percentOfEnergyUsedFromCoal = 60;
        percentOfEnergyUsedFromWind = 15;
        percentOfEnergyUsedFromSolar = 20;
        percentOfEnergyUsedFromWater = 5;
        
        amountOfWasteProduced = 7000;
        airQualityIndex = 180;
        ecoPoints = 65;
        
        cout << BOLD << "\n------ Industrial Zone Information ------" << RESET << endl;
        printDetails();
    }
};

class ResidentialZone : public Building {
public:
    void displayZoneInformation() override {
        numberOfBuildings = 50;
        numberOfWaterPlants = 2;
        gallonsOfWaterProvided = 75000;
        gallonsOfWaterConsumed = 70000;
        gallonsOfWaterWasted = 3000;
        gallonsOfWaterRecycled = 2000;

        percentOfEnergyUsedFromCoal = 30;
        percentOfEnergyUsedFromWind = 25;
        percentOfEnergyUsedFromSolar = 35;
        percentOfEnergyUsedFromWater = 10;

        amountOfWasteProduced = 3000;
        airQualityIndex = 90;
        ecoPoints = 85;

        cout << BOLD << "\n------ Residential Zone Information ------" << RESET << endl;
        printDetails();
    }
};

class CommercialZone : public Building {
public:
    void displayZoneInformation() override {
        numberOfBuildings = 35;
        numberOfWaterPlants = 2;
        gallonsOfWaterProvided = 90000;
        gallonsOfWaterConsumed = 80000;
        gallonsOfWaterWasted = 6000;
        gallonsOfWaterRecycled = 4000;
    
        percentOfEnergyUsedFromCoal = 45;
        percentOfEnergyUsedFromWind = 20;
        percentOfEnergyUsedFromSolar = 25;
        percentOfEnergyUsedFromWater = 10;
    
        amountOfWasteProduced = 5000;
        airQualityIndex = 120;
        ecoPoints = 75;
    
        cout << BOLD << "\n------ Commercial Zone Information ------" << RESET << endl;
        printDetails();
    }
};

// Panel functions
void citizenPanel() {
    clearScreen();
    cout << BOLD << RED << "\n>> CITIZEN PANEL <<" << RESET << endl;
    cout << CYAN << "\nCitizen functionality is working.\n" << RESET;
    cout << "\n1. View city services\n";
    cout << "2. Report issues\n";
    cout << "3. View community events\n";
    cout << "4. Return to main menu\n";
    
    int choice;
    cout << "\nEnter your choice: ";
    cin >> choice;
    pressToContinue();
}
void mayorPanel() {
    IndustrialZone IZ;
    ResidentialZone RZ;
    CommercialZone CZ;

    while (true) {
        // Zone selection
        clearScreen();
        cout << BOLD << BLUE << "\n>> MAYOR PANEL <<" << RESET << endl;
        cout << "Select which zone you want to manage:\n\n";
        
        int zone_choice = 1;
        char zone_key;
        bool zone_selected = false;
        
        while (!zone_selected) {
            cout << (zone_choice == 1 ? "> " : "  ") << "1. Industrial Zone\n";
            cout << (zone_choice == 2 ? "> " : "  ") << "2. Residential Zone\n";
            cout << (zone_choice == 3 ? "> " : "  ") << "3. Commercial Zone\n";
            cout << (zone_choice == 4 ? "> " : "  ") << "4. Return to Main Menu\n";
            
            zone_key = getch();
            if (zone_key == -32 || zone_key == 0) {
                zone_key = getch();
                if (zone_key == 72) { // Up arrow
                    zone_choice = (zone_choice == 1 ? 4 : zone_choice - 1);
                } else if (zone_key == 80) { // Down arrow
                    zone_choice = (zone_choice == 4 ? 1 : zone_choice + 1);
                }
            } else if (zone_key == 13) { // Enter key
                zone_selected = true;
            }
            clearScreen();
            cout << BOLD << BLUE << "\n>> MAYOR PANEL <<" << RESET << endl;
            cout << "Select which zone you want to manage:\n\n";
        }

        if (zone_choice == 4) break;

        // Display zone information
        clearScreen();
        switch(zone_choice) {
            case 1:
                IZ.displayZoneInformation();
                break;
            case 2:
                RZ.displayZoneInformation();
                break;
            case 3:
                CZ.displayZoneInformation();
                break;
        }
        pressToContinue();

        // Action selection
        clearScreen();
        cout << BOLD << BLUE << "\n>> ZONE MANAGEMENT <<" << RESET << endl;
        cout << "Select what action you want to perform:\n\n";
        
        int action_choice = 1;
        char action_key;
        bool action_selected = false;
        
        while (!action_selected) {
            cout << (action_choice == 1 ? "> " : "  ") << "1. Set zone goals\n";
            cout << (action_choice == 2 ? "> " : "  ") << "2. Build new buildings\n";
            cout << (action_choice == 3 ? "> " : "  ") << "3. Upgrade existing buildings\n";
            cout << (action_choice == 4 ? "> " : "  ") << "4. View full report\n";
            cout << (action_choice == 5 ? "> " : "  ") << "5. Back to zone selection\n";
            
            action_key = getch();
            if (action_key == -32 || action_key == 0) {
                action_key = getch();
                if (action_key == 72) { // Up arrow
                    action_choice = (action_choice == 1 ? 5 : action_choice - 1);
                } else if (action_key == 80) { // Down arrow
                    action_choice = (action_choice == 5 ? 1 : action_choice + 1);
                }
            } else if (action_key == 13) { // Enter key
                action_selected = true;
            }
            clearScreen();
            cout << BOLD << BLUE << "\n>> ZONE MANAGEMENT <<" << RESET << endl;
            cout << "Select what action you want to perform:\n\n";
        }

        if (action_choice == 5) continue;

        // Handle actions
        clearScreen();
        switch (zone_choice) {
            case 1: // Industrial
                if (action_choice == 1) IZ.setgoals();
                else if (action_choice == 2) IZ.buildnewbuildings();
                else if (action_choice == 3) IZ.upgradebuildings();
                else if (action_choice == 4) IZ.seefullreportafterchanges();
                break;
            case 2: // Residential
                if (action_choice == 1) RZ.setgoals();
                else if (action_choice == 2) RZ.buildnewbuildings();
                else if (action_choice == 3) RZ.upgradebuildings();
                else if (action_choice == 4) RZ.seefullreportafterchanges();
                break;
            case 3: // Commercial
                if (action_choice == 1) CZ.setgoals();
                else if (action_choice == 2) CZ.buildnewbuildings();
                else if (action_choice == 3) CZ.upgradebuildings();
                else if (action_choice == 4) CZ.seefullreportafterchanges();
                break;
        }
    }
}

void mayorPassword() {
    clearScreen();
    showHeader();

    cout << BLUE << "Mayor Authentication\n" << RESET;
    int input, correct = 12345;
    string dog = "apollo", color = "navy";
    
    while (true) {
        cout << "Enter password: ";
        cin >> input;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Invalid. Enter numeric value.\n" << RESET;
        } else break;
    }
    
    if (input == correct) {
        mayorPanel();
    } else {
        cout << YELLOW << "\nForgot password? Answer security questions:\n";
        string d, c;
        cout << "Dog's name: "; cin >> d;
        cout << "Favorite color: "; cin >> c;
        
        if (d == dog && c == color) {
            mayorPanel();
        } else {
            cout << RED << "Verification failed.\n" << RESET;
            pressToContinue();
        }
    }
}

void citizenPassword() {
    clearScreen();
    showHeader();
    cout << GREEN << "Citizen Authentication\n" << RESET;
    int input, correct = 2468;
    string food = "gyros", car = "tesla";
    
    while (true) {
        cout << "Enter password: ";
        cin >> input;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Invalid. Enter numeric value.\n" << RESET;
        } else break;
    }
    
    if (input == correct) {
        citizenPanel();
    } else {
        cout << YELLOW << "\nForgot password? Answer security questions:\n";
        string f, c;
        cout << "Favorite food: "; cin >> f;
        cout << "Favorite car: "; cin >> c;
        
        if (f == food && c == car) {
            citizenPanel();
        } else {
            cout << RED << "Verification failed.\n" << RESET;
            pressToContinue();
        }
    }
}



void displayMenu() {
    int choice = 1;
    char ch;
    bool firstRun = true;
    
    while (true) {
        clearScreen();
        showHeader();
        
        if (firstRun) {
            displayCityInformation();
            firstRun = false;
            continue;
        }
        
        cout << "\nPlease select your designation:\n";
        cout << "*********************************\n";
        cout << (choice == 1 ? "> " : "  ") << "1. Mayor\n";
        cout << (choice == 2 ? "> " : "  ") << "2. Citizen\n";
        cout << (choice == 3 ? "> " : "  ") << "3. Exit\n";
        cout << "4. View City Information\n";
        cout << "*********************************\n";
        cout << "Use arrow keys to navigate, Enter to select\n";
        
        ch = getch();
        if (ch == -32 || ch == 0) {
            ch = getch();
            if (ch == 72) { // Up arrow
                choice = (choice == 1 ? 4 : choice - 1);
            } else if (ch == 80) { // Down arrow
                choice = (choice == 4 ? 1 : choice + 1);
            }
        } else if (ch == 13) { // Enter key
            clearScreen();
            switch (choice) {
                case 1: 
                    mayorPassword(); 
                    break;
                case 2: 
                    citizenPassword(); 
                    break;
                case 3: 
                    cout << BOLD << GREEN << "\nThank you for using Smart City Athens Simulation!\n" << RESET;
                    return;
                case 4:
                    displayCityInformation();
                    break;
            }
            // Reset choice after returning from a panel
            choice = 1;
        }
    }
}

int main() {
    displayMenu();
    return 0;
}
