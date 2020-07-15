//Review Cpp - TD3
//---------Exo2 - 关于指针和引用作为形参，以及拷贝构造函数的使用和调用情况----------
#include <iostream>
#include "Td3Exo2.h"

using namespace std;

int maMultiplication(int &a, int *b)
{
    return a*(*b);
}

int plusGrandDesDeux(int &a, int *b)
{
    return (a>(*b) ? a:(*b));   
}

int main()
{
    //test Exo1
    int a = 2;
    int *b = new int(3);    //指针变量必须通过new来分配空间和赋值
    cout << maMultiplication(a,b)<< "\n"
    << plusGrandDesDeux(a,b)<<endl;
    delete b;   //并且在使用完后要释放相应内存

    //test Exo2
    Chat Poussy1(2,500);
    Chat Minette1 = Poussy1;
    cout<<"Poids de Poussy1 is: "<<Poussy1.LirePoids()<<endl;
    cout<<"Poids de Minette1 is: "<<Minette1.LirePoids()<<endl;
    //test Exo2 last question
    Chat Poussy(1,900),Minette(2,800);
    Chat Attila;
    //拷贝构造函数会在通过相同的类来初始化新对象时被调用一次。这里对应是“=”时
    Attila = Poussy.plusGrosDesDeux(Minette);
    cout<<"Atiila a "<<Attila.LireAge()<<" ans ";
    cout<<"et pese "<<Attila.LirePoids()<<" g "<<endl;
    Attila = Minette;
    cout<<Attila.LirePoids()<<endl;

    return 0;
}