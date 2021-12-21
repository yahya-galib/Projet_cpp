#ifndef JEU_HPP
#define JEU_HPP

#include"Piece.hpp"
#include"MotCleCommandes.hpp"

class Jeu
{
private:
    static bool termine;
    Piece *pieceCourante;
    Personnage *joueur;

public:
    Jeu();
    void creerJeu();
    void Jouer();
    void afficherMsgBienvennue();
    bool traiterCommande(MotCleCommandes &);
    void afficherAide();
    void informatioin();
    void affichage();
    void nombreObjets();
    void prendreUnObjetParUnJoueur();
    void deposerObjetParUnJoueur();
    void effectuerDeplacement();
    void deplacerVersAutrePiece();
    bool combat(Personnage *, Personnage *);

};


#endif