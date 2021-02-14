//
//  Personne.cpp
//  Gestion Personnel
//


#include "fonctions.hpp"

//CONSTRUCTEURS
Personne::Personne(){}
Personne::Personne(string lePrenom, string leNom, int lAge,string adresseEmail)
{
    prenom=lePrenom;
    nom=leNom;
    age=lAge;
    email=adresseEmail;
}

// implémentation destructeur
Personne::~Personne(){
    //cout<<"Destructeur de la clase Personne"<<endl;
}


// déclaration des getters de la classe personne
string Personne::getPrenom()
{
    return prenom;
}
string Personne::getNom()
{
    return nom;
}
int Personne::getAge()
{
    return age;
}
string Personne::getEmail()
{
    return email;
}


//setters
void Personne::setPrenom(string lePrenom)
{
    prenom=lePrenom;
}
void Personne::setNom(string leNom)
{
    nom=leNom;
}
void Personne::setAge(int lAge)
{
    age=lAge;
}
void Personne::setEmail(string adresseEmail)
{
    email=adresseEmail;
}


//methodes
void Personne::affiche()
{
    cout<<"\nPrénom: "<<getPrenom()<<"\nNom: "<<getNom()<<"\nAge: "<<getAge()<<" ans \nAdresse mail: "<<getEmail()<<endl;
}

void Personne::newPerson()
{
    // pattern regex qui verifie si la saisie d'email correspond au modèle d'un email valide
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    
    cout<<"\n Prenom: ";
    cin.clear();
    cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
    
    getline(cin,prenom);
    
    cout<<"\n Nom: ";
    cin.clear();
    
    //cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); /*PAS NECESSAIRE CAR DEJA UTILISEE AU                                                                  DESSUS SINON BUG*/
    
    getline(cin,nom); // on veux toute la chaine si jamais il y a un espace saisi
    
    cout<<"\n Age: ";
    while(!(cin >> age) || age < 18 || age > 60) // on blinde la saisie de l'age de la personne
    {
       if (cin.fail()) // si la saisie n'est pas un nombre on affiche une erreur et on demande de resaisir
       {
           cout << "         Saisie incorrecte, ressaisissez: ";
           cin.clear();
           cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
       }
       else // sinon, la valeur n'est pas dans les paramètres autorisés donc on redemande la saisie
       {
           cout << "         L'age doit être entre 18 et 60 ans, ressaisissez: ";
       }
    }
    
    cout<<"\n Adresse email: ";
    cin >> email;
    // on vérifie que l'email saisi valide les conditions demandées par le pattern regex
    while(regex_match(email,pattern)==0)
    {
        cout<<"         Saisie incorrecte, ressaisissez: ";
        cin >> email;
        
    }
}




//Destructeur
//Personne::~Personne(){}
