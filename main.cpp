#include"Jeu.hpp"
#include<typeinfo>
#include<iostream>

template<typename Base, typename T>
inline bool instanceof(const T*) {
   return is_base_of<Base, T>::value;
}

void f(Objet *a) {
   Poison *p = dynamic_cast<Poison *>(a);
   cout << p << endl;
}


int main(int argc, char const *argv[])
{
   
   Jeu leJeu;
   leJeu.Jouer();
   

   

   /*MotCleCommandes *com = new MotCleCommandes();
   string s = "aller";
   if (com->estCommande(s))
   {
      cout << "true" << endl;
   }*/

   /*Poison *e = new Poison("poi",30);
   Medicaments *n = new Medicaments("doli", 23);

   Armes *c = new Armes("dolic", 23);
   Boucliers *f = new Boucliers("dolif", 23);

   Poison *l = new Poison("poil",30);
   Medicaments *d = new Medicaments("doliv", 23);

   p.ajouter(e);
   p.ajouter(n);
   p.ajouter(c);
   p.ajouter(f);
   p.ajouter(l);
   p.ajouter(d);

   cout << p.getList()->getNbObjets() << endl;

   for (Objet* k : *p.getList()->getObjets())
   {
      if(dynamic_cast<Poison *>(k)){
         cout << "Poisson: " << k->getNom()  << endl;
      }
      if(dynamic_cast<Armes *>(k)){
         cout << "Armes " << k->getNom()<< endl;
      }
      if(dynamic_cast<Boucliers *>(k)){
         cout << "Boucliers "<< k->getNom() << endl;
      }
      if(dynamic_cast<Medicaments *>(k)){
         cout << "Medic " << k->getNom() << endl;
      }
      cout << 1 << endl;
   }*/
   



    return 0;
}
