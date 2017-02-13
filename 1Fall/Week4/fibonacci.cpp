#include <iostream>
#include <cmath>
using namespace std;

int main () {
    
    int first = 0;
    int second = 1;
    int input = 0;
    int answer = 0;
    
    cout << "Enter a number: ";
    cin >> input;
    
    if(answer == 0)
        cout << "The fibonacci value for " << input << " is 0." << endl;
    else if(n == 1)
        cout << "The fibonacci value for " << input << " is 1." << endl;
    else {
        for(int i = 2; i < n + 1; ++i) {
            answer = first + second;
            first = second;
            second = answer;
            cout << "The fibonacci value for " << input << " is " << answer << endl;
        }
    }
    
    return 0;
    
}