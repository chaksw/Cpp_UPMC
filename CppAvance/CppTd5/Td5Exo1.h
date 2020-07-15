//Review Cpp - TD5
//---------Exo1 and Exo3 - 关于友元函数和各种重载运算符的书写----------
#ifndef _TD5EXO1_H_
#define _TD5EXO1_H_
#include <iostream>

using namespace std;

class Vector
{
    public:
        double *vect;
        unsigned int size;
        unsigned int nEle;
        Vector(unsigned int s = 0);
        Vector(const Vector &v);
        ~Vector();
        void ajoute(double n);
        double operator[](unsigned int i) const;
        double& operator[](unsigned int i);
        Vector& operator+=(double i);
        Vector& operator-=(double i);
        double& operator,(double n);
        // 类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员。
        // 尽管友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数。
        // 友元函数并不能直接访问类的私有和保护成员，而需要先在友元函数内部建立类的对象，才能调用
        friend Vector operator+(const Vector &v1, const Vector &v2);
        friend Vector operator-(const Vector &v1, const Vector &v2);
        friend ostream& operator<<(ostream &output, const Vector &v);


};


#endif