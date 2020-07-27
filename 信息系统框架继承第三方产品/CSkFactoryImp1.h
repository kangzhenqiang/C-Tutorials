#pragma once

#include<iostream>
#include "CSocketProtocol.h"

using namespace std;

class CSkFactoryImp1 :public CSocketProtocol
{
public:

	/*-----------------------------------------*/
	//初始化客户端
	virtual int cltSocketInit();

	//客户端发报文
	virtual int cltSocketSend(unsigned char* buf/*in*/, int buflen/*in*/);

	//客户端收报文
	virtual int cltSocketRev(unsigned char* buf/*out*/, int* buflen/*out*/);

	virtual int cltSocketRev_Free(unsigned char* buf/*out*/);

	//客户端释放资源
	virtual int cltSocketDestory();
	/*-----------------------------------------*/

private:
	unsigned char* p;
	int len;
};


