#include"Jeu.hpp"
#include <unistd.h>

bool Jeu::termine = false;

vector<Personnage *> Jeu::listJoueur = vector<Personnage *>({new Moine("moine1"),
                                                            new Moine("moine2"),
                                                            new Moine("moine3"),
                                                            new Amazone("amazone1"),
                                                            new Amazone("amazone2"),
                                                            new Amazone("amazone3"),
                                                            new Guerrier("Guerrier1"),
                                                            new Guerrier("Guerrier2"),
                                                            new Guerrier("Guerrier3"),
                                                            new Sorciere("Sorciere1"),
                                                            new Sorciere("Sorciere2"),
                                                            new Sorciere("Sorciere3")});

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

    random_shuffle(Jeu::listJoueur.begin(), Jeu::listJoueur.end());

    entree->ajouter(Jeu::listJoueur.at(0));
    Jeu::listJoueur.at(0)->setPiece(entree);
    entree->ajouter(Jeu::listJoueur.at(1));
    Jeu::listJoueur.at(1)->setPiece(entree);

    salle1->ajouter(Jeu::listJoueur.at(2));
    Jeu::listJoueur.at(2)->setPiece(salle1);
    salle1->ajouter(Jeu::listJoueur.at(3));
    Jeu::listJoueur.at(3)->setPiece(salle1);

    salle2->ajouter(Jeu::listJoueur.at(4));
    Jeu::listJoueur.at(4)->setPiece(salle2);
    salle2->ajouter(Jeu::listJoueur.at(5));
    Jeu::listJoueur.at(5)->setPiece(salle2);

    salle3->ajouter(Jeu::listJoueur.at(6));
    Jeu::listJoueur.at(6)->setPiece(salle3);
    salle3->ajouter(Jeu::listJoueur.at(7));
    Jeu::listJoueur.at(7)->setPiece(salle3);

    salle4->ajouter(Jeu::listJoueur.at(8));
    Jeu::listJoueur.at(8)->setPiece(salle4);
    salle4->ajouter(Jeu::listJoueur.at(9));
    Jeu::listJoueur.at(9)->setPiece(salle4);

    salle5->ajouter(Jeu::listJoueur.at(10));
    Jeu::listJoueur.at(10)->setPiece(salle5);
    salle5->ajouter(Jeu::listJoueur.at(11));
    Jeu::listJoueur.at(11)->setPiece(salle5);


    Armes *ar1 = new Armes("épé",5);
    Armes *ar2 = new Armes("marteau_d_acier",4);
    Armes *ar3 = new Armes("dague_de_verre",3);
    Armes *ar4 = new Armes("hache_des_psycho",4);
    Armes *ar5 = new Armes("Bloodquench",5);
    Armes *ar6 = new Armes("Nightbane",6);


    Poison *p1 = new Poison("gout_d_hemoragie",4);
    Poison *p2 = new Poison("rune",2);
    Poison *p3 = new Poison("piakkazol",4);
    Poison *p4 = new Poison("toxine_d_entropie",4);
    Poison *p5 = new Poison("la_Fleur_d_enfance",5);
    Poison *p6 = new Poison("verite",2);

    Medicaments *m1 = new Medicaments("cicloxane",6);
    Medicaments *m2 = new Medicaments("entatinoin",5);
    Medicaments *m3 = new Medicaments("albutecin",5);
    Medicaments *m4 = new Medicaments("navelnex_atomoprox",8);
    Medicaments *m5 = new Medicaments("rositiza",5);
    Medicaments *m6 = new Medicaments("factocane",4);

    Boucliers *b1 = new Boucliers("nights_end",3);
    Boucliers *b2 = new Boucliers("prologue",2);
    Boucliers *b3 = new Boucliers("darkheart",2);
    Boucliers *b4 = new Boucliers("military_visage",3);
    Boucliers *b5 = new Boucliers("vigilant",2);
    Boucliers *b6 = new Boucliers("woeful_shield",3);

    /*##########  Entree  */
    entree->ajouter(ar1);
    entree->ajouter(p2);
    entree->ajouter(m3);
    entree->ajouter(b4);

    /*######## salle1 */
    salle1->ajouter(ar2);
    salle1->ajouter(p3);
    salle1->ajouter(m4);
    salle1->ajouter(b5);


    /*######## salle2 */
    salle2->ajouter(ar3);
    salle2->ajouter(p4);
    salle2->ajouter(m5);
    salle2->ajouter(b6);

    /*######## salle3 */
    salle3->ajouter(ar4);
    salle3->ajouter(p5);
    salle3->ajouter(m6);
    salle3->ajouter(b1);


    /*######## salle4 */
    salle4->ajouter(ar5);
    salle4->ajouter(p6);
    salle4->ajouter(m1);
    salle4->ajouter(b2);

    /*######## salle5 */
    salle5->ajouter(ar6);
    salle5->ajouter(p1);
    salle5->ajouter(m2);
    salle5->ajouter(b3);
}


