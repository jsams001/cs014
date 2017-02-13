#include "IntList.h"

IntList::IntList() {
    
    head = 0;
    tail = 0;
}

IntList::~IntList() {
    
    while(!empty())
        pop_front();
        
}

void IntList::display() const {
    
    if(!empty()) {
        IntNode* curr = head;
        while(curr -> next != 0) {
            cout << curr -> data << " ";
            curr = curr -> next;
        }
        cout << curr -> data;
        return;
    }
    else
        return;
}

void IntList::pop_front() {
    
    if(empty())
        return;
    
    IntNode* temp = head;
    head = head -> next;
    delete temp;
    return;
}

void IntList::push_front(int value) {
        
    if(empty()) {
        IntNode* temp =  new IntNode(value);
        head = temp;
        head -> next = 0;
        tail = head;
        return;
    }
    
    IntNode* temp =  new IntNode(value);
    temp->next = head;
    head = temp;
    return;

}

bool IntList::empty() const {
    
    if(head == 0)
        return true;
    return false;
}

//START OF PROGRAM

IntList::IntList(const IntList &cpy) {
    
    head = 0;
    tail = 0;
    
    IntNode* temp = cpy.head;
    while(temp != 0) {
        push_back(temp->data);
        temp = temp -> next;
    }
    return;
    
}

IntList & IntList::operator=(const IntList &rhs) {
    
    if(this == &rhs)
        return *this;
        
    clear();
    IntNode* temp = rhs.head;
    while(temp != 0) {
        push_back(temp->data);
        temp = temp -> next;
    }
    return *this;
    
}

void IntList::push_back(int value) {
    
    if(empty()) {
        IntNode* temp =  new IntNode(value);
        temp -> next = head;
        tail = temp;
        head = temp;
    }
    else {
        IntNode* temp =  new IntNode(value);
        tail -> next = temp;
        tail = temp;
    }
        
    return;
    
}

void IntList::clear() {
    
    while(!empty()) {
        pop_front();
    }
    head = 0;
    tail = 0;
    return;
        
}

void IntList::selection_sort() {
    IntNode* min;
    IntNode* i = head;
    IntNode* j;
    
    if(empty())
        return;
    
    if(head == tail)
        return;
    
    for(i = head; i != NULL; i = i -> next) {
        min = i;
        for(j = i -> next; j != NULL; j = j -> next) {
            if(min -> data > j -> data)
                min = j;
        }
        swap(min -> data, i -> data);
    }
}

void IntList::insert_ordered(int value) {
    
    if(empty()) {
        push_front(value);
        return;
    }
    
    IntNode* temp = new IntNode(value);
    
    if(temp -> data <= head -> data) {
        push_front(value);
        delete temp;
        return;
    }
    
    if(temp -> data >= tail -> data) {
        push_back(value);
        delete temp;
        return;
    }
    
    IntNode* i;
    IntNode* j;
    for(i = head; i != NULL; i = i -> next) {
        j = i -> next;
        if(temp -> data <= j -> data) {
            i -> next = temp;
            temp -> next = j;
            return;
        }
    }
    return;
}

void IntList::remove_duplicates() {
    
    IntNode* i = 0;
    IntNode* j = 0;
    IntNode* prev = 0;
    
    if(head == tail)
        return;
        
    for(i = head; i != NULL; i = i -> next) {
        prev = i;
        for(j = i -> next; j != NULL; j = prev -> next) {
            if(i -> data == j -> data) {
                if(j == tail) {
                    IntNode* temp = j;
                    prev -> next = 0;
                    tail = prev;
                    delete temp;
                }
                else {
                    IntNode* temp = j;
                    prev -> next = j -> next;
                    delete temp;
                }
            }
            else {
                prev = prev -> next;
            }
        }
    }
        
    return;
}

ostream & operator<<(ostream &out, const IntList &rhs) {
    
    IntNode* nout = rhs.head;
    
    while(nout != 0) {
        if(nout -> next != 0)
            out << nout -> data << " ";
        else
            out << nout -> data;
        nout = nout -> next;
    }
    
    return out;
    
}