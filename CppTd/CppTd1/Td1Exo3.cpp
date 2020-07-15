//Review Cpp - TD1
//---------Exo3----------
#include <iostream>
#include "Td1Exo3.h"

using namespace std;

int Mesure:: LireLongueur() const
{    
    cout<<"Longueur de cet objet est: "<<Longueur<<endl;
    return Longueur;
}

void Mesure:: InitLongueur(int L)
{
    Longueur = L;
}

int Mesure::LireLargeur() const
{
    cout<<"Larguer de cet objet est: "<<Largeur<<endl;
    return Largeur;
}

void Mesure::InitLarguer(int L)
{
    Largeur = L;
}

int Mesure::LireHauteur() const
{
    cout<<"Hauteur de cet objet est: "<<Hauteur<<endl;
    return Hauteur;
}

void Mesure::InitHauteur(int H)
{
    Hauteur = H;
}

int Mesure::Calcul_Volume() const
{
    return (Longueur*Largeur*Hauteur);
}
