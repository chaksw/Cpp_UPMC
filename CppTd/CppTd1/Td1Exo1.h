//Review Cpp - TD1
//---------Exo1 - 关于函数重载----------
#ifndef _TD1EXO1_H_
#define _TD1EXO1_H_
#include<iostream>

class calcul_diviser
{
    public:
        calcul_diviser(){};
        ~calcul_diviser(){};
        int diviser(int a,int b);
        int diviser(float a,float b);
        int diviser(double a,double b);
};

#endif