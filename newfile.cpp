#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <limits>
#include <conio.h>
#include<iomanip>
#include <vector> 
#include <algorithm>
#include <fstream>

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
    cout <<YELLOW<< "\nPress any key to continue...";
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
    int airQualityIndex ,energyEfficientBuildings;
    int ecoPoints,points , waterConserved ;
    int coalPercent,parksAndGardens,solarPercent,windPercent;
    int waterRecycled, greenBuildings , chargingStations;

public:
    virtual void displayZoneInformation() = 0;
    void printDetails() {
    system("CLS");  // Clears the console screen on Windows

    cout << GREEN << "Number of Buildings: " << numberOfBuildings << RESET << endl;
    cout << GREEN << "Number of Water Plants: " << numberOfWaterPlants << RESET << endl;

    cout << GREEN << "Gallons of Water Provided: " << gallonsOfWaterProvided << RESET << endl;
    cout << GREEN << "Gallons of Water Consumed: " << gallonsOfWaterConsumed << RESET << endl;
    cout << GREEN << "Gallons of Water Wasted: " << gallonsOfWaterWasted << RESET << endl;
    cout << GREEN << "Gallons of Water Recycled: " << gallonsOfWaterRecycled << RESET << endl;

    cout << GREEN << "Energy Usage (Coal): " << percentOfEnergyUsedFromCoal << "%" << RESET << endl;
    cout << GREEN << "Energy Usage (Wind): " << percentOfEnergyUsedFromWind << "%" << RESET << endl;
    cout << GREEN << "Energy Usage (Solar): " << percentOfEnergyUsedFromSolar << "%" << RESET << endl;
    cout << GREEN << "Energy Usage (Water): " << percentOfEnergyUsedFromWater << "%" << RESET << endl;

    cout << GREEN << "Amount of Waste Produced: " << amountOfWasteProduced << " kg" << RESET << endl;
    cout << GREEN << "Air Quality Index: " << airQualityIndex << RESET << endl;

    cout << GREEN << "Eco Points: " << ecoPoints << RESET << endl;
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

void setgoals() override {
cout << CYAN << "\nEnter percentage of energy to come from coal (0-100): " << RESET;
cin >> coalPercent;

cout << BLUE << "Enter gallons of water to recycle per day: " << RESET;
cin >> waterRecycled;

cout << GREEN << "Enter number of new green-certified buildings planned: " << RESET;
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
    cout << BOLD << BLUE << "\nBuilding New Structures for Industrial Zone\n" << RESET;

    cout << MAGENTA<< "\nAvailable new buildings to construct:\n" << RESET;
    cout << MAGENTA<< "1. Rainwater Harvesting System\n";
    cout << MAGENTA<<"2. Solar Power Station\n";
    cout << MAGENTA<< "3. Community Gardens\n";
    cout << MAGENTA<<"4. Noise Barriers\n";
    cout << MAGENTA<<"5. Wind Farm\n";
    cout << MAGENTA<<"6. Energy-efficient Factories\n";
    cout << MAGENTA<<"7. Waste Management Facility\n";
    cout << RED << "8. Exit\n" << RESET;

    cout << GREEN << "Enter the number of the building you want to construct (or 8 to exit): " << RESET;
    cin >> choice;


    
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
    cout << BOLD << BLUE << "\nUpgrading Buildings for Industrial Zone\n" << RESET;

    cout << MAGENTA<< "\nAvailable buildings to upgrade:\n" << RESET;
    cout << MAGENTA<< "1. Upgrade Rainwater Harvesting System\n";
    cout << MAGENTA<<"2. Upgrade Solar Power Station\n";
    cout << MAGENTA<<"3. Upgrade Energy-efficient Factories\n";
    cout << MAGENTA<<"4. Upgrade Waste Management Facility\n";
    cout << RED << "5. Exit\n" << RESET;

    cout << GREEN << "Enter the number of the building you want to upgrade (or 5 to exit): " << RESET;
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
   cout << BOLD << YELLOW;
cout << "+---------------------------------------------+\n";
cout << "| " << GREEN << "Buildings Constructed:    " << YELLOW << setw(15) << numberOfBuildings << " |\n";
cout << "| " << GREEN << "Water Recycled (gallons):" << YELLOW << setw(15) << gallonsOfWaterRecycled << " |\n";
cout << "| " << GREEN << "Coal Energy Usage:       " << YELLOW << setw(14) << percentOfEnergyUsedFromCoal << "% |\n";
cout << "| " << GREEN << "Waste Produced (kg):     " << YELLOW << setw(15) << amountOfWasteProduced << " |\n";
cout << "| " << GREEN << "Air Quality Index:       " << YELLOW << setw(15) << airQualityIndex << " |\n";
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
    void setgoals() override {
        cout << CYAN << "\nEnter percentage of energy to come from solar (0-100): " << RESET;
cin >> solarPercent;

cout << BLUE << "Enter gallons of water to conserve per day: " << RESET;
cin >> waterConserved;

cout << GREEN << "Enter number of new parks and community gardens planned: " << RESET;
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

    cout << BOLD << BLUE << "\nUpgrading Buildings for Residential Zone\n" << RESET;

    cout << CYAN << "\nAvailable buildings to upgrade:\n" << RESET;
    cout << CYAN << "1. Upgrade Rainwater Harvesting Systems\n";
    cout << CYAN<<"2. Upgrade Solar Panel Installations\n";
    cout << CYAN<<"3. Upgrade Energy-efficient Homes\n";
    cout << CYAN<<"4. Upgrade Community Gardens\n";
    cout <<CYAN<< "5. Upgrade Waste Management Systems\n";
    cout << RED << "6. Exit\n" << RESET;

    cout << GREEN << "Enter your choice (1-6): " << RESET;
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
                    cout <<BLUE<<"5 more homes converted to energy-efficient models.\n" << RESET;
                    break;
                }
                case 4: {
                    cout << GREEN << "\nUpgrading Community Gardens...\n" << RESET;
                    parksAndGardens += 3;
                    airQualityIndex -= 5; // Improves air quality
                    ecoPoints += 10;
                    cout << GREEN << "+10 points for upgraded Community Gardens.\n";
                    cout <<BLUE<< "Added 3 new green spaces to the neighborhood.\n" << RESET;
                    break;
                }
                case 5: {
                    cout << GREEN << "\nUpgrading Waste Management Systems...\n" << RESET;
                    amountOfWasteProduced -= 500;
                    if (amountOfWasteProduced < 0) amountOfWasteProduced = 0;
                    ecoPoints += 8;
                    cout << GREEN << "+8 points for upgraded Waste Management Systems.\n";
                    cout << BLUE<<"Reduced waste production by 500 kg.\n" << RESET;
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
                cout <<GREEN<< "\nUpgrade completed successfully!\n";
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
            cout << MAGENTA<<"\nAvailable new buildings to construct:\n";
            cout <<MAGENTA<<"1. Rainwater Harvesting System\n";
            cout <<MAGENTA<<"2. Solar Power Station\n";
            cout <<MAGENTA<< "3. Community Gardens\n";
            cout << MAGENTA<<"4. Noise Barriers\n";
            cout << MAGENTA<<"5. Wind Farm\n";
            cout << MAGENTA<<"6. Energy-efficient Homes\n";
            cout << MAGENTA<<"7. Waste Management Facility\n";
            cout <<MAGENTA<< "8. Green Space Parks\n";
            cout << RED<<"9. Exit\n";  // Option to exit
            cout << CYAN<<"Enter the number of the building you want to construct (or 9 to exit): ";
            
            cin >> choice;
    
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
        cout <<BLUE<< "Improved Quality of Life: +" << (ecoPoints/10) << "%\n";
        evaluateEcoRating(ecoPoints);
        pressToContinue();
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
    void setgoals() override {
        cout << CYAN<< "\nEnter percentage of energy to come from wind (0-100): ";
        cin >> windPercent;
    
        cout << BLUE << "Enter number of new electric vehicle charging stations: ";
        cin >> chargingStations;
    
        cout << GREEN << "Enter number of energy-efficient buildings planned: ";
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
            cout << MAGENTA<<"\nAvailable new buildings to construct:\n";
            cout << MAGENTA<<"1. Rainwater Harvesting System\n";
            cout << MAGENTA<<"2. Solar Power Station\n";
            cout << MAGENTA<<"3. Community Gardens\n";
            cout << MAGENTA<<"4. Noise Barriers\n";
            cout << MAGENTA<<"5. Wind Farm\n";
            cout << MAGENTA<<"6. Energy-efficient Offices\n";
            cout << MAGENTA<<"7. Waste Management Facility\n";
            cout << MAGENTA<<"8. Eco-friendly Retail Centers\n";
            cout << RED<<"9. Exit\n";  // Option to exit
            cout << CYAN<<"Enter the number of the building you want to construct (or 9 to exit): ";
            
            cin >> choice;
    
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
            cout << MAGENTA<<"\nAvailable buildings to upgrade:\n";
            cout << MAGENTA<<"1. Upgrade Rainwater Harvesting System\n";
            cout << MAGENTA<<"2. Upgrade Solar Power Station\n";
            cout << MAGENTA<<"3. Upgrade Energy-efficient Offices\n";
            cout << MAGENTA<<"4. Upgrade Eco-friendly Retail Centers\n";
            cout << MAGENTA<<"5. Upgrade Waste Management Facility\n";
            cout << RED<<"6. Exit\n";  // Option to exit
            cout <<CYAN<< "Enter the number of the building you want to upgrade (or 6 to exit): ";
            
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

// Citizen structure
struct Citizen {
    string username;
    string password;
    int ecoPoints;
};
// Add this with your other constants and structures
const int NUM_CITIES = 5;

struct City {
    string name;
    int ecoScore;
    int renewablePercent;
    int transportPercent;
    int greenPercent;
};
// Global constants and variables
const int MAX_CITIZENS = 10;
Citizen citizens[MAX_CITIZENS];
int citizenCount = 0;
int currentCitizenIndex = -1;



void signup() {
    if (citizenCount >= MAX_CITIZENS) {
        cout << CYAN << "Citizen limit reached.\n" << RESET;
        return;
    }

    string uname, pass;
    cout << CYAN << "Enter username: " << RESET;
    cin >> uname;

    for (int i = 0; i < citizenCount; i++) {
        if (citizens[i].username == uname) {
            cout << CYAN << "Username already exists.\n" << RESET;
            return;
        }
    }

    cout << CYAN << "Enter password: " << RESET;
    cin >> pass;

    citizens[citizenCount++] = {uname, pass, 0};
    cout << CYAN << "Signup successful!\n" << RESET;
};

void login() {
    string uname, pass;
    cout << CYAN << "Enter username: " << RESET;
    cin >> uname;
    cout << CYAN << "Enter password: " << RESET;
    cin >> pass;

    for (int i = 0; i < citizenCount; i++) {
        if (citizens[i].username == uname && citizens[i].password == pass) {
            currentCitizenIndex = i;
            cout << CYAN << "Login successful. Welcome, " << citizens[i].username << "!\n" << RESET;
            return;
        }
    }
    cout << CYAN << "Invalid credentials.\n" << RESET;
}

// Update leaderboard sort
bool compareCitizens(const Citizen &a, const Citizen &b) {
    return a.ecoPoints > b.ecoPoints;
}

void sortCitizens() {
    sort(citizens, citizens + citizenCount, compareCitizens);
}

// Show leaderboard (table view)
void showLeaderboard() {
    clearScreen();
    cout << CYAN << "=== LEADERBOARD ===\n" << WHITE;
    sortCitizens();
    cout << "Rank\tUsername\tEco Points\n";
    cout << "----------------------------------\n";
    for (int i = 0; i < citizenCount; i++) {
        cout << i + 1 << "\t" << citizens[i].username << "\t\t" << citizens[i].ecoPoints << endl;
    }
    
    if (currentCitizenIndex != -1) {
        int playerRank = -1;
        for (int i = 0; i < citizenCount; i++) {
            if (citizens[i].username == citizens[currentCitizenIndex].username) {
                playerRank = i + 1;
                break;
            }
        }
        cout << CYAN << "\nYour position: " << playerRank << " of " << citizenCount << RESET << endl;
    }
    
    cout << CYAN << "\nPress Enter to return... " << RESET;
    cin.ignore();
    cin.get();
}
void sortCities(City cities[]) {
    // Simple selection sort
    for (int i = 0; i < NUM_CITIES - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < NUM_CITIES; j++) {
            if (cities[j].ecoScore > cities[maxIndex].ecoScore) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(cities[i], cities[maxIndex]);
        }
    }
};


void displayCitiesLeaderboard() {
    City cities[NUM_CITIES] = {
        {"Copenhagen", 95, 85, 70, 30},
        {"Stockholm", 90, 80, 65, 40},
        {"Amsterdam", 85, 75, 60, 35},
        {"Vienna", 83, 78, 55, 45},
        {"Athens", 80, 65, 50, 25}
    };

    sortCities(cities);

    cout << "\n\n";
    cout << "======================================================\n";
    cout << "|        TOP SUSTAINABLE CITIES LEADERBOARD         |\n";
    cout << "======================================================\n";
    cout << "| Rank | City       | Eco | Clean | Public | Green  |\n";
    cout << "|      |            |Score| Energy| Trans. | Spaces |\n";
    cout << "|------|------------|-----|-------|--------|--------|\n";

    for (int i = 0; i < NUM_CITIES; i++) {
        cout << "| " << setw(4) << right << i+1 << " "
             << "| " << setw(10) << left << cities[i].name << " "
             << "| " << setw(3) << right << cities[i].ecoScore << " "
             << "| " << setw(5) << right << cities[i].renewablePercent << "%"
             << "| " << setw(6) << right << cities[i].transportPercent << "%"
             << "| " << setw(6) << right << cities[i].greenPercent << "% |\n";

        if (cities[i].name == "Athens") {
            cout << "|------|------------|-----|-------|--------|--------|\n";
            cout << "|             *** ATHENS SPECIAL MENTION ***        |\n";
            cout << "|  Fastest improving city in renewable energy (65%) |\n";
            cout << "|------|------------|-----|-------|--------|--------|\n";
        }
    }
    cout << "======================================================\n\n";
    
    cout << YELLOW << "Press Enter to continue... " << RESET;
    cin.ignore();
    cin.get();
}
// Show leaderboard (histogram view)
void showHistogramLeaderboard() {
    clearScreen();
    
    if (citizenCount == 0) {
        cout << CYAN << "No citizens registered yet.\n" << RESET;
        cout << CYAN << "\nPress Enter to return... " << RESET;
        cin.ignore();
        cin.get();
        return;
    }

    sortCitizens(); // Sort by ecoPoints descending
    
    cout << CYAN << "________________________________________________________\n";
    cout << "               ECO POINTS LEADERBOARD\n";
    cout << "________________________________________________________\n\n" << RESET;

    int maxPoints = citizens[0].ecoPoints;
    if (maxPoints == 0) maxPoints = 1;

    cout << WHITE << "RANK  PLAYER NAME         ECO POINTS DISTRIBUTION\n";
    cout << "--------------------------------------------------------\n" << RESET;

    for (int i = 0; i < citizenCount; i++) {
        int barLength = max(1, (citizens[i].ecoPoints * 40) / maxPoints);
        
        cout << WHITE << setw(2) << right << i+1 << ".  " << RESET;
        
        string displayName = citizens[i].username.substr(0, 15);
        cout << CYAN << setw(15) << left << displayName << "  " << RESET;
        
        if (i == 0) cout << GREEN;
        else if (i == 1) cout << YELLOW;
        else if (i == 2) cout << BLUE;
        else cout << MAGENTA;
        
        for (int j = 0; j < barLength; j++) {
            cout << "#";
        }
        cout << RESET;
        
        cout << "  " << citizens[i].ecoPoints;
        if (i == currentCitizenIndex) {
            cout << BOLD << GREEN << " (YOU)" << RESET;
        }
        cout << endl;
    }

    cout << CYAN << "\n--------------------------------------------------------\n";
    cout << "   YOUR CURRENT POSITION: ";
    
    bool found = false;
    for (int i = 0; i < citizenCount; i++) {
        if (citizens[i].username == citizens[currentCitizenIndex].username) {
            cout << i+1 << " of " << citizenCount << RESET << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Not ranked" << RESET << endl;
    }
    
    cout << CYAN << "--------------------------------------------------------\n" << RESET;
    cout << CYAN << "Press Enter to return... " << RESET;
    cin.ignore();
    cin.get();
}
void ecoTriviaQuiz() {
    clearScreen();
    cout << "=== ECO TRIVIA QUIZ ===\n";

    const int QUESTION_COUNT = 10;
    string questions[QUESTION_COUNT] = {
        "1. What is the most eco-friendly energy source?\n   a) Solar\n   b) Coal\n   c) Oil\n   d) Gas",
        "2. What is the term for reusing waste materials?\n   a) Recycling\n   b) Upcycling\n   c) Downcycling\n   d) Reusing",
        "3. Which gas is primarily responsible for global warming?\n   a) Oxygen\n   b) Nitrogen\n   c) Carbon Dioxide\n   d) Hydrogen",
        "4. What percentage of Earth's water is freshwater available for human use?\n   a) 1%\n   b) 10%\n   c) 25%\n   d) 50%",
        "5. Which of these items takes the longest to decompose in nature?\n   a) Banana peel\n   b) Plastic bottle\n   c) Paper bag\n   d) Cotton shirt",
        "6. What is the main benefit of using LED light bulbs?\n   a) They're cheaper to buy\n   b) They last longer and use less energy\n   c) They produce more heat\n   d) They come in more colors",
        "7. Which of these is NOT a renewable energy source?\n   a) Wind\n   b) Solar\n   c) Natural gas\n   d) Hydroelectric",
        "8. What is the '3 R's' of waste management?\n   a) Reduce, Reuse, Recycle\n   b) Read, Write, Arithmetic\n   c) Run, Rest, Relax\n   d) Red, Green, Blue",
        "9. Which activity contributes most to your carbon footprint?\n   a) Taking a 10-minute shower\n   b) Eating a vegetarian meal\n   c) Riding a bicycle to work\n   d) Air travel",
        "10. What is the primary cause of deforestation worldwide?\n   a) Urban development\n   b) Agriculture expansion\n   c) Natural disasters\n   d) Mining operations"
    };

    char correctAnswers[QUESTION_COUNT] = {'a', 'a', 'c', 'a', 'b', 'b', 'c', 'a', 'd', 'b'};
    string explanations[QUESTION_COUNT] = {
        "Solar energy is renewable and produces no greenhouse gas emissions during operation.",
        "Recycling is the process of converting waste materials into new materials and objects.",
        "Carbon dioxide is the primary greenhouse gas emitted through human activities.",
        "Only about 1% of Earth's water is freshwater available for human use, the rest is saltwater or locked in ice caps.",
        "Plastic bottles can take up to 450 years to decompose in nature!",
        "LED bulbs use up to 90% less energy and last 25 times longer than incandescent lighting.",
        "Natural gas is a fossil fuel and non-renewable, while the others are renewable sources.",
        "The 3 R's stand for Reduce (consumption), Reuse (products), and Recycle (materials).",
        "Air travel has a much larger carbon footprint than the other activities listed.",
        "Agriculture expansion, particularly for cattle ranching and crops like soy and palm oil, is the leading cause."
    };

    int score = 0;
    for (int i = 0; i < QUESTION_COUNT; i++) {
        string answer;
        cout << questions[i] << endl;
        cout << "Your answer: ";
        cin >> answer;

        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

        if (answer[0] == correctAnswers[i]) {
            cout << "Correct! " << explanations[i] << "\n\n";
            score++;
        } else {
            cout << "Incorrect. The correct answer is " << correctAnswers[i] << ". " << explanations[i] << "\n\n";
        }
    }

    citizens[currentCitizenIndex].ecoPoints += score * 2;
    cout << "Quiz complete! You scored " << score << " out of 10.\n";
    cout << "You earned " << (score * 2) << " eco points!\n";
}
;

const int ROWS = 10;
const int COLS = 17;

string mazeStr[ROWS] = {
    "#################",
    "#S     X   X    #",
    "# ### ###   ### #",
    "#   X   # X   # #",
    "##### # # ### # #",
    "#     #   #   # #",
    "# ### ### ### # #",
    "#   #   X   #   #",
    "# X ### ### ###E#",
    "#################"
};

char maze[ROWS][COLS];

void initializeMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = mazeStr[i][j];
        }
    }
}


void mazeGame() {
   
       clearScreen();
    initializeMaze();
    int posX = 1, posY = 1, steps = 0, penalty = 0;
    char move;

    while (true) {
        clearScreen();
        cout << "Steps: " << steps << " | Penalties: " << penalty 
             << " | Points: " << citizens[currentCitizenIndex].ecoPoints << "\n\n";

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                cout << ((i == posX && j == posY) ? 'P' : maze[i][j]);
            }
            cout << endl;
        }
        cout <<CYAN<< "\nInstructions: Use W (up), A (left), S (down), D (right) to move.\n";
        cout <<BLUE<< "Your current position is 'P'.\n";
        cout <<GREEN<<"Try to reach 'E' for the recycling center. Avoid the waste ('X').\n";

        cout <<CYAN<<"\nEnter your move (W/A/S/D): ";
        cin >> move;
        move = tolower(move);

        int newX = posX, newY = posY;
        if (move == 'w') newX--;
        else if (move == 'a') newY--;
        else if (move == 's') newX++;
        else if (move == 'd') newY++;
        else continue;

        if (maze[newX][newY] == '#') continue;

        posX = newX;
        posY = newY;
        steps++;

        if (maze[posX][posY] == 'X') {
            citizens[currentCitizenIndex].ecoPoints = max(0, citizens[currentCitizenIndex].ecoPoints - 5);
            penalty++;
        } else if (maze[posX][posY] == 'E') {
            int earned = max(10, 30 - (penalty * 5));
            citizens[currentCitizenIndex].ecoPoints += earned;
            cout << "Reached the recycling center! Points earned: " << earned << "\n";
            break;
        }
    }
};

