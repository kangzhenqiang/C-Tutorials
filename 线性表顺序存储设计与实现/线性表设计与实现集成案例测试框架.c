
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "seqlist.h"


typedef struct Teacher {
	int age;
	char name[64];
} Teacher;

int main()
{
	int ret = 0, i = 0;
	SeqList* list = NULL;
	Teacher t1, t2, t3, t4, t5;
	Teacher* temp;

	//��ֵ
	t1.age = 32;
	strcpy(t1.name, "kangzhenqiang");
	t2.age = 32;
	strcpy(t2.name, "kangzhenqiang");
	t3.age = 32;
	strcpy(t3.name, "kangzhenqiang");
	t4.age = 32;
	strcpy(t4.name, "kangzhenqiang");
	t5.age = 32;
	strcpy(t5.name, "kangzhenqiang");

	//���������б�
	list = SeqList_Create(10);
	if (list == NULL)
	{
		ret = -1;
		printf("func SeqList_Create() ret : %d\n", ret);
		return ret;
	}

	//ͷ�巨�������
	SeqList_Insert(list, (SeqListNode*)(&t1), 0);//ͷ�巨
	SeqList_Insert(list, (SeqListNode*)(&t2), 0);//ͷ�巨
	SeqList_Insert(list, (SeqListNode*)(&t3), 0);//ͷ�巨
	SeqList_Insert(list, (SeqListNode*)(&t4), 0);//ͷ�巨
	SeqList_Insert(list, (SeqListNode*)(&t5), 0);//ͷ�巨

	//ѭ����������
	for (i = 0; i < SeqList_Length(list); i++)
	{
		Teacher* temp = (Teacher*)SeqList_Get(list, i);
		if (temp == NULL)
		{
			continue;
		}
		printf("temp->age:%d\n", temp->age); 
	}

	//ɾ�������еĶ���
	while (SeqList_Length(list) > 0)
	{
		SeqList_Delete(list, 0);
	}

	//���ٶ���
	SeqList_Destroy(list);

	return ret;
}
