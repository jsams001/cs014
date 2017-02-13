#include <iostream>
using namespace std;
#include <cmath>
#include <ctime>

int main() {
    
    //Same as seconds.cpp, only this while show the amount of seconds since the beginning of the time(0) implementation
    int seconds = 0;
    int days = 0;
    int hours = 0;
    int minutes = 0;
    int since = time(0);
    
    days = since / (60 * 60 * 24);
    cout << "Number of days is: " << days << endl;
    
    hours = (since % (60 * 60 * 24)) / 3600;
    cout << "Number of hours is: " << hours << endl;
    
    minutes = (since % (60 * 60)) / 60;
    cout << "Number of minutes is: " << minutes << endl;
    
    seconds = (since % 60);
    cout << "This would be " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds" << endl;
    
    return 0;
}