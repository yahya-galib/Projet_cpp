#ifndef MEDICAMENTS_HPP
#define MEDICAMENTS_HPP

#include"Objet.hpp"

class Medicaments : public Objet
{
private:
   int guerison;
public:
    Medicaments(string, int);
    int getGuerison() const;
    void setGuerison(int);
};

#endif