#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior : public Character {
    private:
        string allegiance;

    public:
        Warrior(const string &name, double health, double attackStrength, string allegiance);
        const string & getAllegiance();
        void attack(Character &);
};

#endif 
