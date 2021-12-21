#include"Jeu.hpp"
#include <unistd.h>

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
    Piece *zero = new Piece("zero");

    
    entree->setSorties(salle2,salle1,salle4,nullptr);
    salle1->setSorties(entree,nullptr,salle3,nullptr);
    salle2->setSorties(nullptr,entree,salle5,nullptr);
    salle3->setSorties(salle4,nullptr,nullptr,salle1);
    salle4->setSorties(salle5,salle3,nullptr,entree);
    salle5->setSorties(nullptr,salle4,nullptr,salle2);
    zero->setSorties(nullptr,nullptr,entree,nullptr);

    pieceCourante = zero;

    Personnage *per = new  Personnage("Reda");

    entree->ajouter(per);

    Armes *ar1 = new Armes("épé",5);
    Armes *ar2 = new Armes("marteau_d_acier",4);
    Armes *ar3 = new Armes("dague_de_verre",3);
    Armes *ar4 = new Armes("hache_des_psycho",4);

    Poison *p1 = new Poison("gout_d_hemoragie",3);
    Poison *p2 = new Poison("rune",2);
    Poison *p3 = new Poison("piakkazol",2);
    Poison *p4 = new Poison("toxine_d_entropie",2);

    Medicaments *m1 = new Medicaments("cicloxane",6);
    Medicaments *m2 = new Medicaments("entatinoin",5);
    Medicaments *m3 = new Medicaments("albutecin",5);
    Medicaments *m4 = new Medicaments("navelnex_atomoprox",4);

    Boucliers *b1 = new Boucliers("nights_end",3);
    Boucliers *b2 = new Boucliers("prologue",2);
    Boucliers *b3 = new Boucliers("darkheart",2);
    Boucliers *b4 = new Boucliers("military_visage",3);

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
    int count{1} ;
    bool auCombat = false;
    while (!termine)
    {
        auCombat = false;
        cout <<"--------------------------" << endl << "Vous êtes dans " <<pieceCourante->getNom() << endl;
        while (!auCombat)
        {
            pieceCourante->getDescription();
            pieceCourante->afficherPersonnages();
            pieceCourante->descriptionSorties();

            MotCleCommandes commande1;
            if (commande1.getCommande() == "aller" && pieceCourante->getPersonnages()->getNbObjets() != 0)
            {
                cout << "Vous pouvez pas vous déplacez tant qu'il y a des ennemis";
            }
            else if (commande1.getCommande() == "au_combat")
            {
                auCombat = true;
            }
            else
            {
                auCombat = traiterCommande(commande1);
            }
        }
        
        for (Personnage *p: *pieceCourante->getPersonnages()->getObjets())
        {
            termine = combat(joueur, p);
            if (termine)
            {
                break;
            }
        }
    }
    
}


void Jeu::afficherMsgBienvennue(){
    cout << endl ;
    cout <<"Bienvennue dans le chateau des Merveilles !" << endl;
    cout <<"BeatOrLeave est un nouveau jeu d'aventure,\n";
    cout <<"votre mission est de survivre et arriver au habilité 3" << endl;
    cout <<"combattre les autres" << endl;
    cout <<"utilisez des armes, boucliers et d'autres objets" << endl;
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
    if (joueur->getObjetsSac()->getNbObjets() == 4)
    {
        cout << "le sac est plein" << endl;
    }
    else{
        cout << "(ou) abandonner" << endl << "objet: ";
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
    cout << "afficher: (sac_joueur) - (objets_Piece) - (personnages_piece) - (état_joueur)" << endl << ">";
    string choice{""};
    cin >> choice;

    if(choice == "sac_joueur")
        joueur->afficherObjetSac();
    else if(choice == "objets_Piece")
        pieceCourante->getDescription();
    else if(choice == "personnages_piece")
        pieceCourante->afficherPersonnages();
    else if(choice == "état_joueur")
        joueur->descriptionPersonnage();
    else
        cout << "j'ai pas compris quoi afficher" << endl;
    
}

bool Jeu::combat(Personnage *j1, Personnage *j2){
    cout << "----------- Combat avec " << j2->getNom() << endl;
    cout << j1->getNom() << " VS " << j2->getNom() << endl;
    cout << j1->getHabilite() << " VS " << j2->getHabilite() << endl;
    cout << j1->getsante() << " VS " << j2->getsante() << endl;
    

    while (j1->getsante() > 0 && j2->getsante() > 0)
    {
        j1->afficherObjetSac();
        cout << "Vous voulez utiliser un objet dans le sac ? (oui/non)" << endl << ">" ;
        string rep;
        cin >>rep;
        if (rep == "non")
        {
            j1->diminuerSante(j2->getFrappeDegat());
            j2->diminuerSante(j1->getFrappeDegat());
        }
        else if ("oui"){
            j1->afficherObjetSac();
            cout << "quel objet: ";
            string s;
            cin >> s;
            int choice = j1->contientObjet(s);
            if (choice != -1)
            {
                if (dynamic_cast<Poison *>(j1->getObjetsSac()->getObjets()->at(choice)))
                {
                    Poison *p = (Poison *) j1->getObjetsSac()->getObjets()->at(choice);
                    j1->diminuerSante(j2->getFrappeDegat());
                    j2->diminuerSante(j1->getFrappeDegat());
                    j2->diminuerSante(p->getPoisonDegat());

                    j1->retirerObjet(p);
                }
                if (dynamic_cast<Armes *>(j1->getObjetsSac()->getObjets()->at(choice)))
                {
                    Armes *p = (Armes *) j1->getObjetsSac()->getObjets()->at(choice);
                    j1->setFrappeDegat(j1->getFrappeDegat() + p->getDegat());

                    j1->diminuerSante(j2->getFrappeDegat());
                    j2->diminuerSante(j1->getFrappeDegat());

                }
                if (dynamic_cast<Medicaments *>(j1->getObjetsSac()->getObjets()->at(choice)))
                {
                    Medicaments *p = (Medicaments *) j1->getObjetsSac()->getObjets()->at(choice);
                    
                    j1->augementerSante(p->getGuerison());

                    j1->diminuerSante(j2->getFrappeDegat());
                    j2->diminuerSante(j1->getFrappeDegat());

                }
                if (dynamic_cast<Boucliers *>(j1->getObjetsSac()->getObjets()->at(choice)))
                {
                    Boucliers *p = (Boucliers *) j1->getObjetsSac()->getObjets()->at(choice);
                    
                    if(p->getTimes() > 0){
                        j2->diminuerSante(j1->getFrappeDegat());
                        p->setTimes(p->getTimes() - 1);
                    }
                    else{
                        cout << "Bouclier damagé (il va être retirer" << endl;
                    }
                } 
            }
            else{
                cout << "cet objet n'existe pas" << endl;
            }
            
        }
        else{
            cout << "je n'ai pas compris -> au combat" << endl;
        }
        j1->descriptionPersonnage();
        j2->descriptionPersonnage();
        sleep(1);
        
    }
    cout << "----------------- Resultat ---------------------" << endl;
    cout << j1->getNom() << " VS " << j2->getNom() << endl;
    cout << j1->getHabilite() << " VS " << j2->getHabilite() << endl;
    cout << j1->getsante() << " VS " << j2->getsante() << endl;

    if (j1->getsante() == 0)
    {
        return true;
    }
    else{
        pieceCourante->retirer(j2);
    }
    return false;
    
}


/*;
void Jeu::informatioin();

void Jeu::nombreObjets();

void Jeu::deposerObjetParUnJoueur();
void Jeu::effectuerDeplacement();
*/