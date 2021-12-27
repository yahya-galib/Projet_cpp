#include "Amazone.hpp"

Amazone::Amazone(string nom):Personnage{nom}{

}

string Amazone::getNom() const{
    string res = Personnage::getNom();
    res+= " (Amazone)";
    return res;
}