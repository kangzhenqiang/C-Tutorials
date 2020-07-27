#pragma once
#include <iostream>
#include "CSkFactoryImp1.h"

using namespace std;

int CSkFactoryImp1::cltSocketInit()
{
	p = NULL;
	len = 0;
	return 0;
}

int CSkFactoryImp1::cltSocketSend(unsigned char* buf, int buflen)
{
	p = (unsigned char*)malloc(sizeof(unsigned char*) * buflen);
	if (p == NULL)
	{
		return -1;
	}
	len = buflen;
	memcpy(p, buf, buflen);
	return 0;
}

int CSkFactoryImp1::cltSocketRev(unsigned char* buf, int* buflen)
{
	if (p == NULL || buflen == NULL)
	{
		return -1;
	}
	*buflen = this->len;
	memcpy(buf, this->p, this->len);
	return 0;
}

int CSkFactoryImp1::cltSocketRev_Free(unsigned char* buf)
{
	return 0;
}

int CSkFactoryImp1::cltSocketDestory()
{
	if (this->p!=NULL)
	{
		free(this->p);
		this->p = NULL;
		this->len = 0;
	}
	return 0;
}
