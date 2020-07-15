//TP3
//----------PERSONNE_H--------------
#ifndef PERSONNE_H
#define PERSONNE_H


class Personne
{
public:
	//constructeur
	Personne(char *mnom, char *mprenom, int mage);
	Personne(int mage=0);		//initialiser la valeur de parametre pour creer un tableau de la classe
	//constructeur par copie
	Personne(const Personne &p);
	//destructeur
	~Personne();

	//les methode pour la initialisation les information d'une personne
	void setPrenom(char *mprenom);
	void setNom(char *mnom);
	bool setAge(int mage);
protected:
	char *nom;
	char *prenom;
	int age;

public:
	//obtenir les information d'une personne
	char* getPrenom() const ;
	char* getNom() const ;
	int getAge();

	void affectation(Personne &p);
	Personne &operator=(const Personne &p);		//	//surcharge l'operateur
	void afficher();			//Afficher l'ensemble des objets Personne


}; 
#endif  // PERSONNE_H



//----------PERSONNE_CPP--------------
#include "Personne.h"
#include <iostream>
using namespace std;

//Constructeur
Personne::Personne(char *mnom, char *mprenom, int mage)
{
	cout << "initialisation les information d'une personne" << endl;
	int Tnom = 0;		//la taille de nom
	int Tprenom = 0;		//la taille de prenom

	//nom
	//Tnom +1 pour ajouter les caracteres
	while (mnom[Tnom] != '\0')
	{
		Tnom++;
	}
	nom = new char[Tnom+1];
	//taille Tnom+1 pour '\0'

	for (int i = 0; i < Tnom; i++)
	{
		//copier le nom caractere par caractere
		nom[i] = mnom[i];
	}
	nom[Tnom] = '\0';
	
	//prenom
	//Tprenom +1 pour ajouter les caracteres
	while (mprenom[Tprenom] != '\0')
	{
		Tprenom++;
	}
	prenom = new char[Tprenom+1];
	//taille Tprenom+1 pour '\0'
	for (int i = 0; i <Tprenom; i++)
	{
		//copier le prenom caractere par caractere
		prenom[i] = mprenom[i];
	}
	prenom[Tprenom] = '\0';
	//age
	age = mage;
}

//Constructeur par defaut pour que l'on puisse creer un tableau d'une classe
Personne::Personne(int mage)
{
	nom = new char[1];		//Allocatqtion dynamique d'un tableau d'un caracter
	nom[0] = '\0';		//fin de caracter
	prenom = new char[1];		//Allocatqtion dynamique d'un tableau d'un caracter
	prenom[0] = '\0';		//fin de caracter
	age = mage;

	cout << "Constructeur du personne par defaut" << endl;
}

//constructeur par refference
Personne::Personne(const Personne &p)
{
	cout << "initialiser les information d'une personne par copie" << endl;
	int Tnom = 0;		//la taille de nom
	int Tprenom = 0;		//la taille de prenom

	//nom
	//Tnom +1 pour ajouter les caracteres
	while (p.nom[Tnom] != '\0')
	{
		Tnom++;
	}
	nom = new char[Tnom+1];		//+1 fin de caracter

	for (int i = 0; i < Tnom; i++)
	{
		//copier le nom caracter par caracter
		nom[i] = p.nom[i];
	}
	nom[Tnom] = '\0';

	//prenom
	while (p.prenom[Tprenom] != '\0')
	{
		Tprenom++;
	}
	prenom = new char[Tprenom+1];		//+1 fin de caracter
	for (int i = 0; i < Tprenom; i++)
	{
		//copier le prenom caracter par caracter
		prenom[i] = p.prenom[i];
	}
	prenom[Tprenom] = '\0';
	//age
	age = p.age;
}

//destructeur
Personne:: ~Personne()
{
	cout << "destruction les information d'une personne :" <<nom<<" "<<prenom<<" "<<age<< endl;
	//libre la memoire
	delete[] nom;
	delete[] prenom;
	cout << "destruction fini" << endl;
}

