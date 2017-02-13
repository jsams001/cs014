/* This program is similar to cookies.cpp, but compiles without the use of if statements */

#include <iostream>
#include <cmath>
using namespace std;

int main () {
    
    int students = 0;
    int cookies = 0;
    int totalcookies = 0;
    const int BATCHES = 12;
    double totalbatches = 0;
    int sicookies = 0;
    
    cout << "Enter the amount of students: " << endl;
    cin >> students;
    cout << "Enter the amount of cookies he wants each student to have: " << endl;
    cin >> cookies;
    
    totalcookies = students * cookies;
    cout << "He has to make " << totalcookies << " cookies." << endl;
    
    totalbatches = (totalcookies + 11) / 12;
    cout << totalbatches << " have to be made." << endl;
        
    sicookies = fabs(totalcookies - (BATCHES * totalbatches));
    cout << sicookies << " are left for SI leaders." << endl;
    
    return 0;
}