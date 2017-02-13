#include <iostream>
using namespace std;

/* Returns true if a solution was found and false if there is no solution.
   x and y will contain a solution if a solution was found. 
   This function will NOT output anything.
*/
bool diophantine(int a, int b, int c, int &x, int &y);

//GCD Function was pulled off of zybooks 
int gcd(int inNum1, int inNum2);

int main() {

    int a, b, c, x, y;

    cout << "Enter a b c" << endl;
    cin >> a >> b >> c;
    cout << endl;

    cout << "Result: ";
    if (diophantine(a, b, c, x, y)) {
        cout << x << " " << y << endl;
    } else {
        cout << "No solution!" << endl;
    }

    return 0;
}

bool diophantine(int a, int b, int c, int &x, int &y) {
    
    if((c % gcd(a,b)) != 0)
        return false;
        
    if(a % b == 0) {
        x = 0;
        y = c / b;
        return true;
    }
    
    if(diophantine(b, a % b, c, x, y)) {
        int temp = x;
        x = y;
        y = temp - (a / b) * x;
        return true;
    }
    
    return true;
}

//GIVEN OFF OF ZYBOOKS
int gcd(int inNum1, int inNum2) {
    int gcdVal = 0; // Holds GCD results
   
    if(inNum1 == inNum2) {    // Base case: Numbers are equal
        gcdVal = inNum1;       // Return value
    }
    else {  // Recursive case: subtract smaller from larger
        if(inNum2 < 0)
            inNum2 = inNum2 * -1;
        if(inNum1 < 0)
            inNum1 = inNum1 * -1;

        if (inNum1 > inNum2)  // Call function with new values
            gcdVal = gcd(inNum1 - inNum2, inNum2);
        else 
            gcdVal = gcd(inNum1, inNum2 - inNum1);
      
    }
   
    return gcdVal;
}
