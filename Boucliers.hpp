#ifndef bOUCLIERS_HPP
#define BOUCLIERS_HPP

#include"Objet.hpp"

class Boucliers : public Objet
{
private:
   int times;
public:
    Boucliers(string, int);
    int getTimes() const;
    void setTimes(int);
};

#endif