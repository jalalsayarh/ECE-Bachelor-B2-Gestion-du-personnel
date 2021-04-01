//
//  Eleve.cpp
//  Gestion Personnel
//


#include "fonctions.hpp"


//constructeurs
Eleve::Eleve()
{
    float f=21;
    note=&f;
}

Eleve::Eleve(string lePrenom, string leNom, int lAge, string adresseEmail, string leCursus,int lAnneeActuelle, int NbUE):Etudiant(lePrenom, leNom, lAge, adresseEmail, leCursus, lAnneeActuelle), nbrUE(NbUE){}

// implémentation destructeur
Eleve::~Eleve(){
    //cout<<"Destructeur de la clase Eleve"<<endl;
    //    for (int i=0; i<nbrUE; i++) {
    //        delete note+i;
    //        delete UE+i;
    //    }
    delete note;
    delete UE;
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

void Eleve::setnote(float* lesNotes)
{
    note=lesNotes;
//    for (int i=0; i<nbrUE; i++)
//    {
//        note[i]=lesNotes[i];
//    }
}

void Eleve::setUE(string *lUE)
{
    UE=lUE;
//    for (int i=0; i<nbrUE; i++)
//    {
//        UE[i]=lUE[i];
//    }
    
    /*On verifie ci dessous que le setter a bien fonctionné */
//    for (int i=0; i<nbrUE; i++)
//    {
//        cout<<"UE "<<i<<" : "<<UE[i]<<endl;
//    }
    
}


//méthodes

void Eleve::saisieNote() /*sur le tableau de notes de l'eleve*/
{
    cout<<"--Saisie des notes--\n\n";
    note=new float();
    for (int i=0; i<nbrUE; i++)
    {
        cout<< "Note /20 en "<<*(UE+i)<<": ";
        while(!(cin >> *(note+i)) || *(note+i) < 0 || *(note+i) > 20) /* on blinde grossièrement (utilisation de regex pour etre plus précis)*/
        {
           if (cin.fail()) /* si la saisie n'est pas un nombre on affiche une erreur et on demande de resaisir*/
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


string Eleve::affiche() //affichage des information relative a un eleve
{
    string affichage = Personne::affiche()+static_cast<string>("UE suivies: ")+to_string(nbrUE);
    if (note!=NULL) {
        affichage = affichage +static_cast<string>("\n\nNotes de l'élève: \n" );
        for (int i=0; i<nbrUE; i++) {
            affichage = affichage + static_cast<string>("UE") + to_string(i+1)+static_cast<string>(" (" ) + static_cast<string>(*(UE+i)) + static_cast<string>(") : ") + to_string(*(getnote()+i)) + static_cast<string>("/20\n");
        }
        
        affichage = affichage + static_cast<string>("\nMoyenne des générale : ") + to_string(moyenneNote());
        
    }
    
    return affichage;
    
}

void Eleve::newEleve()
{
    Etudiant::newEtudiant();
    
    cout<<"\n Combien d'Unités d'Enseignements l'éleve "<<prenom<<" "<<Personne::getNom()<<" suit-il/elle ?\n ->";
    while(!(cin >> nbrUE) || nbrUE < 1 ) // on blinde grossièrement (utilisation de regex pour etre plus précis)
    {
       if (cin.fail()) // si la saisie n'est pas un nombre on affiche une erreur et on demande de resaisir
       {
           cout << "Error 404, recommencez : ";
           cin.clear();
           cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
       }
       else // sinon, la valeur n'est pas dans les paramètres autorisés donc on redemande la saisie
       {
           cout<<"   Attention !\nS'il ne suit pas d'UE c'est qu'il n'est pas élève ;p Veillez à saisir un nombre supérieur a 1\n ->";
       }
    }
    
    cout<<"--Saisie des UE--"<<endl;
    //string lesUE[nbrUE];
    for (int i=0; i<nbrUE; i++) {
        cout<<"UE "<<i+1<<" : ";
        cin>>*(UE+i);
    }
    //setUE(lesUE);
    
    string choix=blindage_Saisie_ChoixBinaire("\nVoulez vous saisir les notes de l'élève dans l'immédiat ? (oui/non)\n->", "oui", "non");
    
    if (choix=="oui") {
        saisieNote();
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
    cout<<"\nMoyenne des notes : "<<moyenneNote()<<endl;
    // fin de modification
    
    int choix=blindage_Saisie_ChoixIntervalle("\n[1]-Modifier toutes les notes\n[2]-Modifier une seule note\n ->", 1, 2);
    
    if(choix==1) 
        saisieNote();
    
    else{

        if (note==NULL) {
            cout<<"\n"<<prenom<<" "<<getNom()<<" n'a pas encore de note. Aucune modification possible"<<endl;
        }
        else
        {
            /* On affiche d'abord toutes les notes*/
            cout<<"\n\n---Liste des notes---\n";
            for (int i=0; i<getnbrUE(); i++) {
                //cout<<"UE"<<i+1<<" ("<<(getUE()+i)<<") : "<<*(getnote()+i)<<"/20"<<endl;
                cout<<"UE"<<i+1<<" ("<<*(UE+i)<<") : "<<setprecision(2)<<(*(note+i))<<"/20\n";
            }
            
             float moy=0;
             for (int i=0; i<nbrUE; i++) {
                 moy = moy + *(note+i);
             }
             moy = moy / nbrUE;
             cout<<"\nMoyenne des générale : "<<moy<<endl;
            
            int choix=blindage_Saisie_ChoixIntervalle("\n[1]-Modifier toutes les notes\n[2]-Modifier une seule note\n ->", 1, 2);
            
            if(choix==1)
                saisieNote();
            
            else
            {
                do{
                    int indiceModif;
                    
                    cout<<"\nEntrez le numéro de l'UE de la note à modifier \n->";
                    cin>>indiceModif;
                    indiceModif = indiceModif-1; /* on facilite les calcul par la suite en remettant la valeur saisie par l'utilisateur en un "veritable" indice*/
                    
                    while ((indiceModif<0)||(indiceModif>nbrUE))
                    {
                        cout<<"Attention! Saisie incorrecte; ";
                        if (indiceModif<0)
                            cout<<"\nIl faut impérativement saisir une valeur positive\n";
                        cout<<"Référez vous a la liste ci-dessus\n->";
                        cin>>indiceModif;
                        indiceModif -= indiceModif;
                    }
                    
                    cout<< "Note /20 en "<<*(UE+indiceModif)<<": ";
                    
                    /* on blinde grossièrement (utilisation de regex pour etre plus précis)*/
                    while(!(cin >> *(note+indiceModif)) || *(note+indiceModif) < 0 || *(note+indiceModif) > 20)
                    {
                       if (cin.fail()) /* si la saisie n'est pas un nombre on affiche une erreur et on demande de resaisir*/
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
    }
}

float Eleve::moyenneNote()
{
    float moy=0;
    for (int i=0; i<getnbrUE(); i++) {
        moy = moy + *(getnote());
    }
    int y = getnbrUE();
    moy = moy / y;
    
    return moy;
}
