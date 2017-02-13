#include <iostream>
using namespace std;
#include <cmath>

int main() { 
    
    double radius = 0.0;
    double circumference = 0.0;
    double area = 0.0;
    double volume = 0.0;
    double surfaceArea = 0.0;
    
    cout << "Enter radius: ";
    cin >> radius;
    
    circumference = 2 * 3.14 * radius;
    cout << "The circumference is " << circumference << endl;
    
    area = 3.14 * pow(radius, 2);
    cout << "Area is " << area << endl;
    
    volume = (4 * 3.14 * pow(radius, 3)) / 3;
    cout << "Volume is " << volume << endl;
    
    surfaceArea = 4 * 3.14 * pow(radius, 2);
    cout << "Surface area is " << surfaceArea << endl;
    
    return 0;   
}