
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

	//�û�ʹ�õĺ���
	ret = DesEnc(plain, plainlen, crpytbuf, &crytlen);
	if (ret != 0)
	{
		printf("func DesEnc() err:%d\n");
		return ret;
	}
	char plainByDesDec[4096] = {0};
	int plainByDesDecLen = 0;

	//�û�ʹ�ú���des����
	ret = DesDec(crpytbuf, crytlen, plainByDesDec, &plainByDesDecLen);
	if (ret != 0)
	{
		printf("func DesDec() err:%d\n");
		return ret;
	}

	if (plainlen != plainByDesDecLen)
	{
		printf("���ĳ��Ⱥͽ��ܺ�����ĳ��Ȳ�һ��\n");
	}

	if (memcmp(plain, plainByDesDec,plainlen)==0)
	{
		printf("���ĺͽ��ܺ������һ��\n");
	}
	else
	{
		printf("���ĺͽ��ܺ�����Ĳ�һ��\n");
	}

	system("pause");
}
