
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct _SCK_HANDLE
{
	char version[64];
	char ip[128];
	int port;
	unsigned* p;
	int plen;
} SCK_HANDLE;//动态库 内部的数据类型，不想让测试程序（上层应用知道）
//数据类型的封装



//socket客户端初始化

//用于导出动态库函数
_declspec(dllexport)
int socket_client_init(void** handle /*out*/)
{
	int ret = 0;
	printf("func cltSocketInit() begin...\n");
	SCK_HANDLE* hdl = NULL;
	hdl = (SCK_HANDLE*)malloc(sizeof(SCK_HANDLE));
	if (hdl == NULL)
	{
		ret = -1;
		printf("func cltSocketInit() err:%d", ret);
		return ret;
	}
	memset(hdl, 0, sizeof(SCK_HANDLE));//把指向的内存空间赋值成0
	strcpy(hdl->ip, "192.168.6.254");
	hdl->port = 8081;
	*handle = hdl;
	printf("func cltSocketInit() end...\n");
	return ret;
}

//socket客户端报文发送
_declspec(dllexport)
int socket_client_send(void* handle/*in*/, unsigned char* buf/*in*/, int buflen/*in*/)
{
	int ret = 0;
	SCK_HANDLE* hdl = NULL;

	if (handle == NULL || buf == NULL)
	{
		ret = -1;
		printf("func socket_client_send() err:%d\n handle == NULL || buf == NULL\n", ret);
		return ret;
	}

	hdl = (SCK_HANDLE*)handle;
	hdl->p = (unsigned char*)malloc(buflen * sizeof(unsigned char));
	if (hdl->p == NULL)
	{
		ret = -2;
		printf("func socket_client_send() err:%d\n (unsigned char*)malloc(buflen * sizeof(unsigned char))\n", ret);
		return ret;
	}
	memcpy(hdl->p, buf, buflen);
	hdl->plen = buflen;
	return 0;
}

//socket客户端报文接受
_declspec(dllexport)
int socket_client_recv(void* handle/*in*/, unsigned char* buf/*in*/, int* buflen/*in*/)
{
	int ret = 0;
	SCK_HANDLE* hdl = NULL;

	if (handle == NULL || buf == NULL || buflen == NULL)
	{
		ret = -1;
		printf("func socket_client_send() err:%d\n handle == NULL || buf == NULL || buflen==NULL\n", ret);
		return ret;
	}
	hdl = (SCK_HANDLE*)handle;
	memcpy(buf, hdl->p, hdl->plen);
	*buflen = hdl->plen;
	return 0;
}

//socketk客户端环境释放
_declspec(dllexport)
int socket_client_destory(void* handle/*in*/)
{
	int ret = 0;
	SCK_HANDLE* hdl = NULL;

	if (handle == NULL)
	{
		ret = -1;
		printf("func socket_client_send() err:%d\n handle == NULL", ret);
		return ret;
	}
	hdl = (SCK_HANDLE*)handle;
	if (hdl->p)
	{
		free(hdl->p);
	}
	free(hdl);
	return 0;
}


_declspec(dllexport)
int cltSocketInit(void** handl)
{
	return socket_client_init(handl);
}

_declspec(dllexport)
int cltSocketSend(void* handle, unsigned char* buf, int buflen)
{
	return socket_client_send(handle, buf, buflen);
}

_declspec(dllexport)
int cltSocketRev(void* handle, unsigned char** buf, int* buflen)
{
	int ret = 0;
	SCK_HANDLE* hdl = NULL;
	char* temp = NULL;

	if (handle == NULL || buf == NULL || buflen == NULL)
	{
		ret = -1;
		printf("func socket_client_send() err:%d\n handle == NULL || buf == NULL || buflen==NULL\n", ret);
		return ret;
	}

	hdl = (SCK_HANDLE*)handle;
	temp = (char*)malloc(hdl->plen);

	if (temp==NULL)
	{
		ret = -2;
		printf("func cltSocketRev() err:%d\n (char*)malloc(hdl->plen)\n",ret);
		return ret;
	}

	memcpy(temp, hdl->p, hdl->plen);
	*buf = temp;//间接赋值
	*buflen = hdl->plen;
	return 0;
}

_declspec(dllexport)
int cltSocketRev_Free(unsigned char** buf)
{
	int ret = 0;
	if (buf==NULL)
	{
		return ret;
	}
	if (*buf!=NULL)
	{
		free(*buf);
	}
	*buf = NULL;
	return 0;
}

_declspec(dllexport)
int cltSocketDestory(void** handle)
{
	int ret = 0;
	SCK_HANDLE* hdl = NULL;

	if (handle == NULL)
	{
		ret = -1;
		printf("func cltSocketDestory() err:%d\n handle == NULL", ret);
		return ret;
	}
	hdl = *handle;
	if (hdl!=NULL)
	{
		free(hdl);
	}
	*handle = NULL;
	return 0;
}