// -------------initialisation les information d'une personne---------------------
// set nom
 void Personne:: setNom(char *mnom) 
{
	 //libre la memoire
	 delete[] nom;
	 //nouvelle allocation de nom
	 cout << "set nom d'une personne" << endl;
	 int Tnom = 0;		//la taille de nom
	 
	 //nom
	 while (mnom[Tnom] != '\0')
	 {
		 Tnom++;
	 }
	 nom = new char[Tnom+1];

	 for (int i = 0; i < Tnom; i++)
	 {
		 //copier le nom caracter par caracter
		 nom[i] = mnom[i];
	 }
	 nom[Tnom] = '\0';
	 cout << "nom set" << endl;
}

//set prenom
void Personne:: setPrenom(char *mprenom) 
{
	//libre la memoire
	delete[] prenom;
	//nouvelle allocation de prenom
	cout << "set prenom d'une personne" << endl;
	int Tprenom = 0;
	 //Tprenom +1 pour ajouter les caracteres
	while (mprenom[Tprenom] != '\0')
	{
		Tprenom++;
	}
	prenom = new char[Tprenom+1];
	for (int i = 0; i < Tprenom; i++)
	{
		//copier le prenom caracterpar caracter
		prenom[i] = mprenom[i];
	}
	prenom[Tprenom] = '\0';
	cout << "prenom set" << endl;
}

//set age
bool Personne:: setAge(int mage)
{
	//nouvelle allocation de l'age
	cout << "set age d'une personne" << endl;
	if (mage > 0)
	{
		age = mage;
		return true;
	}
	cout << "age set" << endl;	
	return false;
	
}

// -------obtenir les information d'une personne-----------
char* Personne::getPrenom() const 
{
	return prenom;
}

char* Personne::getNom() const 
{
	return nom;
}
int Personne::getAge()
{
	return age;
}

//Afficher l'ensemble des objets Personne
void Personne::afficher()
{
	cout << "nom : " << getNom() << "	" << "prenom : " << getPrenom() << "	" << "age : " << getAge()<<"ans" << endl;
}
//
Personne& Personne:: operator=(const Personne &p)
{
	setNom(p.nom);		//set nom
	setPrenom(p.prenom);		//set prenom
	setAge(p.age);		//set age
	cout << "par l'operateur= : " << endl;		//afficher les information d'une personne
	afficher();
	return *this;
}
void Personne::affectation(Personne &p)
{
	setNom(p.nom);		//set nom
	setPrenom(p.prenom);		//set prenom
	setAge(p.age);		//set age
	cout << "par l'affectation : " << endl;		//afficher les information d'une personne
	afficher();
}





//----------Etudiant_H--------------

#ifndef ETUDIANT_H
#define ETUDIANT_H
#include "Personne.h"
#include<iostream>
using namespace std;

class Etudiant : public Personne
{
public:
	Etudiant(char* mnom, char* mprenom, int mage, int mdim);
	Etudiant(int mdim=1);		//initialiser la valeur de parametre pour creer un tableau de la classe
	~Etudiant();
private:
	int dim;
	float* note;

public:
	float* getNote() const ;
	void setNote(float* mnote, int mdim);
	float moyenne();

}; 
#endif //ETUDIANT_H




//----------Etudiant_CPP--------------
#include "Etudiant.h"
#include "Personne.h"
#include<iostream>
using namespace std;

//Constructeur
Etudiant::Etudiant(char* mnom, char* mprenom, int mage, int mdim=1): Personne(mnom, mprenom, mage) // pas besoin de definir le tpye de parametre pour class mere
{
	dim = mdim;
	note = new float[mdim];
	for (int i = 0; i < mdim; i++)
	{
		note[i] = 0;
	}

	cout << "Constucteur d'etudiant par parametre" << endl;
}

//Constrcuteur par défaut
Etudiant::Etudiant(int mdim) :Personne()
{
	dim = mdim;
	note = new float[mdim];
	for (int i = 0; i < mdim; i++)
	{
		note[i] = 0;
	}
	cout << "Constucteur du etudiant par defaut" << endl;
}

//Destructeur
Etudiant::~Etudiant()
{
	cout << "destruction les information d'une etudiant :" << nom << " " << prenom << " " << age << note<<" "<< endl;
	delete[] note;
	cout << "destruction fini" << endl;
}

