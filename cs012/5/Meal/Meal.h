#include <iostream>
#include <string>

using namespace std;

#ifndef __MEAL__
#define __MEAL__

#include "Food.h"

class Meal
{
    private:
        string name;
        int itemCount;
        Food itemArray[10];
        
    public:
        //Set meal to Breakfast, with 0 items
        Meal();
        
        //Set meal name and declare itemArray to have the items in the vector
        Meal(string name, vector<Food> foodVector);
        
        //Add the food to the itemArray
        void addFood(Food);
        
        //Return the name of the meal
        string getName() const;
        
        //Return total amount of calories in the meal
        int getTotalCalories() const;
        
        //Print out the array of food
        void printItems() const;
};

#endif