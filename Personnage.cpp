#include"Personnage.hpp"

Personnage::Personnage(string nm) : nom{nm}, sante{20} ,habilite{1},frappeDegat{5}, sac {new Conteneur<Objet>} {}


string Personnage::getNom() const{
    return nom;
}

int Personnage::getsante() const{
    return sante;
}

int Personnage::getHabilite() const{
    return habilite;
}

int Personnage::getFrappeDegat() const{
    return frappeDegat;
}

void Personnage::setFrappeDegat(int k){
    frappeDegat = k;
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

void Personnage::ramasserObjet(Objet *obj){
    sac->ajouter(obj);
}

void Personnage::retirerObjet(Objet *obj){
    sac->retirer(obj);
}

void Personnage::retirerObjetByIndex(int a){
    sac->retirerByIndex(a);
}

Conteneur<Objet>* Personnage::getObjetsSac() const {
    return sac;
}

void Personnage::afficherObjetSac(){
    for(Objet *s : *sac->getObjets()){
        if (dynamic_cast<Armes *>(s))
            cout << "(Arme: " << s->getNom() <<") ";
        if (dynamic_cast<Poison *>(s))
            cout << "(Poison: " << s->getNom() <<") ";
        if (dynamic_cast<Medicaments *>(s))
            cout << "(Medicament: " << s->getNom() <<") ";
        if (dynamic_cast<Boucliers *>(s))
            cout << "(Bouclier: " << s->getNom() <<") ";
    }
    cout << endl; 
}

int Personnage::contientObjet(string nm){
    int cont{0};
    for (Objet* i: *sac->getObjets())
    {
        if(i->getNom() == nm)
            return cont;
        cont++;
    }

    return -1;
}

void Personnage::descriptionPersonnage(){
    cout << nom << endl;
    cout << "santé: " << sante<< endl;
    cout << "habilité: " <<habilite<< endl;
}