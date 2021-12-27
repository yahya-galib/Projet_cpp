#include "Sorciere.hpp"


Sorciere::Sorciere(string nom):Personnage{nom}{
    
}

string Sorciere::getNom() const{
    string res = Personnage::getNom();
    res+= " (Sorciere)";
    return res;
}