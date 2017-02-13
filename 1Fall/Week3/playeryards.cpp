#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main () { 
    
    string player1;
    string player2;
    string player3;
    int player1yds = 0;
    int player2yds = 0;
    int player3yds = 0;
    
    cout << "Enter player 1's name:" << endl;
    cin >> player1;
    
    cout << "Enter player 1's yards gained:" << endl;
    cin >> player1yds;
    
    cout << "Enter player 2's name:" << endl;
    cin >> player2;
    
    cout << "Enter player 2's yards gained:" << endl;
    cin >> player2yds;
    
    cout << "Enter player 3's name:" << endl;
    cin >> player3;
    
    cout << "Enter player 3's yards gained:" << endl;
    cin >> player3yds;
    cout << endl;
    
    cout << "Player 1 - " << player1 << ": " << player1yds << endl;
    cout << "Player 2 - " << player2 << ": " << player2yds << endl;
    cout << "Player 3 - " << player3 << ": " << player3yds << endl;
    
    if ((player1yds > player2yds) && (player2yds > player3yds)) {
        
        cout << "1. " << player1 << ": " << player1yds << endl;
        cout << "2. " << player2 << ": " << player2yds << endl;
        cout << "3. " << player3 << ": " << player3yds << endl;
    }
    
    else if ((player1yds > player3yds) && (player3yds > player2yds)) {
        
        cout << "1. " << player1 << ": " << player1yds << endl;
        cout << "2. " << player3 << ": " << player3yds << endl;
        cout << "3. " << player2 << ": " << player2yds << endl;
    }
    
    else if ((player2yds > player1yds) && (player1yds > player3yds)) {
        
        cout << "1. " << player2 << ": " << player2yds << endl;
        cout << "2. " << player1 << ": " << player1yds << endl;
        cout << "3. " << player3 << ": " << player3yds << endl;
    }
    
    else if ((player2yds > player3yds) && (player3yds > player1yds)) {
        
        cout << "1. " << player2 << ": " << player2yds << endl;
        cout << "2. " << player3 << ": " << player3yds << endl;
        cout << "3. " << player1 << ": " << player1yds << endl;
    }
    
    else if ((player3yds > player1yds) && (player1yds > player2yds)) {
        
        cout << "1. " << player3 << ": " << player3yds << endl;
        cout << "2. " << player1 << ": " << player1yds << endl;
        cout << "3. " << player2 << ": " << player2yds << endl;
    }
    
    else if ((player3yds > player2yds) && (player2yds > player1yds)) {
        
        cout << "1. " << player3 << ": " << player3yds << endl;
        cout << "2. " << player2 << ": " << player2yds << endl;
        cout << "3. " << player1 << ": " << player1yds << endl;
    }
    
    return 0;
    
}