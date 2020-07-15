#include <iostream>
#include "Tp1Exo4.h"

Tableau::Tableau()
{
    cout<<"Combien de valeur sont à traiter ?"<<endl;
    cin>>nombre;
    Tab = new float[nombre];
    for (int i = 0; i < nombre; i++)
    {
        Tab[i] = i+1.1;
    }
}

float Tableau::moyenne()
{
    float m = 0;
    float sum = 0;
    for (int i = 0; i < nombre; i++)
    {
        sum += Tab[i];
    }
    m = sum/nombre;
    cout<<"la moyenne de ce tableau est: "<<m<<endl;
    return m;
}

bool Tableau::enleveelement()
{
    float e;
    cout<<"taper la valeur cherchée à supprimer"<<endl;
    cin>>e;
    for (int i = 0; i < nombre; i++)
    {
        while (e == Tab[i])
        {
            Tab[i] = 0;
            cout<<"la valeur est suppriméé，on recalcule la monyenne. "<<endl;
            moyenne();
            return true;
        }
    }
    cout<<"la valeur ne faisait pas partie des échantillons et que la moyenne n’a donc pas changée."<<endl;
    return false;
    
}