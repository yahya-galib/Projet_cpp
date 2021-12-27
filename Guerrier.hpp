#ifndef GUERRIER_HPP
#define GUERRIER_HPP

#include "Personnage.hpp"

class Guerrier : public Personnage{

    public:
        Guerrier(string );
        string getNom() const;
        
};


#endif