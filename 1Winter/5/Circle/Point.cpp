//Point implementation file

#include "Point.h"
#include <iostream>

using namespace std;
#include <cmath>

Point::Point() {
	xCoord = 0.0;
	yCoord = 0.0;
}

Point::Point(double x, double y) {
	xCoord = x;
	yCoord = y;
}

void Point::display() const {
	cout << "(" << xCoord << "," << yCoord << ")";
}

double Point::operator-(const Point &rhs) const {
    
    return sqrt((pow(rhs.xCoord - xCoord, 2)) + (pow(rhs.yCoord - yCoord, 2)));
}