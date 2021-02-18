//
//  fonctions.hpp
//  Gestion Personnel
//


#ifndef fonctions_hpp
#define fonctions_hpp

#include <string.h>
#include <stdlib.h>
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
void tri_tab_personne_nom(Personne* tab[],int nb);
void tri_tab_personne_prenom(Personne* tab[],int nb);
void tri_tab_personne_age(Personne* tab[],int nb);
void recherche_personne_in_tab(Personne* tab[],int nb);


/* Etape 9*/

void saisie_Vecteur_Personne(vector<Personne*> *lesGens);
void affiche_Vecteur(vector<Personne*> *lesGens);
void tri_vecteur_personne_nom(vector<Personne*> *lesGens);
void tri_vecteur_personne_prenom(vector<Personne*> *lesGens);
void tri_vecteur_personne_age(vector<Personne*> *lesGens);
void recherche_vecteur(vector<Personne*> *lesGens);


void saisie_Liste_Personne(elementListe* start);    /** Saisie d'une liste de personne à partir d'un element de la liste donné comme point de départ */
void tri_liste_personne_nom(elementListe* start);
void tri_liste_personne_prenom(elementListe* start);
void tri_liste_personne_age(elementListe* start);
void recherche_liste(elementListe* start);

/* Etae 10*/
void write(string nomFichier, Personne* tab[], int nb );   /*écriture dans un fichier */
void write(string nomFichier, vector<Personne*> *lesGens);
void read(string nomFichier);    /* fonctions de lecture */


#endif /* fonctions_hpp */

//bool operator==(Personne const& a, Personne const& b);
