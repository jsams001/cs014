#include <iostream>
#include <cmath>
using namespace std;

int main () { 
    
    double x1 = 0.0;
    double x2 = 0.0;
    double y1 = 0.0;
    double y2 = 0.0;
    double distance = 0.0;
    
    cout << "Enter the first point's coordinates " << endl << "x: ";
    cin >> x1;
    cout << "y: ";
    cin >> y1;
    
    cout << "Enter the second point's coordinates " << endl << "x: ";
    cin >> x2;
    cout << "y: ";
    cin >> y2;
    
    distance = sqrt(pow((x2 - x1), 2) + (pow((y2 - y1), 2)));
    cout << "The distance between the two points is " << distance << endl;
    
    return 0;
    
}