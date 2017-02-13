#include <iostream>
#include <cmath>
using namespace std;

int main () {
    
    int num = 0;
    int odd = 0;
    int even = 0;
    
    cout << "Enter a number: ";
    cin >> num;
    
    while (num != 1){ 
            
        if (num == 1) 
            cout << num << endl;
        else 
            cout << num << " -> ";
            
        if (num % 2 == 0)
            num = num / 2;
        else 
            num = num * 3 + 1;
            
    }
    
    cout << num << endl;
    
    return 0;
    
}