#ifndef ARMES_HPP
#define ARMES_HPP

#include"Objet.hpp"

class Armes : public Objet
{
private:
   int degat;
public:
    Armes(string, int);
    int getDegat() const;
    void setDegat(int);
};

#endif