#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//×Ö·û´®·´×ª
int inverse(char* str)
{
	if (str==NULL)
	{
		printf("fun str is NULL.");
		return -1;
	}

	int length = strlen(str);

	char* p1 = str;
	char* p2 = str + length - 1;

	while (p1 < p2)
	{
		char c = *p1;
		*p1 = *p2;
		*p2 = c;
		++p1;
		--p2;
	}
	return 0;
}


void main()
{
	char buf[] = "abcdefg";
	inverse(buf);
	printf("buf:%s.\n", buf);
	system("pause");
}
