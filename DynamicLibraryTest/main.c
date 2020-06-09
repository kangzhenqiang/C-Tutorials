
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "SocketClient.h"
#include "itcastlog.h"

void main01()
{
	int ret = 0;
	void* handle = NULL;

	char buf[128] = { 0 };
	int buflen = 3;

	char outBuf[128] = { 0 };
	int outBufLen = 3;

	//socket�ͻ��˳�ʼ��
	ret = socket_client_init(&handle/*out*/);
	if (ret != 0)
	{
		printf("fun socket_client_init() err:%d\n", ret);
		return ret;
	}

	//socket�ͻ��˱��ķ���
	ret = socket_client_send(handle/*in*/, buf/*in*/, buflen/*in*/);
	if (ret != 0)
	{
		printf("fun socket_client_send() err:%d\n", ret);
		return ret;
	}

	//socket�ͻ��˱��Ľ���
	ret = socket_client_recv(handle/*in*/, outBuf/*in*/, outBufLen/*in*/);
	if (ret != 0)
	{
		printf("fun socket_client_recv() err:%d\n", ret);
		return ret;
	}

	//socketk�ͻ��˻����ͷ�
	ret = socket_client_destory(handle/*in*/);
	if (ret != 0)
	{
		printf("fun socket_client_destory() err:%d\n", ret);
		return ret;
	}

	system("pause");
}


void main02()
{
	int ret = 0;
	void* handle = NULL;

	char buf[128] = { 0 };
	int buflen = 3;

	char* pOut = NULL;
	int pOutLen = 0;

	strcpy(buf, "kangzhenqing");

	//socket�ͻ��˳�ʼ��
	ret = cltSocketInit(&handle/*out*/);
	if (ret != 0)
	{
		printf("fun cltSocketInit() err:%d\n", ret);
		return ret;
	}

	//socket�ͻ��˱��ķ���
	ret = cltSocketSend(handle/*in*/, buf/*in*/, buflen/*in*/);
	if (ret != 0)
	{
		printf("fun cltSocketSend() err:%d\n", ret);
		return ret;
	}

	//socket�ͻ��˱��Ľ���
	ret = cltSocketRev(handle/*in*/, &pOut/*out*/, &pOutLen/*in*/);
	if (ret != 0)
	{
		printf("fun cltSocketRev() err:%d\n", ret);
		return ret;
	}

	//����Ұָ�� ��outbuf��ָ����ڴ��ͷţ�ͬʱ��pOut��Ϊnull
	ret = cltSocketRev_Free(&pOut);
	if (ret != 0)
	{
		printf("fun cltSocketRev_Free() err:%d\n", ret);
		return ret;
	}

	//socketk�ͻ��˻����ͷ�
	ret = cltSocketDestory(&handle/*in*/);
	if (ret != 0)
	{
		printf("fun socket_client_destory() err:%d\n", ret);
		return ret;
	}

	system("pause");
}


void main03()
{
	ITCAST_LOG(__FILE__,__LINE__ , LogLevel[0], 0, "11111");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[1], 0, "22222");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[2], 0, "33333");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[3], 0, "44444");
	system("pause");
}

