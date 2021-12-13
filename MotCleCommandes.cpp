#include"MotCleCommandes.hpp"

const vector<string> *MotCleCommandes::Commandes = new vector<string>({"aller","rester"});

MotCleCommandes::MotCleCommandes(){}

bool MotCleCommandes::estCommande(string test){
    for (string s : *Commandes)
    {
        if (s == test)
            return true;
    }
    return false;
}

void MotCleCommandes::afficherCommandes(){
    for (string s : *Commandes)
        cout << s << ", ";
    cout << endl;
}