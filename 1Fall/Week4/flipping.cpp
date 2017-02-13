#include <iostream>
#include <string>
using namespace std;

int main () {
    
    string userString;
    string newString;
    int i = 0;
    char c = '-';
    
    cout << "Enter a string: "; 
    getline(cin, userString);
    cout << "Your string is: " << userString << endl;
    
    for (i = userString.size() - 1; i >= 0; --i) {
        
        c = userString.at(i);
        newString.at(i) = userString.insert(userString.size() - 1, c);
    }
    
    cout << "Your new string is: " << newString << endl;
    
    return 0;
    
}