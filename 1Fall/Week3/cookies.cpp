#include <iostream>
#include <cmath>
using namespace std;

int main () {
    
    int students = 0;
    int cookies = 0;
    int totalcookies = 0;
    const int BATCHES = 12;
    int totalbatches = 0;
    int sicookies = 0;
    
    cout << "Enter the amount of students: " << endl;
    cin >> students;
    cout << "Enter the amount of cookies he wants each student to have: " << endl;
    cin >> cookies;
    
    totalcookies =  (students * cookies);
    cout << "He has " << students << " students, he wants each to have " << cookies << " cookies." << endl;
    cout << "He has to make " << totalcookies << " cookies." << endl;
    
    totalbatches = totalcookies / BATCHES;
    if (totalcookies % BATCHES >= 1) {
    
        totalbatches = totalbatches + 1;
    }
    
    cout << "Therefore he has to make " << totalbatches << " batches of 12." << endl;
    
    sicookies = fabs(totalcookies - (BATCHES * totalbatches));
    cout << sicookies << " are left for SI leaders." << endl;
    
    return 0;
}