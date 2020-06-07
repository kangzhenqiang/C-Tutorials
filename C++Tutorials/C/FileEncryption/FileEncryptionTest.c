
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "des.h"

void main01()
{
	int ret = 0;
	char* plain = "123456";
	int plainlen = strlen(plain);
	unsigned char crpytbuf[4096] = {0};
	int crytlen = 0;

	//用户使用的函数
	ret = DesEnc(plain, plainlen, crpytbuf, &crytlen);
	if (ret != 0)
	{
		printf("func DesEnc() err:%d\n");
		return ret;
	}
	char plainByDesDec[4096] = {0};
	int plainByDesDecLen = 0;

	//用户使用函数des解密
	ret = DesDec(crpytbuf, crytlen, plainByDesDec, &plainByDesDecLen);
	if (ret != 0)
	{
		printf("func DesDec() err:%d\n");
		return ret;
	}

	if (plainlen != plainByDesDecLen)
	{
		printf("明文长度和解密后的明文长度不一样\n");
	}

	if (memcmp(plain, plainByDesDec,plainlen)==0)
	{
		printf("明文和解密后的明文一样\n");
	}
	else
	{
		printf("明文和解密后的明文不一样\n");
	}

	system("pause");
}
