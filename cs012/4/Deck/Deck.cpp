#include <algorithm>
#include <vector>
#include <cstdlib>

#include "Card.h"
#include "Deck.h"

Deck::Deck() {
    
    vector<char> names(4);
    names.at(0) = 's';
    names.at(1) = 'h';
    names.at(2) = 'd';
    names.at(3) = 'c';
    
    
    for(unsigned int i = 0; i < 4; ++i) {
        for(unsigned int j = 13; j > 0; --j) {
            theDeck.push_back(Card(names.at(i), j));
        }
    }
}

Deck::dealCard() { 
    
    Card temp;
    
    temp = Card(theDeck.at(theDeck.size() - 1).getSuit(), theDeck.at(theDeck.size() - 1).getRank());
    theDeck.pop_back();
    dealtCards.push_back(temp);
    
    return temp;
}

void Deck::shuffleDeck() {
    
    for(unsigned int i = 0; i < dealtCards.size(); ++i) {
        theDeck.push_back(dealtCards.at(i));
    }
    dealtCards.clear();
        
    random_shuffle(theDeck.begin(), theDeck.end());
    
    return;
}

unsigned Deck::deckSize() const {
    
    return theDeck.size();
}
