#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

// Color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

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

// Clear screen
void clearScreen() {
    cout << string(50, '\n');
}

// Signup a new citizen
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
}

// Login existing citizen
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
}

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
    
    cout << CYAN << "Press Enter to continue... " << RESET;
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
        cout << "\nInstructions: Use W (up), A (left), S (down), D (right) to move.\n";
        cout << "Your current position is 'P'.\n";
        cout << "Try to reach 'E' for the recycling center. Avoid the waste ('X').\n";

        cout << "\nEnter your move (W/A/S/D): ";
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
            cout << "Correct! +5 points\n";
            score += 5;
        } else {
            cout << "Wrong! The word was: " << fullWords[i] << "\n";
        }
    }

    citizens[currentCitizenIndex].ecoPoints += score;
    cout << "Game over! You earned: " << score << " points\n";
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
    cout << WHITE << "You are a delegate voting on future-saving policies.\n";
    cout << "Choose wisely — the planet depends on you!\n\n" << RESET;
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
}


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
            cout << "Error: Unable to open " << filename << endl;
            return;
        }
    }

    string line;
    if (getline(file, line)) {
        currentLine++;
        cout << currentLine << ". " << line << endl;
    } else {
        cout << "Thats all for today!!" << endl;
        file.close();
        currentLine = 0;
    }
}

void tipsFactsDashboard() {
    int choice;
    
    while (true) {
        cout << "\n==== Sustainability Tips & Facts ====\n";
        cout << "1. View Next Tip\n";
        cout << "2. View Next Fact\n";
        cout << "3. Return to Main Dashboard\n";
        cout << "Enter your choice: ";
        
        // Clear any previous errors and ignore remaining input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "\n-- Sustainable Living Tips --\n";
                displayFromFile("tips.txt");
                break;
            case 2:
                cout << "\n-- Climate & Energy Facts --\n";
                displayFromFile("facts.txt");
                break;
            case 3:
                cout << "Returning to main dashboard...\n";
                return;
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3.\n";
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
        cout << CYAN << "=== SMART CITY GAME ===\n" << RESET;
        cout << "Logged in as: " << citizens[currentCitizenIndex].username
             << " (Points: " << citizens[currentCitizenIndex].ecoPoints << ")\n";
        cout << WHITE;
        cout << "1. Play Eco Trivia Quiz\n";
        cout << "2. Play Maze Game\n";
        cout << "3. Play Pattern Matching\n";
        cout << "4. Participate in Climate Summit\n";
        cout << "5. View Citizen Leaderboard (Table)\n";
        cout << "6. View Citizen Leaderboard (Histogram)\n";
        cout << "7. Daily Tips and Facts\n"; 
        cout << "8. Logout\n";
        cout << "Enter your choice: ";
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










// Main menu
int main() {
    int choice;
    do {
        clearScreen();
        cout << CYAN << "==== SMART CITY GAME DASHBOARD ====\n" << RESET;
        cout << WHITE;
        cout << "1. View Global Cities Leaderboard\n";  // New option
        cout << "2. Signup\n";
        cout << "3. Login\n";
        cout << "4. Play Game\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: displayCitiesLeaderboard(); break;  // Cities leaderboard
            case 2: signup(); break;
            case 3: login(); break;
            case 4: playGame(); break;
            case 5:
                cout << CYAN << "Goodbye! Stay green!\n" << RESET;
                return 0;
            default: 
                cout << CYAN << "Invalid choice.\n" << RESET;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << CYAN << "\nPress Enter to continue... " << RESET;
        cin.ignore();
        cin.get();

    } while (true);
}
