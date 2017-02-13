#include <iostream>

using namespace std;

#include "IntVector.h"

int main() {
    
    /* TEST OF DEFAULT CONSTRUCTOR == COMPLETE
    IntVector one;
    
    cout << "Size is " << one.size() << endl;
    cout << "Capacity is " << one.capacity() << endl;
    
    if(one.empty())
        cout << "IntVector one is empty " << endl;
    else
        cout << "IntVector one is not empty " << endl;
    */
    
    /* TEST OF ALL FUNCTIONS; IT SEEMED OK BUT NOT PASSING 
    IntVector two(10, 5);
    
    cout << "Size of our vector is " << two.size() << endl;
    cout << "Capacity of our vector is " << two.capacity() << endl;
        
    if(two.empty()) 
        cout << "IntVector two is empty" << endl;
    else    
        cout << "IntVector two is not empty " << endl;
        
    cout << "Contents of our tested vector are: " << endl;
    for(unsigned int i = 0; i < two.size(); ++i) 
        cout << two.at(i) << " ";
    cout << endl;
    
    cout << "Testing insert; we will insert a 2 after the first index and see what occurs. " << endl;
    two.insert(1, 2);
    
    cout << "New contents of the vector are: " << endl;
    for(unsigned int i = 0; i < two.size(); ++i)
        cout << two.at(i) << " ";
    cout << endl;
    
    cout << "Now watch as we remove the same element we added in. " << endl;
    two.erase(1);
    
    for(unsigned int i = 0; i < two.size(); ++i)
        cout << two.at(i) << " ";
    cout << endl;
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl;
    
    cout << "Next we shall push back a 9. " << endl;
    two.push_back(9);
    
    for(unsigned int i = 0; i < two.size(); ++i)
        cout << two.at(i) << " ";
    cout << endl;
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl;
    
    cout << "Now remove it! " << endl;
    two.pop_back();
    
    for(unsigned int i = 0; i < two.size(); ++i)
        cout << two.at(i) << " ";
    cout << endl;
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl;
       
    cout << "Let's try resizing the vector to a size of 20, adding in the elements as 8. " << endl;
    two.resize(20, 8);
    
    cout << "Let's see the result: " << endl;
    for(unsigned int i = 0; i < two.size(); ++i)
        cout << two.at(i) << " ";
    cout << endl;
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl;
    
    cout << "Now let's bring it down to a size of 6. " << endl;
    two.resize(6);
    
    for(unsigned int i = 0; i < two.size(); ++i) 
        cout << two.at(i) << " ";
    cout << endl;
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl;
    
    cout << "Now let's replace all the elements with a 9, and change the size to 8. " << endl;
    two.assign(8, 9);
    
    for(unsigned int i = 0; i < two.size(); ++i)
        cout << two.at(i) << " ";
    cout << endl;
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl;
    */
    
    
    /* INSERT FUNCTION CHECK == COMPLETE 
    cout << "Testing insert function: Contents currently: " << endl;
    two.push_back(0);
    two.push_back(3);
    two.push_back(5);
    two.push_back(7);
    two.push_back(9);
    
    for(unsigned int i = 0; i < two.size(); ++i)
        cout << two.at(i) << " ";
    cout << endl;
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl << "Now we will start inserting." << endl;
    
    two.insert(1, 1);
    for(unsigned int i = 0; i < two.size(); ++i) 
        cout << two.at(i) << " ";
    cout << endl;
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl << "Now we will start inserting." << endl;
    
    two.insert(2, 2);
    for(unsigned int i = 0; i < two.size(); ++i) 
        cout << two.at(i) << " ";
    cout << endl;
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl << "Now we will start inserting." << endl;
    
    two.insert(4, 4);
    for(unsigned int i = 0; i < two.size(); ++i) 
        cout << two.at(i) << " ";
    cout << endl;
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl << "Now we will start inserting." << endl;
    
    two.insert(6, 6);
    for(unsigned int i = 0; i < two.size(); ++i) 
        cout << two.at(i) << " ";
    cout << endl;
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl << "Now we will start inserting." << endl;
    
    two.insert(8, 8);
    for(unsigned int i = 0; i < two.size(); ++i) 
        cout << two.at(i) << " ";
    cout << endl;
    */
    
    /*ERASE FUNCTION CHECK  == COMPLETE
    cout << "Contents after pushing back random values: " << endl;
    two.push_back(7);
    two.push_back(-3);
    two.push_back(0);
    two.push_back(1);
    
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl;
    
    for(unsigned int i = 0; i < two.size(); ++i) 
        cout << two.at(i) << " ";
    cout << endl;
    
    cout << "Testing erase function: " << endl;
    
    cout << "Erase a 0 " << endl;
    two.erase(0);
    for(unsigned int i = 0; i < two.size(); ++i) 
        cout << two.at(i) << " ";
    cout << endl;
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl;
    
    cout << "Erase the last element " << endl;
    two.erase(2);
    for(unsigned int i = 0; i < two.size(); ++i) 
        cout << two.at(i) << " ";
    cout << endl;
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl;
    
    // cout << "Erase a 7 " << endl;
    // two.erase(7);
    // for(unsigned int i = 0; i < two.size(); ++i) 
    //     cout << two.at(i) << " ";
    // cout << endl;
    
    // cout << "Erase a 6 " << endl;
    // two.erase(6);
    // for(unsigned int i = 0; i < two.size(); ++i) 
    //     cout << two.at(i) << " ";
    // cout << endl;
    
    // cout << "Trying a 0 " << endl;
    // two.erase(0);
    // for(unsigned int i = 0; i < two.size(); ++i) 
    //     cout << two.at(i) << " ";
    // cout << endl;
    
    // cout << "Now the last value " << endl;
    // two.erase(5);
    // for(unsigned int i = 0; i < two.size(); ++i) 
    //     cout << two.at(i) << " ";
    // cout << endl;
    
    // cout << "Let's try an error. " << endl;
    // two.erase(5);
    // for(unsigned int i = 0; i < two.size(); ++i) 
    //     cout << two.at(i) << " ";
    cout << endl;
    */
    
    /* RESIZE FUNCTION CHECK == COMPLETE
    IntVector two;
    cout << "Contents after pushing back some values: " << endl;
    two.push_back(0);
    two.push_back(1);
    two.push_back(2);
    two.push_back(3);
    two.push_back(4);
    two.push_back(5);
    two.push_back(6);
    two.push_back(7);
    two.push_back(8);
    two.push_back(9);
    
    for(unsigned int i = 0; i < two.size(); ++i) 
        cout << two.at(i) << " ";
    cout << endl;
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl;
    
    cout << "Let's try resizing to a value of 20 " << endl;
    two.resize(20);
    
    for(unsigned int i = 0; i < two.size(); ++i) 
        cout << two.at(i) << " ";
    cout << endl;
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl;
    
    cout << "Let's try resizing to a value of 20 " << endl;
    two.resize(20);
    
    for(unsigned int i = 0; i < two.size(); ++i) 
        cout << two.at(i) << " ";
    cout << endl;
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl;
    
    cout << "Now try resizing down " << endl;
    two.resize(5);
    
    for(unsigned int i = 0; i < two.size(); ++i) 
        cout << two.at(i) << " ";
    cout << endl;
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl;
    
    */
    
    /* ASSIGN FUNCTION CHECK == COMPLETE
    IntVector two;
    cout << "Contents after pushing back some values: " << endl;
    two.push_back(0);
    two.push_back(1);
    two.push_back(2);
    two.push_back(3);
    two.push_back(4);
    two.push_back(5);
    two.push_back(6);
    two.push_back(7);
    two.push_back(8);
    two.push_back(9);
    two.push_back(10);
    
    for(unsigned int i = 0; i < two.size(); ++i) 
        cout << two.at(i) << " ";
    cout << endl;
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl;
    
    cout << "Let's try assigning all values to -362. " << endl;
    two.assign(10, -362);
    
    for(unsigned int i = 0; i < two.size(); ++i) 
        cout << two.at(i) << " ";
    cout << endl;
    cout << "Size: " << two.size() << " Capacity: " << two.capacity() << endl;
    cout << "Value at index 0: " << two.at(0) << endl;
    */
    
    return 0;
        
}