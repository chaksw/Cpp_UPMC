//Review Cpp - TD4
//---------Exo1 - 关于拷贝构造函数以及重载运算符的定义和用法----------

#include <iostream>
#include "Td4Exo1.h"

using namespace std;

Vecteur::Vecteur(int i)
{
    cout<<"constructeur"<<endl;
    this->vecteur = new int[i];
    this->taille = i;
    this->nEle = 0;
}

Vecteur::Vecteur(const Vecteur &v)
{
    cout<<"constructeur de copie"<<endl;
    this->vecteur = v.vecteur;
    this->taille = v.taille;
    this->nEle = v.nEle;
}

Vecteur::~Vecteur()
{
    cout<<"vecteur is being deleted"<<endl;
    delete this->vecteur;
}
  

void Vecteur::affichage() 
{
    for (int i = 0; i < nEle; i++)
    {
        cout<<"the no."<< i << " is: "<< this->vecteur[i]<<"\n";
    }
    cout<<endl;
    
}

void Vecteur::RemplirVecteur()
{
    while (nEle < taille)
    {
        int n;
        cin>>n;
        this->vecteur[nEle] = n;
        nEle++;
    }
    
}

Vecteur Vecteur::operator+(const Vecteur &v)
{
    // 下面的对象时成员函数内部建立的对象，数据局部变量，存储在栈空间，
    // 当函数进行返回后，这个对象便会调用析构函数进行内存和值的释放，不再存在，所以不能作为返回值
    Vecteur vs(taille);
    for (int i = 0; i < taille; i++)
    {
        vs.vecteur[i] = this->vecteur[i] + v.vecteur[i];
    }
    cout<<"+++++++++"<<endl;
    return vs;
}

Vecteur& Vecteur::operator=(const Vecteur &v)
{
    for (int i = 0; i < taille; i++)
    {
        this->vecteur[i] = v.vecteur[i];
    }
    cout<<"========="<<endl;
    return *this;
}

int Vecteur::operator*(const Vecteur &v)
{
    int prodScalaire = 0;
    Vecteur vm(taille);
    for (int i = 0; i < taille; i++)
    {
        prodScalaire += this->vecteur[i] * v.vecteur[i];
    }
    return prodScalaire;
}