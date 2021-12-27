#include "Moine.hpp"

Moine::Moine(string nom): Personnage{nom}{

}

string Moine::getNom() const{
    string res = Personnage::getNom();
    res+= " (Moine)";
    return res;
}