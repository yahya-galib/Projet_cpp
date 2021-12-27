#ifndef SORCIERE_HPP
#define SORCIERE_HPP

#include "Personnage.hpp"

class Sorciere : public Personnage{

    public:
        Sorciere(string nom);
        string getNom() const;
};


#endif