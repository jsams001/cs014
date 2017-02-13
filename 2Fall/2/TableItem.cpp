#include "TableItem.h"

TableItem::TableItem(): w(""){}

void TableItem::setWord(string newWord){
    
    w = newWord;
}

string TableItem::word() {
    
    return w;
}

void TableItem::newPos(int p) {
    
    v.push_back(p);
}

int TableItem::atPos(int p) {
    
    return v.at(p);
}

int TableItem::posSize(){
    
    return v.size();
}