#include "CBasePIle.h"
#ifndef CPILELIFO_H
#define CPILELIFO_H

class CPileLifo : public CBasePile
{
public:
	CPileLifo(int aMax = 1);
	~CPileLifo();
	void operator >(int & a);
};
#endif		//CPILELIFO_H