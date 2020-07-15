#include <iostream>
#include <string>
#include "Td6Exo1.h"
#include "Td6Exo2.h"
#include "Td6Exo2_2.h"


using namespace std;

int main()
{
    // 二维数组以及重载运算符<<不会做！！！
    // Test Exo1 operator<< is not secessful
    List<int> *l = new List<int>();
    cout<<"========"<<endl;
    l->get_first();
    cout<<"========"<<endl;
    l->prepend(1);
    cout<<"========"<<endl;
    l->append(2);
    cout<<"========"<<endl;
    l->insert(3);
    cout<<"========"<<endl;
    cout<<l<<endl;

    // Test Exo2_1 et Exo2_2 
    Array<double, 15> arr;
    double d = 1.1;
    for (int i = 0; i < sizeof(arr); i++)
    {
        arr[i] = i+d;
    }
    // cout<arr<<endl;

    Array2D<string,3,3> a2d;

    
    return 0;
}