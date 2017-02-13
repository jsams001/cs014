#include <iostream>
#include <string>

#ifndef __FOOD__
#define __FOOD__

class Food
{
    private:
        string name;
        int calories;
        
    public:
        //Set initial food to an Apple with 100 calories
        //Must use initialization lists
        Food();
        
        //Sets name & calories. Note: You may not change the function parameters
        Food(string name, int calories);
        
        //Returns the name of the food
        string getName() const;
        
        //Returns the amount of calories
        int getCalories() const;
        
        //Output the food
        //Ex
        //Item: Orange
        //Calories: 150
        friend ostream & operator<<(ostream &, const Food &);
};

#endif