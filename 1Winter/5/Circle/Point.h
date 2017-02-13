#ifndef __POINT_H__ 
#define __POINT_H__
class Point
{
private:
 double xCoord;
 double yCoord;
public:
 Point();
 Point(double, double);
 void display() const;
 //returns the distance between 2 points (absolute value)
 double operator-(const Point &) const;
};
#endif