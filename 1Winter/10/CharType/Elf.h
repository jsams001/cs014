#ifndef ELF_H
#define ELF_H

#include "Character.h"

class Elf : public Character {
    private:
        string familyname;

    public:
        Elf(const string &name, double health, double attackStrength, string familyname);
        const string & getFamilyname(); 
        void attack(Character &);
 };
 
 #endif