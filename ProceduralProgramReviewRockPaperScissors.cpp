/* 
FileName: ProceduralProgramReviewRockPaperScissors.cpp
Programmer: Morgan Thorne
Date: February 2026
Program: Create a modular program using the <random> library. The program will allow the user to play against the computer in a game of rock, paper, scissors
, wins, losses, and draws will be tracked until the user decides to quit/stop the game.
*/

#include <iostream>
#include <random>

using namespace std;

int GetRandomNumber();
int GetValidUserChoice();
int DetermineOutcome(int ComputerPick, int UserPick);
void GameDisplay();
void OutcomeTracker(); 
int GetValidReplayQuit();



int main()
{
    bool Play = GetValidReplayQuit();
    
    GameDisplay();

    if (Play == true) {
       
        int ComputerPick = GetRandomNumber();
        int UserPick = GetValidUserChoice();

        DetermineOutcome(ComputerPick, UserPick);

    }
    


    

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


//Function validates user's input then result is sent to WinLossDrawValidator
int GetValidUserChoice() {
    int UserChoice;

    do {
        
        if (!(cin >> UserChoice)) {
            cout << "Enter a number: ";
            
            cin.clear();
            cin.ignore();
            
        }
        else if (UserChoice < 1 || UserChoice > 3) {
            cout << "Enter a number between 1 and 3: ";

        }
    } while (UserChoice < 1 || UserChoice > 3); 
     
    return UserChoice;
}



//Function receives value from RockPaperScissor function and will increment win,loss, and draw values. Those values will be displayed
//at the end of the game to the user. 
int DetermineOutcome(int ComputerPick, int UserPick) {
    int Wins = 0,
        Losses = 0,
        Draws = 0;

    cout << "You picked " << UserPick << " the computer picked " << ComputerPick << endl;;
    
    if (UserPick == ComputerPick) {
        cout << "Draw\n";
        Draws++;
        
        return Draws;
    }
    else if ((UserPick == 1 && ComputerPick == 3) || (UserPick == 2 && ComputerPick == 1) || (UserPick == 3 && ComputerPick == 2)) {
        cout << "Win\n";
        Wins++;

        return Wins;
    }
    else {
        cout << "Loss\n";
        Losses++;

        return Losses;
    }
    
    return 0;
}

//Function will let user choose to keep playing or quit
int GetValidReplayQuit() {
    int DoAgain;
    
    do {

        if (!(cin >> DoAgain)) {
            cout << "Enter a number: ";

            cin.clear();
            cin.ignore();

        }
        else if (DoAgain < 1 || DoAgain > 2) {
            cout << "Enter a numbers 1 or 2: ";

        }
    } while (DoAgain < 1 || DoAgain > 2);

    return DoAgain;
}

void OutcomeTracker() {

}