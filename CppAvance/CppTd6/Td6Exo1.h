// Review Cpp - TD6
//---------Exo1 类模版的定义，书写规格，以及List类的定义----------
// 使用template <class T> 实现类时。若是将函数声明写在.h文件，实现写在.cpp。
// 则出现Undefined symbols for architecture x86_64。应将申明和实现都放在.h文件
#ifndef _TD6EXO1_H_
#define _TD6EXO1_H_
#include <iostream>

using namespace std;
// 单链表的初始化，建立，插入，查找，删除
// 在这个习题中，我们定义了一个list类，它事实上是一个数组的延伸，但比数组有着对组内数据和结构的处理的更加详细的描述
// 在这个类中，我们除了一些常规定义外（构造函数，析构函数，拷贝构造函数等等），还有实现对数组的头尾添加数据，删除头数据
// 以及通过重载运算法实现在具体位置插入数据，在最关键的是，要实现这一系列操作，必须先对数组中的每个元素有基本的描述
// 在这里，我们使用了结构体来描述数组中每个元素的位置（地址），地址中存储的数值以及他的一个元素的地址。
// Prototype de List
template <typename ELEM>
class List;

// Prototype de operator<<
template<typename ELEM>
ostream &operator<<(ostream&, const List<ELEM>&);
template<typename ELEM> class List
{
    public:
        // Constructeur et destructeur
        List():head(0),tail(0){};
        // Destructeur de la première ceullue (destruction récursive)
        virtual ~List(){delete head;};
        // Contructeur de copie et operator=
        List(const List &);
        List& operator=(const List &);
        // Accesseur
        bool is_empty() const {return head == 0;}
        // Ajouter un élément à la liste
        void append(ELEM); // à la fin
        void prepend(ELEM); // au début
        void insert(ELEM); // à sa place selon ELEM ::operator<
        // Supprimer la tête de liste
        ELEM get_first();
        // Affichage
        friend ostream& operator<< <ELEM>(ostream&, const List<ELEM>&);
    private:
        // Le type Cell
        // 通过结构体对数组每个元素进行描述
        struct Cell
        {
            ELEM val;   //元素值 类型为ELEM
            Cell *next; //当前元素对下一个元素的地址
            Cell(ELEM v, Cell *n = 0):val(v),next(n){}   // 构造结构体，每个cell包含当前元素值v以及对下元素的地址n
            ~Cell(){delete next;}   // 析构结构体
        };
        Cell *head; // Pointeur sur la première cellule
        Cell *tail; // Pointeur sur lq dernière cellule
        
};

#endif






template<typename ELEM> 
List<ELEM>::List(const List& l)
{      
    cout<<"copy constructor used"<<endl;
    this->head = l->head;
    this->tail = l->tail;
    
}

template <typename ELEM>
List<ELEM>& List<ELEM>::operator=(const List &l)
{
    this->head = l->head;
    this->tail = l->tail;
}

// ajouter à la fin
// 在数组添加的元素是以一个结构体Cell为单位的，在添加时，先保证数组并非为空，然后通过更改数组中元素的地址属性来进行元素的添加和删除
template<typename ELEM>
void List<ELEM>::append(ELEM e)
{
    // 调用模版类下的结构体。在堆空间中分配地址,并初始化元素的元素值
    List<ELEM>::Cell *c = new List<ELEM>::Cell(e);  //留意类中结构体的调用，结构体会创建实际变量，如果变量为指针，则需要用new分配空间
    if (this->tail !=0)
    {
        this->tail->next = c;   // 在当前元素值对下地址中添加元素,添加的元素的元素值为e
    }
    this->tail = c;     // 将添加的元素设为尾元素，
    if (is_empty())
    {
        this->head = c; // 如果数组为空，则c设为头元素，更新后头元素就是尾元素，
    }
}

// ajouter au début
template<typename ELEM>
void List<ELEM>::prepend(ELEM e)
{
    List<ELEM>::Cell *c = new List<ELEM>::Cell(e);
    if(is_empty())
    {
        this->head = c;
        this->tail = c;     // 如果数组为空，则将头尾元素都设为添加的元素，头元素就是尾元素（地址数值都一样）
    }else
    {
        c->next = this->head;   // 如果数组不为空，则先将目前头元素移动到要添加的元素的对下个地址位
        this->head = c;     //然后将要添加的元素设为头文件
    }
    
}

// insère un élément devant le premier élément de la liste qui lui est supérieur ou égal(ou à la fin
// s'il n'existe pas de tel élément). Cette opérqtion suppose que le type ELEM dispose des opérateurs de 
// comparaision et en particulier d'operator<: Si on construit la liste uniquement à partir d'appels de insert(),
// la liste est donc toujours ordonnée
template<typename ELEM>
void List<ELEM>::insert(ELEM e)
{
    List<ELEM>::Cell *cur_ele = this->head;
    if (is_empty() || (cur_ele->val <= e && cur_ele->next != 0))
    {
        this->prepend(e);
    }else
    {
        this->append(e);
    }
}

template<typename ELEM>
ELEM List<ELEM>::get_first()
{
    ELEM res = 0;
    if (is_empty())
    {
        cout<<"no element, cause the list is empty !!"<<endl;
        return 0;
    }else if (this->head == this->tail)
    {
        res = this->head->val;
        delete this->head;
        this->head = 0;
        this->tail = 0;
        cout<<res<<endl;
        return res;
    }
    res = this->head->val;
    List<ELEM>::Cell *ptr = this->head->next;
    delete this->head;
    this->head = ptr;
    cout<<res<<endl;
    return res;
}

template<typename ELEM>
ostream& operator<<(ostream& output, const List<ELEM>& l)
{
    struct List<ELEM>::Cell *c = l->head;
    while(c->next != NULL)
    {
        output<<*(c->val)<<"\t";
        c = c->next;
    }
    output<<endl;;
    return output;
}

