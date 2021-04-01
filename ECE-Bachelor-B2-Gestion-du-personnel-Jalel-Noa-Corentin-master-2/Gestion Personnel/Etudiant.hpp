//
//  Etudiant.hpp
//  Gestion Personnel
//


#ifndef Etudiant_hpp
#define Etudiant_hpp

#include "fonctions.hpp"

class Etudiant:public Personne
{
//encapsulation des parametres
private:
    string cursus;
    int anneeActuelle;
    
    
//prototypes des méthodes
public:
    //constructeurs
    Etudiant();
    Etudiant(string lePrenom, string leNom, int lAge,string adresseEmail,string leCursus,int lAnneeActuelle);
    
    //destructeur
    virtual ~Etudiant();
    
    //getters
    int getAnneeCursus();
    string getCursus() const;
    
    
    //setters
    void setAnneeCursus(int lAnneeActuelle);
    void setCursus(string const leCursus);
    
    //méthodes
    virtual string affiche();
    void newEtudiant();
    
    
};

#endif /* Etudiant_hpp */
