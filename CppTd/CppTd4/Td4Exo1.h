//Review Cpp - TD4
//---------Exo1 - 关于拷贝构造函数以及重载运算符的定义和用法----------
#ifndef TD4EXO1_H   
#define TD4EXO1_H

#include <iostream>

class Vecteur
{
    public:
        Vecteur(int i);  
        ~Vecteur();
        Vecteur(const Vecteur &v);
        void affichage();
        void RemplirVecteur();
        // 这4个重载运算符会调用拷贝构造函数
        // 在形参的定义中，const可以更好地保护形参不被意外修改，而&的使用可以令函数修改实参的值
        // 以上两者似乎矛盾，但暂时还想不到为什么,但这么做可以防止内存泄漏或者段错误
        Vecteur operator+(const Vecteur &v);   
        Vecteur& operator=(const Vecteur &v);
        int operator*(const Vecteur &v);
    private:
        int *vecteur;
        int nEle;
        int taille;
};

#endif
// 宏定义：在头文件中使用时，用于防止被多重调用，重复声明意思是"if no define“
// 多重调用的错误通常时include嵌套造成的，比如在a.h文件中#include "c.h“，同时
// b.cpp有导入了#include "a.h" 和 #include "c.h“，这意味着c.h会被调用了两次，
// 如果没有上述的宏定义，就会产生重复引用的相关后果。上面的宏定义意思是，当它没有被宏定义时
// 就定义一个，否则不再定义，这样就避免了重复引用
