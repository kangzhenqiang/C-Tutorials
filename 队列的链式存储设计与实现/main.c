
#include "linkqueue.h"

int main()
{
	int i = 0, a[10];
	LinkQueue* queue = NULL;

	queue = LinkQueue_Create();
	if (queue == NULL)
	{
		return -1;
	}

	//����������Ԫ��
	for (i = 0; i < 5; i++)
	{
		a[i] = i;
		LinkQueue_Append(queue, &a[i]);
	}

	//���������
	printf("len:%d\n", LinkQueue_Length(queue));
	printf("Header:%d\n", *((int*)LinkQueue_Header(queue)));

	//������
	while (LinkQueue_Length(queue) > 0)
	{
		int temp = *((int*)LinkQueue_Retrieve(queue));
		printf("temp:%d\n", temp);
	}

	//���ٶ���
	LinkQueue_Destroy(queue);

	return 0;
}