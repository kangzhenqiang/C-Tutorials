#pragma once

/*
	socketclient.lib :资源模式文件描述 socketclient.dll
	socketclient.dll :动态库（函数二进制码集合、里面有函数的函数体）动态库有规范
*/



//SOCKECLIENT_H 如果没有定义就定义
#ifndef _SOCKETCLIENT_H
#endif _SOCKETCLIENT_H


//如果编译器使用c++规范，则按照c规范使用下列函数
#ifdef _cplusplus
extern "C" {

#endif // _cplusplus

	//socket客户端初始化

	int socket_client_init(void** handle/*out*/);

	//socket客户端报文发送

	int socket_client_send(void* handle/*in*/, unsigned char* buf/*in*/, int buflen/**/);

	//socket客户端报文接受

	int socket_client_recv(void* handle/*in*/, unsigned char* buf/*in*/, int* buflen/*in*/);

	//socketk客户端环境释放

	int socket_client_destory(void* handle/*in*/);


	//技术点：1.一级指针；2.二级指针；3.void *handle业务类型封装概念

	//接口封装和设计（功能抽象封装）
		//接口API的使用能力
		//接口API的查找能力
		//接口API的实现能力

	//建立正确的程序运行内存布局图（印象图）
		//内存四区模型图
		//函数调用模型图	


	/*-----------------------------------------*/
	//初始化客户端
	int cltSocketInit(void** handl/*out*/);

	//客户端发报文
	int cltSocketSend(void* handle/*in*/, unsigned char* buf/*in*/, int buflen/*in*/);

	//客户端收报文
	int cltSocketRev(void* handle/*in*/, unsigned char** buf/*out*/, int* buflen/*out*/);

	int cltSocketRev_Free(unsigned char** buf/*out*/);

	//客户端释放资源
	int cltSocketDestory(void** handle/*out*/);
	/*-----------------------------------------*/

#ifdef _cplusplus
}
#endif // _cplusplus





