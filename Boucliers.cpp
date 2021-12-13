#include"Boucliers.hpp"


Boucliers::Boucliers(string nm, int pr) : Objet{nm}, protection{pr} {}

int Boucliers::getProtection() const {
    return protection;
}

void Boucliers::setProtection(int pr) {
    protection = pr;
}