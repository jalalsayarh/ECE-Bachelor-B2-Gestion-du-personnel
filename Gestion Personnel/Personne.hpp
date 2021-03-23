//
//  Personne.hpp
//  Gestion Personnel
//


#ifndef Personne_hpp
#define Personne_hpp

#include "fonctions.hpp"

using namespace std;


class Personne
{
protected:
    string prenom;
//encapsulation des parametres
private:
    
    string nom;
    string email;
    int age;
    
    
//prototypes des methodes
public:
    
    //constructeurs
    Personne();
    Personne(string lePrenom, string leNom, int lAge,string adresseEmail);
    
    //destructeur
    virtual ~Personne();
    
    //getters
    string getPrenom();
    string getNom();
    int getAge();
    string getEmail();
    
    
    //setters
    void setPrenom(string lePrenom);
    void setNom(string leNom);
    void setAge(int lAge);
    void setEmail(string adresseEmail);
    
    
    
    //méthodes
    virtual string affiche();
    void newPerson();       //Saisie de toutes les informations d'une personne
    bool operator==(const Personne &);
};



#endif /* Personne_hpp */
