#ifndef OBJET_HPP
#define OBJET_HPP

#include<string>

using namespace std;

class Objet
{
    protected:
        string nom;
    public:
        Objet(string);
        virtual string getNom() const;
        virtual void setNom(string);
        //~Objet();
};







#endif