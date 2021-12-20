#include"MotCleCommandes.hpp"

const vector<string> *MotCleCommandes::Commandes = new vector<string>({"aller","rester","aide","quitter"});

MotCleCommandes::MotCleCommandes(){
    cout << "> ";
    string n;
    cin >> n;
    commande = n; 
}

bool MotCleCommandes::estCommande(){
    for (string s : *Commandes)
    {
        if (s == commande)
            return true;
    }
    return false;
}

void MotCleCommandes::afficherCommandes(){
    for (string s : *Commandes)
        cout << s << ", ";
    cout << endl;
}

string MotCleCommandes::getCommande() const {
    return commande;
}