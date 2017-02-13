#include <iostream>

using namespace std;

int main() {
    
    int score = 0;
    
    cout << "Enter your midterm score: ";
    cin >> score;
    
    cout << "Your grade: ";
    if (score >= 90) {
        
        cout << "A" << endl;
    }
    else if (score >= 80) {
        
        cout << "B" << endl;
    }
    else if (score >= 70) {
        
        cout << "C" << endl;
    }
    else if (score >= 60) {
        
        cout << "D" << endl;
    }
    else {
        
        cout << "You didn't pass." << endl;
    }
    
    cout << "Good luck on the final exam!" << endl;
    
    return 0;
}