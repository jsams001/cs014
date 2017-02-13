#include <iostream>
using namespace std;

#include "Elf.h"

Elf::Elf(const string &name, double health, double attackStrength, string familyname) : Character(ELF, name, health, attackStrength) {
    
    this->familyname = familyname;
}

const string & Elf::getFamilyname() {
    
    return familyname;
}

void Elf::attack(Character &defender) {
    
    if(defender.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(defender);
        if(opp.getFamilyname() == familyname) {
            cout << "Elf " << getName() << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << familyname << " family." << endl;
            return;
        }
        else {
            double damage = (health / MAX_HEALTH) * attackStrength;
            opp.setHealth(opp.getHealth() - damage);
            cout << "Elf " << getName() << " shoots an arrow at " << defender.getName() << " --- TWANG!!" << endl;
            cout << defender.getName() << " takes " << damage << " damage." << endl;
            return;
        }
    }
    else {
        double damage = (health / MAX_HEALTH) * attackStrength;
        defender.setHealth(defender.getHealth() - damage);
        cout << "Elf " << getName() << " shoots an arrow at " << defender.getName() << " --- TWANG!!" << endl;
        cout << defender.getName() << " takes " << damage << " damage." << endl;
        return;
    }
        
    return;
}
