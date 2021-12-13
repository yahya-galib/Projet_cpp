#include"Personnage.hpp"

Personnage::Personnage(string nm) : nom{nm}, sante{20} ,habilite{1} {}


string Personnage::getNom() const{
    return nom;
}

int Personnage::getsante() const{
    return sante;
}

int Personnage::getHabilite() const{
    return habilite;
}

void Personnage::setNom(string nm){
    nom = nm;
}

void Personnage::setSante(int s){
    sante = s;
}
void Personnage::setHabilite(int h){
    habilite = h;
}

void Personnage::augementerSante(int s){
    sante+=s;
}
void Personnage::augmenterHabilite(int h){
    habilite+=h;
}

void Personnage::diminuerSante(int s){
    sante-=s;
}

void Personnage::diminuerHabilite(int h){
    habilite-=h;
}