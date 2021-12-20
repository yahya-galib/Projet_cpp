#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include"Conteneur.hpp"
#include"Objet.hpp"

class Personnage
{
    protected:
        string nom;
        int sante;
        int habilite;
        Conteneur<Objet>* sac;
        //Conteneur<Objets> sac;


    public:
        Personnage(string);
        string getNom() const;
        int getsante() const;
        int getHabilite() const;
        
        void setNom(string);
        void setSante(int) ;
        void setHabilite(int);

        void augementerSante(int);
        void augmenterHabilite(int);

        void diminuerSante(int);
        void diminuerHabilite(int);
};

#endif