#ifndef _TP1EXO4_H_
#define _TP1EXO4_H_

#include <iostream>

using namespace std;

class Tableau
{
    public:
        Tableau();
        ~Tableau(){delete []Tab;};
        float moyenne();
        bool enleveelement();
    private:
        float *Tab;
        unsigned int nombre;
};
#endif
