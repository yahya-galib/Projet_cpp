#include "Guerrier.hpp"

Guerrier::Guerrier(string nom):Personnage{nom}{
    
}

string Guerrier::getNom() const{
    string res = Personnage::getNom();
    res+= " (Guerrier)";
    return res;
}