#ifndef PIECE_HPP
#define PIECE_HPP

#include"Conteneur.hpp"
#include"Direction.hpp"
#include"Personnage.hpp"
#include"Poison.hpp"

class Piece
{
private:
    string nom;
    vector<pair<enum Direction, Piece*>> *sorties;
    Conteneur<Objet>* list;
    Conteneur<Personnage>* personnages;
public:

    Piece(string);
    Piece(string, Conteneur<Objet>*);

    string getNom() const;

    void getDescription();
    void afficherPersonnages();

    void setSorties(Piece*, Piece*, Piece*, Piece*);
    bool checkSortie(Direction);
    Conteneur<Objet>* getList() const;
    
    void descriptionSorties();

    Piece* pieceSuivante(Direction d);

    void ajouter(Objet *);
    void retirer(Objet *);
    void retirerByIndexObjet(int);

    void ajouter(Personnage *);
    void retirer(Personnage *);
    void retirerByIndexPersonnage(int);

};


#endif