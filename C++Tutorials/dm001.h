#pragma once

//SOCKECLIENT_H ���û�ж���Ͷ���
#ifndef _SOCKETCLIENT_H
#endif _SOCKETCLIENT_H


//���������ʹ��c++�淶������c�淶ʹ�����к���
#ifdef _cplusplus
extern "C" {

#endif // _cplusplus

	//socket�ͻ��˳�ʼ��

	int socket_client_init(void* handle);

	//socket�ͻ��˱��ķ���

	int socket_client_send(void* handle, unsigned char* buf, int buflen);

	//socket�ͻ��˱��Ľ���

	int socket_client_recv(void* handle, unsigned char* buf, int* buflen);

	//socketk�ͻ��˻����ͷ�

	int socket_client_destory(void* handle);


	//�����㣺1.һ��ָ�룻2.����ָ�룻3.void *handleҵ�����ͷ�װ����

	//�ӿڷ�װ����ƣ����ܳ����װ��
		//�ӿ�API��ʹ������
		//�ӿ�API�Ĳ�������
		//�ӿ�API��ʵ������

	//������ȷ�ĳ��������ڴ沼��ͼ��ӡ��ͼ��
		//�ڴ�����ģ��ͼ
		//��������ģ��ͼ	


#ifdef _cplusplus
}
#endif // _cplusplus




