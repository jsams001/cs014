#include <stdexcept>

using namespace std;

#include "IntVector.h"

IntVector::IntVector() : sz(0), cap(0), data(0){}

IntVector::IntVector(unsigned size, int value) {
    
    sz = size;
    cap = size;
    data = new int[size];
    
    for(unsigned int i = 0; i < sz; ++i)
        data[i] = value;
}

IntVector::~IntVector() {
    delete [] data;
}
    
unsigned IntVector::size() const {
    return sz;
}

        
unsigned IntVector::capacity() const {
    return cap;
}
    
bool IntVector::empty() const {
    if(sz == 0) 
        return true;
    
    return false;
}
        
const int & IntVector::at(unsigned index) const {
    
    if(index >= sz)
        throw out_of_range("IntVector::at_range_check");
        
    return data[index];
}
        
const int & IntVector::front() const {
    return data[0];
}
        
const int & IntVector::back() const {
    return data[sz - 1];
}

//start of program functions

void IntVector::insert(unsigned index, int value) {
    
    if(index > sz) {
        throw out_of_range("IntVector::insert_range_check");
        return;
    }
    
    if(sz + 1 > cap) 
        expand();
    
    sz++;
    for(unsigned int i = sz; i > index; i--) 
        data[i] = data[i - 1];
    
    data[index] = value;
    return;
    
}

void IntVector::erase(unsigned index) {
    
    if(index >= sz) {
        throw out_of_range("IntVector::erase_range_check");
        return;
    }
    
    for(unsigned int i = index; i + 1 < sz; ++i) 
        data[i] = data[i + 1];
    sz--;
    return;
}

void IntVector::push_back(int value) {
    
    if(sz + 1 > cap) 
        expand();
    
    sz++;
    data[sz - 1] = value;
}

void IntVector::pop_back() {
    
    if(empty())
        return;
    
    sz--;
    return;
}

void IntVector::clear() {
    
    sz = 0;
    return; 
}

void IntVector::resize(unsigned size, int value) {
    
    while(cap < size) {
        if(cap * 2 < size)
            expand(size - cap);
        else
            expand();
    }
    
    if (sz < size) {
        for(unsigned int i = sz; i < size; ++i)
            data[i] = value;
    }
    
    sz = size;
        
    return;
    
}

void IntVector::reserve(unsigned n) {
    
    while(cap < n) {
        if(cap * 2 < n)
            expand(n - cap);
        else
            expand();
    }
        
    return;
}

void IntVector::assign(unsigned n, int value) {
    
    while(cap < n) {
        if(cap * 2 < n)
            expand(n - cap);
        else
            expand();
    }
    
    sz = n;
    for(unsigned int i = 0; i < sz; ++i)
        data[i] = value;
        
    return;
    
}

int & IntVector::at(unsigned index) {
    
    if(index >= sz)
        throw out_of_range("IntVector::at_range_check");
    return data[index];
    
}

int & IntVector::front( ) {
    return data[0];
}

int & IntVector::back( ) {
    return data[sz - 1];
}

//Private helper functions.
void IntVector::expand() {
    
    if(cap != 0) {
        cap = cap * 2;
        int* newD = new int [cap];
        for (unsigned int i = 0; i < sz; ++i) 
            newD[i] = data[i];
        delete [] data;
        data = newD;
    }
    else {
        cap = 1;
        data = new int [1];
    }
        
    return;
    
}

void IntVector::expand(unsigned amount) {
    
    if(cap != 0) {
        cap = cap + amount;
        int* newD = new int [cap];
        for (unsigned int i = 0; i < sz; ++i) 
            newD[i] = data[i];
        delete [] data;
        data = newD;
    }
    else {
        cap = 1;
        data = new int [1];
    }
        
    return;
    
}


