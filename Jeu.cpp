#include"Jeu.hpp"

bool Jeu::termine = false;

Jeu::Jeu(){
    creerJeu();
    joueur = new Personnage("moi");
}

void Jeu::creerJeu(){
    Piece *entree = new Piece("entree");
    Piece *salle1 = new Piece("salle1");
    Piece *salle2 = new Piece("salle2");
    Piece *salle3 = new Piece("salle3");
    Piece *salle4 = new Piece("salle4");
    Piece *salle5 = new Piece("salle5");

    entree->setSorties(salle2,salle1,salle4,nullptr);
    salle1->setSorties(entree,nullptr,salle3,nullptr);
    salle2->setSorties(nullptr,entree,salle5,nullptr);
    salle3->setSorties(salle4,nullptr,nullptr,salle1);
    salle4->setSorties(salle5,salle3,nullptr,entree);
    salle5->setSorties(nullptr,salle4,nullptr,salle2);

    pieceCourante = entree;

    Armes *ar1 = new Armes("épé",5);
    Armes *ar2 = new Armes("marteau dacier",4);
    Armes *ar3 = new Armes("dague de verre",3);
    Armes *ar4 = new Armes("hache des psycho",4);

    Poison *p1 = new Poison("goût dhémoragie",3);
    Poison *p2 = new Poison("rune",2);
    Poison *p3 = new Poison("piakkazol",2);
    Poison *p4 = new Poison("toxine dentropie",2);

    Medicaments *m1 = new Medicaments("cicloxane",6);
    Medicaments *m2 = new Medicaments("entatinoin",5);
    Medicaments *m3 = new Medicaments("albutecin",5);
    Medicaments *m4 = new Medicaments("navelnex atomoprox",4);

    Boucliers *b1 = new Boucliers("nights end",3);
    Boucliers *b2 = new Boucliers("prologue",2);
    Boucliers *b3 = new Boucliers("darkheart",2);
    Boucliers *b4 = new Boucliers("military visage",3);

    /*##########  Entree  */
    entree->ajouter(ar1);
    entree->ajouter(m1);
    entree->ajouter(b3);

    /*######## salle1 */
    salle1->ajouter(p2);
    salle1->ajouter(p4);


    /*######## salle2 */
    salle2->ajouter(b1);
    salle2->ajouter(b2);
    salle2->ajouter(m4);

    /*######## salle3 */
    salle3->ajouter(ar4);
    salle3->ajouter(p3);
    salle3->ajouter(b4);


    /*######## salle4 */
    salle4->ajouter(m2);
    salle4->ajouter(ar2);

    /*######## salle5 */
    salle5->ajouter(ar3);
    salle5->ajouter(m3);
    salle5->ajouter(p1);
}


void Jeu::Jouer(){
    afficherMsgBienvennue();

    while (!Jeu::termine)
    {
        pieceCourante->getDescription();
        pieceCourante->descriptionSorties();

        MotCleCommandes commande;
        Jeu::termine = traiterCommande(commande);


        

    }
    
}


void Jeu::afficherMsgBienvennue(){
    cout << endl ;
    cout <<"Bienvennue dans le chateau des Merveilles !" << endl;
    cout <<"BeatOrLeave est un nouveau jeu d'aventure,\n";
    cout <<"votre mission est de survivre et arriver au habilité 3";
    cout <<"combattre les autres";
    cout <<"utilisez des armes, boucliers et d'autres objets";
    cout <<"Tapez 'aide' si vous avez besoin d'aide.";
    cout << endl;
}

bool Jeu::traiterCommande(MotCleCommandes &cm){
    if (!cm.estCommande())
    {
        cout << "Je ne comprends pas ce que vous voulez..." << endl;
        return false;
    }
    if (cm.getCommande() == "aide")
    {
        afficherAide();
    }else if (cm.getCommande() == "aller")
    {
        deplacerVersAutrePiece();
    }
    else if (cm.getCommande() == "quitter")
    {
        return true;
    }
    else if (cm.getCommande() == "ramasser")
    {
        prendreUnObjetParUnJoueur();
    }
    else if(cm.getCommande() == "afficher"){
        affichage();
    }
    
    return false;
}

void Jeu::afficherAide(){
    cout << "Vous etes perdu. Vous etes seul. Vous errez" << endl;
    cout << "Les commandes reconnues sont:"<< endl;
    MotCleCommandes::afficherCommandes();
}

void Jeu::deplacerVersAutrePiece(){
    
    string dir{""};
    Direction d;
    bool chosen = true;

    while (chosen)
    {
        cout << "Direction: ";
        cin >> dir;

        if (dir == "nord"){
            d = Direction::nord;
            if(pieceCourante->checkSortie(d)){
                chosen = false;
            }
        }
            
        else if (dir == "sud"){
            d = Direction::sud;
            if(pieceCourante->checkSortie(d)){
                chosen = false;
            }
        }
            
        else if (dir == "ouest"){
            d = Direction::ouest;
            if(pieceCourante->checkSortie(d)){
                chosen = false;
            }
        }
            
        else if (dir == "est"){
            d = Direction::est;
            if(pieceCourante->checkSortie(d)){
                chosen = false;
            }
        }
        else{
            cout << "je ne comprends pas cette direction" << endl;
            cout << "ou la picec n'a pas de sortie dans cette direction" << endl;
        }    
    }

    pieceCourante = pieceCourante->pieceSuivante(d);

}

void Jeu::prendreUnObjetParUnJoueur(){
    cout << "1" << endl;
    if (joueur->getObjetsSac()->getNbObjets() == 4)
    {
        cout << "1" << endl;
        cout << "le sac est plein" << endl;
    }
    else{
        cout << "1" << endl;
        cout << "Objets disponible dans la piece: "<< pieceCourante->getNom() << endl;
        pieceCourante->getDescription();
        cout << "ou abandonner" << endl << "objet: ";
        string nm;
        bool prise = false;
        cin >> nm;

        for (Objet *obj : *pieceCourante->getList()->getObjets())
        {
            if (obj->getNom() == nm)
            {
                pieceCourante->retirer(obj);
                joueur->ramasserObjet(obj);
                prise = true;
            }
            
        }
        if (!prise)
        {
            if (nm == "abandonner")
                cout << "aucun objet n'est choisie" << endl;
            else
                cout << "je n'ai pas compris ce que vous avez ecrit" << endl;
        }
    }
    
    
    


}


void Jeu::affichage(){
    cout << "afficher: (sac joueur) - (objets Piece) - (personnages piece)" << endl << ">";
    string choice{""};
    cin >> choice;

    if(choice == "sac joueur")
        joueur->afficherObjetSac();
    else if(choice == "objets Piece")
        pieceCourante->getDescription();
    else if(choice == "personnages piece")
        pieceCourante->afficherPersonnages();
    else
        cout << "j'ai pas compris quoi afficher" << endl;
    
}


/*;
void Jeu::informatioin();

void Jeu::nombreObjets();

void Jeu::deposerObjetParUnJoueur();
void Jeu::effectuerDeplacement();
*/