
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

	//向队列中添加元素
	for (i = 0; i < 5; i++)
	{
		a[i] = i;
		LinkQueue_Append(queue, &a[i]);
	}

	//求队列属性
	printf("len:%d\n", LinkQueue_Length(queue));
	printf("Header:%d\n", *((int*)LinkQueue_Header(queue)));

	//出队列
	while (LinkQueue_Length(queue) > 0)
	{
		int temp = *((int*)LinkQueue_Retrieve(queue));
		printf("temp:%d\n", temp);
	}

	//销毁队列
	LinkQueue_Destroy(queue);

	return 0;
}