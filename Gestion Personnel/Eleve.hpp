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
    float *note=NULL;//[nbMaxUe]= {21, 21, 21, 21, 21, 21, 21, 21, 21, 21};//vector<float> notes;
    string *UE=new string();//[nbMaxUe];

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
    void setnote(float* lesNotes);
    void setUE(string* lUE);
    
    //méthodes
    virtual string affiche();
    void saisieNote();
    void newEleve();
    void modifNote();

};


#endif /* Eleve_hpp */
