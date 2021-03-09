//
//  elementListe.cpp
//  Gestion Personnel
//
//  Created by Jalal Sayarh on 09/02/2021.
//  Copyright © 2021 Jalal.consulting. All rights reserved.
//

#include "fonctions.hpp"


elementListe::elementListe(){}  /*constructeur par defaut*/
elementListe::~elementListe(){} 


/* Implémentation des Setters*/
void elementListe::setSomeone(Personne* p)   {  someone=p;  }

void elementListe::setNext(elementListe* e)  {  next=e;   }

void elementListe::setPrevious(elementListe* e){ previous=e;}


/* Implémentation des Getters*/
Personne* elementListe::getSomeone()    { return &(*someone);  }

elementListe* elementListe::getNext()   {  return next;   }

elementListe* elementListe::getPrevious(){  return previous;}

void elementListe::afficheListe()
{
    elementListe *intermediaire=new elementListe();
    
    intermediaire=this;
    
    cout<<getSomeone()->affiche(); //affichage de l'element de départ
    
    while (intermediaire->getNext()!=NULL) {       //tant qu'il existe un suivant dans la liste
        intermediaire = intermediaire->getNext();  //On se place sur le suivant en question
        cout<<(intermediaire->getSomeone())->affiche();    //Et on l'affiche
    }
}

