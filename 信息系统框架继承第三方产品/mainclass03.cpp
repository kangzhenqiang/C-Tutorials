
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "CSocketProtocol.h"
#include "CSkFactoryImp1.h"
#include "CEncDesProtocol.h"
#include "HwEncDec.h"

using namespace std;

/* 
//改变类的功能有继承和组合，一般不使用多继承
//注入
//抽象类在多继承中应用
class MainOp :public CEncDesProtocol, public CSocketProtocol
{
public:


private:

};
*/


class MainOP
{
public:
	MainOP() {
		this->sp = NULL;
		this->ed = NULL;
	}
	MainOP(CSocketProtocol* sp, CEncDesProtocol* ed) {
		this->sp = sp;
		this->ed = ed;
	}

	void setCSocketProtocol(CSocketProtocol* sp)
	{
		this->sp = sp;
	}

	void setCEncDesProtocol(CEncDesProtocol* ed)
	{
		this->ed = ed;
	}

	int SckSendAndRec_Enc(unsigned char* in, int inLength, unsigned char* out, int* outLength)
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

private:
	CSocketProtocol* sp;
	CEncDesProtocol* ed;
};


//面向抽象类编程，框架实现完毕

int main()
{
	int ret = 0;
	unsigned char in[4096];
	int inLength;

	unsigned char out[4096];
	int outLength;

	strcpy((char*)in, "kangzhenqiang");
	inLength = sizeof("kangzhenqiang");

	CSocketProtocol* sp = NULL;
	CEncDesProtocol* ed = NULL;

	CSkFactoryImp1 factory;
	sp = &factory;

	HwEncDec hw;
	ed = &hw;

	MainOP mainOp(sp, ed);
	ret = mainOp.SckSendAndRec_Enc(in, inLength, out, &outLength);
	out[outLength] = '\0';
	if (ret != 0)
	{
		cout << "func SckSendAndRec() err:" << ret << endl;
		return ret;
	}

	cout << out << endl;
	system("pause");
	return ret;
}

