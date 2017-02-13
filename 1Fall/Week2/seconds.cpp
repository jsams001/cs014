#include <iostream>
using namespace std;
#include <cmath>
#include <ctime>

int main() {
    
    int seconds = 0;
    int days = 0;
    int hours = 0;
    int minutes = 0;
    
    cout << "Enter number of seconds: ";
    cin >> seconds;
    
    days = seconds / (60 * 60 * 24);
    cout << "Number of days is: " << days << endl;
    
    hours = (seconds % (60 * 60 * 24)) / 3600;
    cout << "Number of hours is: " << hours << endl;
    
    minutes = (seconds % (60 * 60)) / 60;
    cout << "Number of minutes is: " << minutes << endl;
    
    seconds = (seconds % 60);
    cout << "This would be " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds" << endl;
    
    return 0;
}