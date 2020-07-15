#include <iostream>
#include "Td4Exo1.h"
#include "Td4Exo2.h"

using namespace std;

int main()
{
    // test Exo1
    Vecteur M(3), N(3), P(3);
    int prodScalaire;
    M.RemplirVecteur();
    N.RemplirVecteur();
    cout<<"afficher M \n";
    M.affichage();
    cout<<"afficher N \n";
    N.affichage();
    // 此处调用了两次拷贝构造函数：“+”号一次， “=”号一次，加上上面三次构造函数的调用，接下来一共会调用5次析构函数
    P = M + N; 
    cout<<"afficher P \n";
    P.affichage();  
    prodScalaire = P * N;
    cout<<"le produit scalaire des deux vecteur est: "<<prodScalaire<<endl;

    // test Exo2 bis
    // Forme f; 错误，抽象类不能被实例化

    // Forme *pf;  //但可以建立一个父类类型的指针，但指针只能指向具体类（非抽象类）
    // pf = new Forme; //同理

    // FormeCouleur fc(4); 
    // 上面报错时因为作为Forme的子类，FormeCouleur并没有具体实现父类的纯虚函数（我没写而已，理论上应该要没问题的）
    // 所以FormeCouleur就会依旧时纯虚函数，无法实例化，
    // Cercle *pc = &fc; 不建议这么做，如果以一个衍生类指针指向一个基础类对象，必须先做强制转型动作（explicit cast）
    return 0;
}
