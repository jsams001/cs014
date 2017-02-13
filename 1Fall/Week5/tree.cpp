#include <iostream>
using namespace std;

//Currently messed up; worked before but I not so smartly messed with it during my first quarter. 
//Will change sometime in the future

int main() {
    
    int trunkHeight = 0;
    int trunkWidth = 0;
    int leavesWidth = 0;
    int space = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    
    cout << "Enter trunk height: ";
    cin >> trunkHeight;
    
    cout << "Enter trunk width: ";
    cin >> trunkWidth;
    while ((trunkWidth % 2) == 0) {
        cout << "Please enter an odd number for the width." << endl;
        cout << "Enter trunk width again: ";
        cin >> trunkWidth;
    }
    
    cout << "Enter leaves width: ";
    cin >> leavesWidth;
    while ((leavesWidth % 2) == 0) {
        cout << "Please enter an odd number for the width." << endl;
        cout << "Enter leaves width again: ";
        cin >> leavesWidth;
    }
    cout << endl;
    space = leavesWidth / 2;
    
    for (a = 0; a < (leavesWidth / 2) + 2; ++a) {
        
        if (a != 0) {
            for (b = leavesWidth; b > space; --b){
                cout << " ";
            }
        }
        
        for (c = 0; c < 2 * a - 1; ++c) {
            cout << "*";
        }
        
        ++space;
        
        if (a != 0)
            cout << endl;
    }
    
    for (d = 0; d < trunkHeight; ++d) {
        
        if (leavesWidth > 9)
            space = (leavesWidth / 2) - 2;
        else if (leavesWidth > 13)
            space = (leavesWidth / 2) - 3;
            
        for (e = 0; e < space / 2; ++e){
            cout << " ";
        }
        
        for (f = 0;  f < trunkWidth; ++f) {
            cout << "*";
        }
        
        cout << endl;
    }
    
    return 0;
}