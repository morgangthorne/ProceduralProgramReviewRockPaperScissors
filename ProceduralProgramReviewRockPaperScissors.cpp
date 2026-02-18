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
int GetUserChoice();
int DetermineOutcome();
void GameDisplay();
void ReplayQuit();

int main()
{
    GameDisplay();

    GetUserChoice();

    DetermineOutcome();
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
int GetUserChoice() {
    int UserChoice;

    cin >> UserChoice;

    do {
        cin >> UserChoice;
        
        if (UserChoice < 1 || UserChoice > 3) {
            cout << "Please choose a number from 1 - 3: ";
        }
    } while (UserChoice > 1 || UserChoice < 3);
        
    
    
}



//Function receives value from RockPaperScissor function and will increment win,loss, and draw values. Those values will be displayed
//at the end of the game to the user. 
int DetermineOutcome(int UserChoice, int ComputerChoice) {
    int Wins = 0,
        Losses = 0,
        Draws = 0;

    if (UserChoice == ComputerChoice) {
        cout << "Draw\n";
        Draws++;
        
        return Draws;
    }
    else if ((UserChoice == 1 && ComputerChoice == 3) || (UserChoice == 2 && ComputerChoice == 1) || (UserChoice == 3 && ComputerChoice == 2)) {
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
void ReplayQuit() {
    string DoAgain;

    do {

        int Number = GetRandomNumber();

        //int GameResult = RockPaperScissorsValidator(Number);


    } while (DoAgain == "Yes" || DoAgain == "yes");
    cout << "Thank you for playing!\n";

}
