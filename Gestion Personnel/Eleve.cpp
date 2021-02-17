//
//  Eleve.cpp
//  Gestion Personnel
//


#include "fonctions.hpp"



//constructeurs
Eleve::Eleve(){}

Eleve::Eleve(string lePrenom, string leNom, int lAge,string adresseEmail,string leCursus,int lAnneeActuelle, int NbUE):Etudiant(lePrenom, leNom, lAge, adresseEmail, leCursus, lAnneeActuelle),nbrUE(NbUE){}

// implémentation destructeur
Eleve::~Eleve(){
    //cout<<"Destructeur de la clase Eleve"<<endl;
    
}

//getters
int Eleve::getnbrUE() {return nbrUE;}

float* Eleve::getnote()
{
    /* Morceau de code initial non fonctionnel
     
    for (int i=0; i<nbrUE; i++)
    {
        cout<<note[i]<<endl;
    }
     */
    return note; /* On renvoie la premiere case du tableau */
}

string* Eleve::getUE() { return UE; }


//setters
void Eleve::setnbrUE(int nbUe) /*sur le nombre d'UE suivi par l'eleve*/
{
    nbrUE=nbUe;
}

void Eleve::setnote() /*sur le tableau de notes de l'eleve*/
{
    cout<<"--Saisie des notes--\n\n";
    
    for (int i=0; i<nbrUE; i++)
    {
        cout<< "Note /20 en "<<UE[i]<<": ";
        while(!(cin >> note[i]) || note[i] < 0 || note[i] > 20) /* on blinde grossièrement (utilisation de                                                          regex pour etre plus précis)*/
        {
           if (cin.fail()) /* si la saisie n'est pas un nombre on affiche une erreur et on demande de                       resaisir*/
           {
               cout << "!Error 404! Ressaisissez\n -> ";
               cin.clear();
               cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
           }
           else /*sinon, la valeur n'est pas dans les paramètres autorisés donc on redemande la saisie*/
           {
               cout<<"   Attention !\n Vous devez d'abord ramener la note sur 20\n ->";
           }
        }
    }
}

void Eleve::setUE(string* lUE)
{
    for (int i=0; i<nbrUE; i++)
    {
        UE[i]=lUE[i];
    }
    
    /*On verifie ci dessous que le setter a bien fonctionné */
//    for (int i=0; i<nbrUE; i++)
//    {
//        cout<<"UE "<<i<<" : "<<UE[i]<<endl;
//    }
    
}

//méthodes
string Eleve::affiche() //affichage des information relative a un eleve
{
    string affichage = Personne::affiche()+static_cast<string>("UE suivies: ")+to_string(nbrUE)+static_cast<string>("\n\nNotes de l'élève: \n" );

    for (int i=0; i<nbrUE; i++) {
        affichage = affichage + static_cast<string>("UE")+to_string(i+1)+static_cast<string>(" (" ) + static_cast<string>(*(getUE()+i)) + static_cast<string>(") : ")+to_string(*(getnote()+i))+static_cast<string>("/20\n");
    }
    return affichage;
}

void Eleve::newEleve()
{
    Etudiant::newEtudiant();
    
    cout<<"\n Combien d'Unités d'Enseignements l'éleve "<<Personne::getPrenom()<<" "<<Personne::getNom()<<" suit-il/elle ?\n ->";
    while(!(cin >> nbrUE) || nbrUE < 1 || nbrUE > 10) // on blinde grossièrement (utilisation de regex pour etre plus précis)
    {
       if (cin.fail()) // si la saisie n'est pas un nombre on affiche une erreur et on demande de resaisir
       {
           cout << "Error 404, recommencez : ";
           cin.clear();
           cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
       }
       else // sinon, la valeur n'est pas dans les paramètres autorisés donc on redemande la saisie
       {
           cout<<"   Attention !\nUn élève ne peut suivre un nombre maximum de 10 Unités d'Enseignements\n Assurez vous de saisir une valeur comprise entre 1 et 10\n ->";
       }
    }
    
    cout<<"--Saisie des UE--"<<endl;
    
    for (int i=0; i<nbrUE; i++) {
        cout<<"UE "<<i+1<<" : ";
        cin>>UE[i];
    }
    
    string choix=blindage_Saisie_ChoixBinaire("\nVoulez vous saisir les notes de l'élève dans l'immédiat ? (oui/non)n->", "oui", "non");
    
    if (choix=="oui") {
        setnote();
    }
}


/* Modification d'une ou de toutes les notes de l'élève */
void Eleve::modifNote()
{
    /* On affiche d'abord toutes les notes*/
    cout<<"\n\n---Liste des notes---\n";
    for (int i=0; i<getnbrUE(); i++) {
           cout<<"UE"<<i+1<<" ("<<*(getUE()+i)<<") : "<<*(getnote()+i)<<"/20"<<endl;
    }
    
    int choix=blindage_Saisie_ChoixIntervalle("\n[1]-Modifier toutes les notes\n[2]-Modifier une seule note\n ->", 1, 2);
    
    if(choix==1) 
        setnote();
    
    else
    {
        do{
            int indiceModif;
            
            cout<<"\nEntrez le numéro de l'UE de la note à modifier \n->";
            cin>>indiceModif;
            indiceModif = indiceModif-1; /* on facilite les calcul par la suite en remettant la valeur                                      saisie par l'utilisateur en un "veritable" indice*/
            
            while ((indiceModif<0)||(indiceModif>nbrUE))
            {
                cout<<"Attention! Saisie incorrecte; ";
                if (indiceModif<0)
                    cout<<"\nIl faut impérativement saisir une valeur positive\n";
                cout<<"Référez vous a la liste ci-dessus\n->";
                cin>>indiceModif;
                indiceModif -= indiceModif;
            }
            
            cout<< "Note /20 en "<<UE[indiceModif]<<": ";
            
            /* on blinde grossièrement (utilisation de regex pour etre plus précis)*/
            while(!(cin >> note[indiceModif]) || note[indiceModif] < 0 || note[indiceModif] > 20)
            {
               if (cin.fail()) /* si la saisie n'est pas un nombre on affiche une erreur et on demande de                       resaisir*/
               {
                   cout << "!Error 404! Ressaisissez\n -> ";
                   cin.clear();
                   cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
               }
               else /*sinon, la valeur n'est pas dans les paramètres autorisés donc on redemande la saisie*/
               {
                   cout<<"   Attention !\n Vous devez d'abord ramener la note sur 20\n ->";
               }
            }
            
            for (int i=0; i<getnbrUE(); i++) {
                   cout<<"UE"<<i+1<<" ("<<*(getUE()+i)<<") : "<<*(getnote()+i)<<"/20"<<endl;
            }
            
            
            cout<<"\nVoulez vous modifier une autre notes ? (1 pour Oui // 0 pour Non)\n ->";
            
            while(!(cin >> choix) || ((choix != 1) && (choix != 0))) // on blinde grossièrement (utilisation de regex pour etre plus précis)
            {
               if (cin.fail()) // si la saisie n'est pas un nombre on affiche une erreur et on demande de resaisir
               {
                   cout << "Error 404, recommencez : ";
                   cin.clear();
                   cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
               }
               else // sinon, la valeur n'est pas dans les paramètres autorisés donc on redemande la saisie
               {
                   cout<<"   Attention !\nVérifiez l'othographe de la saisie! \n ->";;
               }
            }
        } while (choix==1);
    }
}


