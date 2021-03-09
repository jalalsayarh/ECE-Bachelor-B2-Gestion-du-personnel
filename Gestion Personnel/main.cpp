//
//  main.cpp
//  Gestion Personnel
//


/*
    COMMENTAIRES DU CODE
 */


//  CODE EN COMMENTAIRE


#include "fonctions.hpp"
//#include "fonctions_IO.hpp"
//#include "fonctions_processing_vect.hpp"
//#include "fonctions_processing_tab.hpp"

//derniere version  coco, noa, si vous voyez ce message c'est que le git fonctionne 


int main(int argc, const char * argv[]) {
    
    MYSQL mysql;
    mysql_init(&mysql); //Connection à mysql
    
    if (connexion_bdd(&mysql))
    {
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
                    cout<<p.affiche();
                    
                    cout<<"\n--Saisie des nouvelle informations de la personne--";
                    p.newPerson(); /* fonctionnalité de saisie par l'utilisateur ajouté post etape */
                    cout<<p.affiche();   /* appelle de la fonction affiche pour verifié que tout d'affiche correctement */
        
                    p.setAge(p.getAge()+1); /* Test 2 en 1, getter et setter */
                    cout<<"\n--Affichage après application du setters--";
                    cout<<p.affiche();            /* On a vérifié que le setter et le getter ont fonctionné */

                    break;
                }
                    
                    
                case /* Etape */ 2: /* Déclaration et implémentation de la classe Etudiant */
                {
                    cout<<"\n--Saisie d'un(e)  nouvel(le)  étudiant(e) --\n";
                    et.newEtudiant();   /* fonctionnalité de saisie par l'utilisateur ajouté post etape */
                    cout<<et.affiche(); /* appelle de la fonction affiche pour verifié que tout d'affiche correctement */
                    cout<<"--------------------\n"; /* point de repere dans le code */
                    break;
                }
                  
                    
                case /* Etape */ 3: /* Déclaration et implémentation de la classe Employé*/
                {
                    cout<<"\n-- Saisie d'un(e) nouvel(le) employé(e) --\n";
                    em.newEmploye();    /* fonctionnalité de saisie par l'utilisateur ajouté post etape */
                    cout<<em.affiche();       /* appelle de la fonction affiche pour verifié que tout d'affiche correctement */
        
                    em.setNumBureau(em.getNumBureau()+1); /* Test 2 en 1, getter et setter */
                    cout<<"\n--Affichage après application du setters sur le numéro du bureau--";
                    cout<<em.affiche(); /* On a vérifié que le setter et le getter ont fonctionné */
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
                        cout<<"1. Afficher tout le tableau.\n";
                        cout<<"2. Afficher uniquement les étudiants.\n";
                        cout<<"3. Afficher uniquement les employés \n";
                        cout<<"4. Afficher uniquement les élèves \n";
                        cout<<"5. Trier le tableau par noms.\n";
                        cout<<"6. Trier le tableau par prénoms.\n";
                        cout<<"7. Trier le tableau par age.\n";
                        cout<<"8. Rechercher un élément dans le tableau.\n";
                        cout<<"9. Sauvegarder dans un fichier txt.\n";
                        cout<<"0. Retour au menu principal.\n";
                        
                        int choix;
                        // saisie de la réponse au choix de tri
                        cout<<"Veuillez faire un choix : ";
                        cin>>choix;
                        
                        switch (choix) {
                            
                            case 1: /**Afficher le tableau */
                                afficheTab_Personne(tabEtape4, indiceMax);
                                break;
                            case 2:/**Afficher les Etudiants */
                            {
                                affiche_etudiant(tabEtape4, indiceMax);
                                break;
                            }
                            case 3:/**Afficher les Employés*/
                            {
                                affiche_employe(tabEtape4, indiceMax);
                                break;
                            }
                            case 4: /**Afficher les Eleves*/
                            {
                                affiche_eleve(tabEtape4, indiceMax);
                                break;
                            }
                            case 5: /**Trier le tableau par noms*/
                                tri_tab_personne_nom(tabEtape4, indiceMax);
                                afficheTab_Personne(tabEtape4, indiceMax);
                                break;
                            
                            case 6: /**Trier le tableau par prénoms*/
                                tri_tab_personne_prenom(tabEtape4, indiceMax);
                                afficheTab_Personne(tabEtape4, indiceMax);
                                break;
                                
                            case 7: /**Trier le tableau par âge*/
                                tri_tab_personne_age(tabEtape4, indiceMax);
                                afficheTab_Personne(tabEtape4, indiceMax);
                                break;
                                
                            case 8: /**Rechercher un élément dans le tableau*/
                                recherche_personne_in_tab(tabEtape4, indiceMax);
                                break;
                                
                            case 9: /**Sauvegarde dans un fichier txt*/
                            {
                                string rep=blindage_Saisie_ChoixBinaire("\nAttention ! Si vous continuez le contenu du fichier sera écrasé.\nContinuer ?(oui/non)\n ->", "oui", "non");
                                
                                if (rep=="oui") {
                                    write("/Users/jalalsayarh/Desktop/fichertestProjetAutonome.txt",tabEtape4,indiceMax);
                                    cout<<"\n--------------\n";
                                    read();
                                }
                                break;
                            }
                                
                            case 0: /** Retuor au menu pricipal*/
                                refresh="ok";
                                break;
                                
                            default:
                                break;
                        }
                        if (refresh=="ok")
                            retourMenu="non";
                        else
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
                    cout<<el.affiche();
                    
                    //On blinde le choix de l'utilisateur entre "oui" et "non"; La sensibilité à la casse est a optimiser
                    if (el.getnote()!=NULL) {
                        choix=blindage_Saisie_ChoixBinaire("\nDésirez-vous modifier le tableau de notes ? (oui/non)\n ->", "oui", "non");
                    }
                    else{
                        string saisirnote=blindage_Saisie_ChoixBinaire("\n\nDésirez-vous saisir les notes? (oui/non)\n ->", "oui", "non");
                        if (saisirnote=="oui") {
                            el.saisieNote();
                        }
                    }
                    
                    if (choix=="oui")
                    {
                        cout<<"\n--Modification des notes--";
                        el.modifNote();
                        cout<<el.affiche();
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
                    cout<<"\n           exemple: Objet *o = oBis;  /* Ici, oBis serait l'adresse d'un objet déja existant */"<<endl;
                    
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
                            bool vecteurVide=0;
                                                
                            string retourMenu;
                            do{
                                cout<<"\n\n";
                                // proposition des options de tri
                                cout<<"1. Ajouter un élement au vecteur\n";
                                cout<<"2. Afficher le contenu du vecteur.\n";
                                cout<<"3. Afficher uniquement les étudiants.\n";
                                cout<<"4. Afficher uniquement les employés \n";
                                cout<<"5. Afficher uniquement les élèves \n";
                                cout<<"6. Trier par noms.\n";
                                cout<<"7. Trier par prénoms.\n";
                                cout<<"8. Trier par age.\n";
                                cout<<"9. Rechercher un élément parmis les éléments du vecteur.\n";
                                cout<<"10. Sauvegarder dans un fichier txt.\n";
                                cout<<"0. Retour au menu principal.\n";
                                
                                int choix;
                                // saisie de la réponse au choix de tri
                                cout<<"\nVeuillez faire un choix : \n ->";
                                cin>>choix;
                                
                                switch (choix) {
                                    case 1: /**Ajout d'un élément*/
                                        saisie_Vecteur_Personne(&lesGens);
                                        break;
                                    case 2: /**Afficher le vecteur */
                                        if (lesGens.size()==0) {
                                            cout<<"Vecteur vide ! Veuillez d'abord ajouter au moins un éléments\n";
                                            vecteurVide=1;
                                        }
                                        else affiche_Vecteur(&lesGens);
                                        break;
                                    case 3:/**Afficher les Etudiants */
                                    {
                                        affiche_etudiant(&lesGens);
                                        break;
                                    }
                                    case 4:/**Afficher les Employés*/
                                    {
                                        affiche_employe(&lesGens);
                                        break;
                                    }
                                    case 5: /**Afficher les Eleves*/
                                    {
                                        affiche_eleve(&lesGens);
                                        break;
                                    }
                                    case 6: /**Trier le VECTEUR par nom*/
                                        if (lesGens.size()==0) {
                                            cout<<"Vecteur vide ! Veuillez d'abord ajouter au moins un éléments\n";
                                            vecteurVide=1;
                                        }
                                        else
                                        {   tri_vecteur_personne_nom(&lesGens);
                                            affiche_Vecteur(&lesGens);
                                        }
                                        break;
                                        
                                    case 7: /**Trier le tableau par vecteur*/
                                        if (lesGens.size()==0) {
                                            cout<<"Vecteur vide ! Veuillez d'abord ajouter au moins un éléments\n";
                                            vecteurVide=1;
                                        }
                                        else {
                                            tri_vecteur_personne_prenom(&lesGens);
                                            affiche_Vecteur(&lesGens);
                                        }
                                        break;
                                        
                                    case 8: /**Trier le vecteur par âge*/
                                        if (lesGens.size()==0) {
                                            cout<<"Vecteur vide ! Veuillez d'abord ajouter au moins un éléments\n";
                                            vecteurVide=1;
                                        }
                                        else {
                                            tri_vecteur_personne_age(&lesGens);
                                            affiche_Vecteur(&lesGens);
                                        }
                                        break;
                                        
                                    case 9: /**Rechercher un élément dans le vecteur*/
                                        if (lesGens.size()==0) {
                                            cout<<"Vecteur vide ! Veuillez d'abord ajouter au moins un éléments\n";
                                            vecteurVide=1;
                                        }
                                        else recherche_vecteur(&lesGens);
                                        break;
                                        
                                    case 10: /**Sauvegarde dans un fichier txt*/
                                    {
                                        string rep=blindage_Saisie_ChoixBinaire("\nAttention ! Si vous continuez le contenu du fichier sera écrasé.\nContinuer ?(oui/non)\n ->", "oui", "non");
                                        
                                        if (rep=="oui") {
                                            write("/Users/jalalsayarh/Desktop/fichertestProjetAutonome.txt", &lesGens);
                                            read();
                                        }
                                        break;
                                    }
                                        
                                    case 0: /** Retuor au menu pricipal*/
                                        refresh="ok";
                                        
                                        break;
                                        
                                    default:
                                        break;
                                }
                                if (refresh=="ok") retourMenu="non";
                                else if (vecteurVide) retourMenu="oui";
                                else retourMenu=blindage_Saisie_ChoixBinaire("\nRetour au menu précedent (oui/non) ?\n ->", "oui", "non");
                                
                            }while (retourMenu=="oui");
                            cout<<"\n----------------------FIN VECTEUR--------------------------------\n\n"; /*point de repere dans le code*/

                                        /* Fin de la partie avec le Vecteur */
                        }
            /* ********************************************************************************************************************/

                        else{
                                    /* Etape intermediaire avec liste chaînée*/

                            cout<<"\n--------------Test saisie liste -------------------------\n";/*point de repere dans                                                                    le code */
                            string retourMenu;
                            do{
                                cout<<"\n\n";
                                // proposition des options de tri
                                cout<<"1. Ajouter un élement à la liste\n";
                                cout<<"2. Afficher tous les éléments de la liste.\n";
                                cout<<"3. Trier par noms.\n";
                                cout<<"4. Trier par prénoms.\n";
                                cout<<"5. Trier par age.\n";
                                cout<<"6. Rechercher un élément dans la liste.\n";
                                cout<<"7. Sauvegarder dans un fichier txt.\n";
                                cout<<"0. Retour au menu principal.\n";
                                
                                int choix;
                                // saisie du choix de fonctionnalité
                                cout<<"\nVeuillez faire un choix : \n ->";
                                cin>>choix;

                                switch (choix) {
                                    case 1: /**Ajout d'un élément*/
                                    {
                                        string repeat;
                                        do {
                                            saisie_Liste_Personne(start);
                                            repeat=blindage_Saisie_ChoixBinaire("\nAjouter une nouvelle personne? (oui/non) ?\n ->", "oui", "non");
                                        } while (repeat=="oui");
                                        break;
                                    }
                                    case 2: /**Afficher la liste */
                                        if (start->getSomeone()==NULL) cout<<"Liste vide ! Veuillez d'abord ajouter au moins un éléments\n";
                                        else start->afficheListe();
                                        break;

                                    case 3: /**Trier la liste par nom*/
                                        if (start==NULL) cout<<"Vecteur vide ! Veuillez d'abord ajouter au moins un éléments";
                                        else
                                        {
                                            tri_liste_personne_nom(start);
                                        }
                                        
                                        break;

                                    case 4: /**Trier la liste par prenom*/
                                        if (start==NULL) cout<<"Vecteur vide ! Veuillez d'abord ajouter au moins un éléments";
                                        else {
                                            tri_liste_personne_prenom(start);
                                        }
                                        
                                        break;

                                    case 5: /**Trier la liste par âge*/
                                        if (start==NULL) cout<<"Vecteur vide ! Veuillez d'abord ajouter au moins un éléments";
                                        else {
                                            tri_liste_personne_age(start);
                                        }
                                        
                                        break;

                                    case 6: /**Rechercher un élément dans le vecteur*/
                                        if (start==NULL) cout<<"Vecteur vide ! Veuillez d'abord ajouter au moins un éléments";
                                        else recherche_liste(start);
                                        
                                        break;

                                    case 7:
                                    {/**Sauvegarde dans un fichier txt*/
                                        string rep=blindage_Saisie_ChoixBinaire("\nAttention ! Si vous continuez le contenu du fichier sera écrasé.\nContinuer ?(oui/non)\n ->", "oui", "non");
                                        
                                        if (rep=="oui")
                                        {
                                            write("/Users/jalalsayarh/Desktop/fichertestProjetAutonome.txt", start);
                                            read();
                                        }
                                        break;
                                    }

                                    case 0: /** Retuor au menu pricipal*/
                                        refresh="ok";

                                        break;

                                    default:
                                        break;
                                }
                                if (refresh=="ok") retourMenu="non";
                                else retourMenu=blindage_Saisie_ChoixBinaire("\nRetour au menu précedent (oui/non) ?\n ->", "oui", "non");

                            }while (retourMenu=="oui");
                            cout<<"\n-----------------------FIN LISTE---------------------------------------\n";  /*point de repere dans le code*/
                            
                        }
                        if (refresh=="ok") choixEtape9="non";
                        else choixEtape9 = blindage_Saisie_ChoixBinaire("Revenir au menu precedent ? (oui/non)\n ->", "oui", "non");
                        
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
            if (refresh=="ok") {
                refresh = "oui";
            }else {
                refresh=blindage_Saisie_ChoixBinaire("\n\nRetour au menu principal ? (oui/non)\n ->", "oui", "non");
            }
            
        } while (refresh=="oui"); /* do ligne 38: */
        
        cout<<"Au revoir !\n";
        return 0;
    }
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
//            do {
//                saisie_Vecteur_Personne(&lesGens);
//                nouveau = blindage_Saisie_ChoixBinaire("\nAjouter une nouvelle personne ? (oui / non)\n-> ", "oui", "non");
//              } while (nouveau=="oui");
//
//            cout<<"\nVecteur de Personnes que vous avez saisi: \n";
//            affiche_Vecteur(&lesGens);

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
