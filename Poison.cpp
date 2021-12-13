#include"Poison.hpp"


Poison::Poison(string nm, int pd) : Objet{nm}, poisonDegat{pd} {}

int Poison::getPoisonDegat() const {
    return poisonDegat;
}

void Poison::setPoisonDegat(int pd) {
    poisonDegat = pd;
}