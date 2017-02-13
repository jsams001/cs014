#include <iostream>

using namespace std;

struct IntNode {
    
    int data;
    IntNode *next;
    IntNode(int data) : data(data), next(0) {}
};

class IntList {
    
    private:
        IntNode* head;
        IntNode* tail;
    public:
        IntList();
        void push_front(int value);
        void display() const;
        void display(IntNode *) const;
    private:
};

IntList::IntList() : head(0), tail(0) {}

void IntList::push_front(int value) {
    
    IntNode *nn = new IntNode(value);
    nn->next = head;
    head = nn;
    
}

void IntList::display() const {
    
    if(head == 0) 
        return;
    
    cout << head->data;
    display(head->next);
}

void IntList::display(IntNode* curr) const {
    
    if(curr == 0) 
        return;
    
    cout << ' ' << curr->data;
    display(curr->next);
}

int main() {
    
    IntList* temp = new IntList;
    
    temp->push_front(10);
    temp->push_front(20);
    temp->push_front(30);
    temp->display();
}