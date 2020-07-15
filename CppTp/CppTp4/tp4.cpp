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