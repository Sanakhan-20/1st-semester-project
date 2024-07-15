 #include <iostream>
#include <cstdlib> 
#include <ctime>  

using namespace std;


void printMenu();
int getUserChoice();
int getComputerChoice();
void determineWinner(int userChoice, int computerChoice);

int main() {
    
    srand(time(0));

    
    const char *choices[] = {"rock", "paper", "scissors"};

    while (true) {
        printMenu();
        
        int userChoice = getUserChoice();
        int computerChoice = getComputerChoice();
        
        cout << "You chose: " << choices[userChoice] << endl;
        cout << "Computer chose: " << choices[computerChoice] << endl;

        determineWinner(userChoice, computerChoice);

    
        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            cout << "Thanks for playing!" << endl;
            break;
        }
    }

    return 0;
}


void printMenu() {
    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
}


int getUserChoice() {
    int choice;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    
    while (choice < 1 || choice > 3) {
        cout << "Invalid choice. Enter a number between 1 and 3: ";
        cin >> choice;
    }


    return choice - 1;
}


int getComputerChoice() {
    return rand() % 3; 
}

void determineWinner(int userChoice, int computerChoice) {
    
    const char *choices[] = {"rock", "paper", "scissors"};

    
    if (userChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((userChoice == 0 && computerChoice == 2) ||
               (userChoice == 1 && computerChoice == 0) ||
               (userChoice == 2 && computerChoice == 1)) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }
}


