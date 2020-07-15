#ifndef _TD5EXO2_H_
#define _TD5EXO2_H_

#include<iostream>

using namespace std;

class Matrix
{
    public:
        Matrix(unsigned rows, unsigned cols);   //没有定义数据类型，只定义为非负数，这样调用的形参可以是 int double float等
        Matrix(const Matrix &m);
        ~Matrix();
        double &operator()(unsigned row, unsigned col);
        double operator()(unsigned row, unsigned col) const;
        Matrix& operator=(const Matrix &m);
        friend ostream& operator<<(ostream &output, const Matrix &m);
    private:
        unsigned rows_,cols_;
        double *data_;

};

#endif