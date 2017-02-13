#include "IntList.h"

IntList::IntList() {
    
    head = 0;
}

void IntList::push_front(int value) {
        
    IntNode* temp =  new IntNode(value);
    temp->next = head;
    head = temp;
        
    return;

}

ostream & operator<<(ostream &out, const IntList &rhs) {
    
    IntNode* temp = rhs.head;
    
    if(temp == 0)
        return out;
    else {
        out << temp -> data;
        out << temp -> next;
    }
    
    return out;
    
}

bool IntList::exists(int value) const {
    
    return exists(head, value);
}

bool IntList::exists(IntNode *temp, int value) const {
    
    if (temp == 0)
        return false;
    
    return temp -> data == value || exists(temp -> next, value);
}

ostream & operator<<(ostream &out, IntNode *temp) {
    
    if(temp == 0) 
        return out;
    else {
        out << " " << temp -> data;
        out << temp -> next;
    }
    
    return out;
}


