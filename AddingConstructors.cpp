#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <limits>
#include <conio.h>
#include<iomanip>
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
    int area ; 
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
    int airQualityIndex ,energyEfficientBuildings;
    int ecoPoints,points , waterConserved ;
    int coalPercent,parksAndGardens,solarPercent,windPercent;
    int waterRecycled, greenBuildings , chargingStations;

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
    bool evaluateEcoRating(int ecoPoints) {
        // Display Eco Rating based on total eco points
        cout << CYAN << "\nTotal Eco Points: " << ecoPoints << RESET << endl;
        if (ecoPoints >= 80)
            cout << GREEN << "Eco Rating:  Excellent" << RESET << endl;
        else if (ecoPoints >= 50)
            cout << YELLOW << "Eco Rating:  Moderate" << RESET << endl;
        else
            cout << RED << "Eco Rating:  Needs Improvement" << RESET << endl;

            char response;
            cout << "\nWould you like to continue? (Y/N): ";
            cin >> response;
            return (response == 'Y' || response == 'y');
    }
    void forsetgoal(){
        cout << YELLOW << "\nTotal eco points gained this session: " << points << RESET << endl;
        cout << CYAN << "Cumulative Eco Points for Industrial Zone: " << ecoPoints << RESET << endl;
        cout << "\n";
         if (ecoPoints >= 80)
               cout << GREEN << "Eco Rating:  Excellent" << RESET << endl;
         else if (ecoPoints >= 50)
               cout << YELLOW << "Eco Rating:  Moderate" << RESET << endl;
        else
               cout << RED << "Eco Rating:  Needs Improvement" << RESET << endl;
    
        system("pause");
    }
    virtual void setgoals()= 0;

    virtual void buildnewbuildings() = 0;
    
    virtual void upgradebuildings() = 0;
    
    virtual void seefullreportafterchanges()= 0;
};
class IndustrialZone : public Building {
public:
    IndustrialZone() {
        numberOfBuildings = 20;
        area = 20000;
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
    }

