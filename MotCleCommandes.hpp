#ifndef MOTCLECOMMANDES_HPP
#define MOTCLECOMMANDES_HPP

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class MotCleCommandes
{
private:
    string commande;
    static const vector<string> *Commandes;
public:
    MotCleCommandes();
    string getCommande() const;
    bool estCommande();
    static void afficherCommandes();
};


#endif