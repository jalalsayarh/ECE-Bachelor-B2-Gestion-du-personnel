//
//  fonctions.cpp
//  Gestion Personnel
//


#include "fonctions.hpp"

/*                                      RESUME DES FONCTIONS
 
 
 1-Blinde une saisie dont le choix est LIMITé A DEUX REPONSES POSSIBLE. Le premier string envoyé a la fonction correspond au message qui s'affichera à l'écran lorsque l'utilisateur devrai saisir son choix et les deux autres font références aux valeur des deux choix qu'aura l'utilisateur et renvoie en string la valeur saisie par l'utilisateur
 
 2-Blinde une saisie dont le choix est un INTERVALE etre deux valeur. Le premier string envoyé a la fonction correspond au message qui s'affichera à l'écran lorsque l'utilisateur devrai saisir son choix et les deux autres parametres font références aux valeur des deux bornes qui limite le choix qu'aura l'utilisateur et renvoie en int la valeur saisie par l'utilisateur. A noté, l'ordre des bornes n'a pas d'importance, la fonction se charge de trier les bornes
 
                ********************************************************************************
                                        ETAPE 4 DU PROJET
        Les fonctions numéroté de 3 à 8 recoivent toutes en parametres l'adresse d'un tableau de type <Personne*> et le nombres de cases à afficher. Attention risque d'erreur! Veillez à ce que la fonction ne traite pas de cases vide du tableau
 
 3-Affiche le contenu d'un tableau de type Personne*.
 
 4-Permet la saisie d'un tableau de type Personne*.
 
 5-Tri d'un tableau de type Personne* par nom dans l'ordre alphabétique.
 
 6-Tri d'un tableau de type Personne* par prénom dans l'ordre alphabetique.
 
 7-Tri d'un tableau de type Personne* par age dans un ordre croissant.

 8-Recherche d'un élément dans le tableau par nom prenom age email ou alors par saisie de toutes ces infos pour une recherche précise.

                 ********************************************************************************
                                         ETAPE 9 DU PROJET
        Les fonctions numérotées 9 et 15 et recoivent en parametres l'adresse du vecteur en question
 
 9-Saisie des élement d'un vecteur de type Personne*.
 
 10-On affiche tous les éléments d'un vecteur de type Personne*.
 
 11-Tri par nom dans l'ordre alphabétique
 
 12-Tri par prénom dans l'ordre alphabétique
 
 13- Tri par age dans l'ordre croissant
 
 14- Recherche d'un élément
  

 15-Saisie d'une liste d'étudiant et d'employé. Recois en parametre l'adresse du premier element de la liste (permet aussi l'ajout d'un nouvel element auquel cas on peut envoyer en parametre un des element de la liste )
 
                 ********************************************************************************
                                         ETAPE 10 DU PROJET
 
 16-Ecriture dans un fichier. ATTENTION quand on appelle la fonction plusieurs fois pour le meme fichier, la derniere saisie écrase toujours la précedente
 
 17-Lecture du contenu d'un fichier
 
 
 */




// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

/*1*/string blindage_Saisie_ChoixBinaire(string phrase, string choix1,string choix2)
{
    string choix;
    cout<<phrase;
    
    while(!(cin >> choix) || ((choix !=choix1) && (choix!=choix2))) // on blinde grossièrement entre 0 et 2 (utilisation de regex pour etre plus précis)
    {
       if (cin.fail()) // si la saisie n'est pas un nombre on affiche une erreur et on demande de resaisir
       {
           cout << "Error 404, recommencez : ";
           cin.clear();
           cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
       }
       else // sinon, la valeur n'est pas dans les paramètres autorisés donc on redemande la saisie
       {
           cout<<"   Attention !\nVérifiez l'othographe de la saisie! \n ->";
       }
    }
    return choix;
}

// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

/*2*/int blindage_Saisie_ChoixIntervalle(string phrase, int borne1 ,int borne2)
{
    int choix;
    
        /** TRI DES BORNES; Peut importe l'ordre des valeur des bornes envoyés dans les parmetres da le fonctions il n'y aura pas de bugs */
    if (borne1>borne2)
    {
        choix=borne1;
        borne1=borne2;
        borne2=choix;
    }
    cout<<phrase;
    
    while(!(cin >> choix) || ((choix < borne1) && (choix > borne2))) // on blinde grossièrement entre 0 et 2 (utilisation de regex pour etre plus précis)
    {
       if (cin.fail()) // si la saisie n'est pas un nombre on affiche une erreur et on demande de resaisir
       {
           cout << "Error 404, recommencez : ";
           cin.clear();
           cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
       }
       else // sinon, la valeur n'est pas dans les paramètres autorisés donc on redemande la saisie
       {
           cout<<"   Attention !\n Le choix saisi n'est pas répertorié \n ->";
       }
    }
    return choix;
}


// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

/*3*/void afficheTab_Personne(Personne* tab[],int nombre) /* étape 4: partie affichage d'un tableau via fonctions */
{
    /* °L'idéal ici serait de blindé la fonction pour palier au risque que ne nombre envoyé en paramètre soit plus grand que la taille du tableau. Pour se faire il faudrait pouvoir recuperer la taille du tableau du coup nous avons pensez divisé sizeof(tab) par la taille d'une seule personne mais le probleme c'est que nous avons ici un tableau de pointeur et non pas un tableau de personne d'ou le "L'idéal".
     */
//    int i=0;
//    cout<<"taille du tableau :"<<sizeof(tab)/sizeof(Personne);
//    cout<<"taille du tableau :"<<sizeof(*tab)/sizeof(Personne);
//    cout<<"taille du tableau :"<<sizeof(&tab)/sizeof(Personne);
//    while (i<(sizeof(&tab)/sizeof(Personne)))

    for (int i=0; i<nombre; i++)
    {
       cout<< dynamic_cast<Personne*>(*(tab+i))->affiche();
    }
}

// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/


/*4*/ void saisieTab_Personne(Personne* tab[],int nombre)

{
    cout<<"---SAISIE DU TABLEAU---\n";
    string choixPersonne;
    for (int i=0; i<nombre; i++) {
        do{
            cout<<"\nSaisir [1] pour ajouter un(e) Etudiant(e)\nSaisir [2] pour ajouter un(e) Employé(e)\nSaisir [3] pour ajouter un(e) Elève(e)\n->";
            cin>>choixPersonne;
        }while ((choixPersonne!="1")&&(choixPersonne!="2")&&(choixPersonne!="3"));

        if (choixPersonne=="1") {
            Etudiant* LeEtudiant= new Etudiant();
            auto *etu = dynamic_cast<Etudiant *>(LeEtudiant);;
            etu->newEtudiant();
            *(tab+i)=LeEtudiant;
        }
        else if (choixPersonne=="2"){
            Employe *LeEmploye= new Employe();
            auto *emp = dynamic_cast<Employe*>(LeEmploye);
            emp->newEmploye();
            *(tab+i)=LeEmploye;
        }
        else{
            Eleve *lEleve= new Eleve();
            auto *el = dynamic_cast<Eleve*>(lEleve);
            el->newEleve();
            *(tab+i)=lEleve;
        }
    }
    //cout<<"---Fin de la fonction---\n";   /* Point de repère*/
}

// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/


/*5*/void tri_tab_personne_nom(Personne* tab[], int nb)
{
    Personne* intermediaire=new Personne();
    
    // on fait un parcours de toutes le lignes du tableau, en donnant des coordonnés de cellule pour la permu.
    for(int i=0; i<nb-1; i++)
    {
        for(int j=i+1; j<nb; j++)
        {
            if (dynamic_cast<Personne*>(*(tab+i))->getNom() > dynamic_cast<Personne*>(*(tab+j))->getNom())/**si le premier caractère est plus petit que le                                                                                                                                                                                                                                    suivant alors on permute*/
            {
                // permutation nom
                intermediaire=*(tab+i);
                *(tab+i)=*(tab+j);
                *(tab+j)=intermediaire;
            }
           
        }
    }// fin double boucle imbriquée
    
}// fin


// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/


/*6*/void tri_tab_personne_prenom(Personne* tab[], int nb)
{
    Personne* intermediaire=new Personne();
    
    // on fait un parcours de toutes le lignes du tableau, en donnant des coordonnés de cellule pour la permu.
    for(int i=0; i<nb-1; i++)
    {
        for(int j=i+1; j<nb; j++)
        {
            if (dynamic_cast<Personne*>(*(tab+i))->getPrenom() > dynamic_cast<Personne*>(*(tab+j))->getPrenom())/**si le premier caractère est plus petit que le                                                                                                                                                                                                                                    suivant alors on permute*/
            {
                // permutation nom
                intermediaire=*(tab+i);
                *(tab+i)=*(tab+j);
                *(tab+j)=intermediaire;
            }
           
        }
    }// fin double boucle imbriquée
    
}// fin


// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/


/*7*/void tri_tab_personne_age(Personne* tab[], int nb)
{
    Personne* intermediaire=new Personne();
    
    // on fait un parcours de toutes le lignes du tableau, en donnant des coordonnés de cellule pour la permu.
    for(int i=0; i<nb-1; i++)
    {
        for(int j=i+1; j<nb; j++)
        {
            if ((*(tab+i))->getAge() > (*(tab+j))->getAge()) /**Si le premier est plus âgé que le suivant alors on permute*/
            {
                // permutation nom
                intermediaire=*(tab+i);
                *(tab+i)=*(tab+j);
                *(tab+j)=intermediaire;
            }
           
        }
    }// fin double boucle imbriquée
    
}// fin


// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/


void affiche_etudiant(Personne* tab[],int nb)
{
    int compteur=0;
    for (int i=0; i<nb; i++)
    {
        if ((typeid(**(tab+i)).name())==typeid(Etudiant).name())
        {
            compteur++;
            cout<< dynamic_cast<Personne*>(*(tab+i))->affiche();
        }
    }
    if (compteur==0) {
        cout<<"Il n'y a pas d'étudiants dans le tableau"<<endl;
    }
}

    
void affiche_employe(Personne* tab[],int nb)
{
    int compteur=0;
    for (int i=0; i<nb; i++)
    {
        if ((typeid(**(tab+i)).name())==typeid(Employe).name())
        {
            compteur++;
            cout<< dynamic_cast<Personne*>(*(tab+i))->affiche();
        }
    }
    if (compteur==0) {
        cout<<"Il n'y a pas d'employés dans le tableau"<<endl;
    }
}

void affiche_eleve(Personne* tab[],int nb)
{
    int compteur=0;
    for (int i=0; i<nb; i++)
    {
        if ((typeid(**(tab+i)).name())==typeid(Eleve).name())
        {
            compteur++;
            cout<< dynamic_cast<Personne*>(*(tab+i))->affiche();
        }
    }
    if (compteur==0) {
        cout<<"Il n'y a pas d'élèves dans le tableau"<<endl;
    }
}
// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/


/*8*/void recherche_personne_in_tab(Personne* tab[],int nb)
{
    int choixMenu;
    string nouvelleRecherche;
    do {
        cout<<"\n-----Recherche d'un élément-----\n";
        cout<<"\n1-Recherche par nom";
        cout<<"\n2-Recherche par prénom";
        cout<<"\n3-Recherche par mail";
        cout<<"\n4-Recherche par age";
        cout<<"\n5-Rechercher une personne";
        
        choixMenu=blindage_Saisie_ChoixIntervalle("\n\n-> ", 1, 5);
        
        do {
            switch (choixMenu) {
                case 1:
                {
                    string rechercheNom;
                    int compteur=0;
                    cout<<"\n Recherche par nom"<<endl;
                    cout<<"     -> ";
                    cin>>rechercheNom;
                    
                    for (int i=0; i<nb; i++)
                    {
                        if ( (*(tab+i))->getNom()==rechercheNom)
                        {
                            compteur++;
                            cout<<"-------------------------\n";
                            cout<<(*(tab+i))->affiche();
                        }
                    }
                    if (compteur==0)
                        cout<<"\n Désolé; Aucun élément ne correspond à votre recherche\n";
                    else
                        cout<<"-------------------------\n";
                    break;
                }
                    
                case 2: /**Recherche par prénom*/
                {
                    string recherchePrenom;
                    int compteur=0;
                    cout<<"\n Recherche par prénom"<<endl;
                    cout<<"     -> ";
                    cin>>recherchePrenom;
                    
                    for (int i=0; i<nb; i++)
                    {
                        if ( (*(tab+i))->getPrenom()==recherchePrenom)
                        {
                            compteur++;
                            cout<<"-------------------------\n";
                            cout<<(*(tab+i))->affiche();
                        }
                    }
                    if (compteur==0)
                        cout<<"\n Désolé; Aucun élément ne correspond à votre recherche\n";
                    else
                        cout<<"-------------------------\n";
                    break;
                }
                case 3: /**Recherche par mail*/
                {
                    string rechercheMail;
                    int compteur=0;
                    cout<<"\n Recherche par mail"<<endl;
                    cout<<"     -> ";
                    cin>>rechercheMail;
                    
                    for (int i=0; i<nb; i++)
                    {
                        if ( (*(tab+i))->getEmail()==rechercheMail)
                        {
                            compteur++;
                            cout<<"-------------------------\n";
                            cout<<(*(tab+i))->affiche();
                        }
                    }
                    if (compteur==0)
                        cout<<"\n Désolé; Aucun élément ne correspond à votre recherche\n";
                    else
                        cout<<"-------------------------\n";
                    
                    break;
                }
                case 4: /**Recherche par age*/
                {
                    int rechercheAge,compteur=0;
                    cout<<"\n Recherche par age"<<endl;
                    cout<<"     -> ";
                    cin>>rechercheAge;
                    
                    for (int i=0; i<nb; i++)
                    {
                        if ( (*(tab+i))->getAge()==rechercheAge)
                        {
                            compteur++;
                            cout<<"-------------------------\n";
                            cout<<(*(tab+i))->affiche();
                        }
                    }
                    if (compteur==0)
                        cout<<"\n Désolé; Aucun élément ne correspond à votre recherche\n";
                    else
                        cout<<"-------------------------\n";
                    
                    break;
                }
                    
                case 5: /**Rechercher une personne*/
                {
                    Personne p;
                    int compteur=0;
                    p.newPerson();
                    for (int i=0; i<nb; i++)
                    {
                        if ( p==(**(tab+i)) )
                        {
                            compteur++;
                            cout<<"-------------------------\n";
                            cout<<(*(tab+i))->affiche();
                        }
                    }
                    if (compteur==0)
                        cout<<"\n Désolé; Aucun élément ne correspond à votre recherche\n";
                    else
                        cout<<"-------------------------\n";
                    
                }
                    break;
                    
                default:
                {
                    cout<<"\nErreur de saisie\n";
                    choixMenu=100;
                }
                    break;
            }
        } while (choixMenu==100);
        
        cout<<"effectuer une nouvelle recherche ? (oui/non)";
        nouvelleRecherche=blindage_Saisie_ChoixBinaire("\n->", "oui", "non");
        
    }while (nouvelleRecherche=="oui");
}



// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/



/*9*/void saisie_Vecteur_Personne(vector<Personne*> *lesGens)
{
    Personne *intermediaire=new Personne();
    string choixPersonne;
    
    do{
        cout<<"\nSaisir [1] pour ajouter un(e) Etudiant(e)\nSaisir [2] pour ajouter un(e) Employé(e)\nSaisir [3] pour ajouter un(e) Elève(e)\n->";
        cin>>choixPersonne;
    }while ((choixPersonne!="1")&&(choixPersonne!="2")&&(choixPersonne!="3"));

    if (choixPersonne=="1")
    {
        /*
            Nous avons volontairmeent laissé en commeaires les lignes de codes
            non fonctionnelles mais qui ont servit à la reflexion d'un point de vue
            algorithmique du code notamment les 4 lignes de codes qui suivent
         */

        /*
        auto *LeEtudiant = dynamic_cast<Etudiant *>(person);
        lesGens.push_back(static_cast<Etudiant*>(malloc(sizeof(Etudiant*))));
        Etudiant Letudiant;
        LeEtudiant=&Letudiant;
        */

        Etudiant* LeEtudiant= new Etudiant();
        auto *etu = dynamic_cast<Etudiant *>(LeEtudiant);;
        etu->newEtudiant();
        intermediaire=LeEtudiant;
    }

    else if (choixPersonne=="2")
    {
        Employe *LeEmploye= new Employe();
        auto *emp = dynamic_cast<Employe*>(LeEmploye);
        emp->newEmploye();
        intermediaire=LeEmploye;
    }
    else{
        Eleve *lEleve= new Eleve();
        auto *el = dynamic_cast<Eleve*>(lEleve);
        el->newEleve();
        intermediaire=lEleve;
    }
    
    lesGens->push_back(intermediaire);
}


// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/


/*10*/void affiche_Vecteur(vector<Personne*> *lesGens)
{
    for (Personne* gens : *lesGens)
    {
        cout<<gens->affiche();
    }
}


void affiche_etudiant(vector<Personne*> *lesGens)
{
    int compteur=0;
    for (Personne* gens : *lesGens)
    {
        if ((typeid(*gens).name())==typeid(Etudiant).name())
        {
            compteur++;
            cout<<gens->affiche();
        }
    }
    
    if (compteur==0) {
        cout<<"Il n'y a pas d'étudiants dans le tableau"<<endl;
    }
}

void affiche_employe(vector<Personne*> *lesGens)
{
    int compteur=0;
    for (Personne* gens : *lesGens)
    {
        if ((typeid(*gens).name())==typeid(Employe).name())
        {
            compteur++;
            cout<<gens->affiche();
        }
    }
    
    if (compteur==0) {
        cout<<"Il n'y a pas d'employés dans le tableau"<<endl;
    }
}

void affiche_eleve(vector<Personne*> *lesGens)
{
    int compteur=0;
    for (Personne* gens : *lesGens)
    {
        if ((typeid(*gens).name())==typeid(Eleve).name())
        {
            compteur++;
            cout<<gens->affiche();
        }
    }
    
    if (compteur==0) {
        cout<<"Il n'y a pas d'élèves dans le tableau"<<endl;
    }
}

// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/


/*11*/void tri_vecteur_personne_nom(vector<Personne*> *lesGens)
{
    vector<Personne*>::iterator gens;
    vector<Personne*>::iterator gens2;
    Personne* intermediaire=new Personne();
    
    // on fait un parcours de toutes le lignes du tableau, en donnant des coordonnés de cellule pour la permu.
    for (gens=lesGens->begin(); gens!=lesGens->end()-1; gens++)
    {
        for(gens2=gens+1; gens2<lesGens->end(); gens2++)
        {
            if ((*(gens))->getNom() > (*(gens2))->getNom())/**si le premier caractère est plus petit que le                                                                                                                                                                                                                                    suivant alors on permute*/
            {
                // permutation nom
                intermediaire=(*(gens));
                *(gens)=*(gens2);
                *(gens2)=intermediaire;
            }
           
        }
    }// fin double boucle imbriquée
    
}


// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/


/*12*/void tri_vecteur_personne_prenom(vector<Personne*> *lesGens)
{
    {
        vector<Personne*>::iterator gens;
        vector<Personne*>::iterator gens2;
        Personne* intermediaire=new Personne();
        
        // on fait un parcours de toutes le lignes du tableau, en donnant des coordonnés de cellule pour la permu.
        for (gens=lesGens->begin(); gens!=lesGens->end()-1; gens++)
        {
            for(gens2=gens+1; gens2<lesGens->end(); gens2++)
            {
                if ((*(gens))->getPrenom() > (*(gens2))->getPrenom())/**si le premier caractère est plus petit que le                                                                                                                                                                                                                                    suivant alors on permute*/
                {
                    // permutation nom
                    intermediaire=(*(gens));
                    *(gens)=*(gens2);
                    *(gens2)=intermediaire;
                }
               
            }
        }// fin double boucle imbriquée
        
    }
}


// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/


/*13*/void tri_vecteur_personne_age(vector<Personne*> *lesGens)
{
    {
        vector<Personne*>::iterator gens;
        vector<Personne*>::iterator gens2;
        Personne* intermediaire=new Personne();
        
        // on fait un parcours de toutes le lignes du tableau, en donnant des coordonnés de cellule pour la permu.
        for (gens=lesGens->begin(); gens!=lesGens->end()-1; gens++)
        {
            for(gens2=gens+1; gens2<lesGens->end(); gens2++)
            {
                if ((*(gens))->getAge() > (*(gens2))->getAge())/**si le premier caractère est plus petit que le                                                                                                                                                                                                                                    suivant alors on permute*/
                {
                    // permutation nom
                    intermediaire=(*(gens));
                    *(gens)=*(gens2);
                    *(gens2)=intermediaire;
                }
               
            }
        }// fin double boucle imbriquée
        
    }
}


// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/


/*14*/void recherche_vecteur(vector<Personne*> *lesGens)
{
    int choixMenu;
    string nouvelleRecherche;
    do {
        cout<<"\n-----Recherche d'un élément-----\n";
        cout<<"\n1-Recherche par nom";
        cout<<"\n2-Recherche par prénom";
        cout<<"\n3-Recherche par mail";
        cout<<"\n4-Recherche par age";
        cout<<"\n5-Rechercher une personne";
        
        choixMenu=blindage_Saisie_ChoixIntervalle("\n\n-> ", 1, 5);
        
        do {
            switch (choixMenu) {
                case 1:
                {
                    string rechercheNom;
                    int compteur=0;
                    cout<<"\n Recherche par nom"<<endl;
                    cout<<"     -> ";
                    cin>>rechercheNom;
                    
                    for (Personne* gens : *lesGens)
                    {
                        if (gens->getNom()==rechercheNom)
                        {
                            compteur++;
                            cout<<"-------------------------\n";
                            cout<<gens->affiche();
                        }
                    }
                    if (compteur==0) {
                        cout<<"\n Désolé; Aucun élément ne correspond à votre recherche\n";
                    }
                    else cout<<"-------------------------\n";
            
                    break;
                }
                    
                case 2: /**Recherche par prénom*/
                {
                    string recherchePrenom;
                    int compteur=0;
                    cout<<"\n Recherche par prénom"<<endl;
                    cout<<"     -> ";
                    cin>>recherchePrenom;
                    
                    for (Personne* gens : *lesGens)
                    {
                        if (gens->getPrenom()==recherchePrenom)
                        {
                            compteur++;
                            cout<<"-------------------------\n";
                            cout<<gens->affiche();
                        }
                    }
                        if (compteur==0) {
                            cout<<"\n Désolé; Aucun élément ne correspond à votre recherche\n";
                        }
                        else cout<<"-------------------------\n";
                    
                    break;
                }
                case 3: /**Recherche par mail*/
                {
                    string rechercheMail;
                    int compteur=0;
                    cout<<"\n Recherche par mail"<<endl;
                    cout<<"     -> ";
                    cin>>rechercheMail;
                    
                    for (Personne* gens : *lesGens)
                    {
                        if (gens->getEmail()==rechercheMail)
                        {
                            compteur++;
                            cout<<"-------------------------\n";
                            cout<<gens->affiche();
                        }
                    }
                        if (compteur==0) {
                            cout<<"\n Désolé; Aucun élément ne correspond à votre recherche\n";
                        }
                        else cout<<"-------------------------\n";
                    break;
                }
                case 4: /**Recherche par age*/
                {
                    int rechercheAge,compteur=0;
                    cout<<"\n Recherche par age"<<endl;
                    cout<<"     -> ";
                    cin>>rechercheAge;
                    
                    for (Personne* gens : *lesGens)
                    {
                        if (gens->getAge()==rechercheAge)
                        {
                            compteur++;
                            cout<<"-------------------------\n";
                            cout<<gens->affiche();
                        }
                    }
                        if (compteur==0) {
                            cout<<"\n Désolé; Aucun élément ne correspond à votre recherche\n";
                        }
                        else cout<<"-------------------------\n";
                    break;
                }
                    
                case 5: /**Rechercher une personne*/
                {
                    Personne p;
                    p.newPerson();
                    for (Personne* gens : *lesGens)
                    {
                        if (p==*gens)
                            gens->affiche();
                        else
                            cout<<"\nAucun élément ne correspond à votre recherche";
                    }
                }
                    break;
                    
                default:
                {
                    cout<<"\nErreur de saisie\n";
                    choixMenu=100;
                }
                    break;
            }
        } while (choixMenu==100);
        
        cout<<"effectuer une nouvelle recherche ? (oui/non)";
        nouvelleRecherche=blindage_Saisie_ChoixBinaire("\n->", "oui", "non");
        
    }while (nouvelleRecherche=="oui");
    
}


// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/


/*15*/void saisie_Liste_Personne(elementListe* start)
{
    string choixPersonne;
    elementListe* intermediaire= new elementListe();
    elementListe *e= new elementListe();
    
    
    do{
        cout<<"\nSaisir [1] pour ajouter un(e) Etudiant(e)\nSaisir [2] pour ajouter un(e) Employé(e)\nSaisir [3] pour ajouter un(e) Elève(e)\n->";
        cin>>choixPersonne;
    }while ((choixPersonne!="1")&&(choixPersonne!="2")&&(choixPersonne!="3"));

    if (choixPersonne=="1")
    {
        Etudiant *LeEtudiant=new Etudiant();
        auto *etu = dynamic_cast<Etudiant *>(LeEtudiant);
        etu->newEtudiant();
        e->setSomeone(LeEtudiant);
    }

    else if(choixPersonne=="2")
    {
        Employe *LeEmploye= new Employe();
        auto *emp = dynamic_cast<Employe*>(LeEmploye);
        emp->newEmploye();
        //lesGens.push_back(LeEmploye);
        e->setSomeone(LeEmploye);
    }
    else{
        Eleve *lEleve= new Eleve();
        auto *el = dynamic_cast<Eleve*>(lEleve);
        el->newEleve();
        e->setSomeone(lEleve);
    }
    
    if (start->getSomeone()==NULL) { // si il n'y pas encore d'element dans la liste
        start->setSomeone(e->getSomeone());          //On sauvegarde le premier element de la liste dans un pointeur
    } else{
       intermediaire=start; //on se place au premier element de la liste
       while(intermediaire->getNext()!= NULL)
       {
           intermediaire = (intermediaire->getNext()); /* On va jusqu'au dernier élement */
       }
        //e->setPrevious(intermediaire);
        intermediaire->setNext(e);
    }
}


// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/


void tri_liste_personne_nom(elementListe* start)
{
//    elementListe* intermediare=new elementListe();
//    *intermediare=*start;
//    elementListe intermediare2=*((*start).getNext());
//    
//    if (dynamic_cast<Personne*>(intermediare->getSomeone())->getNom()) {
//        =
//    }
    cout<<"\nDésolé, cette fonctionnalité n'est pas encore disponible";
}
void tri_liste_personne_prenom(elementListe* start){cout<<"\nDésolé, cette fonctionnalité n'est pas encore disponible";}
void tri_liste_personne_age(elementListe* start){cout<<"\nDésolé, cette fonctionnalité n'est pas encore disponible";}
void recherche_liste(elementListe* start){cout<<"\nDésolé, cette fonctionnalité n'est pas encore disponible";}






// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/


