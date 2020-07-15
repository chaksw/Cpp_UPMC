//Review Cpp - TD2
//---------Exo1----------
#include <iostream>
#include "Td2Exo1.h"
#include "Td2Exo2.h"
#include "Td2Exo3.h"

using namespace std;

int main()
{
    //test Exo1
    Complexe z1(1);
    Complexe z2(5,4);
    if (z1.reelPur()) cout<<"Complexe reel pur"<<endl;

    //test Exo2
    Chat *Poussy = new Chat();  //此处new为*Poussy分配了空间，并调用了Chat的构造函数
    //对于指针构建的对象，其调用类的成员方法的方式是“->“，因为Poussy在这里是一个存放对象的地址，而不是一个对象，所以不能用.
    cout<<Poussy->LireAge()<<endl;  
    Poussy->DefAge(13);
    cout<<Poussy->LireAge()<<endl;

    //test Exo3
    TabFloat ens(10);
    int i;
    for (i = 0; i < ens.Taille(); i++) ens.ajoute(i);
    
    if (ens.appartient(3))
    {
        cout<<"3 appartient au tableau"<<endl;
    }else
    {
        cout<<"3 n'appartient pas au tableau"<<endl;
    }

    cout<<"la somme des éléments saisis du tableau: "<<ens.somme();
    
    
    return 0;
}