#ifndef MOINE_HPP
#define MOINE_HPP

#include "Personnage.hpp"

class Moine : public Personnage{

    public:
        Moine(string );
        string getNom() const;
};

#endif