void patternMatching() {
  clearScreen();
    cout << "=== ECO PATTERN MATCHING ===\n";
//    srand(time(0));

    const int PATTERN_COUNT = 5;
    const int MAX_PATTERN_LENGTH = 7;
    char patterns[PATTERN_COUNT][MAX_PATTERN_LENGTH] = {
        {'R', 'E', 'C', 'Y', 'C', 'L', 'E'},
        {'G', 'R', 'E', 'E', 'N', '\0', '\0'},
        {'S', 'U', 'S', 'T', 'A', 'I', 'N'},
        {'C', 'L', 'I', 'M', 'A', 'T', 'E'},
        {'E', 'C', 'O', '\0', '\0', '\0', '\0'}
    };
    string fullWords[PATTERN_COUNT] = {"RECYCLE", "GREEN", "SUSTAIN", "CLIMATE", "ECO"};
    int score = 0;

    for (int i = 0; i < PATTERN_COUNT; i++) {
        cout << "Pattern " << i + 1 << ": ";
        for (int j = 0; j < MAX_PATTERN_LENGTH && patterns[i][j] != '\0'; j++) {
            cout << patterns[i][j] << " ";
        }
        cout << "\nYour guess: ";
        string guess;
        cin >> guess;
        transform(guess.begin(), guess.end(), guess.begin(), ::toupper);

        if (guess == fullWords[i]) {
            cout <<GREEN<< "Correct! +5 points\n";
            score += 5;
        } else {
            cout <<RED<< "Wrong! The word was: " << fullWords[i] << "\n";
        }
    }

    citizens[currentCitizenIndex].ecoPoints += score;
    cout <<GREEN<< "Game over! You earned: " << score << " points\n";
};



