#include <iostream>
using namespace std;

int main (){
    
    int cashTendered = 0;
    int purchaseAmount = 0;
    int change = 0;
    double changeInCents = 0.0;
    
    cout << "Enter purchase amount: $" << endl;
    cin >> purchaseAmount;
    
    cout << "Enter cash tendered: $" << endl;
    cin >> cashTendered;
    
    change = cashTendered - purchaseAmount;

    cout << "Total change: $" << static_cast<double>(change) << endl;
    
    changeInCents = change * 100;
    
    cout << "Total # of pennies: " << changeInCents << " cents" << endl;
    
    return 0;
    
}