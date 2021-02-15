//
//  main.cpp
//  Gestion Personnel
//


/*
    COMMENTAIRES DU CODE
 */


//  CODE EN COMMENTAIRE


#include "fonctions.hpp"

//derniere version  coco, noa, si vous voyez ce message c'est que le git fonctionne 


int main(int argc, const char * argv[]) {
    
    Employe em("Charles","Dubois",20,"charlesdubois@hotmail.fr","Compta",12); /* création d'un nouvel employé */
    Etudiant et ("nico","sarko",20,"charlesdubois@hotmail.fr","dev web",2020);  /* création d'un nouvel étudiant */
    
    /* Pointeurs nécessaire pour les test des étapes 4 et 9*/
    Etudiant *ett;
    Employe *emm;
    
    ett=&et;
    emm=&em;
    
    /*pointeur nécessaire dans la 2e partie de l'étape 9*/
    elementListe* start=new elementListe();      /*qui pointera sur le premier element de la liste*/
    
    string refresh; /*retour au menu principal*/
    
    cout<<"-------------------------GESTION DU PERSONNEL--------------------------";
    do {
        int choixMenuPrincipal;
        
        cout<<"\n\n\nMENU PRINCIPAL\n";
        cout<<"\n1- Déclaration et implémentation de la classe Racine";
        cout<<"\n2- Déclaration et implémentation de la classe Etudiant";
        cout<<"\n3- Déclaration et implémentation de la classe Employé";
        cout<<"\n4- Gestion générique";
        cout<<"\n5- Déclaration et implémentation de la classe Elève";
        cout<<"\n6- Destruction";
        cout<<"\n7- Constance et références";
        cout<<"\n8- Initialisation et affectation";
        cout<<"\n9- STL (Réécrire l'étape 4 en utilisant les vecteurs puis les listes chaînées)";
        cout<<"\n0- Quitter";
        
        choixMenuPrincipal=blindage_Saisie_ChoixIntervalle("\n\n->", 0, 9);
        
        switch (choixMenuPrincipal) {
                
            case /* Etape */ 1: /* Déclaration et implémentation de la classe Racine */
            {
                Personne p("Charles","Dubois",20,"charlesdubois@hotmail.fr"); /* création d'une nouvelle personne */
                p.affiche();
                
                cout<<"\n--Saisie des nouvelle informations de la personne--";
                p.newPerson(); /* fonctionnalité de saisie par l'utilisateur ajouté post etape */
                p.affiche();   /* appelle de la fonction affiche pour verifié que tout d'affiche correctement */
    
                p.setAge(p.getAge()+1); /* Test 2 en 1, getter et setter */
                cout<<"\n--Affichage après application du setters--";
                p.affiche();            /* On a vérifié que le setter et le getter ont fonctionné */

                break;
            }
                
                
            case /* Etape */ 2: /* Déclaration et implémentation de la classe Etudiant */
            {
                cout<<"\n--Saisie d'un(e)  nouvel(le)  étudiant(e) --\n";
                et.newEtudiant();   /* fonctionnalité de saisie par l'utilisateur ajouté post etape */
                et.affiche(); /* appelle de la fonction affiche pour verifié que tout d'affiche correctement */
                cout<<"--------------------\n"; /* point de repere dans le code */
                break;
            }
              
                
            case /* Etape */ 3: /* Déclaration et implémentation de la classe Employé*/
            {
                cout<<"\n-- Saisie d'un(e) nouvel(le) employé(e) --\n";
                em.newEmploye();    /* fonctionnalité de saisie par l'utilisateur ajouté post etape */
                em.affiche();       /* appelle de la fonction affiche pour verifié que tout d'affiche correctement */
    
                em.setNumBureau(em.getNumBureau()+1); /* Test 2 en 1, getter et setter */
                cout<<"\n--Affichage après application du setters sur le numéro du bureau--";
                em.affiche(); /* On a vérifié que le setter et le getter ont fonctionné */
                break;
            }
                
                
            case /* Etape */ 4: /* Gestion générique */
            {
                int indiceMax=2; /**variable indice pour le nombre de case dans le tableau; déja initialisé mais possibilité de la faire saisir par l'utilisateur */
                string choixPersonne;
                Personne *tabEtape4[indiceMax];
    
                
                
                for (int i=0; i<indiceMax; i++) {
                    /**Initialisation du tableau de pointeur */
                    tabEtape4[i]=NULL;
                }
    
                /* Saisie et affichages des élements du tableau */
                saisieTab_Personne(tabEtape4, indiceMax);
    
                afficheTab_Personne(tabEtape4, indiceMax);
                
                string retourMenu;
                do{
                    cout<<"\n\n";
                    // proposition des options de tri
                    cout<<"1. Afficher le tableau.\n";
                    cout<<"2. Trier le tableau par noms.\n";
                    cout<<"3. Trier le tableau par prénoms.\n";
                    cout<<"4. Trier le tableau par age.\n";
                    cout<<"5. Rechercher un élément dans le tableau.\n";
                    cout<<"6. Sauvegarder dans un fichier txt.\n";
                    //cout<<"0. Retour au menu principal.\n";
                    
                    int choix;
                    // saisie de la réponse au choix de tri
                    cout<<"Veuillez faire un choix : ";
                    cin>>choix;
                    
                    switch (choix) {
                        case 1: /**Afficher le tableau */
                            afficheTab_Personne(tabEtape4, indiceMax);
                            break;
                            
                        case 2: /**Trier le tableau par noms*/
                            tri_tab_personne_nom(tabEtape4, indiceMax);
                            afficheTab_Personne(tabEtape4, indiceMax);
                            break;
                            
                        case 3: /**Trier le tableau par prénoms*/
                            tri_tab_personne_prenom(tabEtape4, indiceMax);
                            afficheTab_Personne(tabEtape4, indiceMax);
                            break;
                            
                        case 4: /**Trier le tableau par âge*/
                            tri_tab_personne_age(tabEtape4, indiceMax);
                            afficheTab_Personne(tabEtape4, indiceMax);
                            break;
                            
                        case 5: /**Rechercher un élément dans le tableau*/
                            recherche_personne_in_tab(tabEtape4, indiceMax);
                            break;
                            
                        case 6: /**Sauvegarde dans un fichier txt*/
                            
                            break;
                        
                            
                        case 0: /** Retuor au menu pricipal*/
                            
                            break;
                            
                        default:
                            break;
                    }
                    retourMenu=blindage_Saisie_ChoixBinaire("\nRetour au menu précedent (oui/non) ?\n ->", "oui", "non");
                }while (retourMenu=="oui");
                cout<<"--------------------\n"; /* point de repere dans le code */
                break;
            }
                
            
            case /* Etape */ 5: /* Déclaration et implémentation de la classe Elève */
            {
                string choix;
                int nbue=3;
                Eleve el ("nico","sarko",20,"charlesdubois@hotmail.fr","dev web",2020,nbue);/*création d'un nouvel élève*/
             

                cout<<"\n-- Saisie d'un(e)  nouvel(le)  élève --\n";
                el.newEleve();
                el.affiche();
                
                //On blinde le choix de l'utilisateur entre "oui" et "non"; La sensibilité à la casse est a optimiser
                choix=blindage_Saisie_ChoixBinaire("\nDésirez-vous modifier le tableau de notes ? (oui/non)\n ->", "oui", "non");
                
                if (choix=="oui")
                {
                    cout<<"\n--Modification des notes--";
                    el.modifNote();
                    el.affiche();
                }
                break;
            }
                
            
            case /* Etape */ 6: /* Destruction */
            {
                cout<<"\nVous Trouverez les réponses à vos questions dans le rapport"<<endl;
                cout<<"Le code source du programme a été modifié en conséquence"<<endl;
                break;
            }
                
            
            case /* Etape */ 7: /* Constance et références */
            {
                break;
            }
                
        
            case /* Etape */ 8:/* Initialisation et affectation */
            {
                cout<<"\n   Vos objets contiennent probablement des pointeurs (typiquement vers le tableau de notes). Il est donc dangereux de les recopier par simple affectation (les variables d'instances des 2 objets pointeraient vers les mêmes valeurs)\n.";
                
                cout<<"\n       le même problème peut également se poser à l'initialisation d'un objet : dans quel cas (donnez un exemple) ?\n";
                cout<<"\n           exemple: Objet *o = oBis;  /* Ici, oBis serait un pointeur sur un objet";
                cout<<"\n                                   préalablement*/"<<endl;
                
                cout<<"\n       comment faire pour que l'affectation et l'initialisation soient interdites par le compilateur pour toutes les classes de la hiérarchie ?\n";
                cout<<"\n           ->Réponse à venir; les recherches sont encore en cours"<<endl;
                
                cout<<"\n       comment faire pour que l'affectation et l'initialisation des objets de classe Eleve puissent se faire sans danger ?\n";
                cout<<"\n           ->Réponse à venir; les recherches sont encore en cours"<<endl;
                
                break;
            }
                
            
            case /* Etape */ 9: /* STL (Réécrire l'étape 4 en utilisant les vecteurs puis les listes chaînées) */
            {
                    /* Partie avec utilisation d'un vecteur */
                
                
                string choixEtape9,nouveau;
                do{
                    choixEtape9 = blindage_Saisie_ChoixBinaire("\nPour la partie Vecteur, saisir [1] \nPour la partie Liste chaînée, saisir [2]\n ->", "1", "2");
                    
                    if(choixEtape9=="1")
                    {
                        cout<<"\n--------------Test saisie vecteur -------------------------\n";/*point de repere dans                                                                    le code */
                        vector<Personne*> lesGens;
                        
                          do {
                              saisie_Vecteur_Personne(&lesGens);
                              nouveau = blindage_Saisie_ChoixBinaire("\nAjouter une nouvelle personne ? (oui / non)\n-> ", "oui", "non");
                            } while (nouveau=="oui");
                        
                        cout<<"\nVecteur de Personnes que vous avez saisi: \n";
                        affiche_Vecteur(&lesGens);
                        
                        string retourMenu;
                        do{
                            cout<<"\n\n";
                            // proposition des options de tri
                            cout<<"1. Afficher le contenu du vecteur.\n";
                            cout<<"2. Trier par noms.\n";
                            cout<<"3. Trier par prénoms.\n";
                            cout<<"4. Trier par age.\n";
                            cout<<"5. Rechercher un élément parmis les éléments du vecteur.\n";
                            cout<<"6. Sauvegarder dans un fichier txt.\n";
                            //cout<<"0. Retour au menu principal.\n";
                            
                            int choix;
                            // saisie de la réponse au choix de tri
                            cout<<"Veuillez faire un choix : ";
                            cin>>choix;
                            
                            switch (choix) {
                                case 1: /**Afficher le tableau */
                                    afficheTab_Personne(tabEtape4, indiceMax);
                                    break;
                                    
                                case 2: /**Trier le tableau par noms*/
                                    tri_tab_personne_nom(tabEtape4, indiceMax);
                                    afficheTab_Personne(tabEtape4, indiceMax);
                                    break;
                                    
                                case 3: /**Trier le tableau par prénoms*/
                                    tri_tab_personne_prenom(tabEtape4, indiceMax);
                                    afficheTab_Personne(tabEtape4, indiceMax);
                                    break;
                                    
                                case 4: /**Trier le tableau par âge*/
                                    tri_tab_personne_age(tabEtape4, indiceMax);
                                    afficheTab_Personne(tabEtape4, indiceMax);
                                    break;
                                    
                                case 5: /**Rechercher un élément dans le tableau*/
                                    recherche_personne_in_tab(tabEtape4, indiceMax);
                                    break;
                                    
                                case 6: /**Sauvegarde dans un fichier txt*/
                                    
                                    break;
                                
                                    
                                case 0: /** Retuor au menu pricipal*/
                                    
                                    break;
                                    
                                default:
                                    break;
                            }
                            retourMenu=blindage_Saisie_ChoixBinaire("\nRetour au menu précedent (oui/non) ?\n ->", "oui", "non");
                        }while (retourMenu=="oui");
                        cout<<"\n----------------------FIN VECTEUR--------------------------------\n\n"; /*point de repere dans le code*/

                                    /* Fin de la partie avec le Vecteur */
                    }
        /* ********************************************************************************************************************/

                    else{
                                /* Etape intermediaire avec liste chaînée*/

                        cout<<"\n--------------Test saisie liste -------------------------\n";/*point de repere dans                                                                    le code */
                        
                        do {
                            saisie_Liste_Personne(start);
                            nouveau=blindage_Saisie_ChoixBinaire("\n1-Ajouter une nouvelle personne\n2-afficher la liste\n-> ", "1", "2");
                        } while (nouveau=="oui");


                        /*
                            affichage des differents element de la liste à partir de start
                         */
                        
                        cout<<"\n\n---Liste de Personnes que vous avez saisie: \n";
                        start->afficheListe();
                        cout<<"\n-----------------------FIN LISTE---------------------------------------\n";  /*point de repere dans le code*/
                        
                    }
                    choixEtape9 = blindage_Saisie_ChoixBinaire("Revenir au menu precedent ? (oui/non)\n ->", "oui", "non");
                    
                } while(choixEtape9=="oui");
                break;
            } /* case 9*/
                
        
            case 0: /* QUITTER*/
            {
                cout<<"Au revoir !\n";
                return 0;
                break;
            }
                
            
            default:
            {
                cout<<"Ce choix n'est pas repertorié désolé!";
                break;
            }
                
        } /* switch ligne 55 */
    
        cout<<"\n\nRetour au menu principal ? (oui/non)\n ->";
        cin>>refresh;
        
    } while (refresh=="oui"); /* do ligne 38: */
    
    cout<<"Au revoir !\n";
    return 0;
}


