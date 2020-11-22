#pragma once

#ifndef _MY_LINKSTACH_H
#define _MY_LINKSTACH_H

typedef void LinkStack;

//创建线性存储栈
LinkStack* LinkStack_Create();

//销毁链式存储栈
void LinkStack_Destory(LinkStack* stack);

//清空链式存储栈
void LinkStack_Clear(LinkStack* stack);

//压入链式存储栈对象
int LinkStack_Push(LinkStack* stack, void* item);

//移除链式存储栈对象
void* LinkStack_Pop(LinkStack* stack);

//获取链式存储栈的顶部对象
void* LinkStack_Top(LinkStack* stack);

//获取链式存储栈的对象数量
int  LinkStack_Size(LinkStack* stack);

#endif // !_MY_LINKSTACH_H

