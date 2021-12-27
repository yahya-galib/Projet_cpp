#ifndef AMAZONE_HPP
#define AMAZONE_HPP

#include "Personnage.hpp"

class Amazone : public Personnage{

    public:
        Amazone(string );
        string getNom() const;
};

#endif