void Jeu::Jouer(){
    afficherMsgBienvennue();
    bool auCombat = false;
    while (!termine)
    {
        auCombat = false;
        while (!auCombat)
        {
            cout << endl << "---------------------------------------------------------------" << endl;
            cout <<"--------------------------" << endl << "Vous êtes dans " <<pieceCourante->getNom() << endl;
            pieceCourante->getDescription();
            pieceCourante->afficherPersonnages();
            pieceCourante->descriptionSorties();
            cout << "---------------------------------------------------------------" << endl;


            MotCleCommandes commande1;
            if (commande1.getCommande() == "aller" && pieceCourante->getNbPersonnages() != 0)
                cout << "Vous pouvez pas vous déplacez tant qu'il y a des ennemis";
            else if (commande1.getCommande() == "au_combat")
                auCombat = true;
            else if(commande1.getCommande() == "quitter"){
                termine = true;
                break; 
            }
            else
                auCombat = traiterCommande(commande1);
        }
        if(!termine){
            bool aug = false;
            for (Personnage *p: *pieceCourante->getPersonnages()->getObjets())
            {
                combat(joueur, p);
                if (joueur->getsante() <= 0)
                {
                    if (joueur->getHabilite() == 0){
                        termine = true ;
                        cout << "Vous avez perdu" << endl;
                        break;
                    }
                    else{
                        joueur->diminuerHabilite(1);
                        joueur->setSante(20);
                    }
                }
                else if(p->getsante() <= 0){
                    pieceCourante->retirer(p);
                    removeJoueur(p);
                    aug = true;
                }
            }
            if(aug){
                joueur->augmenterHabilite(1);
                joueur->augmenteFrappeDegat(3);
            }
            
            if (joueur->getHabilite() >=3)
            {
                termine = true ;
                cout << "Vous avez gagné" << endl;
            }
            
        }   
    }


    
}

void Jeu::removeJoueur(Personnage *p){
    for (int i = 0; i < (int) listJoueur.size(); i++)
    {
        if (Jeu::listJoueur.at(i) == p)
            Jeu::listJoueur.erase(listJoueur.begin()+i);
    }
    
}

