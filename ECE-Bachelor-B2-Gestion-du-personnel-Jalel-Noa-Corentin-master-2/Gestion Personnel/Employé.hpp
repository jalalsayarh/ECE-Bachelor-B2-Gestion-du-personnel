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
    string getNomDep() const;
    int getNumBureau() const;
    
    
    //setters
    void setNumBureau(const int leNumBureau);
    void setNomDep(const string leNomDep);
    
    //méthodes
    virtual string affiche();
    void newEmploye();
};


#endif /* Employe__hpp */
