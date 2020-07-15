//Review Cpp - TD3
//---------Exo2 - 关于指针和引用作为形参，以及拷贝构造函数的使用和调用情况----------
#include <iostream>
#include "Td3Exo2.h"

using namespace std;

Chat::Chat(const Chat &chat)
{
    //定义拷贝值
    cout<<"constructeur de copie"<<endl;
    this->mAge = chat.mAge; 
    this->mPoids = chat.mPoids;
    // this指针是一个额外的隐式参数，它用于访问调用它的对象的地址，是所有成员函数的隐含参数，他的函数就是：”这个对象的“某个成员
    // 在成员函数内部，我们其实无须通过this来访问对象的成员，但设计继承和友元函数时，要注意
    // 除此之外，事实上，我们可以通过*this来指代当前对象,以便在不定义实名对象时调用成员函数和变量
    // 另外根据测试，this似乎能防止析构函数过早地调用
}
//事实上，拷贝构造函数还可以通过重载赋值运算符“=”来实现
Chat& Chat:: operator=(const Chat &chat)
{
    if(&chat != this)
    {
        this->mAge = chat.mAge;
        this->mPoids = chat.mPoids;
    }
    return *this;
}
int Chat::LireAge() const
{
    return this->mAge;
}

void Chat::DefAge(int age)
{
    this->mAge = age;
}

int Chat::LirePoids() const
{
    return this->mPoids;
}

void Chat::DefPoids(int poids)
{
    this->mPoids = poids;
}

Chat Chat::plusGrosDesDeux(Chat chat)
{
    if (this->LirePoids()>chat.LirePoids()) return *this;   //通过*this来指代当前对象，调用成员函数
    return chat;
}
