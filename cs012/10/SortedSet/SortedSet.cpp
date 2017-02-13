#include "SortedSet.h"

//CONSTRUCTORS
SortedSet::SortedSet() { }

SortedSet::SortedSet(const SortedSet &cpy) : IntList(cpy) { }

SortedSet::SortedSet(const IntList &cpy) : IntList(cpy) {

    remove_duplicates();
    selection_sort();
    return;
}

SortedSet::~SortedSet() { }

//ACCESSORS
bool SortedSet::in(int data) const {
    
    IntNode* temp = head;
    while(temp != 0) {
        if(temp -> data == data)
            return true;
        temp = temp -> next;
    }
    
    return false;
}

SortedSet SortedSet::operator|(const SortedSet& rhs) {
    
    SortedSet temp(*this);
    
    IntNode* n = rhs.head;
    while(n != 0) {
        temp.add(n -> data);
        n = n -> next;
    }
    
    return temp;
}
        
        
SortedSet SortedSet::operator&(SortedSet& rhs) {
    
    SortedSet temp;
        
    IntNode* n = rhs.head;
    while(n != 0) {
        if(in(n->data))
            temp.add(n -> data);
        n = n -> next;
    }
    
    return temp;
}

void SortedSet::add(int data) {
    
    /* NOTE: Professor Miller wanted us to just go through the list 
    once, but the above works fine; it goes through it twice (while loop
    in in, and the for loop in insert_ordered) if the value is not a duplicate 
    and if it's in the middle of the list. He said one for loop would do, 
    but this code is more succinct so I'm keeping it. */
    
    if(!in(data))
        IntList::insert_ordered(data);

    return;
}

void SortedSet::push_front(int data) {
    
    add(data);
    return;
}

void SortedSet::push_back(int data) {
    
    add(data);
    return;
}

void SortedSet::insert_ordered(int data) {
    
    add(data);
    return;
}

SortedSet & SortedSet::operator|=(SortedSet& rhs) {
    
    *this = *this | rhs;
    return *this;
}
        
SortedSet & SortedSet::operator&=(SortedSet& rhs) {
    
    *this = *this & rhs;
    return *this;
}


