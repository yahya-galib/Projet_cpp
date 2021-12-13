#include"Piece.hpp"

Piece::Piece(string des) : nom{des} , sorties{new vector<pair<enum Direction, Piece*>>()} ,list{new Conteneur<Objet>} {}
Piece::Piece(string des, Conteneur<Objet>* cont) : nom{des}, sorties{new vector<pair<Direction, Piece*>>()} ,list{cont} {}

Conteneur<Objet>* Piece::getList() const{
    return list;
}

string Piece::getNom() const{
    return nom;
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
    cout << "Nom: "<< nom << endl;
    cout << "objets: ";
    for(Objet* s: *list->getObjets()){
        cout << "(" << s->getNom() <<") "; 
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

void Piece::retirerByIndex(int i){
    list->retirerByIndex(i);
}