    void displayZoneInformation() override {
        cout << BOLD << "\n------ Industrial Zone Information ------" << RESET << endl;
        printDetails();
    };



void setgoals() override {
        cout << "\nEnter percentage of energy to come from coal (0-100): ";
        cin >> coalPercent;
    
        cout << "Enter gallons of water to recycle per day: ";
        cin >> waterRecycled;
    
        cout << "Enter number of new green-certified buildings planned: ";
        cin >> greenBuildings;
    
        // Award eco points independently
        if (coalPercent < 30) {
            points += 15;
            cout << GREEN << "+15 points for low coal usage.\n" << RESET;
        }
        if (waterRecycled > 500) {
            points += 10;
            cout << GREEN << "+10 points for high water recycling.\n" << RESET;
        }
        if (greenBuildings >= 5) {
            points += 10;
            cout << GREEN << "+10 points for green building initiative.\n" << RESET;
        }
    
        ecoPoints += points;
        forsetgoal();
        
    }

void buildnewbuildings() override {
        system("cls||clear");
        int choice;
        bool continueBuilding = true;
    
        while (continueBuilding) {
            cout << BOLD << "\nBuilding New Structures for Industrial Zone\n" << RESET;
            cout << "\nAvailable new buildings to construct:\n";
            cout << "1. Rainwater Harvesting System\n";
            cout << "2. Solar Power Station\n";
            cout << "3. Community Gardens\n";
            cout << "4. Noise Barriers\n";
            cout << "5. Wind Farm\n";
            cout << "6. Energy-efficient Factories\n";
            cout << "7. Waste Management Facility\n";
            cout << "8. Exit\n";  // Option to exit
            cout << "Enter the number of the building you want to construct (or 8 to exit): ";
            
            cin >> choice;

            if (choice > 0 && choice < 9) {
        // Valid choice
             area += 1000 ;
    }
    
            switch (choice) {
                case 1: {
                    cout << GREEN << "\nBuilding Rainwater Harvesting System...\n" << RESET;
                    ecoPoints += 10; // Assign eco points for rainwater harvesting
                    cout << GREEN << "+10 points for Rainwater Harvesting System.\n" << RESET;
                    break;
                }
                case 2: {
                    cout << GREEN << "\nBuilding Solar Power Station...\n" << RESET;
                    ecoPoints += 15; // Assign eco points for solar power station
                    cout << GREEN << "+15 points for Solar Power Station.\n" << RESET;
                    break;
                }
                case 3: {
                    cout << GREEN << "\nBuilding Community Gardens...\n" << RESET;
                    ecoPoints += 8; // Assign eco points for community gardens
                    cout << GREEN << "+8 points for Community Gardens.\n" << RESET;
                    break;
                }
                case 4: {
                    cout << GREEN << "\nBuilding Noise Barriers...\n" << RESET;
                    ecoPoints += 7; // Assign eco points for noise barriers
                    cout << GREEN << "+7 points for Noise Barriers.\n" << RESET;
                    break;
                }
                case 5: {
                    cout << GREEN << "\nBuilding Wind Farm...\n" << RESET;
                    ecoPoints += 20; // Assign eco points for wind farm
                    cout << GREEN << "+20 points for Wind Farm.\n" << RESET;
                    break;
                }
                case 6: {
                    cout << GREEN << "\nBuilding Energy-efficient Factories...\n" << RESET;
                    ecoPoints += 12; // Assign eco points for energy-efficient factories
                    cout << GREEN << "+12 points for Energy-efficient Factories.\n" << RESET;
                    break;
                }
                case 7: {
                    cout << GREEN << "\nBuilding Waste Management Facility...\n" << RESET;
                    ecoPoints += 10; // Assign eco points for waste management facility
                    cout << GREEN << "+10 points for Waste Management Facility.\n" << RESET;
                    break;
                }
                case 8: {
                    cout << GREEN << "\nExiting building construction menu...\n" << RESET;
                    continueBuilding = false; // Exit the loop
                    break;
                }
                default:
                    cout << RED << "Invalid choice, no building constructed.\n" << RESET;
                    break;
            }
    
          
        }
        evaluateEcoRating(ecoPoints);
        system("pause");
    }

void upgradebuildings() override {
        system("cls||clear");
        int choice;
        bool continueUpgrading = true;
    
        while (continueUpgrading) {
            cout << BOLD << "\nUpgrading Buildings for Industrial Zone\n" << RESET;
            cout << "\nAvailable buildings to upgrade:\n";
            cout << "1. Upgrade Rainwater Harvesting System\n";
            cout << "2. Upgrade Solar Power Station\n";
            cout << "3. Upgrade Energy-efficient Factories\n";
            cout << "4. Upgrade Waste Management Facility\n";
            cout << "5. Exit\n";  // Option to exit
            cout << "Enter the number of the building you want to upgrade (or 5 to exit): ";
            
            cin >> choice;
    
            switch (choice) {
                case 1: {
                    cout << GREEN << "\nUpgrading Rainwater Harvesting System...\n" << RESET;
                    ecoPoints += 12; // Additional eco points for upgrading rainwater harvesting
                    cout << GREEN << "+12 points for upgraded Rainwater Harvesting System.\n" << RESET;
                    break;
                }
                case 2: {
                    cout << GREEN << "\nUpgrading Solar Power Station...\n" << RESET;
                    ecoPoints += 18; // Additional eco points for upgrading solar power station
                    cout << GREEN << "+18 points for upgraded Solar Power Station.\n" << RESET;
                    break;
                }
                case 3: {
                    cout << GREEN << "\nUpgrading Energy-efficient Factories...\n" << RESET;
                    ecoPoints += 15; // Additional eco points for upgrading energy-efficient factories
                    cout << GREEN << "+15 points for upgraded Energy-efficient Factories.\n" << RESET;
                    break;
                }
                case 4: {
                    cout << GREEN << "\nUpgrading Waste Management Facility...\n" << RESET;
                    ecoPoints += 10; // Additional eco points for upgrading waste management facility
                    cout << GREEN << "+10 points for upgraded Waste Management Facility.\n" << RESET;
                    break;
                }
                case 5: {
                    cout << GREEN << "\nExiting building upgrade menu...\n" << RESET;
                    continueUpgrading = false; // Exit the loop
                    break;
                }
                default:
                    cout << RED << "Invalid choice, no upgrade made.\n" << RESET;
                    break;
            }
    
           
    }
    evaluateEcoRating(ecoPoints);
    system("pause");
}

void seefullreportafterchanges() override {
    clearScreen();
    cout << BOLD << "\n------ INDUSTRIAL ZONE FULL REPORT ------" << RESET << endl;
    cout << GREEN << "Current Status After Changes:\n" << RESET;
    
    // Display updated metrics
    cout << YELLOW;
    cout << "+---------------------------------------------+\n";
    cout << "| Buildings Constructed:      " << setw(15) << numberOfBuildings << " |\n";
    cout << "| Water Recycled (gallons):    " << setw(15) << gallonsOfWaterRecycled << " |\n";
    cout << "| Coal Energy Usage:          " << setw(14) << percentOfEnergyUsedFromCoal << "% |\n";
    cout << "| Waste Produced (kg):        " << setw(15) << amountOfWasteProduced << " |\n";
    cout << "| Air Quality Index:          " << setw(15) << airQualityIndex << " |\n";
    cout << "+---------------------------------------------+\n" << RESET;
    
    // Display eco impact
    cout << MAGENTA << "\nSustainability Impact:\n";
    cout << "Eco Points Gained: " << ecoPoints << endl;
    evaluateEcoRating(ecoPoints);
    pressToContinue();
}
};