//set note
void Etudiant:: setNote(float* mnote, int mdim) 
{
	delete[] note;		//liberer la memoire
	//nouvelle allocation de note
	dim = mdim;
	note = new float[mdim];
	for (int i = 0; i < mdim; i++)
	{
		note[i] = mnote[i];
	}
	cout << "l'allocation de note fini" << endl;
}

//get note
float* Etudiant::getNote()const
{
	for (int i = 0; i < dim; i++)
	{
		cout << "note" << i << " :" << note[i] << endl;
	}
	return note;
}

//calculer la moyenne
float Etudiant::moyenne()
{
	float somme=0;		//il faut initialiser la valeur par defaut
	for  (int i= 0; i < dim; i++)
	{
		somme += note[i];
	}
	return somme / dim;
}






/*
构造原则如下：

1. 如果子类没有定义构造方法，则调用父类的无参数的构造方法。

2. 如果子类定义了构造方法，不论是无参数还是带参数，在创建子类的对象的时候, 首先执行父类无参数的构造方法，然后执行自己的构造方法。

3. 在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数，则会调用父类的默认无参构造函数。

4. 在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数且父类自己提供了无参构造函数，则会调用父类自己的无参构造函数。

5. 在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数且父类只定义了自己的有参构造函数，则会出错（如果父类只有有参数的构造方法，则子类必须显示调用此带参构造方法）。

6. 如果子类调用父类带参数的构造方法，需要用初始化父类成员对象的方式.
*/



//----------main-------------

#include "Etudiant.h"
#include "Personne.h"
#include <iostream>
using namespace std;

int main()
{
	//-------Personne---------
	cout << "NBA all star PF :" << endl;
	Personne p1((char*)"James", (char*)"Leborn", 39);
	p1.afficher();
	Personne p2((char*)"Wade", (char*)"Dwyane", 36);

	Personne tabPer[3];		// on utilise ici le constructeur par defaut
	//initialisation de 1ere personne
	cout << "NBA all star PG :" << endl;
	tabPer[0].setNom((char*)"Iverson");
	tabPer[0].setPrenom((char*)"Allen");
	tabPer[0].setAge(41);
	tabPer[0].afficher();		//afficher le 1ere personne

	//initialisation de 2eme personne par l'operateur 
	cout << "NBA all star PF :" << endl;
	//definir par l'operateur 
	tabPer[1] = p1;

	//initialisation de 3eme personne par methode de l'affectation
	cout << "NBA all star SG :" << endl;
	tabPer[2].affectation(p2);

	//afficher des personnes
	cout << "welcome the 2017 NBA all star" << endl;
	for (int i = 0; i < 3; i++)
	{
		tabPer[i].afficher();
	}
	p1.~Personne();

	//-------Etudiant---------
	cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << endl;
	cout << "les information des Ă©tudiants" << endl;
	float note1[] = { 14,13,12,13,14 };
	//float *p = note1;
	//cout << p << endl;
	float note2[] = { 14,12,13,14,15 };
	Etudiant e1((char*)"Wu", (char*)"Runsheng", 25,5);
	e1.afficher();
	Etudiant e2((char*)"Xu", (char*)"Fei", 20, 5);
	e2.afficher();
	//creer un tableau d'etudiant
	Etudiant tabEtu[2];
	tabEtu[0] = e1;
	tabEtu[0].setNote(note1, 5);
	cout << "les note de " << tabEtu[0].getNom() << " " << tabEtu[0].getPrenom() << " : " << endl; 
	cout << tabEtu[0].getNote() << endl;
	cout<<"la moyenne de "<< tabEtu[0].getNom()<<" "<< tabEtu[0].getPrenom()<<" : "<<tabEtu[0].moyenne()<<endl;

	tabEtu[1] = e2;
	tabEtu[1].setNote(note2, 5);
	cout << "les note de " << tabEtu[1].getNom() << " " << tabEtu[1].getPrenom() << " : " << endl;
	cout << tabEtu[1].getNote() << endl;
	cout << "la moyenne de " << tabEtu[1].getNom() << " " << tabEtu[1].getPrenom() << " : " << tabEtu[1].moyenne() << endl;

}