// Climate summit (stub)
void climateSummit() {
    const int ROUNDS = 5;
    const int POLICIES_PER_ROUND = 3;
    int correctChoices = 0;  // Track correct answers (like your 'score')

    string policies[ROUNDS][POLICIES_PER_ROUND] = {
        {"Subsidize fossil fuels to reduce fuel prices.", 
         "Ban single-use plastics and promote reusables.", 
         "Cut taxes for private car manufacturers."},
        {"Invest heavily in public transportation.", 
         "Expand deforestation to build roads.", 
         "Delay climate action by 20 years."},
        {"Mandate solar panels on all new buildings.", 
         "Reduce funding for clean energy research.", 
         "Promote coal as a clean alternative."},
        {"Introduce a global carbon tax.", 
         "Support oil drilling in the Arctic.", 
         "Ignore emissions from big industries."},
        {"Provide incentives for zero-waste lifestyle.", 
         "Legalize dumping industrial waste in oceans.", 
         "Ban renewable energy advertisements."}
    };

    int bestChoice[ROUNDS] = {1, 0, 0, 0, 0}; // Correct answers (0-based index)

    cout << CYAN << "?? WELCOME TO THE GLOBAL CLIMATE SUMMIT\n" << RESET;
    cout <<  CYAN << "You are a delegate voting on future-saving policies.\n";
    cout << CYAN<<"Choose wisely — the planet depends on you!\n\n" << RESET;
    cout << CYAN << "Press Enter to begin...\n" << RESET;
    cin.ignore();

    for (int round = 0; round < ROUNDS; round++) {
        cout << "\n" << CYAN << "?? Round " << round + 1 << ": Climate Policy Voting\n" << RESET;

        for (int i = 0; i < POLICIES_PER_ROUND; i++) {
            cout << CYAN << (i + 1) << ". " << WHITE << policies[round][i] << "\n";
        }

        int choice;
        cout << CYAN << "\nCast your vote (1-3): " << RESET;
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << CYAN << "Invalid choice. Please vote again (1-3): " << RESET;
            cin >> choice;
        }

        cout << WHITE << "\n??? Council is reviewing your decision...\n";
        // sleep(2);

        if (choice - 1 == bestChoice[round]) {
            cout << CYAN << "? The Council PASSED your policy!\n";
            correctChoices++;  // Increment correct answers (like your 'score++')
            cout << WHITE << "✓ Correct choice!\n";
        } else {
            cout << CYAN << "? Your policy was REJECTED by the council.\n";
            cout << WHITE << "✗ Incorrect choice.\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << CYAN << "\nPress Enter to continue...\n" << RESET;
        cin.get();
    }

    // Final scoring (like your 'score * 2' system)
    int ecoPointsEarned = correctChoices * 2;
    citizens[currentCitizenIndex].ecoPoints += ecoPointsEarned;  // Update global score

    cout << "\n" << CYAN << "?? Summit Concluded!\n" << RESET;
    cout << WHITE << "Correct choices: " << correctChoices << "/" << ROUNDS << "\n";
    cout << "Eco Points earned: " << ecoPointsEarned << "\n" << RESET;
};


