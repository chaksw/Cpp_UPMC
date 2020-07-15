//Review Cpp - TD2
//---------Exo3 - 关于new 和 delete 以及 指针数组----------
#include <iostream>
#include "Td2Exo3.h"

using namespace std;

TabFloat::TabFloat(int i)
{
    this->tabfloat = new float[i];   //指定空间同时分配大小
    this->taille = i;
    this->nEle = 0;
}

TabFloat::~TabFloat()
{
    delete tabfloat;    //释放内存
}

int TabFloat::Taille() const
{
    return taille;
}

void TabFloat::ajoute(float i)
{
    tabfloat[nEle] = i;
    nEle++;
}

bool TabFloat::appartient(float f)
{
    for (int i = 0; i < nEle; i++)
    {
        if (f == tabfloat[i]) return true;  
    }
    return false;
}

float TabFloat::somme()
{
    float s = 0;
    for (int i = 0; i < nEle; i++)
    {
        s += tabfloat[i];
    }
    return s;
}