/*16*/void write(string nomFichier,Personne* tab[], int nb )
{
    /*
    Sur un fichier déja existant
    Fichier .txt
    Ecriture dans un fichier
    */

      
    // faire une saisie de chemin par l'utilisateur
    // préciser à l'utilisateur qu'il doit avoir un fichier crée au préalable
    //string const nomFichier("/Users/jalalsayarh/Desktop/fichertestProjetAutonome.txt");
    string const monFichier(nomFichier);
    ofstream monFlux(monFichier.c_str());
    
    // Déclaration d'un flux qui permet d'écrire dans un fichier
    if(monFlux) // on teste pour voir si tout est ok
    {
        cout<<"\n Enregistrement dans le fichier "<<nomFichier<<" en cours..."<<endl;
        // modifier l'écriture pour pouvoir écrire dans le fichier les informations relatives
        
        for(int i=0; i<nb; i++)
        {
            monFlux<<"\n---------------------------\n";
            monFlux <<(*(tab+i))->affiche();
            //message="\nEnregistremenet dans le fichier okay";
        }
        monFlux<<"\n---------------------------\n";
        
        cout<<"\nEnregistrement terminé !"<<endl;
    }
    else // en cas d'erreur : pas de fichier, chemin incorrect ...
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
        
}

// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

void write(string nomFichier, vector<Personne*> *lesGens)
{
    string const monFichier(nomFichier);
    ofstream monFlux(monFichier.c_str());
    
    // Déclaration d'un flux qui permet d'écrire dans un fichier
    if(monFlux) // on teste pour voir si tout est ok
    {
        cout<<"\n Enregistrement dans le fichier "<<nomFichier<<" en cours..."<<endl;
        // modifier l'écriture pour pouvoir écrire dans le fichier les informations relatives
        
        for (Personne* gens : *lesGens)
        {
            monFlux<<"\n---------------------------\n";
            monFlux <<gens->affiche();
            //message="\nEnregistremenet dans le fichier okay";
        }
        monFlux<<"\n---------------------------\n";
        
        cout<<"\nEnregistrement terminé !"<<endl;
    }
    else // en cas d'erreur : pas de fichier, chemin incorrect ...
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}


// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/


void write(string nomFichier, elementListe *start)
{
    string const monFichier(nomFichier);
    ofstream monFlux(monFichier.c_str());
    
    // Déclaration d'un flux qui permet d'écrire dans un fichier
    if(monFlux) // on teste pour voir si tout est ok
    {
        cout<<"\n Enregistrement dans le fichier "<<nomFichier<<" en cours..."<<endl;
        // modifier l'écriture pour pouvoir écrire dans le fichier les informations relatives
        elementListe *intermerdiaire = new elementListe();
        intermerdiaire=start;
        
        monFlux<< "\n---------------------------\n";
        monFlux<< intermerdiaire->getSomeone()->affiche();
        
        while (intermerdiaire->getNext()!=NULL) {
            intermerdiaire=intermerdiaire->getNext();
            monFlux<< "\n---------------------------\n";
            monFlux<< intermerdiaire->getSomeone()->affiche();
        }
        
    
        monFlux<<"\n---------------------------\n";
        
        cout<<"\nEnregistrement terminé !"<<endl;
    }
    else // en cas d'erreur : pas de fichier, chemin incorrect ...
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}

// ////////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

/*17*/void read()
{
    string nomFichier;
    do {
        cout<<"\n Entrez le nom du fichier à lire (ou saisir 0 pour annuler l'opération)\n -> ";
        cin>>nomFichier;
        
        ifstream fichier(nomFichier);

        if(fichier) // L'ouverture s'est bien passé, on peut donc lire le fichier dans la console
        {
            string ligne; //Une variable pour stocker les lignes lues

            while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
            {
                cout << ligne << endl;
            }
        }
        else if (nomFichier!="0") // en cas d'erreur : pas de fichier, chemin incorrect ...
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
        }
        else cout << "Annulation en cours..."<<endl;
    } while ((nomFichier!="0"));
}



bool connexion_bdd(MYSQL*mysql)
{
//    struct connect {
//        string login;
//        string mdp;
//    };
//    vector<connect> connect;
    
    string login;
    string mdp;
    
   
    mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(mysql,"127.0.0.1" ,"root","root","scola",8889,NULL,0))
    {
        cout<<"----------------CONNEXION----------------"<<endl;
        cout<<"\nlogin: ";
        cin>>login;
        cout<<"\nmot de passe: ";
        cin>>mdp;
//        char requete[200];
//        strcpy(requete, "SELECT FROM users where login='");
//
//        strcat(requete,static_cast<char*>(login));
//        strcat(requete,"' and password='");
//        strcat(requete,static_cast<char*>(mdp));
//        strcat(requete,"'");

        //RequÍte qui sÈlectionne tout dans ma table scores
        mysql_query(mysql, "SELECT * FROM users");
        //DÈclaration des pointeurs de structure
        MYSQL_RES *result=new MYSQL_RES();
        
        MYSQL_ROW row;
        //unsigned int i = 0;
        unsigned int num_champs = 0;
        //int j =1;
        //On met le jeu de rÈsultat dans le pointeur result

        //result = mysql_store_result(mysql);
        result = mysql_use_result(mysql);
        //On rÈcupËre le nombre de champs
        //num_champs = mysql_num_fields(result);        //on stock les valeurs de la ligne choisie
        while ((row = mysql_fetch_row(result)))
        {
            //On déclare un pointeur long non signé pour y stocker la taille des valeurs
            unsigned long *lengths;
            //On stocke ces tailles dans le pointeur
            lengths = mysql_fetch_lengths(result);

            //On fait une boucle pour avoir la
            //On fait une boucle pour avoir la valeur de chaque champs
//            struct connect id;
//            id.login=row[1];
//            id.mdp=row[2];
//
//            connect.push_back(id);
            if ( (login==row[1]) && (mdp==row[2]) )
            {
                //LibÈration du jeu de rÈsultat
                mysql_free_result(result);
                return true;
            }
        }
        cout<<"erreur de login ou de mot de passe"<<endl;
        mysql_free_result(result);
        return false;
    }
    else
    {
        cout<<"\nUne erreur s'est produite lors de la connexion à la base de donnée !"<<endl;
        cout<<mysql_error(mysql);
        return false;
    }
}

