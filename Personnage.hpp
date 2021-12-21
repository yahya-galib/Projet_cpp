#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include"Conteneur.hpp"
#include"Objet.hpp"
#include"Medicaments.hpp"
#include"Poison.hpp"
#include"Armes.hpp"
#include"Boucliers.hpp"

class Personnage
{
    protected:
        string nom;
        int sante;
        int habilite;
        Conteneur<Objet>* sac;

    public:
        Personnage(string);
        string getNom() const;
        int getsante() const;
        int getHabilite() const;
        Conteneur<Objet>* getObjetsSac() const;
        
        void setNom(string);
        void setSante(int) ;
        void setHabilite(int);

        void augementerSante(int);
        void augmenterHabilite(int);

        void diminuerSante(int);
        void diminuerHabilite(int);

        void ramasserObjet(Objet*);
        void retirerObjet(Objet *);
        void retirerObjetByIndex(int);

        void afficherObjetSac();

};

#endif