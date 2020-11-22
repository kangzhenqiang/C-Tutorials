#include<stdio.h>


//创建线性列表
TSeqList* SeqList_Create(int capacty);

//销毁线性列表
void SeqList_Destroy(SeqList* list);

//清空线性列表
void SeqList_Clear(SeqList* list);

//获取线性列表长度
int SeqList_Length(SeqList* list);

//获取线性列表开辟空间长度
int SeqList_Capacity(TSeqList* list)

//向线性表中插入一个新元素
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);

//获取线性表在pos位置出的元素
SeqListNode* SeqList_Get(SeqList* list, int post);

//删除一个线性表位置出的元素，返回值为删除的元素，NULL表示删除失败
ListNode* SeqList_Delete(SeqList* list, int post);