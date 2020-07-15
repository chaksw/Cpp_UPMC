//Review Cpp - TD4
//---------Exo2 - 关于继承和多态，抽象类、虚函数以及纯虚函数以及抽象定义virtual的作用----------
// 虚函数与纯虚函数都是为了实现多态而在基类中定义的
// 纯虚函数一定没有定义，是用来规范派生类的行为，即接口
// 虚函数一定需要定义，基类和派生类都有各自的版本，由多态方式调用的时候动态邦定
// 实现了纯虚函数的子类，该纯虚函数在子类中就编程了虚函数，子类的子类即孙子类可以覆盖该虚函数，由多态方式调用的时候动态绑定。
// 在有动态分配堆上内存的时候，析构函数必须是虚函数，但没有必要是纯虚的。
// 析构函数应当是虚函数，将调用相应对象类型的析构函数，因此，如果指针指向的是子类对象，将调用子类的析构函数，然后自动调用基类的析构函数。
// 有纯虚函数的类是抽象类，不能生成对象，只能派生。他派生的类的纯虚函数没有被改写，那么，它的派生类还是个抽象类
#ifndef _TD4EXO2_H_
#define _TD4EXO2_H_

//Exo2 bis
// 抽象类是为了给其他类提供一个可以继承的适当的基类。抽象类不能被用于实例化对象，它只能作为接口使用。如果试图实例化一个抽象类的对象，会导致编译错误。
// 可用于实例化对象的类被称为具体类。
class Forme
{   public:
        virtual ~Forme(){}; //将析构函数定义为虚函数，防止动态绑定中在析构时发生的内存泄漏
        virtual void affiche() = 0;
};

class FormeCouleur : public Forme
{
    public:
        FormeCouleur():couleur(0){};
        virtual ~FormeCouleur(){};  //将析构函数定义为虚函数，防止动态绑定中在析构时发生的内存泄漏
        FormeCouleur(int c):couleur(c){};
        virtual void Affiche(); //定义虚函数，必须定义
    private:
        int couleur;
};

//一个头文件可以定义多个类，多个源文件调用时只需要include这个头文件即可
// 但从规范角度上看，还是一一对应比较好

// 通过继承，派生类会继承基类的所有方法，除了：
// 1:基类的构造函数、析构函数和拷贝构造函数
// 2:基类的重载运算符（因为会调用拷贝构造函数）
// 3:基类的友元函数（爸爸的朋友不是儿子的朋友、而且友元函数本身就不是成员函数）
// 4:在创建子类对象时，为了初始化从父类继承来的数据成员，默认情况下，系统会先调用其父类的无参构造方法，然后再调用子类的构造方法
// 5:但如果再子类构造函数中有显示调用父类的其他有参构造方法，则系统在创建子类对象时会调用父类的该构造方法
// 继承的格式 class A（派生类） :  访问修饰符（pulic protecter private、默认为private） 基类
class Cercle : public FormeCouleur //用public 这样外部的类和派生类都可以访问这个类内部的成员
{
    public:
        Cercle();
        Cercle(int c, int r):centre(c),rayon(r){};
        void Affiche();
    private:
        int centre;
        int rayon;
};

class Rectangle : public FormeCouleur
{
    public:
        Rectangle();
        Rectangle(int p, int lo, int la):point(p),longueur(lo),largeur(la){};
        virtual ~Rectangle(){}; ////将析构函数定义为虚函数，防止动态绑定中在析构时发生的内存泄漏
        void Affiche();
    private:
        int point;
        int longueur;
        int largeur;
};

class Carre : public Rectangle
{
    public:
        Carre();
        Carre(int p, int l):point_c(p),longueur_c(l){};
    private:
        int point_c;
        int longueur_c;
};




#endif