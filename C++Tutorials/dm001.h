#pragma once

//SOCKECLIENT_H 如果没有定义就定义
#ifndef _SOCKETCLIENT_H
#endif _SOCKETCLIENT_H


//如果编译器使用c++规范，则按照c规范使用下列函数
#ifdef _cplusplus
extern "C" {

#endif // _cplusplus

	//socket客户端初始化

	int socket_client_init(void* handle);

	//socket客户端报文发送

	int socket_client_send(void* handle, unsigned char* buf, int buflen);

	//socket客户端报文接受

	int socket_client_recv(void* handle, unsigned char* buf, int* buflen);

	//socketk客户端环境释放

	int socket_client_destory(void* handle);


	//技术点：1.一级指针；2.二级指针；3.void *handle业务类型封装概念

	//接口封装和设计（功能抽象封装）
		//接口API的使用能力
		//接口API的查找能力
		//接口API的实现能力

	//建立正确的程序运行内存布局图（印象图）
		//内存四区模型图
		//函数调用模型图	


#ifdef _cplusplus
}
#endif // _cplusplus




