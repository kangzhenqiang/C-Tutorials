
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "CSocketProtocol.h"
#include "CSkFactoryImp1.h"
#include "CEncDesProtocol.h"
#include "HwEncDec.h"

using namespace std;


//面向抽象类编程，框架实现完毕
int SckSendAndRec_Enc02(CSocketProtocol* sp, CEncDesProtocol* ed, unsigned char* in, int inLength, unsigned char* out, int* outLength)
{
	int ret = 0;

	unsigned char data[4096];
	int dncLength = 0;

	ret = sp->cltSocketInit();
	if (ret != 0)
	{
		goto End;
	}
	ret = ed->EncData(in, inLength, data, &dncLength);
	if (ret != 0)
	{
		goto End;
	}

	ret = sp->cltSocketSend(data, dncLength);
	if (ret != 0)
	{
		goto End;
	}

	ret = sp->cltSocketRev(data, &dncLength);
	if (ret != 0)
	{
		goto End;
	}
	ret = ed->DecData(data, dncLength, out, outLength);
	if (ret != 0)
	{
		goto End;
	}

	ret = sp->cltSocketRev_Free(out);
	if (ret != 0)
	{
		goto End;
	}

	ret = sp->cltSocketDestory();
	if (ret != 0)
	{
		goto End;
	}

End:

	return ret;
}


int main02()
{
	int ret = 0;
	unsigned char in[4096];
	int inLength;

	unsigned char out[4096];
	int outLength;

	strcpy((char*)in, "kangzhenqiang");
	inLength = 12;

	CSocketProtocol* sp = NULL;
	CEncDesProtocol* ed = NULL;


	CSkFactoryImp1 factory;
	sp = &factory;

	HwEncDec hw;
	ed = &hw;

	ret = SckSendAndRec_Enc02(sp, ed, in, inLength, out, &outLength);
	if (ret != 0)
	{
		cout << "func SckSendAndRec() err:" << ret << endl;
		return ret;
	}

	cout << out << endl;
	system("pause");
	return ret;
}

