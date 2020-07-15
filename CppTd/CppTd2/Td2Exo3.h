//Review Cpp - TD2
//---------Exo3 - 关于new 和 delete 以及 指针数组----------
#ifndef _TD2EXO3_H_
#define _TD2EXO3_H_

#include <iostream>

class TabFloat
{
    public:
        TabFloat(int i);
        ~TabFloat();
        int Taille() const;
        void ajoute(float i);
        bool appartient(float f);
        float somme();
    private:
        float *tabfloat;
        int taille;
        int nEle;
};

#endif