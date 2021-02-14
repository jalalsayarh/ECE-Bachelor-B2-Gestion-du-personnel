//
//  fonctions.cpp
//  Gestion Personnel
//


#include "fonctions.hpp"

/*          Résumé des Fonctions
 
 1-Blinde une saisie dont le choix est LIMITé A DEUX REPONSES POSSIBLE. Le premier string envoyé a la fonction correspond au message qui s'affichera à l'écran lorsque l'utilisateur devrai saisir son choix et les deux autres font références aux valeur des deux choix qu'aura l'utilisateur et renvoie en string la valeur saisie par l'utilisateur
 
 2-Blinde une saisie dont le choix est un INTERVALE etre deux valeur. Le premier string envoyé a la fonction correspond au message qui s'affichera à l'écran lorsque l'utilisateur devrai saisir son choix et les deux autres parametres font références aux valeur des deux bornes qui limite le choix qu'aura l'utilisateur et renvoie en int la valeur saisie par l'utilisateur. A noté, l'ordre des bornes n'a pas d'importance, la fonction se charge de trier les bornes
 
 
 3-Affiche le contenu d'un tableau de type Personne*. Recois respectivement en parametres l'adresse du tableau à afficher et la dimension du tableau en question
 
 4-Permet la saisie d'un tableau de type Personne*. Recois respectivement en parametres l'adresse du tableau à afficher et la dimension du tableau en question
 
 
 
 5-Saisie des élement d'un vecteur de type Personne*. On transmet l'adresse du vesteur en parametre
 
 6-On affiche tous les éléments d'un vecteur de type Personne*. On transmet l'adresse du vecteur en parametre
 
 7-Saisie d'une liste de Personne, transmettre en parametre le premier element de la liste.
 
 
 
 8-Ecriture dans un fichier. ATTENTION quand on appelle la fonction plusieurs fois pour le meme fichier, la derniere saisie écrase toujours la précedente
 
 9-Lecture du contenu d'un fichier
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



/*5*/void saisie_Vecteur_Personne(vector<Personne*> *lesGens)
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



/*6*/void affiche_Vecteur(vector<Personne*> *lesGens)
{
    for (Personne* gens : *lesGens)
    {
        gens->affiche();
    }
}

/*7*/void saisie_Liste_Personne(elementListe* start)
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



/*8*/void write()
{
    cout<<"\n----fonction write-----";
    /*
    Sur un fichier déja existant
    Fichier .txt
    Ecriture dans un fichier
    */
      
    // faire une saisie de chemin par l'utilisateur
    // préciser à l'utilisateur qu'il doit avoir un fichier crée au préalable
    string const nomFichier("/Users/jalalsayarh/Desktop/fichertestProjetAutonome.txt");
    ofstream monFlux(nomFichier.c_str());
    
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

/*9*/void read()
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
