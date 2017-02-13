#ifndef __CIRCLE__
#define __CIRCLE__

#include "Point.h"

class Circle {
    
    private:
        Point center;
        double radius;
    public:
        Circle();
        Circle(const Point &, double);
        double operator-(const Circle &) const;
        void display() const;
        
};

#endif