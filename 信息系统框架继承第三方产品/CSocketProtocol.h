#pragma once

#include <iostream>

using namespace std;

class CSocketProtocol
{
public:

	CSocketProtocol() {

	}
	virtual ~CSocketProtocol() {

	}//����������

	/*-----------------------------------------*/
	//��ʼ���ͻ���
	virtual int cltSocketInit() = 0;

	//�ͻ��˷�����
	virtual int cltSocketSend(unsigned char* buf/*in*/, int buflen/*in*/) = 0;

	//�ͻ����ձ���
	virtual int cltSocketRev(unsigned char* buf/*out*/, int* buflen/*out*/) = 0;

	virtual int cltSocketRev_Free(unsigned char* buf/*out*/) = 0;

	//�ͻ����ͷ���Դ
	virtual int cltSocketDestory() = 0;
	/*-----------------------------------------*/
};
