#ifndef SORTEDSET_H
#define SORTEDSET_H

#include "IntList.h"

class SortedSet : public IntList{
    public:
        //CONSTRUCTORS
        SortedSet();
        SortedSet(const SortedSet &);
        SortedSet(const IntList &);
        ~SortedSet();
        //ACCESSORS
        bool in(int data) const;
        SortedSet operator|(const SortedSet&);
        SortedSet operator&(SortedSet&);
        //MUTATORS
        void add(int data);
        void push_front(int data);
        void push_back(int data);
        void insert_ordered(int data);
        SortedSet & operator|=(SortedSet&);
        SortedSet & operator&=(SortedSet&);
};

#endif