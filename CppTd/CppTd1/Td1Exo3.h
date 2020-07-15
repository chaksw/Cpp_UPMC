#ifndef _TD1EXO3_H_
#define _TD1EXO3_H_

#include <iostream>

class Mesure
{
    public:
        //初始化列来表示初始化字段,效果等同Td1Exo2的构造函数
        Mesure(int Longueur, int Largeur, int Hauteur):Longueur(Longueur),Largeur(Largeur),Hauteur(Hauteur){};
        ~Mesure(){};
        int LireLongueur() const;
        void InitLongueur(int L);
        int LireLargeur() const;
        void InitLarguer(int L);
        int LireHauteur() const;
        void InitHauteur(int H);
        int Calcul_Volume() const;

    private:
        int Longueur;
        int Largeur;
        int Hauteur;
    
};

#endif