#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Meal.h"

int main() {
    
    string input;
    int input2;
    string mealname;
    vector <Food> myVector;
    Food passin;
    string ask;
    
    Food food1;
    
    cout << food1 << endl;
    
    cout << "Enter food name. " << endl;
    cin >> input;
    cout << "Now calories. " << endl;
    cin >> input2;
    
    Food food2(input, input2);
    
    cout << food2 << endl;
    
    cout << "Now the meal. " << endl;
    
    Meal meal1;
    
    meal1.printItems();
    
    cout << "Enter the meal name. " << endl;
    cin >> mealname;
    
    cout << "Declare how many items in vector (Press c to stop) " << endl;
    
    cin >> ask;
    
    while(ask != "c") {
        
        cout << "Enter food name. " << endl;
        cin >> input;
        cout << "Now calories. " << endl;
        cin >> input2;
        
        myVector.push_back(Food(input, input2));
        
        cin >> ask;
    }
    
    Meal meal2(mealname, myVector);
    meal1.printItems();
    
    return 0;
}