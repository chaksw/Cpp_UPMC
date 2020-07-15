#ifndef _TP1EXO6_H_
#define _TP1EXO6_H_

class Polynome
{
private:
    int deg;
    double *coffe;
public:
    Polynome(int deg_,double *coffe_);
    ~Polynome(){delete[] coffe;}
    void affichage();
    Polynome integre();
    Polynome deriver();
};


#endif