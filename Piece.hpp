#ifndef PIECE_HPP
#define PIECE_HPP

#include"Conteneur.hpp"
#include"Direction.hpp"
#include"Objet.hpp"
#include"Armes.hpp"
#include"Boucliers.hpp"
#include"Medicaments.hpp"
#include"Poison.hpp"

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
    bool checkSortie(Direction);
    Conteneur<Objet>* getList() const;
    
    void descriptionSorties();

    Piece* pieceSuivante(Direction d);

    void ajouter(Objet *);
    void retirer(Objet *);
    void retirerByIndex(int);

    
    /*~Piece();*/
};


#endif