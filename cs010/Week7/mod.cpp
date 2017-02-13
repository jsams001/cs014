#include <iostream>
using namespace std;

int gen_remainder (int a, int b) {
    
    return a - b * (a / b);
}

int main() {
    
    int rem = 0;
    int a = 0;
    int b = 0;
    
    cout << "Enter numerator: ";
    cin >> a;
    cout << "Enter denominator: ";
    cin >> b;
    
    rem = gen_remainder(a, b);
    
    cout << rem << endl;
    
    return 0;
}