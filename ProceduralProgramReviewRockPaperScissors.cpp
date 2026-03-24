/* +
FileName: ProceduralProgramReviewRockPaperScissors.cpp
Programmer: Morgan Thorne
Date: February 2026
Program: Create a modular program using the <random> library. The program will allow the user to play against the computer in a game of rock, paper, scissors
, wins, losses, and draws will be tracked until the user decides to quit/stop the game.
*/

#include <iostream>
#include <random>
#include <limits>

using namespace std;

int GetRandomNumber();
int GetValidUserChoice();
int DetermineOutcome(int ComputerPick, int UserPick);
void ChoiceToStringConverter(int ComputerPick, int UserPick);
void GameDisplay();
void OutcomeTracker(int GameResult, int *Draw, int *Wins, int *Loss); 
int GetValidReplayQuit();
void OutcomeDisplay(int Draw, int Wins, int Loss);

int main()
{
    int Draw = 0;
    int Wins = 0;
    int Loss = 0;
    
    do {

        GameDisplay();

        int ComputerPick = GetRandomNumber();
        int UserPick = GetValidUserChoice();

        string Convert(int choice);

        ChoiceToStringConverter(ComputerPick, UserPick);
        
        int GameResult = DetermineOutcome(ComputerPick, UserPick);
        
        OutcomeTracker(GameResult, &Draw, &Wins, &Loss);
         
    } while (GetValidReplayQuit() == 1);
        
        OutcomeDisplay(Draw, Wins, Loss);

        return 0;
}

//Creates a random number from 1-3 to simulate rock, paper, scissors
int GetRandomNumber() {
    random_device x;
    uniform_int_distribution<int> randomInt(1, 3);

    int Number = randomInt(x);

    return Number;
}

//Function Displays directions for the game
void GameDisplay() {
    cout << "---------------------------------------------\n";

    cout << "Choose Rock (1), Paper (2), or Scissors(3): ";
}

//Function validates user's input with a do while loop then valid result is sent to WinLossDrawValidator
int GetValidUserChoice() {
    int UserChoice;

    do {
        
        if (!(cin >> UserChoice)) {
            cout << "Enter a number: ";
            
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (UserChoice < 1 || UserChoice > 3) {
            cout << "Enter a number between 1 and 3: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (UserChoice < 1 || UserChoice > 3); 
     
    return UserChoice;
}

string Convert(int choice) {
    if (choice == 1) return "Rock";
    if (choice == 2) return "Paper";
    return "Scissors";
}


//Function reads what choices were made by the user and computer then converts them to their corresponding string, those choices are then displayed. 
void ChoiceToStringConverter(int ComputerPick, int UserPick) {
 
    cout << "You picked " << Convert(UserPick) << " the computer picked " << Convert(ComputerPick) << endl;
}

/*
1 - Function receives and displays numbers genreated by GetRandomNumber(); and GetValidUserChoice(); 
2 - if, else if, and else statement used to determine game logic
3 - Based off logic int Result is given a value that gets passed to main.
*/
int DetermineOutcome(int ComputerPick, int UserPick) {
    int Result;
    
    if (UserPick == ComputerPick) {
        cout << "Draw!\n";
        
        Result = 1;
    }
    else if ((UserPick == 1 && ComputerPick == 3) || (UserPick == 2 && ComputerPick == 1) || (UserPick == 3 && ComputerPick == 2)) {
        cout << "You Win!\n";
        
        Result = 2;
    }
    else {
        cout << "You Lose!\n";
        
        Result = 3;
    }
    
    return Result;
}

//Function uses do while loop to validate input, input is then returned to main 
int GetValidReplayQuit() {
    int DoAgain;
    
    cout << "Would you like to replay(1) or Quit(2): ";
    
    do {

        if (!(cin >> DoAgain)) {
            cout << "Enter a number: ";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (DoAgain < 1 || DoAgain > 2) {
            cout << "Enter number 1 or 2: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (DoAgain < 1 || DoAgain > 2);

    return DoAgain;
}

//Uses pointers to change the result of Draw, Wins, and Loss variables in main. 
void OutcomeTracker(int GameResult, int *Draw, int *Wins, int *Loss) {
    
    if (GameResult == 1) {
        (*Draw)++;
    }
    else if (GameResult == 2) {
        (*Wins)++;
    }
    else {
        (*Loss)++;
    }
}

//Displays values from OutcomeTracker.
void OutcomeDisplay(int Draw, int Wins, int Loss) {
    cout << "Thank you for playing.\n";
    cout << "Results are: \n" << Draw << " Draws, " << Wins << " Wins, " << Loss << " Losses";
}


