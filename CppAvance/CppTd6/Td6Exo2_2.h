#ifndef _TD6EXO2_2_H_
#define _TD6EXO2_2_H_

#include <iostream>

using namespace std;

template<typename TYPE,unsigned int SIZE1,unsigned int SIZE2>
class Array2D;

template<typename TYPE, unsigned int SIZE1,unsigned int SIZE2>
ostream& operator<<(ostream&, const Array2D<TYPE, SIZE1, SIZE2> &);

template<typename TYPE,unsigned int SIZE1,unsigned int SIZE2>
class Array2D
{
    public:
        Array2D(){};
        ~Array2D(){};
        TYPE& operator[](unsigned int);
        friend ostream& operator<< <TYPE, SIZE1,SIZE2>(ostream&, const Array2D<TYPE, SIZE1, SIZE2>&);
    private:
        TYPE v2d[SIZE1][SIZE2];
};
#endif


template<typename TYPE,unsigned int SIZE1,unsigned int SIZE2>
TYPE& Array2D<TYPE,SIZE1,SIZE2>::operator[](unsigned int n)
{
        if ((n*SIZE2) > (SIZE1*SIZE2))
    {
        cout<<"Array 2D Index exceeds maximum"<<endl;
        return v2d[0][0];
    }
    return v2d+n*SIZE2;
}

template<typename TYPE,unsigned int SIZE1,unsigned int SIZE2>
ostream& operator<<(ostream& output, const Array2D<TYPE,SIZE1, SIZE2> & a2d)
{
    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE2; j++)
        {
            cout<<a2d.v2d[i][j]<<"\t";
        }
        
    }
    cout<<endl;
    return output;
    
}
