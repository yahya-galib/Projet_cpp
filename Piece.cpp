#include"Piece.hpp"

Piece::Piece(string des) : nom{des} , sorties{new vector<pair<enum Direction, Piece*>>()} ,list{new Conteneur<Objet>}, personnages{new Conteneur<Personnage>}{}

Conteneur<Objet>* Piece::getList() const{
    return list;
}

Conteneur<Personnage>* Piece::getPersonnages() const{
    return personnages;
}

string Piece::getNom() const{
    return nom;
}

int Piece::getNbObjet() const{
    return list->getNbObjets();
}
int Piece::getNbPersonnages() const{
    return personnages->getNbObjets();
}

void Piece::setSorties(Piece* est, Piece* ouest, Piece* nord, Piece* sud){
    if (nord != nullptr) {
        sorties->push_back({Direction::nord, nord});
    }
    if (sud != nullptr) {
        sorties->push_back({Direction::sud, sud});
    }
    if (est != nullptr) {
        sorties->push_back({Direction::est, est});
    }
    if (ouest != nullptr) {
        sorties->push_back({Direction::ouest, ouest});
    }
}

void Piece::descriptionSorties(){
    cout << "Sorties: ";
    for(pair<enum Direction, Piece*> s: *sorties){
        cout << s.first << " (" << s.second->nom <<") "; 
    }
    cout << endl;
}

void Piece::getDescription(){
    cout << "objets: ";
    for(Objet* s: *list->getObjets()){
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

void Piece::afficherPersonnages(){
    cout << "Personnages: ";
    for(Personnage* s: *personnages->getObjets()){
        cout << s->getNom() << ", ";
    }
    cout << endl;
}

Piece* Piece::pieceSuivante(Direction d){
    for(pair<enum Direction, Piece*> dir : *sorties){
        if (dir.first == d)
        {
            return dir.second;
        }
    }
    return new Piece("None");
}

void Piece::ajouter(Objet *o){
    list->ajouter(o);
}

void Piece::retirer(Objet *o){
    list->retirer(o);
}

void Piece::retirerByIndexObjet(int i){
    list->retirerByIndex(i);
}

void Piece::ajouter(Personnage *o){
    personnages->ajouter(o);
}

void Piece::retirer(Personnage *o){
    personnages->retirer(o);
}

void Piece::retirerByIndexPersonnage(int i){
    personnages->retirerByIndex(i);
}

bool Piece::checkSortie(Direction d){
    for (pair<enum Direction, Piece*> s : *sorties)
    {
        if (s.first == d)
        {
            return true;
        }
        
    }
    return false;
}