#ifndef bOUCLIERS_HPP
#define BOUCLIERS_HPP

#include"Objet.hpp"

class Boucliers : public Objet
{
private:
   int protection;
public:
    Boucliers(string, int);
    int getProtection() const;
    void setProtection(int);
};

#endif