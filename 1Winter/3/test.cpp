#include <vector>
#include <iostream>
#include <cctype>
#include <string>
#include <stdio.h>

using namespace std;

int main () {
 string input;
 char c;

cout << "Input" << endl;
cin >> input;

if(islower(input.at(0))) {
 c = input.at(0);
 ptoupper(c);
 input.replace(0, 1, c);
}
 
 
 
 cout << input << endl;
 
 return 0;  
}