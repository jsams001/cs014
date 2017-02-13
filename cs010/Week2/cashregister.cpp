#include <iostream>

using namespace std;

int main()
{
   double purchaseAmount = 0.0;
   double cashTendered = 0.0;
   double change = 0.0;          //floating-point change amount to be given to customer
   int changeInCents = 0;       //change amount converted to a total number of cents
   
   cout << "Enter purchase amount: ";
   cin >> purchaseAmount;
   
   cout << "Enter cash tendered by customer: ";
   cin >> cashTendered;
   
   cout << endl << "Total Change: $";
   
   //store total change in variable change
   change = cashTendered - purchaseAmount;
   
   //output change and newline
   cout << change << endl;

   //calculate and store in changeIntCents the total change amount in cents
   changeInCents = change * 100;
   
   cout << "Dollars: ";
   //calculate and output number of dollar bills to give back
   cout << changeInCents / 100;
   cout << endl;
   
   cout << "Quarters: ";
   //calculate and output number of quarters to give back
   changeInCents = changeInCents % 100;
   cout << changeInCents / 25;
   cout << endl;
   
   cout << "Dimes: ";
   //calculate and output number of dimes to give back
   changeInCents = (changeInCents % 25) / 10;
   cout << changeInCents;
   cout << endl;
   
   cout << "Nickels: ";
   //calculate and output number of nickels to give back
   changeInCents = (changeInCents % 25) / 5;
   cout << changeInCents;
   cout << endl;
   
   cout << "Pennies: ";
   //calculate and output number of pennies to give back
   changeInCents = ceil(changeInCents % 5) + 0.5;
   cout << changeInCents;
   cout << endl;
   return 0;
}