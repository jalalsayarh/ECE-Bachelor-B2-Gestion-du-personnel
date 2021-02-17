//
//  Eleve.hpp
//  Gestion Personnel
//


#ifndef Eleve_hpp
#define Eleve_hpp

#include "fonctions.hpp"

#define nbMaxUe 10     //nombre max d'UE que peux suivre un étudiant

/*struct note
{
    string UE;
    int note;
};
*/

class Eleve:public Etudiant
{
//encapsulation des paramètres
private:
    
    int nbrUE;
    float note[10];//vector<float> notes;
    string UE[10];

//prototypes des méthodes
public:
    //constructeurs
    Eleve();
    Eleve(string lePrenom, string leNom, int lAge,string adresseEmail,string leCursus,int lAnneeActuelle, int NbUE);
    
    //destructeur
    ~Eleve();
    
    //getters
    int getnbrUE();
    float* getnote();
    string* getUE();
    
    //setters
    void setnbrUE(int nbUe);
    void setnote();
    void setUE(string* lUE);
    
    //méthodes
    /*virtual*/ string affiche();
    void newEleve();
    void modifNote();

};


#endif /* Eleve_hpp */
