#include <iostream>
#include <string>

using namespace std;

#include "Food.h"

Food::Food():name("Apple"), calories(100) {}

Food::Food(string name, int calories):name(name), calories(calories) {}

string Food::getName() const {
    
    return name;
}

int Food::getCalories() const {
    
    return calories;
}

ostream & operator<<(ostream &out, const Food&rhs) {
    
    out << "Item: " << rhs.name << endl;
    out << "Calories: " << rhs.calories << endl;
    
    return out;
}

// int main() {
    
//     string input;
//     int input2;
    
//     Food food1;
    
//     cout << food1 << endl;
    
//     cin >> input;
//     cin >> input2;
    
//     Food food2(input, input2);
    
//     cout << food2 << endl;
    
// }

