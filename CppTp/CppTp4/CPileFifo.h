#include "CBasePIle.h"
#ifndef CPILEFIFO_H
#define CPILEFIFO_H


class CPileFifo :public CBasePile
{
public:
	CPileFifo(int aMax = 1);
	~CPileFifo();
	void operator >(int & a);
};
#endif		//CPILEFIFO_H
