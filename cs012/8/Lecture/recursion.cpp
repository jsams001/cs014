#include <iostream>
#include <string>
using namespace std;

double powerTo(double base, int power) {
    
    if(power == 0)
        return 1;
    else 
        return base * powerTo(base, power - 1);
}

bool isPalindrome(string s) {
    
    if(s.size() <= 1) 
        return true;
    else if(s.at(0) != s.at(s.size() - 1)) //if doesn't work try s.at(0) and s.size() - 1;
        return false;
    else
        return isPalindrome(s.substr(1, s.size() - 2));
    
}

int main() {
    
    int input = 0;
    int power = 0;
    string word;
    
    cout << "Enter a number " << endl;
    cin >> input;
    cout << "Enter a power " << endl;
    cin >> power;
    cout << input << "^" << power << " = " << powerTo(input, power) << endl;
    
    cout << "Enter a word " << endl;
    cin >> word;
    
    if(isPalindrome(word))
        cout << "Your word is the same spelled backwards. " << endl;
    else
        cout << "Your word is not the same spelled backwards. " << endl;
    
    return 0;
}