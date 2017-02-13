#include <iostream>
using namespace std;

#include "Wizard.h"

Wizard::Wizard(const string &name, double health, double attackStrength, int rank) : Character(WIZARD, name, health, attackStrength) {
    
    this->rank= rank;
}

int Wizard::getRank() const {
    
    return rank;
}

void Wizard::attack(Character &defender) {
    
    if(defender.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(defender);
        double damage = attackStrength * static_cast<double>(rank) / opp.getRank();
        opp.setHealth(opp.getHealth() - damage);
        cout << "Wizard " << getName() << " attacks " << opp.getName() << " --- POOF!!" << endl;
        cout << opp.getName() << " takes " << damage << " damage." << endl;
        return;
    }
    
    else {
        cout << "Wizard " << getName() << " attacks " << defender.getName() << " --- POOF!!" << endl;
        cout << defender.getName() << " takes " << attackStrength << " damage." << endl;\
        defender.setHealth(defender.getHealth() - attackStrength);
        return;
    }
        
    return;
}