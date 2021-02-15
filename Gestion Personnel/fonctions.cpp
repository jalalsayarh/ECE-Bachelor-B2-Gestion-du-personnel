//
//  fonctions.cpp
//  Gestion Personnel
//

#include <string.h>
#include "fonctions.hpp"

/*          Résumé des Fonctions
 
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
        Les fonctions 9 et 10 et recoivent en parametres l'adresse du vecteur en question
 
 9-Saisie des élement d'un vecteur de type Personne*.
 
 10-On affiche tous les éléments d'un vecteur de type Personne*.
 

 11-Saisie d'une liste d'étudiant et d'employé. Recois en parametre l'adresse du premier element de la liste (permet aussi l'ajout d'un nouvel element auquel cas on peut envoyer en parametre un des element de la liste )
 
                 ********************************************************************************
                                         ETAPE 10 DU PROJET
 12-Ecriture dans un fichier. ATTENTION quand on appelle la fonction plusieurs fois pour le meme fichier, la derniere saisie écrase toujours la précedente
 
 13-Lecture du contenu d'un fichier
 */



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
        dynamic_cast<Personne*>(*(tab+i))->affiche();
    }
}


/*4*/ void saisieTab_Personne(Personne* tab[],int nombre)

{
    cout<<"---SAISIE DU TABLEAU---\n";
    string choixPersonne;
    for (int i=0; i<nombre; i++) {
        do{
            cout<<"\nSaisir [1] pour ajouter un(e) Etudiant(e)\nSaisir [2] pour ajouter un(e) Employé(e)\n->";
            cin>>choixPersonne;
        }while ((choixPersonne!="1")&&(choixPersonne!="2"));

        if (choixPersonne=="1") {
            Etudiant* LeEtudiant= new Etudiant();
            auto *etu = dynamic_cast<Etudiant *>(LeEtudiant);;
            etu->newEtudiant();
            *(tab+i)=LeEtudiant;
        }
        else{
            Employe *LeEmploye= new Employe();
            auto *emp = dynamic_cast<Employe*>(LeEmploye);
            emp->newEmploye();
            *(tab+i)=LeEmploye;
        }
    }
    //cout<<"---Fin de la fonction---\n";   /* Point de repère*/
}


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
                        if ((*(tab+i))->getNom()==rechercheNom)
                        {
                            compteur++;
                            cout<<"-------------------------\n";
                            (*(tab+i))->affiche();
                        }
                        if (compteur==0) {
                            cout<<"\n Désolé; Aucun élément ne correspond à votre recherche\n";
                        }
                        else cout<<"-------------------------\n";
                    }
                    
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
                        if ((*(tab+i))->getPrenom()==recherchePrenom)
                        {
                            compteur++;
                            cout<<"-------------------------\n";
                            (*(tab+i))->affiche();
                        }
                        if (compteur==0) {
                            cout<<"\n Désolé; Aucun élément ne correspond à votre recherche\n";
                        }
                        else cout<<"-------------------------\n";
                    }
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
                        if ((*(tab+i))->getEmail()==rechercheMail)
                        {
                            compteur++;
                            cout<<"-------------------------\n";
                            (*(tab+i))->affiche();
                        }
                        if (compteur==0) {
                            cout<<"\n Désolé; Aucun élément ne correspond à votre recherche\n";
                        }
                        else cout<<"-------------------------\n";
                    }
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
                        if ((*(tab+i))->getAge()==rechercheAge)
                        {
                            compteur++;
                            cout<<"-------------------------\n";
                            (*(tab+i))->affiche();
                        }
                        if (compteur==0) {
                            cout<<"\n Désolé; Aucun élément ne correspond à votre recherche\n";
                        }
                        else cout<<"-------------------------\n";
                    }
                    break;
                }
                    
                case 5: /**Rechercher une personne*/
