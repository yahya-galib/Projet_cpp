#include"Piece.hpp"
#include"Poison.hpp"
#include"Medicaments.hpp"
#include"MotCleCommandes.hpp"
#include"Armes.hpp"
#include<typeinfo>
#include<iostream>

template<typename Base, typename T>
inline bool instanceof(const T*) {
   return is_base_of<Base, T>::value;
}


int main(int argc, char const *argv[])
{
    Piece p("cuisine");

    p.setSorties(new Piece("garage"), nullptr, nullptr, new Piece("ssss"));

    MotCleCommandes *com = new MotCleCommandes();
    string s = "aller";
    if (com->estCommande(s))
    {
       cout << "true" << endl;
    }
    
    
    

    return 0;
}
