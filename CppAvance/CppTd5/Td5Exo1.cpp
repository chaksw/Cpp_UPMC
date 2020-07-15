//Review Cpp - TD5
//---------Exo1 and Exo3 - 关于友元函数和各种重载运算符的书写----------

#include <iostream>
#include "Td5Exo1.h"

using namespace std;

Vector::Vector(unsigned int s)
{
    this->vect = new double[s];    //如果实例化对象是数组，所以析构时析构的也是数组
    this->size = s;
    this->nEle = 0;
    for (int i = 0; i < s; i++)
    {
        this->vect[i] = 0;
    }
    
}

Vector::Vector(const Vector &v)
{
    this->size = v.size;
    for (int i = 0; i < v.size; i++)
    {
        this->vect[i] = v.vect[i];
    }
    
}

Vector::~Vector()
{
    cout<<"delete vector and release space"<<endl;
    delete[] vect;
}

double Vector::operator[](unsigned int i) const //const 表示函数只读，无法做内部修改
{
    if (i >= size)
    {
        cout<<"Index exceeds maximum"<<endl;
        return this->vect[0];
    }
    return this->vect[i];
}

double& Vector::operator[](unsigned int i)
{
    if (i >= size)
    {
        cout<<"Index exceeds maximum"<<endl;
        return this->vect[0];
    }
    return this->vect[i];
}

Vector& Vector::operator+=(double v)
{
    for (int i = 0; i < size; i++)
    {
        this->vect[i] += v;
    }
    return *this;
}

Vector& Vector::operator-=(double v)
{
    for (int i = 0; i < size; i++)
    {
        this->vect[i] -= v;
    }
    return *this;
}

Vector operator+(const Vector &v1, const Vector &v2)
{
    int s = v1.size;
    Vector v(s);
    for (int i = 0; i < s; i++)
    {
        v.vect[i] = v1.vect[i] + v2.vect[2];
    }
    return v;
}

Vector operator-(const Vector &v1, const Vector &v2)
{
    int s = v1.size;
    Vector v(s);
    for (int i = 0; i < s; i++)
    {
        v.vect[i] = v1.vect[i] - v2.vect[2];
    }
    return v;
}

ostream& operator<<(ostream &output,const Vector &v)
{
    for (int i = 0; i < v.size; i++)
    {
        output<<v.vect[i]<<",";
    }
    output<<endl;
    return output;
}

void Vector::ajoute(double n)
{
    this->vect[nEle] = n;
    nEle++;
}
// 重载逗号 放弃
double& Vector::operator,(double n)
{
    ajoute(n);
    return this->vect[nEle-1];
}

