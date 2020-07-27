#include "HwEncDec.h"
#include "des.h"


int HwEncDec::EncData(unsigned char* plain, int plainlen, unsigned char* cryptdata, int* cryplen)
{
	int ret = 0;
	ret = DesEnc(plain, plainlen, cryptdata, cryplen);

	if (ret != 0)
	{
		printf("func EncData() err:%d\n", ret);
		return ret;
	}
	return 0;
}

int HwEncDec::DecData(unsigned char* cryptdata, int cryplen, unsigned char* plain, int* plainlen)
{
	int ret = 0;
	ret = DesDec(cryptdata, cryplen, plain, plainlen);
	if (ret != 0)
	{
		printf("func DecData() err:%d", ret);
		return ret;
	}

	return 0;
}