void Jeu::effectuerDeplacement(){
    for(Personnage *p : Jeu::listJoueur){
        p->getPieceActuelle()->retirer(p);
        Direction d = p->getPieceActuelle()->getUneSortie();
        p->getPieceActuelle()->pieceSuivante(d)->ajouter(p);
        p->setPiece(p->getPieceActuelle()->pieceSuivante(d));
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
        effectuerDeplacement();
    }
    else if (cm.getCommande() == "quitter")
    {
        return true;
    }
    else if (cm.getCommande() == "ramasser")
    {
        prendreObjetParUnJoueur();
    }
    else if (cm.getCommande() == "deposer")
    {
        deposerObjetParUnJoueur();
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

void Jeu::deposerObjetParUnJoueur(){
    if (joueur->getNbObjets() > 0)
    {
        joueur->afficherObjetSac();
        cout << "(ou) abandonner" << endl << "objet: ";
        string nm;
        bool depose = false;
        cin >> nm;

        for (Objet *obj : *joueur->getObjetsSac()->getObjets())
        {
            if (obj->getNom() == nm)
            {
                joueur->retirerObjet(obj);
                pieceCourante->ajouter(obj);
                joueur->diminuerNbObjet();
                depose = true;
            }
        }
        if (!depose)
        {
            if (nm == "abandonner")
                cout << "aucun objet n'est deposé" << endl;
            else
                cout << "je n'ai pas compris ce que vous avez ecrit" << endl;
        }
        
    }
    else{
        cout << "le sac est vide" << endl;
    }
}

void Jeu::prendreObjetParUnJoueur(){
    if (joueur->getNbObjets() < 4)
    {
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
                joueur->augmenterNbObjet();
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
    else{
        cout << "le sac est plein" << endl;
    }
}


void Jeu::affichage(){
    cout << "afficher: (sac_joueur) - (objets_Piece) - (personnages_piece) - (état_joueur) - (Personnages_pieces)" << endl << ">";
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
    else if(choice == "Personnages_pieces"){
        afficheJoueursPiece();
    }
    else
        cout << "j'ai pas compris quoi afficher" << endl;
    
}

void Jeu::afficheJoueursPiece(){
    for(Personnage *p : Jeu::listJoueur)
        cout << p->getNom() << ": " << p->getPieceActuelle()->getNom() << endl;
}

void Jeu::combat(Personnage *j1, Personnage *j2){
    cout << "----------- Combat avec " << j2->getNom() << "--------------------" << endl;
    cout << j1->getNom() << " VS " << j2->getNom() << endl;
    cout << "Habilité: " << j1->getHabilite() << " VS " << j2->getHabilite() << endl;
    cout << "Santé: " << j1->getsante() << " VS " << j2->getsante() << endl;
    

    while (j1->getsante() > 0 && j2->getsante() > 0)
    {

        if (j1->getNbObjetsSac() == 0)
        {
            j1->diminuerSante(j2->getFrappeDegat());
            j2->diminuerSante(j1->getFrappeDegat());
        }
        else{
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
                        j1->diminuerNbObjet();
                    }
                    else if (dynamic_cast<Armes *>(j1->getObjetsSac()->getObjets()->at(choice)))
                    {
                        Armes *p = (Armes *) j1->getObjetsSac()->getObjets()->at(choice);
                        j1->setFrappeDegat(j1->getFrappeDegat() + p->getDegat());
                        
                        j1->diminuerSante(j2->getFrappeDegat());
                        j2->diminuerSante(j1->getFrappeDegat());
                        j1->retirerObjet(p);
                    }
                    else if (dynamic_cast<Medicaments *>(j1->getObjetsSac()->getObjets()->at(choice)))
                    {
                        Medicaments *p = (Medicaments *) j1->getObjetsSac()->getObjets()->at(choice);
                        
                        j1->augementerSante(p->getGuerison());
                        j1->retirerObjet(p);
                        j1->diminuerNbObjet();

                        j1->diminuerSante(j2->getFrappeDegat());
                        j2->diminuerSante(j1->getFrappeDegat());

                    }
                    else if (dynamic_cast<Boucliers *>(j1->getObjetsSac()->getObjets()->at(choice)))
                    {
                        Boucliers *p = (Boucliers *) j1->getObjetsSac()->getObjets()->at(choice);
                        
                        if(p->getTimes() > 0){
                            j2->diminuerSante(j1->getFrappeDegat());
                            p->setTimes(p->getTimes() - 1);
                        }
                        if(p->getTimes() == 0){
                            cout << "Bouclier damagé (il va être retirer)" << endl;
                            j1->retirerObjet(p);
                            j1->diminuerNbObjet();
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
        }
        
        sleep(2);
        cout << "----------------------" << endl;
        cout << j1->getNom() << " VS " << j2->getNom() << endl;
        cout << "Habilité: " << j1->getHabilite() << " VS " << j2->getHabilite() << endl;
        cout << "Santé: " << j1->getsante() << " VS " << j2->getsante() << endl;

        
        
    }
    cout << "----------------- Resultat ---------------------" << endl;
    cout << j1->getNom() << " VS " << j2->getNom() << endl;
    cout << j1->getHabilite() << " VS " << j2->getHabilite() << endl;
    cout << j1->getsante() << " VS " << j2->getsante() << endl;
    
}