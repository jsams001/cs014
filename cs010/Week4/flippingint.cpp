#include <iostream>
#include <cmath>
using namespace std;

int main () {
    
    int userNum = 0;
    int ones = 0;
    int tens = 0;
    int hundreds = 0;
    
    cout << "Enter a number: ";
    cin >> userNum;
    //cout << userNum;
    
    //while 
    hundreds = (floor(userNum / 100));
    tens = floor(userNum % 100) / 10;
    ones = userNum % 10;
    
    cout << ones << tens << hundreds << endl;
    
    return 0;
    
}