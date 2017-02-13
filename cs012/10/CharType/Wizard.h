#ifndef WIZARD_H
#define WIZARD_H

#include "Character.h"

class Wizard : public Character {
    private:
        int rank;

    public:
        Wizard(const string &name, double health, double attackStrength, int rank);
        int getRank() const;
        void attack(Character &);
};

#endif 
