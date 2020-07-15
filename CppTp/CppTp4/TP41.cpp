//--------------TP4------------
//-------------CBASEPILE_H------------
#ifndef CBASEPILE_H
#define CBASEPILE_H
#include <iostream>
using namespace std;


class CBasePile
{
public:
	CBasePile(int aMax = 1);		//constructeur
	CBasePile(const CBasePile& rp);		//constructeur par copie
	~CBasePile();		//destructeur

protected:
	int mMax;		//la taille max
	int mSommet;		// le sommet de pile
	int *mPile;		//un pointeur qui point sur tableau de int

public:
	int getSommet() const;
	int getPile(int i) const;

	CBasePile& operator =(const CBasePile& p);
	CBasePile& operator <(int a);
	virtual void operator >(int& a) = 0;		//méthode de virtual pure qui sera redéfini dans la classe file

};

ostream& operator<<(ostream &os, const CBasePile &p);
#endif		//CBASEPILE_H




//-------------CBASEPILE_CPP------------
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




//-------------CPILEFIFO_H------------
#include "CBasePIle.h"
#ifndef CPILEFIFO_H
#define CPILEFIFO_H


class CPileFifo :public CBasePile
{
public:
	CPileFifo(int aMax = 1);
	~CPileFifo();
	void operator >(int & a);
};
#endif		//CPILEFIFO_H



//-------------CPILEFIFO_CPP------------
#include "CBasePIle.h"
#include "CPileFifo.h"
#include <iostream>
using namespace std;

//constructeur
CPileFifo::CPileFifo(int aMax) :CBasePile(aMax)
{
	cout << "le constructeur de  la classe CPileFifo" << endl;
}

//destructeur
CPileFifo::~CPileFifo()
{
	cout << "-----destructeur de la classe CPileFifo-----" << endl;
	cout << "destrcution fini" << endl;
}

//Surcharge de l'opérateur '>' ,méthode dépile
void CPileFifo::operator>(int &a)
{
	if (mSommet > 0)		//si le tableau pile n'est pas vide
	{
		a = mPile[0];		//dépiler la première valeur
		mSommet--;
		for (int i = 0; i < mSommet; i++)
		{
			mPile[i] = mPile[i + 1];
		}
	}
	else {
		cout << "le pile est vide" << endl;
	}
}





//-------------CPILELIFO_H------------
#include "CBasePIle.h"
#ifndef CPILELIFO_H
#define CPILELIFO_H

class CPileLifo : public CBasePile
{
public:
	CPileLifo(int aMax = 1);
	~CPileLifo();
	void operator >(int & a);
};
#endif		//CPILELIFO_H





//-------------CPILELIFO_CPP------------


#include "CBasePIle.h"
#include "CPileLifo.h"
#include <iostream>
using namespace std;

//constructeur
CPileLifo::CPileLifo(int aMax) :CBasePile(aMax)
{
	cout << "le constructeur de  la classe CPileLifo" << endl;
}

//destructeur
CPileLifo::~CPileLifo()
{
	cout << "-----destructeur de la classe CPileLifo-----" << endl;
	cout << "destrcution fini"<<endl;
}

//Surcharge de l'opérateur '>' ,méthode dépile
void CPileLifo::operator>(int &a)
{
	if (mSommet > 0)		//si le tableau pile n'est pas vide
	{
		a = mPile[mSommet-1];		//dépiler la dernière valeur
		mSommet--;
		
	}
	else {
		cout << "le pile est vide" << endl;
	}

}




//------------------main------------------
#include "CBasePIle.h"
#include "CPileFifo.h"
#include "CPileLifo.h"
#include <iostream>
using namespace std;
/*
-  les structures de donnee commune à une pile LIFO et FIFO sont la taille actuelle de pile et la taille maximale de pile
   donc les données membres de la classe base sont deux entiers mMax et mSommet et un tableu pile

- les opérateur communs aux piles LIFO et FIFO : '=', '>' et '<'
*/


int main()
{
	CBasePile *ptPile;
	CPileFifo fifo(5);		//pile First In First Out
	CPileLifo lifo(5);			//pile Last In First Out


	ptPile = &fifo;		//ptPile pointe vers la pile FIFO
	cout << "on empile les valeurs, 0 1 2 3" << endl;
	*ptPile < 0 < 1< 2< 3;		// on empile 0 1 2 3
	cout << "pile=" << *ptPile << endl;

	
	int i;
	cout << "on dépile la première valeur" << endl;
	*ptPile > i;		//dépile dans i
	cout << "pile=" << *ptPile << "i=" << i << endl;		// à l'écran : pile=1 2 3 i=0

	cout << "on empile 2 valeurs 0 et 1" << endl;
	ptPile = &lifo;		//ptPile pointe vers la pile LIFO
	*ptPile < 0 < 1;		//on empile 0 puis 1
	cout << "pile=" << *ptPile << endl;;		// à l'écran : pile =0 1

	cout << "on dépile la dernière valeur" << endl;
	*ptPile > i;		// dépile dans i
	cout << "pile=" << *ptPile << "i=" << i << endl;		//à l'écran : pile =0  i=1

	return 0;
}