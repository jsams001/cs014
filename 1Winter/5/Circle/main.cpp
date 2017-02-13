#include "Point.h" 
#include "Circle.h"
#include <iostream>
using namespace std;
int main()
{
 Point p = Point(1, 1);
 cout << "p: "; p.display(); cout << endl;
 Point q;
 cout << "q: "; q.display(); cout << endl;
 cout << "Distance between p and q: " << q - p << endl;
 Circle c1;
 cout << "c1: "; c1.display(); cout << endl;
 Circle c2 = Circle(Point(4.0, 3.0), 2.5);
 cout << "c2: "; c2.display(); cout << endl;
 cout << "Distance between c1 and c2: " << c1 - c2 << endl;
 return 0;
}