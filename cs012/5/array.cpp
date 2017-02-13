#include <iostream>
using namespace std;

 /*
 Passes in an array along with the size of the array and returns the mean of all values stored in the array.
 */
double mean(const double array[], int arraySize);

 /*
 Passes in an array, the size of the array, and the index of a value to be removed from the array. 
 The function should remove the value at this index by shifting all of the values after this value up, 
 keeping the same relative order of all values not removed.
 */
void remove(double array[], int arraySize, int index);

 /*
 Passes in an array and the size of the array, and then outputs each value in the array 
 separated by a comma and space, with no comma, space or newline at the end.
 */
void display(const double array[], int arraySize);

int main() {
    
    const int asize = 10;
    double myArray[10];
    double input;
    int index;
    
    cout << "Enter 10 values:" << endl << endl;
    for(int i = 0; i < 10; ++i) {
        
        cin >> input;
        myArray[i] = input;
    }
    
    cout << "Mean: " << mean(myArray, 10) << endl << endl;
    
    cout << "Enter index of value to be removed: " << endl;
    cin >> index;
    
    cout << "Before removing value: ";
    display(myArray, asize);
    remove(myArray, asize, index);
    cout << "After removing value: ";
    display(myArray, asize - 1);
    
    return 0;
}

double mean(const double array[], int arraySize) {
    
    double sum = 0.0;
    
    for(int i = 0; i < arraySize; ++i) {
        
        sum = sum + array[i];
    }
    
    return sum / arraySize;
}

void remove(double array[], int arraySize, int index) {
    
    double temp = 0.0;
    int count = 0;
    
    if(index == arraySize - 1) {
        return;
    }
    
    array[index] = 0;
    for(int i = index; i < arraySize - 1; ++i) {
        
        temp = array[i + 1];
        array[i + 1] = array[index + count];
        array[index + count] = temp;
        ++count;
    }
    
    return;
}

void display(const double array[], int arraySize) {
    
    
    for(int i = 0; i < arraySize - 1; ++i)
        cout << array[i] << ", ";
        
    cout << array[arraySize - 1] << endl;
    
    return;
}