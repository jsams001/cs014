#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string userInput;
    
    cout << "Enter text: " << endl;
    getline(cin, userInput);
    cout << "You entered: " << userInput << endl;
        
    if (userInput.find("BFF") != string::npos) 
        cout << "BFF: best friend forever" << endl;
        
    if (userInput.find("IDK") != string::npos ) 
        cout << "IDK: I don't know" << endl;
        
    if (userInput.find("JK") != string::npos ) 
        cout << "JK: just kidding" << endl;
        
    if (userInput.find("TMI") != string::npos ) 
        cout << "TMI: too much information" << endl;
        
    if (userInput.find("TTYL") != string::npos ) 
        cout << "TTYL: talk to you later" << endl;
        
    return 0;
    
}