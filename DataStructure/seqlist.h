#include<stdio.h>


//���������б�
TSeqList* SeqList_Create(int capacty);

//���������б�
void SeqList_Destroy(SeqList* list);

//��������б�
void SeqList_Clear(SeqList* list);

//��ȡ�����б���
int SeqList_Length(SeqList* list);

//��ȡ�����б��ٿռ䳤��
int SeqList_Capacity(TSeqList* list)

//�����Ա��в���һ����Ԫ��
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);

//��ȡ���Ա���posλ�ó���Ԫ��
SeqListNode* SeqList_Get(SeqList* list, int post);

//ɾ��һ�����Ա�λ�ó���Ԫ�أ�����ֵΪɾ����Ԫ�أ�NULL��ʾɾ��ʧ��
ListNode* SeqList_Delete(SeqList* list, int post);