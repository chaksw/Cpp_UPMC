//Review Cpp - TD2
//---------Exo2 - 关于new 和 delete----------
#ifndef _TD2EXO2_H_
#define _TD2EXO2_H_

#include <iostream>

class Chat
{
    public:
        Chat(int age=1, int poids=2);   //Clang编译器问题，形参初始化需要在.h文件中进行
        ~Chat();
        int LireAge() const;
        void DefAge(int age);
    private:
        int *mAge;
        int *mPoids;
};

#endif