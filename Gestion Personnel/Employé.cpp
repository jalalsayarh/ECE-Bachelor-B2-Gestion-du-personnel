//  Employé.cpp
//  Gestion Personnel
//


#include "fonctions.hpp"

//constructeurs
Employe::Employe(){}
Employe::Employe(string lePrenom, string leNom, int lAge,string adresseEmail,string leNomDep,int leNumBureau):Personne(lePrenom, leNom, lAge, adresseEmail),nomDep(leNomDep),numBureau(leNumBureau){}





// implémentation destructeur
Employe::~Employe(){
    //cout<<"Destructeur de la clase Employé"<<endl;
}




//getters
string Employe::getNomDep()
{
    return nomDep;
}
int Employe::getNumBureau()
{
    return numBureau;
}


//setters
void Employe::setNumBureau(int leNumBureau)
{
    numBureau=leNumBureau;
}
void Employe::setNomDep(string leNomDep)
{
    nomDep=leNomDep;
}

//methodes

void Employe::affiche() //affichage des informations
{
    Personne::affiche();
    cout<<"Département: "<<getNomDep()<<"\nBureau n°"<<getNumBureau()<<endl;
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


