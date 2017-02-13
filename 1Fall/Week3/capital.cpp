#include <iostream>
#include <string>
using namespace std;

int main () {
    
    char character1 = 'a';
    
    cout << "Enter a letter: ";
    cin >> character1;
    
    if ((character1 >= 'a') && (character1 <= 'z')) {
        
        cout << "You entered a lowercase letter." << endl;
        
    }
    
    else if ((character1 >= 'A') && (character1 <= 'Z')) {
        
        cout << "You entered an uppercase letter." << endl;
    }
    
    return 0;
}