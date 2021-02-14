//
//  fonctions.hpp
//  Gestion Personnel
//


#ifndef fonctions_hpp
#define fonctions_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <limits>
#include <regex> // on doit inclure la bibliothèque regex afin de faire les vérifications sur les emails
#include <string>
#include <cstring>
#include <vector>

#include "Personne.hpp"
#include "Employé.hpp"
#include "Etudiant.hpp"
#include "Eleve.hpp"
#include "elementListe.hpp"

using namespace std;

string blindage_Saisie_ChoixBinaire(string phrase, string choix1,string choix2);
int blindage_Saisie_ChoixIntervalle(string phrase, int borne1 ,int borne2); 

/* Etape 4*/
void saisieTab_Personne(Personne* tab[],int nombre);    /** Saisie d'un tableau de personne envoyé en paramètre pour un nombre int de case envoyé en deuxieme parametre*/
void afficheTab_Personne(Personne* tab[],int nombre);   /**Affichage d'un tableau de personne envoyé en paramètre pour un nombre int de case envoyé en deuxieme parametre*/



/* Etape 9*/

void saisie_Vecteur_Personne(vector<Personne*> *lesGens);
void affiche_Vecteur(vector<Personne*> *lesGens);

void saisie_Liste_Personne(elementListe* start);    /** Saisie d'une liste de personne à partir d'un element de la liste donné comme point de départ */


/* Etae 10*/
void write();   /*écriture dans un fichier */
void read();    /* fonctions de lecture */



#endif /* fonctions_hpp */
