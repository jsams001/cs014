#include <iostream>
#include <cmath>
using namespace std;

int main () {
    
    int i = 0;
    int n = 0;
    int power = 0; 
    
    cout << "Enter a number: " << endl;
    cin >> n;
    cout << "Powers of 2 up to 2^" << n << endl;
    
    for (i = 0; i < n; ++i) {
        
        power = pow(2, i);
        cout << power << endl;
        
    }
    
    return 0;
    
}