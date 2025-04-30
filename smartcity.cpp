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

void showHeader() {
    cout << BOLD << CYAN << "\n===== SMART CITY ATHENS SIMULATION =====" << RESET << endl;
}

void cityOverview() {
    cout << BOLD << GREEN;
    printLine("\nWELCOME TO THE FUTURE OF URBAN LIVING");
    cout << "+----------------------------------------+-----------------------------+\n";
    cout << "| Attribute                              | Value                       |\n";
    cout << "+----------------------------------------+-----------------------------+" << RESET << endl;

    cout << YELLOW;
    cout << "| Country                                | " << WHITE << "Greece                     " << YELLOW << "|\n";
    cout << "| City                                   | " << WHITE << "Athens (Eco Simulation)    " << YELLOW << "|\n";
    cout << "| Energy Source                          | " << WHITE << "Solar, Wind, Hydro         " << YELLOW << "|\n";
    cout << "| Emission Status                        | " << WHITE << "Carbon Neutral             " << YELLOW << "|\n";
    cout << "| Smart Infrastructure                   | " << WHITE << "Yes                        " << YELLOW << "|\n";
    cout << "| Sustainable Transport                  | " << WHITE << "Electric Buses, Bikes      " << YELLOW << "|\n";
    cout << "+----------------------------------------+-----------------------------+" << RESET << endl;
}

void generalInfo() {
    cout << BOLD << GREEN;
    printLine("\nGENERAL INFORMATION");
    cout << "+----------------------------------------+-----------------------------+\n";
    cout << "| Attribute                              | Value                       |\n";
    cout << "+----------------------------------------+-----------------------------+" << RESET << endl;

    cout << YELLOW;
    cout << "| Country                                | " << WHITE << "Greece                     " << YELLOW << "|\n";
    cout << "| Region                                 | " << WHITE << "Attica                     " << YELLOW << "|\n";
    cout << "| Coordinates                            | " << WHITE << "37.9838 N, 23.7275 E       " << YELLOW << "|\n";
    cout << "| Founding Year                          | " << WHITE << "c. 3000 BC                 " << YELLOW << "|\n";
    cout << "| Time Zone                              | " << WHITE << "UTC+2 (EET)                " << YELLOW << "|\n";
    cout << "| Climate                                | " << WHITE << "Mediterranean              " << YELLOW << "|\n";
    cout << "| Elevation (Min - Max)                  | " << WHITE << "70 - 338 meters            " << YELLOW << "|\n";
    cout << "+----------------------------------------+-----------------------------+" << RESET << endl;
}

void populationArea() {
    cout << BOLD << GREEN;
    printLine("\nPOPULATION & AREA");
    cout << "+----------------------------------------+-----------------------------+\n";
    cout << "| Attribute                              | Value                       |\n";
    cout << "+----------------------------------------+-----------------------------+" << RESET << endl;

    cout << YELLOW;
    cout << "| Population (City Proper)               | " << WHITE << "Approx. 650,000            " << YELLOW << "|\n";
    cout << "| Population (Metropolitan Area)         | " << WHITE << "Approx. 3,150,000          " << YELLOW << "|\n";
    cout << "| Area (City Proper)                     | " << WHITE << "39 km^2                    " << YELLOW << "|\n";
    cout << "| Area (Metropolitan Area)               | " << WHITE << "2,928.7 km^2               " << YELLOW << "|\n";
    cout << "+----------------------------------------+-----------------------------+" << RESET << endl;
}

void economicCultural() {
    cout << BOLD << GREEN;
    printLine("\nECONOMIC & CULTURAL HIGHLIGHTS");
    cout << "+----------------------------------------+-----------------------------+\n";
    cout << "| Attribute                              | Value                       |\n";
    cout << "+----------------------------------------+-----------------------------+" << RESET << endl;

    cout << YELLOW;
    cout << "| GDP (Metro Area, est.)                 | " << WHITE << "€109.65 billion (2023)     " << YELLOW << "|\n";
    cout << "| GDP per Capita                         | " << WHITE << "€29,000                    " << YELLOW << "|\n";
    cout << "| Famous Landmark                        | " << WHITE << "Acropolis of Athens        " << YELLOW << "|\n";
    cout << "| Known For                              | " << WHITE << "Philosophy, Democracy      " << YELLOW << "|\n";
    cout << "+----------------------------------------+-----------------------------+" << RESET << endl;

    cout << BOLD << MAGENTA;
    printLine("\n        A city rooted in history, wisdom, and resilience.");
    cout << RESET << endl;
}

void mayorPanel() {
    system("cls||clear");
    cout << BOLD << BLUE << "\n>> MAYOR PANEL <<" << RESET << endl;
    // Displaying only the mayor functionality message
    cout << CYAN << "\nMayor functionality is working.\n" << RESET;
    system("pause");  // Add pause to allow the user to read the message before continuing
}

void citizenPanel() {
    system("cls||clear");
    cout << BOLD << RED << "\n>> CITIZEN PANEL <<" << RESET << endl;
    // Displaying only the citizen functionality message
    cout << CYAN << "Citizen functionality is working.\n" << RESET;
    system("pause");  // Add pause to allow the user to read the message before continuing
}

void mayorPassword() {
    showHeader();
    cout << BLUE << "Mayor Authentication\n" << RESET;
    int input, correct = 12345;
    string dog = "apollo", color = "navy";
    while (true) {
        cout << "Enter password: ";
        cin >> input;
        if (cin.fail()) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        if (d == dog && c == color) mayorPanel();
        else cout << RED << "Verification failed.\n" << RESET;
    }
}

void citizenPassword() {
    showHeader();
    cout << GREEN << "Citizen Authentication\n" << RESET;
    int input, correct = 2468;
    string food = "gyros", car = "tesla";
    while (true) {
        cout << "Enter password: ";
        cin >> input;
        if (cin.fail()) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        if (f == food && c == car) citizenPanel();
        else cout << RED << "Verification failed.\n" << RESET;
    }
}

void displayMenu() {
    showHeader();
    cityOverview();
    generalInfo();
    populationArea();
    economicCultural();

    int choice = 1;
    char ch;
    while (true) {
        cout << "\nPlease select your designation:\n";
        cout << "--------------------------------------------------\n";
        cout << (choice == 1 ? "-> " : "   ") << "Mayor\n";
        cout << (choice == 2 ? "-> " : "   ") << "Citizen\n";
        cout << (choice == 3 ? "-> " : "   ") << "Exit\n";
        cout << "--------------------------------------------------\n";
    
        ch = getch();
        if (ch == -32 || ch == 0) {
            ch = getch();
            if (ch == 72) choice = (choice == 1 ? 3 : choice - 1);       // Up arrow
            else if (ch == 80) choice = (choice == 3 ? 1 : choice + 1);  // Down arrow
        } else if (ch == 13) { // Enter key
            system("cls||clear"); // Clear screen after selection
            switch (choice) {
                case 1: mayorPassword(); break;
                case 2: citizenPassword(); break;
                case 3: cout << "\nGoodbye!\n"; return;
            }
        }
    }
}

int main() {
    displayMenu();
    return 0;
}
