//
//  Etudiant.cpp
//  Gestion Personnel
//


#include "fonctions.hpp"

// CONSTRUCTEURS
Etudiant::Etudiant(){}
Etudiant::Etudiant(string lePrenom, string leNom, int lAge,string adresseEmail,string leCursus,int lAnneeActuelle):Personne(lePrenom, leNom, lAge, adresseEmail),cursus(leCursus),anneeActuelle(lAnneeActuelle){}

// implémentation destructeur
Etudiant::~Etudiant(){
    //cout<<"Destructeur de la clase Etudiant"<<endl;
}

//getters
int Etudiant::getAnneeCursus()
{
    return anneeActuelle;
}
string Etudiant::getCursus()
{
    return cursus;
}


//setters
void Etudiant::setAnneeCursus(int lAnneeActuelle)
{
    anneeActuelle=lAnneeActuelle;
}
void Etudiant::setCursus(string leCursus)
{
    cursus=leCursus;
}

//méthodes
string Etudiant::affiche()
{
    return (Personne::affiche()+static_cast<string>("Cursus: ")+static_cast<string>(getCursus())+static_cast<string>("\nAnnée actuelle dans le cursus: ")+to_string(getAnneeCursus())+static_cast<string>("\n"));
}

void Etudiant::newEtudiant()
{
    Personne::newPerson();
    
    cout<<"\n Saisissez le cursus de l'étudiant : ";
    cin.clear();
    cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
    getline(cin,cursus); // on veux toute la chaine si jamais il y a un espace saisi
    
    cout<<"\n Saisissez l'année actuelle dans le cursus : ";
    while(!(cin >> anneeActuelle) || anneeActuelle < 1 || anneeActuelle > 5) // on blinde grossièrement (utilisation de regex pour etre plus précis)
    {
       if (cin.fail()) // si la saisie n'est pas un nombre on affiche une erreur et on demande de resaisir
       {
           cout << "         Saisie incorrecte, recommencez : ";
           cin.clear();
           cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
       }
       else // sinon, la valeur n'est pas dans les paramètres autorisés donc on redemande la saisie
       {
           cout << "         Un étudiant ne peut être qu'en 5e année maximum, recommencez : ";
       }
    }
}

//Destructeur
//Etudiant::~Etudiant(){}
