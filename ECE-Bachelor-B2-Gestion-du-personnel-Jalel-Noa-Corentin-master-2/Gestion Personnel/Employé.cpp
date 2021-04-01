//  Employé.cpp
//  Gestion Personnel
//


#include "fonctions.hpp"

//constructeurs
Employe::Employe(){}
Employe::Employe(string lePrenom, string leNom, int lAge, string adresseEmail, string leNomDep, int leNumBureau):Personne(lePrenom, leNom, lAge, adresseEmail), nomDep(leNomDep), numBureau(leNumBureau){}


// implémentation destructeur
Employe::~Employe(){
    //cout<<"Destructeur de la clase Employé"<<endl;
}




//getters
string Employe::getNomDep() const
{
    return nomDep;
}
int Employe::getNumBureau() const
{
    return numBureau;
}


//setters
void Employe::setNumBureau(const int leNumBureau)
{
    numBureau=leNumBureau;
}
void Employe::setNomDep(const string leNomDep)
{
    nomDep=leNomDep;
}

//methodes

string Employe::affiche() //affichage des informations
{
    return (Personne::affiche()+static_cast<string>("Département: ")+static_cast<string>(getNomDep())+static_cast<string>("\nBureau n°")+to_string(getNumBureau())+static_cast<string>("\n"));
    
}

void Employe::newEmploye() //saisie d'un nouvel employé
{
    Personne::newPerson();
    
    cout<<"\n Département: ";
    cin.clear();
    cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
    getline(cin, nomDep); // on veux toute la chaine si jamais il y a un espace saisi
    
    cout<<"\n Numéro de bureau : ";
    while(!(cin >> numBureau) || numBureau < 1 || numBureau > 100) 
    {
       if (cin.fail()) // si la saisie n'est pas un nombre on affiche une erreur et on demande de resaisir
       {
           cout << "Saisie incorrecte, ressaisissez : ";
           cin.clear();
           cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
       }
       else // sinon, la valeur n'est pas dans les paramètres autorisés donc on redemande la saisie
       {
           cout << "Le numéro de bureau doit être compris entre 1 et 100, ressaisissez : ";
       }
    }
}


