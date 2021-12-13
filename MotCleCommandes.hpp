#ifndef MOTCLECOMMANDES_HPP
#define MOTCLECOMMANDES_HPP

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class MotCleCommandes
{
private:
    static const vector<string> *Commandes;
public:
    MotCleCommandes();
    bool estCommande(string);
    void afficherCommandes();
};


#endif