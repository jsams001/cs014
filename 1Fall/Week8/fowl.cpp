#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

const double pi = 3.14159265;
const double grav = 9.8; // Earth gravity (m/s^2)

// Given time, angle, velocity, and gravity
// Update x and y values
void Trajectory(double t, double a, double v,
                double& x, double& y) {
    x = v * t * cos(a);
    y = v * t * sin(a) - 0.5 * grav * t * t;
    return;
}

// convert degree value to radians
double DegToRad(double deg) {
    return ((deg * pi) / 180.0);
}

// print time, x, and y values
void PrintUpdate(double t, double x, double y) {
    cout << "Time " << fixed << setprecision(0)
         << setw(3) << t << "   x = " << setw(3)
         << x << "   y = " << setw(3) << y << endl;
    return;
}

// Prints game's intro message
void PrintIntro() {
    cout << "Welcome to Upset Fowl!\n";
    cout << "The objective is to hit the Mean Swine.\n";
    return;
}

// Given swine's current horiz. position
// Get user's desired launch angle and velocity for fowl
void GetUsrInpt(double swineX, double &fowlAngle, double &fowlVel) {
    
    cout << "\nThe Mean Swine is " << swineX << " meters away.\n";

    cout << "Enter launch angle (deg): ";
    cin >> fowlAngle;
    cout << endl;
    fowlAngle = DegToRad(fowlAngle); // convert to radians

    cout << "Enter launch velocity (m/s): ";
    cin >> fowlVel;
    cout << endl;
    return;
}


// Given fowl launch angle and velocity
// Return horiz. landing position of fowl
double LaunchFowl(double fowlAngle, double fowlVel) {
    
    double t = 1.0;
    double fowlX = 0.0;
    double fowlY = 0.0;
    double fowlLandingX = fowlX;
    
    do {
        PrintUpdate(t, fowlX, fowlY);
        Trajectory(t, fowlAngle, fowlVel, fowlX, fowlY);
        t = t + 1.0;
    } while ( fowlY > 0.0 ); // while above ground
    PrintUpdate(t, fowlX, fowlY);

    fowlLandingX = fowlX;
    return fowlLandingX;
}


// Given fowl's horiz. landing position and swine's horiz. position
// Return whether fowl hit swine or not
bool DtrmnIfHit(double fowlLandingX, double swineX) {
    
    double beforeSwineX = 0.0;
    bool didHitSwine = false; 
    
    beforeSwineX = swineX - 30;
    if ((fowlLandingX <= swineX) && (fowlLandingX >= beforeSwineX)) {
        cout << "Hit'em!!!" << endl;
        didHitSwine = true;
    } else {
        cout << "Missed'em..." << endl;
        didHitSwine = false;
    }
   return didHitSwine;
}

int main() {
    double fowlAngle = 0.0; // angle of launch (rad)
    double fowlVel = 0.0; // velocity (m/s)
    double fowlLandingX = 0.0;
    double swineX = 40.0; // distance to swine (m)
    bool didHitSwine = false;
    int tries = 4;
    int i = 0;

    srand(20); //to ensure the correct output for grading
    swineX = (rand() % 201) + 50;
    
    
    PrintIntro();
    for (i = 0; i < tries; ++i) {
        
        if (didHitSwine) {
            GetUsrInpt(swineX, fowlAngle, fowlVel);
    
            fowlLandingX = LaunchFowl(fowlAngle, fowlVel);
    
            didHitSwine = DtrmnIfHit(fowlLandingX, swineX);
        }
        
    }
        
    return 0;
}