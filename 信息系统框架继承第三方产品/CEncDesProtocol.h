#pragma once

class CEncDesProtocol
{
public:
	virtual ~CEncDesProtocol() {

	}

	virtual int EncData(unsigned char* plain, int plainlen, unsigned char* cryptdata, int* cryplen) = 0;
	virtual int DecData(unsigned char* cryptdata, int cryplen, unsigned char* plain, int* plainlen) = 0;
};
