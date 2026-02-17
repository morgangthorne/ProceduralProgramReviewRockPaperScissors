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

int RockPaperScissorsValidator();

void GameDisplay();

void WinLossDrawTracker();

void ReplayQuit();


int main()
{
    GameDisplay();

    RockPaperScissorsValidator();

    WinLossDrawTracker();
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

}







//Function validates user's inputs and determines the winner of the game, then result is sent to WinLossDrawTracker
int RockPaperScissorsValidator(int ComputerChoice) {
    
}



//Function receives value from RockPaperScissor function and will increment win,loss, and draw values. Those values will be displayed
//at the end of the game to the user. 
void WinLossDrawTracker() {
    int Wins, 
        Losses, 
        Draws = 0;
    



}

//Function will let user choose to keep playing or quit
void ReplayQuit() {
    string DoAgain;

    do {

        int Number = GetRandomNumber();

        int GameResult = RockPaperScissorsValidator(Number);


    } while (DoAgain == "Yes" || DoAgain == "yes");
    cout << "Thank you for playing!\n";



}
