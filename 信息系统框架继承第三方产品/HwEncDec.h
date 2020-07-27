#pragma once
#include<iostream>

#include "CEncDesProtocol.h"

using namespace std;

class HwEncDec:public CEncDesProtocol
{
public:
	virtual int EncData(unsigned char* plain, int plainlen, unsigned char* cryptdata, int* cryplen);
	virtual int DecData(unsigned char* cryptdata, int cryplen, unsigned char* plain, int* plainlen);
};
