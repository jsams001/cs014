#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string userInput;
    int i = 0;
    
    cout << "Enter text: " << endl;
    getline(cin, userInput);
    cout << "You entered: " << userInput << endl;
    
    for (i = 0; i < userInput.size(); ++i) { 
    
        if (userInput.find("BFF") != string::npos) 
            userInput.replace(userInput.find("BFF"), 3, "best friend forever");
            
        if (userInput.find("IDK") != string::npos) 
            userInput.replace(userInput.find("IDK"), 3, "I don't know");
        
        if (userInput.find("JK") != string::npos) 
            userInput.replace(userInput.find("JK"), 2, "just kidding");
        
        if (userInput.find("TMI") != string::npos) 
            userInput.replace(userInput.find("TMI"), 3, "too much information");
        
        if (userInput.find("TTYL") != string::npos) 
            userInput.replace(userInput.find("TTYL"), 4, "talk to you later");
        
    }
    
    cout << "Expanded: " << userInput << endl;
     
    return 0;
    
}