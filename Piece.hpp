#ifndef PIECE_HPP
#define PIECE_HPP

#include"Conteneur.hpp"
#include"Direction.hpp"
#include"Objet.hpp"

class Piece
{
private:
    string nom;
    vector<pair<enum Direction, Piece*>> *sorties;
    Conteneur<Objet>* list;
public:

    Piece(string);
    Piece(string, Conteneur<Objet>*);

    string getNom() const;

    void getDescription();

    void setSorties(Piece*, Piece*, Piece*, Piece*);

    Conteneur<Objet>* getList() const;
    
    void descriptionSorties();

    Piece* pieceSuivante(Direction d);

    void ajouter(Objet *);
    void retirer(Objet *);
    void retirerByIndex(int);

    
    /*~Piece();*/
};


#endif