/* **************************************************BROUILLON***********************************************************/


/* ETAPE 1*/

/* ETAPE 2*/

/* ETAPE 3*/

/* ETAPE 4*/

//                tabEtape4[0]=ett;       /*ett et emm déclarés en début de programme */
//                tabEtape4[1]=emm;
//
//                for (int i=0; i<indiceMax; i++)
//                {
//                    tabEtape4[i]->affiche();
//                }
//                afficheTab_Personne(tabEtape4, indiceMax+1);
                



/* ETAPE 5*/

/* Série de Test rapide et simple pour des vérifications de fonctionnalité */

//                float lesNotes[el.getnbrUE()]; /*Tableau pour stocker les notes*/
//                string UE[el.getnbrUE()];      /*Tableau de string pour le nom des UE*/
//
//                *UE="python";
//                *(UE+1)="pysique";
//                *(UE+2)="Algo";
//                el.setUE(UE);
//
//                lesNotes[0]=12;
//                lesNotes[1]=9;
//                lesNotes[2]=15;
//                el.setnote(lesNotes); /* Cette ligne de code n'est plus fonctionnelle car le setter a été amélioré                                pour ne pus avoir à passer par un tableau intermediare */
//
//                for (int i=0; i<el.getnbrUE(); i++) {
//                       cout<<i+1<<" - "<<*(el.getUE()+i)<<" : "<<*(el.getnote()+i)<<endl;
//                }

                  /* Fin de la série de test */






/* ETAPE 9*/

/* Série de Test rapide et simple pour des vérifications de fonctionnalité */

//                 lesGens.push_back(ett);
//                 lesGens.push_back(emm);
//                 for (Personne* gens : lesGens)
//                  {
//                      gens->affiche();
//                  }
//                  cout<<"--------------------\n"; /* point de repere dans le code */

       /*      Fin de la serie de test   */


/* Série de Test rapide et simple pour des vérifications de fonctionnalité.
 Initilement la classe element Liste etait une structure, les tests ci dessous ont été réalisés à ce moment la*/
//
//                elementListe a,b;
//
//                start=&a;
//                a.someone=emm;
//                b.someone=ett;
//                a.next=&b;
//
//                intermediaire=*start; // on se place sur le premier element de la liste
//                intermediaire.someone->affiche(); //affichage du premier element de la liste a part
//
//                while (intermediaire.next!=NULL) {          /* tant qu'il existe un suivant dans la liste */
//                    intermediaire = *(intermediaire.next);  /* On se place sur le suivant en question */
//                    intermediaire.someone->affiche();             /* Et on l'affiche */
//                }

            /* FIN DE LA SERIE DE TEST */
