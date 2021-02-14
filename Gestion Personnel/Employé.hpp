//
//  Employé.hpp
//  Gestion Personnel
//

#ifndef Employe__hpp
#define Employe__hpp

#include "fonctions.hpp"
using namespace std;

class Employe:public Personne
{
//encapsulation des paramètres
private:
    string nomDep;
    int numBureau;
    
    
//prototypes des méthodes
public:
    //constructeurs
    Employe();
    Employe(string lePrenom, string leNom, int lAge,string adresseEmail,string leNomDep,int leNumBureau);
    
    // destructeur
    ~Employe();
    
    //getters
    string getNomDep();
    int getNumBureau();
    
    
    //setters
    void setNumBureau(int leNumBureau);
    void setNomDep(string leNomDep);
    
    //méthodes
    void affiche();
    void newEmploye();
};


#endif /* Employe__hpp */
