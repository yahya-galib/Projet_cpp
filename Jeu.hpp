#ifndef JEU_HPP
#define JEU_HPP

#include"Piece.hpp"
#include"MotCleCommandes.hpp"
#include"Moine.hpp"
#include"Guerrier.hpp"
#include"Amazone.hpp"
#include"Sorciere.hpp"
#include<algorithm>

class Jeu
{
private:
    static bool termine;
    static vector<Personnage*> listJoueur;
    Piece *pieceCourante;
    Personnage *joueur;

public:
    Jeu();
    void creerJeu();
    void Jouer();
    void afficherMsgBienvennue();
    void afficheJoueursPiece();
    bool traiterCommande(MotCleCommandes &);
    void afficherAide();
    void informatioin();
    void affichage();
    void nombreObjets();
    void prendreObjetParUnJoueur();
    void deposerObjetParUnJoueur();
    void effectuerDeplacement();
    void deplacerVersAutrePiece();
    void combat(Personnage *, Personnage *);
    void removeJoueur(Personnage *);

};


#endif