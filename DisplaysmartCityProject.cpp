#include <iostream>
using namespace std;

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

int main() {
    // Title Banner
    cout << BOLD << CYAN;
    cout << "************************************************************" << endl;
    cout << "*                                                          *" << endl;
    cout << "*                   ATHENS CITY STATISTICS                 *" << endl;
    cout << "*                                                          *" << endl;
    cout << "************************************************************" << RESET << endl;

    // Info Table Header
    cout << BOLD << GREEN;
    cout << "\nGENERAL INFORMATION\n";
    cout << "+----------------------------------------+-----------------------------+" << endl;
    cout << "| Attribute                              | Value                       |" << endl;
    cout << "+----------------------------------------+-----------------------------+" << RESET << endl;

    // Table Content
    cout << YELLOW << "| Country                                | " << WHITE << "Greece                     " << YELLOW << "|\n";
    cout << "| Region                                 | " << WHITE << "Attica                     " << YELLOW << "|\n";
    cout << "| Coordinates                            | " << WHITE << "37.9838 N, 23.7275 E     " << YELLOW << "|\n";
    cout << "| Founding Year                          | " << WHITE << "c. 3000 BC                 " << YELLOW << "|\n";
    cout << "| Time Zone                              | " << WHITE << "UTC+2 (EET)                " << YELLOW << "|\n";
    cout << "| Climate                                | " << WHITE << "Mediterranean              " << YELLOW << "|\n";
    cout << "| Elevation (Min - Max)                  | " << WHITE << "70 - 338 meters            " << YELLOW << "|\n";
    cout << "+----------------------------------------+-----------------------------+" << RESET << endl;

    cout << BOLD << GREEN;
    cout << "\nPOPULATION & AREA\n";
    cout << "+----------------------------------------+-----------------------------+" << endl;
    cout << "| Attribute                              | Value                       |" << endl;
    cout << "+----------------------------------------+-----------------------------+" << RESET << endl;

    cout << YELLOW << "| Population (City Proper)               | " << WHITE << "Approx. 650,000            " << YELLOW << "|\n";
    cout << "| Population (Metropolitan Area)         | " << WHITE << "Approx. 3,150,000          " << YELLOW << "|\n";
    cout << "| Area (City Proper)                     | " << WHITE << "39 km^2                    " << YELLOW << "|\n";
    cout << "| Area (Metropolitan Area)               | " << WHITE << "2,928.7 km^2               " << YELLOW << "|\n";
    cout << "+----------------------------------------+-----------------------------+" << RESET << endl;

    cout << BOLD << GREEN;
    cout << "\nECONOMIC & CULTURAL HIGHLIGHTS\n";
    cout << "+----------------------------------------+-----------------------------+" << endl;
    cout << "| Attribute                              | Value                       |" << endl;
    cout << "+----------------------------------------+-----------------------------+" << RESET << endl;

    cout << YELLOW << "| GDP (Metro Area, est.)                 | " << WHITE << "€109.65 billion (2023)     " << YELLOW << "|\n";
    cout << "| GDP per Capita                         | " << WHITE << "€29,000                    " << YELLOW << "|\n";
    cout << "| Famous Landmark                        | " << WHITE << "Acropolis of Athens        " << YELLOW << "|\n";
    cout << "| Known For                              | " << WHITE << "Philosophy, Democracy      " << YELLOW << "|\n";
    cout << "+----------------------------------------+-----------------------------+" << RESET << endl;

    cout << BOLD << MAGENTA;
    cout << "\n        A city rooted in history, wisdom, and resilience." << RESET << endl;
    cout << endl;

    return 0;
}
