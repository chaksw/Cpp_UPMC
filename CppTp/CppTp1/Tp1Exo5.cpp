#include <iostream>
#include <cmath>    //平方根等运算符对应函数库
#include "Tp1Exo5.h"

using namespace std;

Equation2::Equation2()
{
    cout<<"Saisir les paramètres d'équation"<<endl;
    cin>>a>>b>>c;
    delta = (b*b) - (4*a*c);
    realP = 0;
    imaginaryP = 0;
}
void Equation2::calcule()
{
    
    if (a == 0) 
    {
        x1 = (-c)/b;
        x2 = x1;
    }else if (delta == 0)
    {
        x1 = -b/(2*a);
        x2 = x1;
    }else if (delta > 0)
    {
        x1 = (-b + sqrt(delta))/(2*a);
        x2 = (-b - sqrt(delta))/(2*a);
    }else if (delta < 0)
    {
        realP = -b/(2*a);
        imaginaryP = sqrt(-delta)/(2*a);
    }
}

void Equation2::affichage()
{
    calcule();
    if (a == 0)
    {
        cout<<"c'est pas une équation de second degré"<<endl;
        cout<<"la solution de l'équation "<< b << "x + " << c << " est : "<< x1 <<endl;
    }else if (delta == 0)
    {
        cout<<"les roots sont pareil"<<endl;
        cout<<"la solution de l'équation "<< a << "xˆ2 + " << b << "x + " << c << " est : "<< x1 <<endl;
    }else if (delta > 0)
    {
        cout<<"les roots sont différentes"<<endl;
        cout<<"la solution de l'équation "<< a << "xˆ2 + " << b << "x + " << c << " est : "<<endl;
        cout<< "x1 = "<< x1 <<endl;
        cout<< "x2 = "<< x2 <<endl;
    }else if (delta < 0)
    {
        cout<<"les roots sont différents et imaginaire"<<endl;
        cout<<"la solution de l'équation "<< a << "xˆ2 + " << b << "x + " << c << " est : "<<endl;
        cout<< "x1 = "<< realP << " + i"<< imaginaryP <<endl;
        cout<< "x2 = "<< realP << " - i"<< imaginaryP <<endl;
    }
    
    
    
    
}
