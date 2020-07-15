#include <iostream>
#include "Td5Exo1.h"
#include "Td5Exo2.h"

using namespace std;

int main()
{
    //test Exo1
    double a = 1;
    Vector v(5), v1(5), v2(5);
    v += a;
    cout<<v<<endl;
    v1 += a;
    v2 = v + v1;
    cout<<v1<<"\n"<<v2<<endl;

    // test Exo2
    Matrix m(10,10);
    m(5,8) = 106.15;
    cout<<m(5,8)<<endl;

    // test Exo3
    Vector v3(5);
    v3 = 0, 1, 2, 3, 4;
    cout<<v3<<endl;
    return 0;
}