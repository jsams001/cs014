#ifndef TABLEITEM_H
#define TABLEITEM_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TableItem {
    private: 
        string w;
        vector<int> v;
    public:
        TableItem();
        void setWord(string newWord);
        string word();
        void newPos(int p);
        int atPos(int p);
        int posSize();
        
};

#endif