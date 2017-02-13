#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Food.h"
#include "Meal.h"

Meal::Meal() : name("Breakfast"), itemCount(0) {}

Meal::Meal(string name, vector<Food> foodVector) {
    
    this->name = name;
    
    itemCount = foodVector.size();
    
    itemArray[itemCount];
    
    for(int i = 0; i < itemCount; ++i) {
        
        addFood(vector.at(i));
    }
    
}

void Meal::addFood(Food setting) {
    
    itemArray[] = setting;
}

string Meal::getName() const {
    
    return name;
}

int Meal::getTotalCalories() const {
    
    int sum = 0;

    for(int i = 0; i < itemCount; ++i) {
        sum = sum + itemArray[i].calories;
    }
    
    return sum;
}

void Meal::printItems() const {
    
    for(int i = 0; i < itemCount; ++i)
        cout << itemArray[i] << " " << endl;
}