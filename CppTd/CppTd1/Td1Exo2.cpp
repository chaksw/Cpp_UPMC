//Review Cpp - TD1
//---------Exo2----------
#include <iostream>
#include "Td1Exo2.h"

using namespace std;

//定义成员函数实现方式
Chien::Chien(int initage)
{
    mAge = initage; //初始化成员变量
    cout<<"Constructeur Chien"<<endl;
}

Chien::~Chien()
{
    cout<<"Destructeur Chien"<<endl;
}

int Chien::LireAge() const
{
    return(mAge);
}

void Chien::DefAge(int age)
{
    mAge = age;
}

void Chien::Aboyer()
{
    cout<<"Ouaff!! Ouaff!!"<<endl;
}

