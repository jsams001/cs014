#include <iostream>
using namespace std;

#include "Warrior.h"

Warrior::Warrior(const string &name, double health, double attackStrength, string allegiance) : Character(WARRIOR, name, health, attackStrength) {
    
    this->allegiance = allegiance;
}

const string & Warrior::getAllegiance() {
    
    return allegiance;
}

void Warrior::attack(Character &defender) {
    
    if(defender.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(defender);
        if(opp.getAllegiance() == allegiance) {
            cout << "Warrior " << getName() << " does not attack Warrior " << opp.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
            return;
        }
        else {
            double damage = (health / MAX_HEALTH) * attackStrength;
            opp.setHealth(opp.getHealth() - damage);
            cout << "Warrior " << getName() << " attacks " << defender.getName() << " --- SLASH!!" << endl;
            cout << defender.getName() << " takes " << damage << " damage." << endl;
            return;
        }
    }
    else {
        double damage = (health / MAX_HEALTH) * attackStrength;
        defender.setHealth(defender.getHealth() - damage);
        cout << "Warrior " << getName() << " attacks " << defender.getName() << " --- SLASH!!" << endl;
        cout << defender.getName() << " takes " << damage << " damage." << endl;
        return;
    }
        
    return;
}