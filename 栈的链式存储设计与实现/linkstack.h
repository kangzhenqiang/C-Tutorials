#pragma once

#ifndef _MY_LINKSTACH_H
#define _MY_LINKSTACH_H

typedef void LinkStack;

//�������Դ洢ջ
LinkStack* LinkStack_Create();

//������ʽ�洢ջ
void LinkStack_Destory(LinkStack* stack);

//�����ʽ�洢ջ
void LinkStack_Clear(LinkStack* stack);

//ѹ����ʽ�洢ջ����
int LinkStack_Push(LinkStack* stack, void* item);

//�Ƴ���ʽ�洢ջ����
void* LinkStack_Pop(LinkStack* stack);

//��ȡ��ʽ�洢ջ�Ķ�������
void* LinkStack_Top(LinkStack* stack);

//��ȡ��ʽ�洢ջ�Ķ�������
int  LinkStack_Size(LinkStack* stack);

#endif // !_MY_LINKSTACH_H

