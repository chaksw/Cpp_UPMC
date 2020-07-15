#ifndef _TD6EXO2_H_
#define _TD6EXO2_H_

#include <iostream>

using namespace std;

template<typename TYPE, unsigned int SIZE>
class Array;

template<typename TYPE, unsigned int SIZE>
ostream& operator<<(ostream&, const Array<TYPE,SIZE> &);

template<typename TYPE, unsigned int SIZE>
class Array
{
    public:
        Array(){};
        ~Array(){};
        TYPE& operator[](unsigned int);
        friend ostream& operator<< <TYPE, SIZE>(ostream&, const Array<TYPE, SIZE>&);
    private:
        TYPE vec[SIZE];
        
};
#endif

template<typename TYPE, unsigned int SIZE>
TYPE& Array<TYPE, SIZE>::operator[](unsigned int n)
{
    if (n > SIZE)
    {
        cout<<"Index exceeds maximum"<<endl;
        return vec[0];
    }
    return vec[n];
    
}

template<typename TYPE,unsigned int SIZE>
ostream& operator<<(ostream& output, const Array<TYPE, SIZE>& v)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout<<v.vec[i]<<"\t";
    }
    cout<<endl;
    return output;
    
}