#ifndef _TD1EXO2_H_
#define _TD1EXO2_H_

#include <iostream>

class Chien
{
    public :    //定义公共成员（变量、函数），即在类的外部、模块内部的函数可以访问的
        Chien(int initage); //构造函数，不返回任何类型，包活void，可用于为成员变量设置初始值
        ~Chien();   //析构函数,用于删除所创建的对象，它会在main函数所用命令执行完后自动执行），释放内存
        int LireAge() const;    //定义只读（const）函数，此函数只有定义为const的对象所调用，同时，此函数不能修改类同类下成员变量的值
        void DefAge(int age);
        void Aboyer();
    private:
      int mAge;   //私有成员变量，说明该变量只能被同类中其他成员访问，在类外部不能直接访问
};

#endif