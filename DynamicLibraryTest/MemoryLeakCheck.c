
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "memwatch.h"


int getMem(char** p/*out*/)
{
	int ret = 0;
	char* temp = NULL;
	temp = (char*)malloc(100);
	if (temp==NULL)
	{
		ret = -1;
		return ret;
	}

	strcpy(temp, "aaaaa");
	*p = temp;
	return ret;
}


void main()
{
	char* p = NULL;
	getMem(&p);
	printf("%s\n", p);
	system("pause");
}
