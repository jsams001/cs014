#include <iostream>
using namespace std;
#include <cmath>

int main () {
    
    int x = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    
    cout << "Enter a: ";
    cin >> a;
    
    cout << "Enter b: ";
    cin >> b;
    
    cout << "Enter c: ";
    cin >> c;
    
    if (4 * a * c > pow(b, 2)) {
        
        cout << "You can not take the square root of a negative number. Try again." << endl;
    }
    
    else if (a == 0) {
        
        cout << "You can not divide by zero. Enter a new a value." << endl;
    }
    else {
        
        x = (-b + (sqrt((pow(b, 2)) - (4 * a * c)))) / (2 * a); //minus part of quadratic
    
        cout << "First value of x is: " << x << endl;
    
        x = (-b - (sqrt((pow(b, 2)) - (4 * a * c)))) / (2 * a); //plus part of quadratic
    
        cout << "Second value of x is: " << x << endl;
    }
    
    return 0;
}