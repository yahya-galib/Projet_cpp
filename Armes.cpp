#include"Armes.hpp"


Armes::Armes(string nm, int dg) : Objet{nm}, degat{dg} {}

int Armes::getDegat() const {
    return degat;
}

void Armes::setDegat(int dg) {
    degat = dg;
}