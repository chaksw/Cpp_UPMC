#ifndef _TP1EXO5_H_
#define _TP1EXO5_H_

#include <iostream>


class Equation2
{
private:
    double a,b,c,x1,x2,delta,realP,imaginaryP;
public:
     Equation2();
    ~ Equation2(){};
    void calcule();
    void affichage();
};


#endif