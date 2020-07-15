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