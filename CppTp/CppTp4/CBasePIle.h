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
