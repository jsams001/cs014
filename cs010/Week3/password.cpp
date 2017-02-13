#include <iostream>
using namespace std;

int main () {
    
    const string PASSWORD = "password";
    string passwordg;
    
    cout << "Enter a password: ";
    cin >> passwordg;
    
    if (PASSWORD == passwordg)  {
        
        cout << "Password accepted. Welcome." << endl;
    }
    else {
        
        cout << "Wrong password. Try again." << endl;
    }
    
    return 0;
    
}