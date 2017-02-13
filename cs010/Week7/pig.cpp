#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int PLAYER1 = 0;
const int PLAYER2 = 1;
const int WINNING_SCORE = 100;

void printIntro() {

    cout << "Welcome to the dice game Pig!" << endl << "The objective is to be first to score 100 points." << endl << endl;

}

int humanTurn(string playername, int playerscore) {
    
    int score = 0;
    int roll = 0;
    
    string response;
    
    while (roll != 1 || score < WINNING_SCORE) {
        
        cout << playername << endl;
        
        roll = rand() % 6 + 1;
        
        if (roll != 1) {
            
            cout << "You rolled a " << roll << endl;
        
            score = roll + score;
            cout << "Your score: " << playerscore + score << endl;
        
            if ((playerscore + score) < WINNING_SCORE) {
                cout << "Do you want to roll again? (y/n): ";
                cin >> response;
                cout << endl;
            }
            
            else {
                return playerscore + score;
            }
        
        }
        else {
            
            cout << "You rolled a 1 (PIG!)" << endl << "Your turn is over" << endl << "Your score: " << playerscore << endl << endl;
            return playerscore;
        }
        
        if (response == "n")
            return playerscore + score;
    }
    
}

int main() {
    
    srand(4444);

    string response;
    int turn = PLAYER1;
    int player1score = 0;
    int player2score = 0;
    string player1name;
    string player2name;

    printIntro();

    cout << "Player 1 - Enter your name: ";
    cin >> player1name;
    cout << endl;
    
    cout << "Player 2 - Enter your name: ";
    cin >> player2name;
    cout << endl;

    //play game
    while (player1score < WINNING_SCORE && player2score < WINNING_SCORE) {

        //player 1's turn or player 2's turn
        if (turn == PLAYER1) {
            player1score = humanTurn(player1name, player1score);
            turn = PLAYER2;
        }
        else {
            player2score = humanTurn(player2name, player2score);
            turn = PLAYER1;
        }
        
    }

    if (player1score >= WINNING_SCORE)
        cout << endl << player1name << " wins!" << endl;
    else if (player2score >= WINNING_SCORE)
        cout << endl << player2name << " wins!" << endl;

    return 0;
}