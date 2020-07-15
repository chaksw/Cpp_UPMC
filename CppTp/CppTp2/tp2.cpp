//TP2
//-------------PILEDECHAR_H-----------

//预编辑语句，命名格式与头文件名对应
//预编辑语句，命名格式与头文件名对应
#ifndef PILEDECHAR_H
#define PILEDECHAR_H
#include<string>


class PiledeChar
{
private:
	int mMax;		//La donnée membre mMax contient la taille de la pile crée
	int mSommet;		//La donnée membre mSommet indique le numéro de la case vide dans laquelle on pourra empiler le prochain caractère
	char *mPile;		//Le pointeur sur un caractère mPile désigne le tableau de caractères, alloué dynamiquement
public:
	PiledeChar(const int mMax);
	PiledeChar(const PiledeChar &piledechar);
	~PiledeChar();
	int CompterElements();
	void AfficherPile();
	bool EmpilerElem(char c);
	char DesempilerElem();
	char& operator [](int i);

};

//Fonction afficheinverse()
char afficheinverse(PiledeChar pile);

//Fonction inversemajuscule()
char inversemajuscule(PiledeChar pile);

#endif  // PILEDECHAR_H



//-------------PILEDECHAR_CPP-----------

//将头文件包含进来
#include "PiledeChar.h"
#include <iostream>
#include <ctype.h>
#include<string>
using  std::string;
using  std::wstring;
using namespace std;

//le constructeurs
PiledeChar:: PiledeChar(const int mMax=100)
{
	this->mMax = mMax;
	mSommet = 0;
	mPile = new char[mMax];		
	for (int i = 0; i < mMax; i++)
	{
		mPile[i] = ' ';
	}
	cout << "la constructeur au niveau de construction " << endl;
}

//le constructeur de copie
PiledeChar:: PiledeChar(const PiledeChar &p)
{
	//les valeur copiées
	this->mMax = p.mMax;
	mSommet = 0;
	mPile = new char[mMax];
	for (int i = 0; i < p.mMax; i++)
	{
		this->mPile[i] = p.mPile[i];
	}
	mPile = p.mPile;

	cout << "la constructeur de copie au niveau de construction de copie" << endl;
}

//le destructeur
PiledeChar:: ~PiledeChar()
{
	delete[] mPile;
	cout << "la destructeur au niveau de destruction " << endl;
}

//un méthode CompterElements() qui donne retourne un entier positif qui correspond au nombre d'éléments actuellement présents dans la pile
int PiledeChar::CompterElements()
{
	return mSommet;
}

//la méthode AfficherPile() qui affiche entre des ’[’ et ’]’ les éléments actuellement présents dans la pile.
void PiledeChar::AfficherPile()
{
	//cout << mSommet << endl;
	cout << "les éléments actuellement présents dans la pile" << '\n' << "[";
	for (int i = 0; i < mMax; i++)
		{
			cout << mPile[i];
		}
	//cout << mPile[mMax];
	cout<< "]"<<endl;
}

//EmpilerElem() qui prend un caractère en paramètre et le place sur le dessus de la pile.
bool PiledeChar::EmpilerElem(char c)
{
	if (mSommet < mMax)
	{
		mPile[mSommet] = c;
		mSommet++;
		return true;
	}
	return false;
}

//DesempilerElem() qui retourne le caractère du dessus de la pile.
char PiledeChar::DesempilerElem()
{
	char c;
	if (mPile[mSommet - 1] != '\0')
	{
		c = mPile[mSommet - 1];
		mPile[mSommet - 1] = '\0';
	}
	else
	{
		c = mPile[mSommet - 2];
		mPile[mSommet - 2] = mPile[mSommet - 1];
		mPile[mSommet - 1] = ' ';
	}
	mSommet--;
	return c;
}

char& PiledeChar::operator [](int i)
{
	return mPile[i];
}


//Fonction afficheinverse()
char afficheinverse(PiledeChar pile)
{
	
	int nbele = pile.CompterElements();
	char *res = new char[nbele];
	for (int i = 0; i <nbele; i++)
	{
		res += pile.DesempilerElem();
	}
	return *res;
	//cout << pile.DesempilerElem() << endl;
}



//Fonction inversemajuscule()
	char inversemajuscule(PiledeChar pile)
{
	int nb = pile.CompterElements();
	cout << nb << endl;
	PiledeChar nPile(nb);
	char *res = new char[nb];
	for (int  i = 0; i < nb; i++)
	{
		res += tolower(nPile[i]);
	}
	return *res;
	/*int j = 1;
	while (j<=nb)
	{
		nPile.EmpilerElem(res[nb-j]);
		j++;
	}
	pile.EmpilerElem('\0');
	nPile.AfficherPile();
	*/
}



//------------main------------
#include "PiledeChar.h"
#include <iostream>
#include <ctype.h>
#include<string>
using namespace std;
using  std::string;
using  std::wstring;


int main()
{
	//Déclarer un tableau de caractère et demandez à l’utilisateur d’entrer un mot au clavier.
	//On utilisera la méthode getline()
	const int tMax = 10;
	PiledeChar pile(tMax);
	cout << "veuillez entre un mot ";
	char tab[tMax];
	cin.getline(tab, tMax-1);
	cout << "chaine : " << tab << endl;


	int i = 0;
	while (tab[i] != '\0')
	{
		pile.EmpilerElem(tab[i]);
		i++;
	}
	if (i<tMax)
	{
		pile.EmpilerElem('\0');
	}

	cout << "Pile :" << endl;
	pile.AfficherPile();

	cout << "test de Desemplie : " << pile.DesempilerElem() << endl;
	cout << "Pile apres desempliage :" << endl;
	pile.AfficherPile();

	//Constructeur de copie
	PiledeChar rPile = pile;
	cout << "test de constructeur de copie :" << endl;
	rPile.AfficherPile();
	rPile.EmpilerElem('t');
	rPile.AfficherPile();

	//Fonction afficheinverse()
	cout << "test de Afficheinverse : " << endl;
	char res =afficheinverse(pile);
	cout << res << endl;
	//pile.AfficherPile();

	//Fonction inversemajuscule()
	cout << "test de inversemajuscule : " << endl;
	char r= inversemajuscule(pile);
	cout << r << endl;

	pile.~PiledeChar();
	pile.AfficherPile();


	return 0;
}