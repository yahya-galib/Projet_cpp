#include"Boucliers.hpp"


Boucliers::Boucliers(string nm, int pr) : Objet{nm}, times{pr} {}

int Boucliers::getTimes() const {
    return times;
}

void Boucliers::setTimes(int pr) {
    times = pr;
}