void displayFromFile(const string& filename) {
    static string currentFilename;
    static ifstream file;
    static int currentLine = 0;

    // If this is a different file than last time, reset everything
    if (filename != currentFilename) {
        if (file.is_open()) {
            file.close();
        }
        currentFilename = filename;
        currentLine = 0;
        file.open(filename);
        if (!file) {
            cout <<RED<< "Error: Unable to open " << filename << endl;
            return;
        }
    }

    string line;
    if (getline(file, line)) {
        currentLine++;
        cout << currentLine << ". " << line << endl;
    } else {
        cout <<BLUE<< "Thats all for today!!" << endl;
        file.close();
        currentLine = 0;
    }
}

void tipsFactsDashboard() {
    int choice;
    
    while (true) {
        cout <<GREEN<< "\n==== Sustainability Tips & Facts ====\n";
        cout <<GREEN<< "1. View Next Tip\n";
        cout <<GREEN<< "2. View Next Fact\n";
        cout <<GREEN<<"3. Return to Main Dashboard\n";
        cout <<RED<< "Enter your choice: ";
        
        // Clear any previous errors and ignore remaining input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (!(cin >> choice)) {
            cout <<RED<< "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout <<BLUE<< "\n-- Sustainable Living Tips --\n";
                displayFromFile("tips.txt");
                break;
            case 2:
                cout <<GREEN<< "\n-- Climate & Energy Facts --\n";
                displayFromFile("facts.txt");
                break;
            case 3:
                cout <<YELLOW<< "Returning to main dashboard...\n";
                return;
            default:
                cout <<RED<< "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    }
}




// Game dashboard
void playGame() {
    if (currentCitizenIndex == -1) {
        cout << CYAN << "Please login first.\n" << RESET;
        return;
    }

    int choice;
    do {
        clearScreen();
        cout <<YELLOW << "=== SMART CITY GAME ===\n" << RESET;
        cout << "Logged in as: " << citizens[currentCitizenIndex].username
             << " (Points: " << citizens[currentCitizenIndex].ecoPoints << ")\n";
        cout << WHITE;
        cout << MAGENTA<<"1. Play Eco Trivia Quiz\n";
        cout <<MAGENTA<< "2. Play Maze Game\n";
        cout << MAGENTA<<"3. Play Pattern Matching\n";
        cout <<MAGENTA<< "4. Participate in Climate Summit\n";
        cout <<MAGENTA<< "5. View Citizen Leaderboard (Table)\n";
        cout <<MAGENTA<< "6. View Citizen Leaderboard (Histogram)\n";
        cout <<MAGENTA<<"7. Daily Tips and Facts\n"; 
        cout <<RED<< ". Logout\n";
        cout <<CYAN << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0;
        }

        switch (choice) {
            case 1: ecoTriviaQuiz(); break;
            case 2: mazeGame(); break;
            case 3: patternMatching(); break;
            case 4: climateSummit(); break;
            case 5: showLeaderboard(); break;
            case 6: showHistogramLeaderboard(); break;
            
            case 7: tipsFactsDashboard(); break;
            case 8:
                cout << CYAN << "Logging out...\n" << RESET;
                currentCitizenIndex = -1;
                return;
            default: cout << CYAN << "Invalid choice. Try again.\n" << RESET;
        }

    } while (true);
}



