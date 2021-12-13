#include"Objet.hpp"

Objet::Objet(string nm) : nom{nm} {}

//Objet::~Objet(){}

string Objet::getNom() const {
    return nom;
}

void Objet::setNom(string nm){
    nom = nm;
}