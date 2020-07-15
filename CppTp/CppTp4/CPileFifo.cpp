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