// Panel functions
void citizenPanel (){
    int choice;
    do {
        clearScreen();
        cout << CYAN << "==== SMART CITY GAME DASHBOARD ====\n" << RESET;
        cout << WHITE;
        cout << MAGENTA<<"1. View Global Cities Leaderboard\n";  // New option
        cout << MAGENTA<<"2. Signup\n";
        cout << MAGENTA<<"3. Login\n";
        cout << MAGENTA<<"4. Play Game\n";
        cout << RED<<"5. Exit\n";
        cout <<GREEN<< "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: displayCitiesLeaderboard(); break;  // Cities leaderboard
            case 2: signup(); break;
            case 3: login(); break;
            case 4: playGame(); break;
            case 5:
                cout << CYAN << "Goodbye! Stay green!\n" << RESET;
                return ;
            default: 
                cout << CYAN << "Invalid choice.\n" << RESET;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << CYAN << "\nPress Enter to continue... " << RESET;
        cin.ignore();
        cin.get();

    } while (true);
};

class TransportZone : public Building {
private:
    int newRoadsPlanned;
    int underpassesPlanned;
    int chargingStationsPlanned;
    int smartSignalsPlanned;
    int points;

public:
    TransportZone() {
        newRoadsPlanned = 0;
        underpassesPlanned = 0;
        chargingStationsPlanned = 0;
        smartSignalsPlanned = 0;
        points = 0;
    }

