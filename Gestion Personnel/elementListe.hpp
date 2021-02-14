//
//  elementListe.hpp
//  Gestion Personnel
//
//  Created by Jalal Sayarh on 09/02/2021.
//  Copyright © 2021 Jalal.consulting. All rights reserved.
//

#ifndef elementListe_hpp
#define elementListe_hpp

#include "fonctions.hpp"

/*
    Initialement cette classe était une structure pour simplifier la phase "sprint" de la methode agile faite pour l'etape 9. A noté que la série de test avec les elementListe a ete réalisée lorsque la classe était une structure. Afin d'offrir de nouvelles possibilité elle a été tranformée en classe pour pouvoir développer des methodes specifique par la suite si le temps nous l'accorde, comme pour modifier voire supprimer un element de la liste avec l'ajout peut etre d'un compteur static. Affaire à suivre...
 */

class elementListe /* étape 9: partie liste chainée */
{
private:
    Personne *someone;                /* nécéssité d'un pointeur ici pour utiliser le polymorphisme plus tard */
    elementListe *next=NULL;         /* Pointera sur l'élement suiant; null par défaut*/
    elementListe *previous=NULL;
    
public:
    elementListe();
    ~elementListe();
    
    void setSomeone(Personne*);
    void setNext(elementListe*);
    void setPrevious(elementListe*);
    
    Personne* getSomeone();
    elementListe* getNext();
    elementListe* getPrevious();
    
    void afficheListe(); /* Afficher tous les élement de la liste a partir de l'adresse l'objet en question */
    
};

#endif /* elementListe_hpp */
