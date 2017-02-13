#include <iostream>
#include <sstream>
#include <stdlib.h> 

using namespace std;

int main() {
    
    string a = "1,46,2,44,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0";
    istringstream line(a);
    int b = 0;
    char junk;
    int c = 0;
    
    line >> b;
    line >> junk;
    line >> c;
    
    cout << b << endl << junk << endl << c << endl;
}