    void displayZoneInformation() override {
        numberOfBuildings = 50; // Number of active transport projects
        gallonsOfWaterProvided = 50000; // e.g., from vehicle cleaning, metro stations
        gallonsOfWaterConsumed = 45000;
        gallonsOfWaterRecycled = 3000;
        gallonsOfWaterWasted = 2000;

        percentOfEnergyUsedFromCoal = 30;
        percentOfEnergyUsedFromSolar = 40;
        percentOfEnergyUsedFromWind = 20;
        percentOfEnergyUsedFromWater = 10;

        amountOfWasteProduced = 2000;
        airQualityIndex = 90;
        ecoPoints = 65;


        cout << BOLD << "\n------ Transport Zone  ------" << RESET << endl;
        
    }

    void setgoals() override {
        cout << CYAN << "\nEnter number of new eco-friendly roads planned: ";
        cin >> newRoadsPlanned;

        cout << BLUE << "Enter number of underpasses to construct: ";
        cin >> underpassesPlanned;

        cout << GREEN << "Enter number of electric charging stations to install: ";
        cin >> chargingStationsPlanned;

        cout << YELLOW << "Enter number of smart traffic signals to deploy: ";
        cin >> smartSignalsPlanned;

        if (newRoadsPlanned >= 5) {
            points += 10;
            cout << GREEN << "+10 points for wide eco-friendly road planning.\n" << RESET;
        }
        if (chargingStationsPlanned >= 3) {
            points += 10;
            cout << GREEN << "+10 points for installing charging stations.\n" << RESET;
        }
        if (smartSignalsPlanned >= 4) {
            points += 5;
            cout << GREEN << "+5 points for smart traffic system.\n" << RESET;
        }

        ecoPoints += points;
        forsetgoal(); // optional function you may have defined elsewhere
    }

