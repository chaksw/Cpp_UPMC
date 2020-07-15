#include "CBasePIle.h"
#include <iostream>
using namespace std;

CBasePile::CBasePile(int aMax)
{
	if (aMax < 0)
	{
		aMax = -aMax;
	}
	mMax = aMax;
	mSommet = 0;
	mPile = new int[mMax];
	mPile[0] = 0;
	cout << "le constructeur de CBasePile" << endl;
}

//constructeur par copie
CBasePile::CBasePile(const CBasePile &rp)
{
	mMax = rp.mMax;
	mSommet = rp.mSommet;
	mPile = new int[mMax];
	for (int i = 0; i < mMax; i++)
	{
		mPile[i] = rp.mPile[i];
	}

	cout << "le constructeur par coipe de CBasePile" << endl;
}

//destructeur
CBasePile::~CBasePile()
{
	cout << "destrcution de la classe CBasePile  ----- "<<"liberer la mémoire -----" << endl;
	delete[] mPile;
	cout << "destruction fini" << endl;
}


//Surcharge de opérateur d'affectations
// rp est la reference de type CBasePile, il faut return un objet de type CBasePile

CBasePile& CBasePile:: operator=(const CBasePile &rp)
{
	delete[] mPile;		//liberer la mémoire
	mMax = rp.mMax;		//affectation de la taille max
	mSommet = rp.mSommet;		//affectation du sommet
	mPile = new int[mMax];		//alloue un nouveau tableau
	for (int i = 0; i < mMax; i++)
	{
		mPile[i] = rp.mPile[i];
	}

	if (mSommet < mMax)
	{
		mPile[mSommet] = 0;
	}

	return *this;
}

int CBasePile::getPile(int i) const 
{
	return mPile[i];
}

int CBasePile::getSommet() const
{
	return mSommet;
}

//Surcharge de opérateur '<'
/*
Cette fonction est commun pour les 2types de pile: on empile de la mem façon,
ajouter à la fin de pile, afiicher un erreur si la pile est rempile
*/
CBasePile& CBasePile::operator<(int a)
{
	if (mSommet < mMax)		//s'il reste de la place dans le pile
	{
		mPile[mSommet] = a;
		mSommet++;
		return *this;
	}
	cout << "pile plein" << endl;
	return *this;
}


//Surcharge de operateur '<<'
ostream& operator<<(ostream& os, const CBasePile & p)
{
	for (int i = 0; i < p.getSommet(); i++)
	{
		os << p.getPile(i) << "    ";
	}
	os << endl;
	return os;
}