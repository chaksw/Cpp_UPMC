#ifndef _TD2EXO1_H_
#define _TD2EXO1_H_

#include <iostream>

class Complexe
{
    public:
        Complexe(float r=0, float i=0):reel(r),imag(i){};
        ~Complexe(){};
        bool reelPur();
    private:
        float reel;
        float imag;
};

#endif