class ResidentialZone : public Building {
public:
class ResidentialZone : public Building {
public:
    ResidentialZone() {
        numberOfBuildings = 500;
        area = 25000 ; 
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
    }

    void displayZoneInformation() override {
        cout << BOLD << "\n------ Residential Zone Information ------" << RESET << endl;
        printDetails();
    }
};

    void setgoals() override {
        cout << "\nEnter percentage of energy to come from solar (0-100): ";
        cin >> solarPercent;
    
        cout << "Enter gallons of water to conserve per day: ";
        cin >> waterConserved;
    
        cout << "Enter number of new parks and community gardens planned: ";
        cin >> parksAndGardens;
    
        // Award eco points independently
        if (solarPercent > 50) {
            points += 15;
            cout << GREEN << "+15 points for high solar energy usage.\n" << RESET;
        }
        if (waterConserved > 1000) {
            points += 10;
            cout << GREEN << "+10 points for high water conservation.\n" << RESET;
        }
        if (parksAndGardens >= 3) {
            points += 10;
            cout << GREEN << "+10 points for parks and green spaces.\n" << RESET;
        }
    
        ecoPoints += points;
    
        forsetgoal();
    }
    void upgradebuildings() override {
        system("cls||clear");
        int choice;
        bool continueUpgrading = true;
    
        while (continueUpgrading) {
            cout << BOLD << "\nUpgrading Buildings for Residential Zone\n" << RESET;
            cout << "\nAvailable buildings to upgrade:\n";
            cout << "1. Upgrade Rainwater Harvesting Systems\n";
            cout << "2. Upgrade Solar Panel Installations\n";
            cout << "3. Upgrade Energy-efficient Homes\n";
            cout << "4. Upgrade Community Gardens\n";
            cout << "5. Upgrade Waste Management Systems\n";
            cout << "6. Exit\n";
            cout << "Enter your choice (1-6): ";
    
            cin >> choice;
          
    
            switch (choice) {
                case 1: {
                    cout << GREEN << "\nUpgrading Rainwater Harvesting Systems...\n" << RESET;
                    gallonsOfWaterRecycled += 2000;
                    ecoPoints += 12;
                    cout << GREEN << "+12 points for upgraded Rainwater Harvesting Systems.\n";
                    cout << "Additional 2000 gallons of water recycling capacity added.\n" << RESET;
                    break;
                }
                case 2: {
                    cout << GREEN << "\nUpgrading Solar Panel Installations...\n" << RESET;
                    percentOfEnergyUsedFromSolar += 10;
                    if (percentOfEnergyUsedFromSolar > 100) percentOfEnergyUsedFromSolar = 100;
                    ecoPoints += 15;
                    cout << GREEN << "+15 points for upgraded Solar Panel Installations.\n";
                    cout << "Solar energy contribution increased by 10%.\n" << RESET;
                    break;
                }
                case 3: {
                    cout << GREEN << "\nUpgrading Energy-efficient Homes...\n" << RESET;
                    energyEfficientBuildings += 5;
                    ecoPoints += 18;
                    cout << GREEN << "+18 points for upgraded Energy-efficient Homes.\n";
                    cout << "5 more homes converted to energy-efficient models.\n" << RESET;
                    break;
                }
                case 4: {
                    cout << GREEN << "\nUpgrading Community Gardens...\n" << RESET;
                    parksAndGardens += 3;
                    airQualityIndex -= 5; // Improves air quality
                    ecoPoints += 10;
                    cout << GREEN << "+10 points for upgraded Community Gardens.\n";
                    cout << "Added 3 new green spaces to the neighborhood.\n" << RESET;
                    break;
                }
                case 5: {
                    cout << GREEN << "\nUpgrading Waste Management Systems...\n" << RESET;
                    amountOfWasteProduced -= 500;
                    if (amountOfWasteProduced < 0) amountOfWasteProduced = 0;
                    ecoPoints += 8;
                    cout << GREEN << "+8 points for upgraded Waste Management Systems.\n";
                    cout << "Reduced waste production by 500 kg.\n" << RESET;
                    break;
                }
                case 6: {
                    cout << GREEN << "\nReturning to previous menu...\n" << RESET;
                    continueUpgrading = false;
                    break;
                }
                default: {
                    cout << RED << "Invalid choice. Please try again.\n" << RESET;
                    break;
                }
            }
    
            if (choice >= 1 && choice <= 5) {
                cout << "\nUpgrade completed successfully!\n";
                pressToContinue();
                system("cls||clear");
            }
        }
        evaluateEcoRating(ecoPoints);
        system("pause");
    }
    
void buildnewbuildings() override {
        system("cls||clear");
        int choice;
        bool continueBuilding = true;
    
        while (continueBuilding) {
            cout << BOLD << "\nBuilding New Structures for Residential Zone\n" << RESET;
            cout << "\nAvailable new buildings to construct:\n";
            cout << "1. Rainwater Harvesting System\n";
            cout << "2. Solar Power Station\n";
            cout << "3. Community Gardens\n";
            cout << "4. Noise Barriers\n";
            cout << "5. Wind Farm\n";
            cout << "6. Energy-efficient Homes\n";
            cout << "7. Waste Management Facility\n";
            cout << "8. Green Space Parks\n";
            cout << "9. Exit\n";  // Option to exit
            cout << "Enter the number of the building you want to construct (or 9 to exit): ";
            
            cin >> choice;

              if (choice > 0 && choice < 9) {
        // Valid choice
        area += 1000;
    }
          
            switch (choice) {
                case 1: {
                    cout << GREEN << "\nBuilding Rainwater Harvesting System...\n" << RESET;
                    ecoPoints += 10; // Assign eco points for rainwater harvesting
                    cout << GREEN << "+10 points for Rainwater Harvesting System.\n" << RESET;
                    break;
                }
                case 2: {
                    cout << GREEN << "\nBuilding Solar Power Station...\n" << RESET;
                    ecoPoints += 15; // Assign eco points for solar power station
                    cout << GREEN << "+15 points for Solar Power Station.\n" << RESET;
                    break;
                }
                case 3: {
                    cout << GREEN << "\nBuilding Community Gardens...\n" << RESET;
                    ecoPoints += 8; // Assign eco points for community gardens
                    cout << GREEN << "+8 points for Community Gardens.\n" << RESET;
                    break;
                }
                case 4: {
                    cout << GREEN << "\nBuilding Noise Barriers...\n" << RESET;
                    ecoPoints += 7; // Assign eco points for noise barriers
                    cout << GREEN << "+7 points for Noise Barriers.\n" << RESET;
                    break;
                }
                case 5: {
                    cout << GREEN << "\nBuilding Wind Farm...\n" << RESET;
                    ecoPoints += 20; // Assign eco points for wind farm
                    cout << GREEN << "+20 points for Wind Farm.\n" << RESET;
                    break;
                }
                case 6: {
                    cout << GREEN << "\nBuilding Energy-efficient Homes...\n" << RESET;
                    ecoPoints += 12; // Assign eco points for energy-efficient homes
                    cout << GREEN << "+12 points for Energy-efficient Homes.\n" << RESET;
                    break;
                }
                case 7: {
                    cout << GREEN << "\nBuilding Waste Management Facility...\n" << RESET;
                    ecoPoints += 10; // Assign eco points for waste management facility
                    cout << GREEN << "+10 points for Waste Management Facility.\n" << RESET;
                    break;
                }
                case 8: {
                    cout << GREEN << "\nBuilding Green Space Parks...\n" << RESET;
                    ecoPoints += 15; // Assign eco points for green space parks
                    cout << GREEN << "+15 points for Green Space Parks.\n" << RESET;
                    break;
                }
                case 9: {
                    cout << GREEN << "\nExiting building construction menu...\n" << RESET;
                    continueBuilding = false; // Exit the loop
                    break;
                }
                default:
                    cout << RED << "Invalid choice, no building constructed.\n" << RESET;
                    break;
            }
    
            
        }
        evaluateEcoRating(ecoPoints);
        system("pause");
    }
    void seefullreportafterchanges() override {
        clearScreen();
        cout << BOLD << "\n------ RESIDENTIAL ZONE FULL REPORT ------" << RESET << endl;
        cout << GREEN << "Current Status After Changes:\n" << RESET;
        
        // Display updated metrics
        cout << YELLOW;
        cout << "+---------------------------------------------+\n";
        cout << "| Homes Upgraded:             " << setw(15) << numberOfBuildings << " |\n";
        cout << "| Water Conserved (gallons):  " << setw(15) << waterConserved << " |\n";
        cout << "| Solar Energy Usage:         " << setw(14) << percentOfEnergyUsedFromSolar << "% |\n";
        cout << "| Green Spaces Added:         " << setw(15) << parksAndGardens << " |\n";
        cout << "| Air Quality Index:          " << setw(15) << airQualityIndex << " |\n";
        cout << "+---------------------------------------------+\n" << RESET;
        
        // Display community impact
        cout << CYAN << "\nCommunity Benefits:\n";
        cout << "Improved Quality of Life: +" << (ecoPoints/10) << "%\n";
        evaluateEcoRating(ecoPoints);
        pressToContinue();
    } 
};