    void buildnewbuildings() override {
        int choice;
        bool building = true;
        while (building) {
            cout << BOLD << "\n--- Build Transport Infrastructure ---\n" << RESET;
            cout << CYAN << "1. Construct Eco-Friendly Roads\n";
            cout << "2. Build Underpasses\n";
            cout << "3. Add Ev bus fleets\n";
            cout << "4. Add Deisel bus fleets\n";
            cout << RED << "5. Exit\n" << RESET;
            cout << GREEN << "Your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: newRoadsPlanned++; break;
                case 2: underpassesPlanned++; break;
                case 3: chargingStationsPlanned=chargingStationsPlanned+20; break;
                case 4: smartSignalsPlanned=smartSignalsPlanned+20; break;
                case 5: building = false; break;
                default: cout << RED << "Invalid input.\n" << RESET;
            }
            if (choice >= 1 && choice <= 4) {
                numberOfBuildings++;
                cout << GREEN << "Structure / Fleet  added successfully.\n" << RESET;
            }
        }
    }

    void upgradebuildings() override {
        int choice;
        bool upgrading = true;
        while (upgrading) {
            cout << BOLD << "\n--- Upgrade Transport Facilities ---\n" << RESET;
            cout << CYAN << "1. Convert signals to solar power\n";
            cout << CYAN<<"2. Install smart traffic sensors\n";
            cout << CYAN<<"3. Convert deisel buses to electric \n";
            cout << RED << "4. Exit\n" << RESET;
            cout << GREEN << "Your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                case 2:
                case 3:
                    ecoPoints += 10;
                    cout << GREEN << "Eco upgrade successful. +10 Eco Points.\n" << RESET;
                    break;
                case 4: upgrading = false; break;
                default: cout << RED << "Invalid input.\n" << RESET;
            }
        }
    }

    void seefullreportafterchanges() override {
        clearScreen();
        cout << BOLD << "\n------ TRANSPORT ZONE FULL REPORT ------" << RESET << endl;
        cout << GREEN << "Current Status After Changes:\n" << RESET;
        
        cout << YELLOW;
        cout << "+---------------------------------------------+\n";
        cout << "| Roads Constructed/Planned:    " << setw(13) << newRoadsPlanned << " |\n";
        cout << "| Underpasses Built:            " << setw(13) << underpassesPlanned << " |\n";
        cout << "| EV buses added:               " << setw(13) << chargingStationsPlanned << " |\n";
        cout << "| deisel buses added:           " << setw(13) << smartSignalsPlanned << " |\n";
        cout << "| Air Quality Index:            " << setw(13) << airQualityIndex << " |\n";
        cout << "+---------------------------------------------+\n" << RESET;

        cout << CYAN << "\nCommunity Benefits:\n";
        cout << BLUE << "Traffic Efficiency Boost: +" << (ecoPoints / 10) << "%\n";
        evaluateEcoRating(ecoPoints);
        pressToContinue();
    }
};







