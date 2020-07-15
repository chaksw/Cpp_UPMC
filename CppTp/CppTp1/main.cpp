#include <iostream>
#include <cmath>
#include "Tp1Exo4.h"
#include "Tp1Exo5.h"
#include "Tp1Exo6.h"


using namespace std;
// Exo2
/*函数重载：在同一个作用域中，允许声明多个功能类似的同名函数
  它们的参数列表必须不相同，但实现方式（定义）和返回值可以不同
*/

int additonne(int a, int b)
{
    return a+b;
}

float addtionne(float a, float b)
{
    return a+b;
}

int* addtionne(int *a, int *b)  //用指针形参代替数组，这样函数调用会根据实际需要修改实参的值
{
    int *add = new int[10];
    for (int i = 0; i < sizeof(add); i++)
    {
        add[i] = a[i] + b[i];
    }
    // 对于数组的相加，返回值是*add的话，它只会数组的第一个值，在调用时，虽然会将两个数组进行相加，但最后只会将数组和第一个值返回，其余值为默认值（这里是0）
    return add; //当将函数返回类型设定为指针时，函数会返回数组的头元素地址，实际它所返回的是整个数组
}

// Exo3
float* ech2paradresse(float *a, float *b)
{
    float *c = new float[2];
    if (*a>*b) 
    {
        c[0] = *a; c[1] = *b;
    }else 
    {
        c[0] = *b;
        c[1] = *a;
    }
    return c;
}
float* ordonnetrois(float *a, float *b, float *d)
{
    float *c = new float[3];
    float *e = new float[2];
    c = ech2paradresse(a,b);
    c[2] = c[1];    
    e = ech2paradresse(c+0,d);
    c[0] = e[0];
    c[1] = e[1];
    e = ech2paradresse(c+1,c+2);
    c[1] = e[0];
    c[2] = e[1];
    return c;
}
int main()
{
    // Tp1_Exo1
    // 在C++中，指针无法直接通过赋值来初始化，而必须通过new来声明在堆空间中分配空间地址，
    // New的作用有两个1:分配动态内存（堆空间），2:调用构造函数，其中第二点是new区别于malloc()的关键
    // 用new时，要意识到（）的用处，比如下面的例子
    int *p = new int;   // 对于内置类型（非自定义类，如int,float等）不用括号的new不会将申请到的空间里面的值初始化，值会是随即值
    // 但似乎c++20中，不加括号的new也会对指针进行0初始化
    cout<<"addresse de p: "<<p<<" valeur de p: "<<*p<<endl;
    int *j = new int();     // 如果用到了括号，则new会将申请到的动态空间里面的值初始化为默认值，即0
    cout<<"addresse de j: "<<j<<" valeur de j: "<<*j<<endl;
    int *q = new int(10);   // 括号内加入特定常量，则申请到的动态空间里的值就是对应的常量
    cout<<"addresse de q: "<<q<<" valeur de q: "<<*q<<endl;
    const int *r = new int(20);  //这是常量指针，const的作用是将指针定义为常量（只读，无法修改），这样，我们在对r进行操作时无法修改它所指向的地址值，但存储的值可以修改,而且const指针在创建时必须进行初始化
    cout<<"addresse de r: "<<r<<" valeur de r: "<<*r<<endl;
    int *t = new int[10](); // 同样，对于一维数组，用过new给10个指针分配动态空间，而括号会将这10个动态空间的值初始化为0
    cout<<"addresse de t: "<<t<<" valeur de t: "<<*t<<endl;
    int a = 30;
    // 定义NULL指针，声明变量时，如果没有确切的地址可以赋值，可以为指针变量赋一个NULL，定义为空指针
    int *y =NULL; // 空指针是指指针的地址值为0x0，但指针是不指向任何值的，如果用*y访问指针的值，会出现段错误，原因是访问了不存在的空间
    cout<<"addresse de y: "<<y<<endl;;
    // cout<<" valeur de y: "<<*y<<endl; // 段错误，无法访问指针y指向的值，因为不存在
    int &s = a; //不存在空引用，即引用在创建时必须进行初始化，且初始化的值必须时已存在的另一个变量(const修饰的常量无法作为初始化值)
    *p = a; 
    y = &a;
    cout<<"addresse de p: "<<p<<" valeur de p: "<<*p<<endl;
    cout<<"addresse de s: "<<&s<<" valeur de s: "<<s<<endl;
    cout<<"addresse de y: "<<y<<" valeur de y: "<<*y<<endl;
    delete p;
    delete j;
    delete q;
    delete[] t;

    // test Tp1_Exo2
    int e = 1, b = 2;
    float c = 1.1, d = 2.2;
    int *t1 = new int[10];
    // t1 = {1,2,3,4,5,6,7,8,9,10}; 错误，指针数组无法用花括号初始化
    int *t2 = new int[10];
    for (int i = 0; i < sizeof(t1); i++)
    {
        t1[i] = i;
        t2[i] = i+1;
    }
    int *add = new int[10];
    add = addtionne(t1,t2); // 将函数执行后返回的数组头元素地址赋给add，这样就会将整个数组返回给add
    cout<<addtionne(e,b)<<endl;
    cout<<addtionne(c,d)<<endl;
    for (int i = 0; i < sizeof(add); i++)
    {
        cout<<add[i]<<"\t";
    }
    cout<<endl;
    
    // test Exo3
    float f=10.5,g=5.3,h=-0.2;
    float *t3 = new float[3];
    t3 = ordonnetrois(&f,&g,&h);
    for (int i = 0; i < 3; i++)
    {
        cout<<t3[i]<<"\t";
    }
    cout<<endl;

    // Test Exo4
    Tableau *tab = new Tableau();
    tab->moyenne();
    tab->enleveelement();
    tab->enleveelement();

    // Test Exo5
    Equation2 equa;
    equa.affichage();
    
    // Test Exo6
    int deg;
    cout<<"saisir le degre:";
    cin>>deg;

    double coeff1[deg+1];

    for(int i=0;i<deg+1;i++){
        cout<<"Saisir la "<<deg-i+1<<"e valeur du polynome: ";
        cin>>coeff1[i];
    }

    cout<<"Le polynome est"<<endl;
    Polynome P1 = Polynome(deg,coeff1);
    P1.affichage();

    cout<<"Le polynome integre est"<<endl;
    Polynome P2 = P1.integre();
    P2.affichage();

    cout<<"Le polynome derive est"<<endl;
    Polynome P3 = P1.deriver();
    P3.affichage();
    
    return 0;
}