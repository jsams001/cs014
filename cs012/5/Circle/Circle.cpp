#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle():radius(0.0) {}

Circle::Circle(const Point &c, double r): center(c), radius(r) {}

void Circle::display() const {
    
    center.display();
    cout << " , " << radius;
}

double Circle::operator-(const Circle &rhs) const {
    
    return center - rhs.center;
}