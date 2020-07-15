//Review Cpp - TD2
//---------Exo2 - 关于new 和 delete----------
#include <iostream>
#include "Td2Exo2.h"

using namespace std;

Chat::Chat(int age, int poids)
{
    //new的功能有1：在堆空间中开辟一个存储空间（动态分配内存）2：调用类的构造函数
    //开辟一个存储空间，返回该存储空间的地址，这里就是为*mAge开辟一个存储空间，并返回a的地址，从而使mAge指向a的地址
    this->mAge = new int(age);   //指针变量必须通过new来分配空间和赋值 
    this->mPoids = new int(poids);
}

Chat::~Chat()
{
    delete mAge;    //释放变量所指向的内存
    delete mPoids;
}

int Chat::LireAge() const
{
    return *mAge;
}
void Chat::DefAge(int age)
{
    *mAge = age;
}