class CommercialZone : public Building {
public:
    CommercialZone() {
        numberOfBuildings = 35;
        area = 35000 ; 
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
    }

    void displayZoneInformation() override {
        cout << BOLD << "\n------ Commercial Zone Information ------" << RESET << endl;
        printDetails();
    }

    void setgoals() override {
        cout << "\nEnter percentage of energy to come from wind (0-100): ";
        cin >> windPercent;
    
        cout << "Enter number of new electric vehicle charging stations: ";
        cin >> chargingStations;
    
        cout << "Enter number of energy-efficient buildings planned: ";
        cin >> energyEfficientBuildings;
    
        // Award eco points independently
        if (windPercent > 40) {
            points += 15;
            cout << GREEN << "+15 points for high wind energy usage.\n" << RESET;
        }
        if (chargingStations >= 5) {
            points += 10;
            cout << GREEN << "+10 points for installing EV charging stations.\n" << RESET;
        }
        if (energyEfficientBuildings >= 4) {
            points += 10;
            cout << GREEN << "+10 points for energy-efficient building designs.\n" << RESET;
        }
    
        ecoPoints += points;
      forsetgoal();
        
    }
    void buildnewbuildings() override {
        system("cls||clear");
        int choice;
        bool continueBuilding = true;
    
        while (continueBuilding) {
            cout << BOLD << "\nBuilding New Structures for Commercial Zone\n" << RESET;
            cout << "\nAvailable new buildings to construct:\n";
            cout << "1. Rainwater Harvesting System\n";
            cout << "2. Solar Power Station\n";
            cout << "3. Community Gardens\n";
            cout << "4. Noise Barriers\n";
            cout << "5. Wind Farm\n";
            cout << "6. Energy-efficient Offices\n";
            cout << "7. Waste Management Facility\n";
            cout << "8. Eco-friendly Retail Centers\n";
            cout << "9. Exit\n";  // Option to exit
            cout << "Enter the number of the building you want to construct (or 9 to exit): ";
            
            cin >> choice;

            if (choice > 0 && choice < 9) {
        // Valid choice
        area += 1000 ; 
    }
          
            switch (choice) {
                case 1: {
                    cout << GREEN << "\nBuilding Rainwater Harvesting System...\n" << RESET;
                    ecoPoints += 10; // Assign eco points for rainwater harvesting
                    cout << GREEN << "+10 points for Rainwater Harvesting System.\n" << RESET;
                    break;
                }
                case 2: {
                    cout << GREEN << "\nBuilding Solar Power Station...\n" << RESET;
                    ecoPoints += 15; // Assign eco points for solar power station
                    cout << GREEN << "+15 points for Solar Power Station.\n" << RESET;
                    break;
                }
                case 3: {
                    cout << GREEN << "\nBuilding Community Gardens...\n" << RESET;
                    ecoPoints += 8; // Assign eco points for community gardens
                    cout << GREEN << "+8 points for Community Gardens.\n" << RESET;
                    break;
                }
                case 4: {
                    cout << GREEN << "\nBuilding Noise Barriers...\n" << RESET;
                    ecoPoints += 7; // Assign eco points for noise barriers
                    cout << GREEN << "+7 points for Noise Barriers.\n" << RESET;
                    break;
                }
                case 5: {
                    cout << GREEN << "\nBuilding Wind Farm...\n" << RESET;
                    ecoPoints += 20; // Assign eco points for wind farm
                    cout << GREEN << "+20 points for Wind Farm.\n" << RESET;
                    break;
                }
                case 6: {
                    cout << GREEN << "\nBuilding Energy-efficient Offices...\n" << RESET;
                    ecoPoints += 12; // Assign eco points for energy-efficient offices
                    cout << GREEN << "+12 points for Energy-efficient Offices.\n" << RESET;
                    break;
                }
                case 7: {
                    cout << GREEN << "\nBuilding Waste Management Facility...\n" << RESET;
                    ecoPoints += 10; // Assign eco points for waste management facility
                    cout << GREEN << "+10 points for Waste Management Facility.\n" << RESET;
                    break;
                }
                case 8: {
                    cout << GREEN << "\nBuilding Eco-friendly Retail Centers...\n" << RESET;
                    ecoPoints += 15; // Assign eco points for eco-friendly retail centers
                    cout << GREEN << "+15 points for Eco-friendly Retail Centers.\n" << RESET;
                    break;
                }
                case 9: {
                    cout << GREEN << "\nExiting building construction menu...\n" << RESET;
                    continueBuilding = false; // Exit the loop
                    break;
                }
                default:
                    cout << RED << "Invalid choice, no building constructed.\n" << RESET;
                    break;
            }
    
            
        }
        evaluateEcoRating(ecoPoints);
        system("pause");
    }
    void upgradebuildings() override {
        system("cls||clear");
        int choice;
        bool continueUpgrading = true;
    
        while (continueUpgrading) {
            cout << BOLD << "\nUpgrading Buildings for Commercial Zone\n" << RESET;
            cout << "\nAvailable buildings to upgrade:\n";
            cout << "1. Upgrade Rainwater Harvesting System\n";
            cout << "2. Upgrade Solar Power Station\n";
            cout << "3. Upgrade Energy-efficient Offices\n";
            cout << "4. Upgrade Eco-friendly Retail Centers\n";
            cout << "5. Upgrade Waste Management Facility\n";
            cout << "6. Exit\n";  // Option to exit
            cout << "Enter the number of the building you want to upgrade (or 6 to exit): ";
            
            cin >> choice;
    
            switch (choice) {
                case 1: {
                    cout << GREEN << "\nUpgrading Rainwater Harvesting System...\n" << RESET;
                    ecoPoints += 12; // Additional eco points for upgrading rainwater harvesting
                    cout << GREEN << "+12 points for upgraded Rainwater Harvesting System.\n" << RESET;
                    break;
                }
                case 2: {
                    cout << GREEN << "\nUpgrading Solar Power Station...\n" << RESET;
                    ecoPoints += 18; // Additional eco points for upgrading solar power station
                    cout << GREEN << "+18 points for upgraded Solar Power Station.\n" << RESET;
                    break;
                }
                case 3: {
                    cout << GREEN << "\nUpgrading Energy-efficient Offices...\n" << RESET;
                    ecoPoints += 15; // Additional eco points for upgrading energy-efficient offices
                    cout << GREEN << "+15 points for upgraded Energy-efficient Offices.\n" << RESET;
                    break;
                }
                case 4: {
                    cout << GREEN << "\nUpgrading Eco-friendly Retail Centers...\n" << RESET;
                    ecoPoints += 20; // Additional eco points for upgrading eco-friendly retail centers
                    cout << GREEN << "+20 points for upgraded Eco-friendly Retail Centers.\n" << RESET;
                    break;
                }
                case 5: {
                    cout << GREEN << "\nUpgrading Waste Management Facility...\n" << RESET;
                    ecoPoints += 10; // Additional eco points for upgrading waste management facility
                    cout << GREEN << "+10 points for upgraded Waste Management Facility.\n" << RESET;
                    break;
                }
                case 6: {
                    cout << GREEN << "\nExiting building upgrade menu...\n" << RESET;
                    continueUpgrading = false; // Exit the loop
                    break;
                }
                default:
                    cout << RED << "Invalid choice, no upgrade made.\n" << RESET;
                    break;
            }
    
           
        }
        evaluateEcoRating(ecoPoints);
        system("pause");
    }
    void seefullreportafterchanges() override {
        clearScreen();
        cout << BOLD << "\n------ COMMERCIAL ZONE FULL REPORT ------" << RESET << endl;
        cout << GREEN << "Current Status After Changes:\n" << RESET;
        
        // Display updated metrics
        cout << YELLOW;
        cout << "+---------------------------------------------+\n";
        cout << "| Businesses Improved:       " << setw(15) << numberOfBuildings << " |\n";
        cout << "| EV Charging Stations:      " << setw(15) << chargingStations << " |\n";
        cout << "| Wind Energy Usage:         " << setw(14) << percentOfEnergyUsedFromWind << "% |\n";
        cout << "| Energy Efficient Buildings:" << setw(15) << energyEfficientBuildings << " |\n";
        cout << "| Air Quality Index:          " << setw(15) << airQualityIndex << " |\n";
        cout << "+---------------------------------------------+\n" << RESET;
        
        // Display economic impact
        cout << BLUE << "\nEconomic Impact:\n";
        cout << "Business Productivity: +" << (ecoPoints/8) << "%\n";
        evaluateEcoRating(ecoPoints);
        pressToContinue();
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
