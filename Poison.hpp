#ifndef POISON_HPP
#define POISON_HPP

#include"Objet.hpp"

class Poison : public Objet
{
private:
   int poisonDegat;
public:
    Poison(string, int);
    int getPoisonDegat() const;
    void setPoisonDegat(int);
};

#endif