#pragma once

/*
	socketclient.lib :��Դģʽ�ļ����� socketclient.dll
	socketclient.dll :��̬�⣨�����������뼯�ϡ������к����ĺ����壩��̬���й淶
*/



//SOCKECLIENT_H ���û�ж���Ͷ���
#ifndef _SOCKETCLIENT_H
#endif _SOCKETCLIENT_H


//���������ʹ��c++�淶������c�淶ʹ�����к���
#ifdef _cplusplus
extern "C" {

#endif // _cplusplus

	//socket�ͻ��˳�ʼ��

	int socket_client_init(void** handle/*out*/);

	//socket�ͻ��˱��ķ���

	int socket_client_send(void* handle/*in*/, unsigned char* buf/*in*/, int buflen/**/);

	//socket�ͻ��˱��Ľ���

	int socket_client_recv(void* handle/*in*/, unsigned char* buf/*in*/, int* buflen/*in*/);

	//socketk�ͻ��˻����ͷ�

	int socket_client_destory(void* handle/*in*/);


	//�����㣺1.һ��ָ�룻2.����ָ�룻3.void *handleҵ�����ͷ�װ����

	//�ӿڷ�װ����ƣ����ܳ����װ��
		//�ӿ�API��ʹ������
		//�ӿ�API�Ĳ�������
		//�ӿ�API��ʵ������

	//������ȷ�ĳ��������ڴ沼��ͼ��ӡ��ͼ��
		//�ڴ�����ģ��ͼ
		//��������ģ��ͼ	


	/*-----------------------------------------*/
	//��ʼ���ͻ���
	int cltSocketInit(void** handl/*out*/);

	//�ͻ��˷�����
	int cltSocketSend(void* handle/*in*/, unsigned char* buf/*in*/, int buflen/*in*/);

	//�ͻ����ձ���
	int cltSocketRev(void* handle/*in*/, unsigned char** buf/*out*/, int* buflen/*out*/);

	int cltSocketRev_Free(unsigned char** buf/*out*/);

	//�ͻ����ͷ���Դ
	int cltSocketDestory(void** handle/*out*/);
	/*-----------------------------------------*/

#ifdef _cplusplus
}
#endif // _cplusplus





