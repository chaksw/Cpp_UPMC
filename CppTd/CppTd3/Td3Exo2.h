//Review Cpp - TD3
//---------Exo2 - 关于指针和引用作为形参，以及拷贝构造函数的使用和调用情况----------

/*
拷贝构造函数是一种特殊的构造函数，它在创建对象是，是使用同一类中之前创建的对象来
初始化新创建的对象。
拷贝构造函数用于：
    1: 通过使用另一个同类型对象来初始化新创建的对象
    2: 复制对象把它作为参数传递给函数
    3: 复制对象，并从函数返回这个对象
    拷贝构造函数默认是隐式的，即类中没有定义拷贝构造函数，编译器会自行定义一个
    但如果类带有指针变量，并有动态内存分配，则它必须有一个拷贝构造函数
*/


#ifndef _TD3EXO2_H_
#define _TD3EXO2_H_

#include <iostream>

class Chat
{
    public:
        Chat(int age=0,int poids=0):mAge(age),mPoids(poids){};
        ~Chat(){};
        Chat(const Chat &chat); //拷贝构造函数 用const修饰为只读，防止对实参的意外修改
        Chat& operator=(const Chat &chat);   //事实上，拷贝构造函数还可以通过重载赋值运算符“=”来实现
        int LireAge() const;
        void DefAge(int age);
        int LirePoids() const;
        void DefPoids(int poids);
        Chat plusGrosDesDeux(Chat chat);  //复制对象把它作为参数传递给函数,并从函数返回这个对象
    private:
        int mAge;
        int mPoids;
};

#endif
