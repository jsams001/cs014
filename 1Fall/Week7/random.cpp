#include <iostream>
#include <cstdlib>
using namespace std;

int gen_rand (int a, int b) {
    
    if (a > b) 
        return (rand() % a - b + 1); 
    else 
        return (rand() % b - a + 1);
        
}

int main() {
    srand(time(0));
    
    int random = 0;
    int a = 0;
    int b = 0;
    
    cout << "Enter 1st: ";
    cin >> a;
    cout << "Enter 2nd: ";
    cin >> b;
    
    random = gen_rand(a, b);
    
    cout << random << endl;
    
    return 0;
}