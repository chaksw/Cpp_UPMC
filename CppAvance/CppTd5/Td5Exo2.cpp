//Review Cpp - TD5
//---------Exo1 and Exo3 - 关于友元函数和各种重载运算符的书写----------
#include <iostream>
#include "Td5Exo2.h"

using namespace std;

Matrix::Matrix(unsigned rows, unsigned cols)
{
    cout<<"constructor used"<<endl;
    this->rows_ = rows;
    this->cols_ = cols;
    this->data_ = new double[rows];    //一维数组转化为二维数组的形式,内存连续，但是不能用[][]指定某个值
    // 这种转化实际上是jiang
    if ((rows == 0) || (cols == 0))    
    {
        cout<<"Error !! can't create Matrix !"<<endl;
    }
}

Matrix::Matrix(const Matrix &m)
{
    cout<<"copy constructor used"<<endl;
    this->rows_ = m.rows_;
    this->cols_ = m.cols_;
    this->data_ = new double[rows_*cols_];
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; i++)
        {
            this->data_[i+j] = m.data_[i+j];
        }
        
    }
}

Matrix::~Matrix()
{
    cout<<"delete and release space"<<endl;
    delete []data_;
}
// 函数调用运算符 () 可以被重载用于类的对象。当重载 () 时，您不是创造了一种新的调用函数的方式，
// 相反地，这是创建一个可以传递任意数目参数的运算符函数。
double& Matrix::operator()(unsigned rows, unsigned cols)
{
    if ((rows >= rows_) || (cols >= cols_))
    {
        cout<<"Matrix inedc"<<endl;
    }
    return data_[rows+cols];
    
}

double Matrix::operator()(unsigned rows, unsigned cols) const
{
    if ((rows >= rows_) || (cols >= cols_))
    {
        cout<<"Matrix inedc"<<endl;
    }
    return data_[rows+cols];
    
}
