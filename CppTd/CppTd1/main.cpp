//Review Cpp - TD1
//---------Exo 1 2 3----------
#include <iostream>
#include "Td1Exo1.h"
#include "Td1Exo2.h"
#include "Td1Exo3.h"

using namespace std;

int main()
{
    //test Exo1
    calcul_diviser cd;
    int a = 30, b;
    float c = 30.12,d;
    double e = 33.12, f;
    cin >> b >> d >> f;
    cout << cd.diviser(a,b) << "\n" 
    << cd.diviser(c,d) << "\n"
    << cd.diviser(e,f) << endl;
    
    //test Exo2
    Chien Fido(10);
    Fido.Aboyer();
    Fido.DefAge(5);

    //test Exo3
    Mesure M1(2,4,5);
    Mesure M2(3,5,7);
    M1.InitHauteur(8);
    M1.LireHauteur();
    cout<< "la volume de M1 is:" << M1.Calcul_Volume()<<endl;

    M2.InitLarguer(9);
    M2.LireLargeur();
    M2.Calcul_Volume();
    cout<< "la volume de M2 is:" << M2.Calcul_Volume()<<endl;

    return 0;
}
