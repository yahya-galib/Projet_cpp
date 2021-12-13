#include"Medicaments.hpp"


Medicaments::Medicaments(string nm, int gr) : Objet{nm}, guerison{gr} {}

int Medicaments::getGuerison() const {
    return guerison;
}

void Medicaments::setGuerison(int gr) {
    guerison = gr;
}