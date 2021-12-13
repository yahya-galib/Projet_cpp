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
        string getNom() const;
        void setNom(string);
        //~Objet();
};







#endif