void mayorPanel() {
    IndustrialZone IZ;
    ResidentialZone RZ;
    CommercialZone CZ;
    TransportZone TZ;  // Assuming you have this class defined

    while (true) {
        // Zone selection
        clearScreen();
        cout << BOLD << BLUE << "\n>> MAYOR PANEL <<" << RESET << endl;
        cout << "Select which zone you want to manage:\n\n";
        
        int zone_choice = 1;
        char zone_key;
        bool zone_selected = false;
        
        while (!zone_selected) {
            cout << YELLOW << (zone_choice == 1 ? "> " : "  ") << "1. Industrial Zone\n";
            cout << YELLOW << (zone_choice == 2 ? "> " : "  ") << "2. Residential Zone\n";
            cout << YELLOW << (zone_choice == 3 ? "> " : "  ") << "3. Commercial Zone\n";
            cout << YELLOW << (zone_choice == 4 ? "> " : "  ") << "4. Transport Zone\n";
            cout << CYAN   << (zone_choice == 5 ? "> " : "  ") << "5. Return to Main Menu\n";
            
            zone_key = getch();
            if (zone_key == -32 || zone_key == 0) {
                zone_key = getch();
                if (zone_key == 72) { // Up arrow
                    zone_choice = (zone_choice == 1 ? 5 : zone_choice - 1);
                } else if (zone_key == 80) { // Down arrow
                    zone_choice = (zone_choice == 5 ? 1 : zone_choice + 1);
                }
            } else if (zone_key == 13) { // Enter key
                zone_selected = true;
            }
            clearScreen();
            cout << BOLD << BLUE << "\n>> MAYOR PANEL <<" << RESET << endl;
            cout << "Select which zone you want to manage:\n\n";
        }

        if (zone_choice == 5) break;

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
            case 4:
                TZ.displayZoneInformation();
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
            cout << CYAN << (action_choice == 1 ? "> " : "  ") << "1. Set goals\n";
            cout << CYAN << (action_choice == 2 ? "> " : "  ") << "2. Introduce New Stuctures / Fleets \n";
            cout << CYAN << (action_choice == 3 ? "> " : "  ") << "3. Upgrade existing buildings\n";
            cout << CYAN << (action_choice == 4 ? "> " : "  ") << "4. View full report\n";
            cout << CYAN << (action_choice == 5 ? "> " : "  ") << "5. Back to zone selection\n";
            
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
            case 4: // Transport
                if (action_choice == 1) TZ.setgoals();
                else if (action_choice == 2) TZ.buildnewbuildings();
                else if (action_choice == 3) TZ.upgradebuildings();
                else if (action_choice == 4) TZ.seefullreportafterchanges();
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
        cout<<CYAN << "Enter password: ";
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
        cout <<CYAN<< "Dog's name: "; cin >> d;
        cout <<CYAN<< "Favorite color: "; cin >> c;
        
        if (d == dog && c == color) {
            mayorPanel();
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
        
        cout <<YELLOW<< "\nPlease select your designation:\n";
        cout <<GREEN<< "*********************************\n";
        cout <<WHITE<< (choice == 1 ? "> " : "  ") << "1. Mayor\n";
        cout <<WHITE<<(choice == 2 ? "> " : "  ") << "2. Citizen\n";
         cout <<RED<< (choice == 3 ? "> " : "  ") << "3. Exit\n";
        cout <<GREEN<< "*********************************\n";
        cout <<MAGENTA<< "Use arrow keys to navigate, Enter to select\n";
        
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
                    citizenPanel(); 
                    break;
                case 3:
                cout << BOLD << GREEN << "\nThank you for using Smart City Athens Simulation!\n" << RESET;
                    return;
                    
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
