#include <iostream>
#include <cmath>
using namespace std;

int gen_gcf (int a, int b) {
    
    int gcf = 0;
    
    return fabs(b - a);
}

int main() {
    
    int gcf = 0;
    int a = 0;
    int b = 0;
    
    cout << "Enter 1st: ";
    cin >> a;
    cout << "Enter 2nd: ";
    cin >> b;
    
    gcf = gen_gcf(a, b);
    
    cout << gcf << endl;
    
    return 0;
}