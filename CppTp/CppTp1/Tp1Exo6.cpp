#include <iostream>
#include "Tp1Exo6.h"

using namespace std;

Polynome::Polynome(int degre_, double *coffe_)
{
    deg = degre_;
    if (deg < 0)
    {
        coffe = new double[(-deg)+1];
    }else if (deg > 0)
    {
        coffe = new double[deg+1];
    }else
    {
        cout<<"Erreur !! le degré ne peut pas etrê zéro"<<endl;
    }
    for (int i = 0; i < sizeof(coffe); i++)
    {
        coffe[i] = coffe_[i];
    }  
}
// 求积分
Polynome Polynome::integre()
{  
    double *coffeNew = new double[deg+2]();
    int d = deg;
    for (int i = 0; i < deg+1; i++) // 不能用sizeof(),因为这里定义的是一个数组指针，size(double指针) 是8
    {
        coffeNew[i] = coffe[i]/(d+1);
        d--;
    }
    coffeNew[deg+1] = 0;
    Polynome p(deg+1,coffeNew);
    delete[] coffeNew;
    return p; 
}
// 求导
Polynome Polynome::deriver()
{
    double *coffeNew = new double[deg];
    int d = deg;
    for (int i = 0; i < deg; i++)
    {
        coffeNew[i] = coffe[i]*d;
        d--;
    }
    Polynome p(deg-1,coffeNew);
    delete[] coffeNew;
    return p;
}

void Polynome::affichage()
{
    cout<<"le polynome est: "<<"\t";
    for (int i = 0; i < deg+1; i++)
    {
        
        if (i != deg)
        {
            cout<<coffe[i]<<"x^"<<deg-i<<" + ";
        }else
        {
            cout<<coffe[i];
        }
        
    }
    cout<<endl; 
}