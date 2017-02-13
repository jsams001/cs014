#include <string>
#include <iostream>

using namespace std;

#include "Card.h"

Card::Card() { 
    
    suit = 'c';
    rank = 2;
    
}

Card::Card(char suitPass, int rankPass) {
    
    if(suitPass == 'c' || suitPass == 'C')
        suit = 'c';
    else if(suitPass == 'd' || suitPass == 'D')
        suit = 'd';
    else if(suitPass == 'h' || suitPass == 'H')
        suit = 'h';
    else if(suitPass == 's' || suitPass == 'S')
        suit = 's';
    else
        suit = 'c';
    
    if(rankPass >= 1 && rankPass <= 13)
        rank = rankPass;
    else
        rank = 2;
        
}

char Card::getSuit() const {
    
    return suit;
    
}

int Card::getRank() const {
    
    return rank;
}

ostream & operator<<(ostream &out, const Card &rhs) {
    
    string newSuit;
    int number = 0;
    string face;
    
    if(rhs.rank == 1)
        face = "Ace";
    else if(rhs.rank == 11)
        face = "Jack";
    else if(rhs.rank == 12)
        face = "Queen";
    else if(rhs.rank == 13)
        face = "King";
    else
        number = rhs.rank;
    
    if(rhs.suit == 'c')
        newSuit = "Clubs";
    else if(rhs.suit == 'd')
        newSuit = "Diamonds";
    else if(rhs.suit == 'h') 
        newSuit = "Hearts";
    else if(rhs.suit == 's')
        newSuit = "Spades";
    
    
    if(number == 0)
        out << face << " of " << newSuit;
    else
        out << number << " of " << newSuit;
    
    return out;
}