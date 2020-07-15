//Review Cpp - TD1
//---------Exo1 - 关于函数重载----------
#include<iostream>
#include "Td1Exo1.h"
using namespace std;

/*函数重载：在同一个作用域中，允许声明多个功能类似的同名函数
  它们的参数列表必须不相同，但实现方式（定义）和返回值可以不同
*/



int calcul_diviser:: diviser(int a, int b)
{
    return a/b;
}
int calcul_diviser::diviser(float a, float b)
{
    return (int)(a/b);
}
int calcul_diviser::diviser(double a, double b)
{
    return int(a/b);
}


