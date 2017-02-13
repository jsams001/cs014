#include "Distance.h"

Distance::Distance() {
    
    feet = 0;
    inches = 0;
}

Distance::Distance(unsigned ft, double in) {
    
    feet = ft;
    inches = in;
    
    init();
}

Distance::Distance(double in) {
    
    feet = 0;
    inches = in;
    
    init();
}

unsigned Distance::getFeet() const {
    
    return feet;
}

double Distance::getInches() const {
    
    return inches;
}

double Distance::distanceInInches() const {
    
    return (feet * 12) + inches;
}

double Distance::distanceInFeet() const {
    
    return (inches / 12) + (static_cast<double>(feet));
}

double Distance::distanceInMeters() const {
    
    double inM;
    double ftM;
    
    inM = inches * 0.0254;
    ftM = feet * 12 * 0.0254;
    
    return inM + ftM;
}

const Distance Distance::operator+(const Distance &rhs) const {
    
    Distance totalD;
    
    totalD.feet = feet + rhs.feet;
    totalD.inches = inches + rhs.inches;
    
    totalD.init();
    
    return totalD;
}

const Distance Distance::operator-(const Distance &rhs) const {
    
    Distance totalD;
    
    double range = distanceInInches();
    totalD.inches = range - rhs.distanceInInches();
    
    totalD.init();
    
    return totalD;
}

ostream & operator<<(ostream &out, const Distance &rhs) {
    
    out << rhs.feet << "\' " << rhs.inches << "\"";
    return out;
}

void Distance::init() {
    
    if(inches < 0)
        inches = inches * -1;
        
    if(inches >= 12) {
        feet = feet + static_cast<int>(inches) / 12;
        inches = (inches - static_cast<int>(inches)) + static_cast<int>(inches) % 12;
    }
}