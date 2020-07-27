
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "CSocketProtocol.h"
#include "CSkFactoryImp1.h"
#include "HwEncDec.h"

using namespace std;


//���sokect������ļ���

//����������̣����ʵ�����
int SckSendAndRec01(CSocketProtocol* sp, unsigned char* in, int inLength, unsigned char* out, int* outLength)
{
	int ret = 0;

	ret = sp->cltSocketInit();
	if (ret != 0)
	{
		goto End;
	}

	ret = sp->cltSocketSend(in, inLength);
	if (ret != 0)
	{
		goto End;
	}

	ret = sp->cltSocketRev(out, outLength);
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


int main01()
{
	int ret = 0;
	unsigned char in[4096];
	int inLength;

	unsigned char out[4096];
	int outLength;

	strcpy((char*)in, "kangzhenqiang");
	inLength = 12;

	CSocketProtocol* sp = NULL;
	CSkFactoryImp1 factory;
	sp = &factory;

	ret = SckSendAndRec01(sp, in, inLength, out, &outLength);
	if (ret != 0)
	{
		cout << "func SckSendAndRec() err:" << ret << endl;
		return ret;
	}

	system("pause");
	return ret;
}

