#include <vector>
#include <iostream>

using namespace std;

const bool CLEAR_SCREEN = true;

/// @brief Utilizes an escape character sequence to clear the screen
void clearScreen() {
    cout << endl;

    if (CLEAR_SCREEN)
    {
        cout << "\033c";
    }

    cout << endl;

    return;
}


/// @brief Draws the provided tic-tac-toe board to the screen
//  @param board is the tic-tac-toe board that should be drawn
void drawBoard(const vector < char >&gameBoard) {
    clearScreen();
    for (int i = 0; i < 9; i += 3)
    {
        cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
            << gameBoard.at(i + 2) << "  " << endl;
        if (i < 6)
            cout << "-----|-----|-----" << endl;
    }
    cout << endl;

    return;
}

/// @brief Fills vector with characters starting at lower case a.
///
///     If the vector is size 3 then it will have characters a to c.
///     If the vector is size 5 then it will have characters a to e.
///     If the vector is size 26 then it will have characters a to z.
///
/// @param v the vector to initialize
/// @pre-condition the vector size will never be over 26
void initVector(vector <char> &v) {
    
    char main = 'a';
    for(int i = 0; i < 9; ++i) {
        
        v.at(i) = main;
        main++;
    }
    return;
}

/// @brief Converts a character representing a cell to associated vector index
/// @param the position to be converted to a vector index
/// @return the integer index in the vector, should be 0 to (vector size - 1)
int convertPosition(char boardPosition) {
    
    int newPosition = 0;
    newPosition = boardPosition - 'a';
    return newPosition;
}

/// @brief Predicate function to determine if a spot in board is available.
/// @param board the current tic-tac-toe board 
/// @param position is an index into vector to check if available
/// @return true if position's state is available (not marked) AND is in bounds
bool validPlacement(const vector <char> &gameBoard, int positionIndex) {
    
    if ((gameBoard.at(positionIndex) != 'X') && (gameBoard.at(positionIndex) != 'O'))
        return true;
    
    return false;
}

/// @brief Acquires a play from the user as to where to put her mark
///
///     Utilizes convertPosition and validPlacement functions to convert the
///     user input and then determine if the converted input is a valid play.
///
/// @param board the current tic-tac-toe board 
/// @return an integer index in board vector of a chosen available board spot
int getPlay(const vector <char> &gameBoard) {

    char boardPosition = ' ';
    int position = 0;
    bool check = false;
    
    cout << "Please choose a position: ";
    cin >> boardPosition;
    cout << endl;
        
    position = boardPosition - 'a';
        
    check = validPlacement(gameBoard, position);
    
    int i = 0;
    while (i == 0) {
        
        if (check) {
            ++i;
        }
        
        else {
            
            cout << "Please choose a position: ";
            cin >> boardPosition;
            cout << endl;
            position = boardPosition - 'a';
            check = validPlacement(gameBoard, position);
        }
    }
    return position;
}

/// @brief Predicate function to determine if the game has been won
///
///     Winning conditions in tic-tac-toe require three marks from same 
///     player in a single row, column or diagonal.
///
/// @param board the current tic-tac-toe board 
/// @return true if the game has been won, false otherwise
bool gameWon(const vector <char> &gameBoard) {

    if ((gameBoard.at(0) == gameBoard.at(3)) && (gameBoard.at(3) == gameBoard.at(6)))
        return true;
    else if ((gameBoard.at(0) == gameBoard.at(1)) && (gameBoard.at(1) == gameBoard.at(2)))
        return true;
    else if ((gameBoard.at(0) == gameBoard.at(4)) && (gameBoard.at(4) == gameBoard.at(8)))
        return true;
    else if ((gameBoard.at(1) == gameBoard.at(4)) && (gameBoard.at(4) == gameBoard.at(7)))
        return true;
    else if ((gameBoard.at(2) == gameBoard.at(4)) && (gameBoard.at(4) == gameBoard.at(6)))
        return true;
    else if ((gameBoard.at(2) == gameBoard.at(5)) && (gameBoard.at(5) == gameBoard.at(8)))
        return true;
    else if ((gameBoard.at(3) == gameBoard.at(4)) && (gameBoard.at(4) == gameBoard.at(5)))
        return true;
    else if ((gameBoard.at(6) == gameBoard.at(7)) && (gameBoard.at(7) == gameBoard.at(8)))
        return true;
    else
        return false;
}

/// @brief Predicate function to determine if the board is full
/// @param board the current tic-tac-toe board 
/// @return true iff the board is full (no cell is available)
bool boardFull(const vector <char> &gameBoard) {

    unsigned int i = 0;
    bool check = true;
    while(i < gameBoard.size()) {
        
        if((gameBoard.at(i) == 'X') || (gameBoard.at(i) == 'O'))
            ++i;
        else {
            check = false;
            return check;
        }
    }
    return check;
}

// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;

int main() {
    // Variables that you may find useful to utilize
    vector <char> gameBoard(9);
    int whosTurn = PLAYER1; // Player 1 always goes first and is 'X'
        
    initVector(gameBoard);
    drawBoard(gameBoard);

    while(!boardFull(gameBoard) && !gameWon(gameBoard)) {
        int position = 0;
    
        position = getPlay(gameBoard);
        
        if(whosTurn == PLAYER1) {
            gameBoard.at(position) = 'X';
            whosTurn = PLAYER2;
        }
        else {
            gameBoard.at(position) = 'O';
            whosTurn = PLAYER1;
        }
    drawBoard(gameBoard);
    
    }
    
    if(whosTurn == PLAYER1)
        cout << "PLAYER 2 WINS!";
    else 
        cout << "PLAYER 1 WINS!";
        
    cout << endl;

    return 0;
}