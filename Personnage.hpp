#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP




#include"Conteneur.hpp"
#include"Medicaments.hpp"
#include"Poison.hpp"
#include"Armes.hpp"
#include"Boucliers.hpp"

class Piece;

class Personnage
{
    protected:
        string nom;
        int sante;
        int habilite;
        int frappeDegat;
        int nbObjets;
        Piece *pieceActuel;
        Conteneur<Objet>* sac;

    public:
        Personnage(string);
        virtual string getNom() const;
        int getsante() const;
        int getHabilite() const;
        int getFrappeDegat() const;
        int getNbObjets() const;
        Conteneur<Objet>* getObjetsSac() const;
        int getNbObjetsSac() const;
        Piece* getPieceActuelle() const;
        
        void setNom(string);
        void setSante(int) ;
        void setHabilite(int);
        void setFrappeDegat(int);
        void setPiece(Piece*);

        void augementerSante(int);
        void augmenterHabilite(int);
        void augmenterNbObjet();
        void augmenteFrappeDegat(int);

        void diminuerSante(int);
        void diminuerHabilite(int);
        void diminuerNbObjet();

        void ramasserObjet(Objet*);

        void retirerObjet(Objet *);
        void retirerObjetByIndex(int);

        void afficherObjetSac();
        void descriptionPersonnage();

        int contientObjet(string);

};

#endif