void saveIntoBDD(Personne* tab[],int nb,MYSQL*mysql)
{
    int i = 0;
    char sql[256];
    mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(mysql,"127.0.0.1" ,"root","root","scola",8889,NULL,0))
    {
        while (i < nb) {
                if((typeid(**(tab+i)).name())==typeid(Employe).name())
             {
             //snprintf(sql, sizeof(sql), "INSERT INTO Employe(champs,champs1,champs2)values ('','','')",(*(tab+i))->get...(),(*(tab+i))->get...(),(*(tab+i))->get...());
             
             }
                if((typeid(**(tab+i)).name())==typeid(Etudiant).name())
             {
                //snprintf(sql, sizeof(sql), "INSERT INTO Etudiant (champs,champs1,champs2)values ('','','')",(*(tab+i))->get...(),(*(tab+i))->get...(),(*(tab+i))->get...());
             }
             if((typeid(**(tab+i)).name())==typeid(Eleve).name())
             {
                //snprintf(sql, sizeof(sql), "INSERT INTO Etudiant (champs,champs1,champs2)values ('','','')",(*(tab+i))->get...(),(*(tab+i))->get...(),(*(tab+i))->get...());
             }

            if(mysql_query(mysql, sql)) {
                fprintf(stderr, "%s\n", mysql_error(mysql));
            }
            i++;
        }
    }
}

Personne* loadFromBDD(int* nbElements,MYSQL*mysql)
{
    Personne* tabPersonneFromBDD = new Personne();
    mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(mysql,"127.0.0.1" ,"root","root","scola",8889,NULL,0))
//    if(mysql_real_connect(&mysql,"192.168.43.208","root","","tp1_cinema",0,NULL,0))
    {
        //RequÍte qui sÈlectionne tout dans ma table scores
        mysql_query(mysql, "select * from Etudiant and Employe");
        //DÈclaration des pointeurs de structure
        MYSQL_RES *result= NULL;
        
        MYSQL_ROW row;
        unsigned int i = 0;
        unsigned int num_champs = 0;
        *nbElements =0;
        //On met le jeu de rÈsultat dans le pointeur result

        result = mysql_store_result(mysql);
//        result = mysql_use_result(mysql);
        //On rÈcupËre le nombre de champs
        num_champs = mysql_num_fields(result);        //on stock les valeurs de la ligne choisie
        while ((row = mysql_fetch_row(result)))
        {
            //On déclare un pointeur long non signé pour y stocker la taille des valeurs
            unsigned long *lengths;
            //On stocke ces tailles dans le pointeur
            lengths = mysql_fetch_lengths(result);

            //On fait une boucle pour avoir la valeur de chaque champs
            ((tabPersonneFromBDD+*nbElements))->setPrenom(row[0]); //si la preiere colone est bien le prenom
            ((tabPersonneFromBDD+(*nbElements)))->setNom(row[1]);
            ((tabPersonneFromBDD+(*nbElements)))->setAge(atoi(row[2]));
            ((tabPersonneFromBDD+(*nbElements)))->setEmail(row[3]);
            
            //OPTIONNEL JUSTE UN AFFICAGE
            for(i = 0; i < num_champs; i++)
            {
                //On ecrit toutes les valeurs
                printf("\n%.*s ", (int) lengths[i], row[i] ? row[i] : "NULL");
            }
            printf("\n\n");
            //On incrÈmente la position du joueur
            (*nbElements)++;
        }
        //LibÈration du jeu de rÈsultat
        mysql_free_result(result);
    }
    else
    {
        printf("Une erreur s'est produite lors de la connexion à la BDD: %s", mysql_error(mysql));
        return NULL;
    }
    return tabPersonneFromBDD; //on renvoie la premiere case du tableau issu de la bdd
}
