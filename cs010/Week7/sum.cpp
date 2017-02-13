#include <iostream>
#include <cmath>
using namespace std;

int gen_sum (int a, int b) {
    
    int i = 0;
    int j = 0;
    int sum = 0;
    for (i = a; i <= b; ++i) {
        sum = sum + i;
    }
    
    return sum;
}

int main() {
    
    int sum = 0;
    int a = 0;
    int b = 0;
    
    cout << "Enter 1st: ";
    cin >> a;
    cout << "Enter 2nd: ";
    cin >> b;
    
    sum = gen_sum(a, b);
    
    cout << sum << endl;
    
    return 0;
}