//                {
//                    Personne p;
//                    p.newPerson();
//                    for (int i=0; i<nb; i++)
//                    {
//                        if (p==(**(tab+i)))
//                            (*tab+i)->affiche();
//                        else
//                            cout<<"\nAucun élément ne correspond à votre recherche";
//                    }
//                }
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






/*9*/void saisie_Vecteur_Personne(vector<Personne*> *lesGens)
{
    Personne *intermediaire=new Personne();
    string choixPersonne;
    
    choixPersonne=blindage_Saisie_ChoixBinaire("\nSaisir [1] pour ajouter un(e) Etudiant(e)\nSaisir [2] pour ajouter un(e) Employé(e)\n->","1","2");

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

    else
    {
        Employe *LeEmploye= new Employe();
        auto *emp = dynamic_cast<Employe*>(LeEmploye);
        emp->newEmploye();
        intermediaire=LeEmploye;
    }
    
    lesGens->push_back(intermediaire);
}



/*10*/void affiche_Vecteur(vector<Personne*> *lesGens)
{
    for (Personne* gens : *lesGens)
    {
        gens->affiche();
    }
}

/*11*/void saisie_Liste_Personne(elementListe* start)
{
    string choixPersonne;
    elementListe* intermediaire= new elementListe();
    elementListe *e= new elementListe();
    
    
    do{
        cout<<"\nSaisir [1] pour ajouter un(e) Etudiant(e)\nSaisir [2] pour ajouter un(e) Employé(e)\n->";
        cin>>choixPersonne;
    }while ((choixPersonne!="1")&&(choixPersonne!="2"));

    if (choixPersonne=="1")
    {
        Etudiant *LeEtudiant=new Etudiant();
        auto *etu = dynamic_cast<Etudiant *>(LeEtudiant);
        etu->newEtudiant();
        e->setSomeone(LeEtudiant);
    }

    else
    {
        Employe *LeEmploye= new Employe();
        auto *emp = dynamic_cast<Employe*>(LeEmploye);
        emp->newEmploye();
        //lesGens.push_back(LeEmploye);
        e->setSomeone(LeEmploye);
    }
    
    if (start->getSomeone()==NULL) { // si il n'y pas encore d'element dans la liste
        start->setSomeone(e->getSomeone());          //On sauvegarde le premier element de la liste dans un pointeur
    } else{
       intermediaire=start; //on se place au premier element de la liste
       while(intermediaire->getNext()!= NULL)
       {
           intermediaire = (intermediaire->getNext()); /* On va jusqu'au dernier élement */
       }
        e->setPrevious(intermediaire);
        intermediaire->setNext(e);
    }
}



/*12*/void write(string nomFichier)
{
    cout<<"\n----fonction write-----";
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
    
    string message;
    // Déclaration d'un flux qui permet d'écrire dans un fichier
    if(monFlux) // on teste pour voir si tout est ok
    {
        cout<<"\n Tout est ok pour le fichier"<<endl;
        // modifier l'écriture pour pouvoir écrire dans le fichier les informations relatives
        monFlux << "Test fichier." << endl;
        int age=22;
        monFlux << "J'ai " << age << " ans." << endl;
        monFlux<< "pas la peine de verifier, tout est okay on a dit"<<endl;
        //message="\nEnregistremenet dans le fichier okay";
    }
    else // en cas d'erreur : pas de fichier, chemin incorrect ...
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
        
}

/*13*/void read(string nomFichier)
{
    cout<<"\n----fonction read-----\n\n";
    // Lecture d'un fichier
    ifstream fichier("/Users/jalalsayarh/Desktop/fichertestProjetAutonome.txt");

    if(fichier) // L'ouverture s'est bien passé, on peut donc lire le fichier dans la console
    {
        string ligne; //Une variable pour stocker les lignes lues

        while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {
            cout << ligne << endl;
        }
    }
    else // en cas d'erreur : pas de fichier, chemin incorrect ...
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
}

//bool operator==(Personne a, Personne b)
//{
//    return (a.getPrenom() == b.getPrenom() && a.getNom() == b.getNom() && a.getAge() == b.getAge());
//}
