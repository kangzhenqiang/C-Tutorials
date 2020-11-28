#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "seqqueue.h"

int main()
{
	SeqQueue* queue = NULL;
	int a[10], i = 0;

	queue = SeqQueue_Create(10);
	if (queue == NULL)
	{
		return -1;
	}

	for (i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		SeqQueue_Append(queue,&a[i]);
	}

	//打印队列属性
	printf("queue length:%d\n", SeqQueue_Length(queue));
	printf("queue header:%d\n", *(int*)SeqQueue_Header(queue));
	printf("queue capacity:%d\n", SeqQueue_Capacity(queue));


	while (SeqQueue_Length(queue)>0)
	{
		int temp = *(int*)SeqQueue_Retrieve(queue);
		printf("temp is : %d\n", temp);
	}

	return 0;
}