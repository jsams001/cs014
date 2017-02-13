#include <iostream>
using namespace std;

int main () { 
    
    int numStudents = 0;
    int numClassrooms = 0;
    
    cout << "Enter number of students: ";
    cin >> numStudents;
    cout << "Enter number of classrooms ";
    cin >> numClassrooms;
    
    cout << "Avg number of students per classroom: "
        << static_cast<double>(numStudents) / numClassrooms
        << endl;
}