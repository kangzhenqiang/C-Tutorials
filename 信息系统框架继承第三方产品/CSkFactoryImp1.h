#pragma once

#include<iostream>
#include "CSocketProtocol.h"

using namespace std;

class CSkFactoryImp1 :public CSocketProtocol
{
public:

	/*-----------------------------------------*/
	//��ʼ���ͻ���
	virtual int cltSocketInit();

	//�ͻ��˷�����
	virtual int cltSocketSend(unsigned char* buf/*in*/, int buflen/*in*/);

	//�ͻ����ձ���
	virtual int cltSocketRev(unsigned char* buf/*out*/, int* buflen/*out*/);

	virtual int cltSocketRev_Free(unsigned char* buf/*out*/);

	//�ͻ����ͷ���Դ
	virtual int cltSocketDestory();
	/*-----------------------------------------*/

private:
	unsigned char* p;
	int len;
};


