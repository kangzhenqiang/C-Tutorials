
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//指针数组案例讲解 char *char[3]
	//指针数组的两种用法（菜单 命令行）
	//操作系统拉起应用 在框架下干活


//演示：指针数组的用法
//演示：找错误 注意return

//知道在那个框架下办公


int searchKeyTable(const char* table[], const int size, const char* key, int* pos)
{
	int rv = 0;
	int i = 0;
	int inum = 0;
	if (table == NULL || key == NULL || pos == NULL)
	{
		rv = -1;
		printf("func searcheKeyTable:%d", rv);
	}

	inum = (sizeof(table) / sizeof(*table));

	for (i = 0; i < size; i++)
	{
		if (strcmp(key, table[i]) == 0)
		{
			*pos = i;
			return rv;
		}
	}

	if (i == size)
	{
		*pos = -1;
	}
	return rv;
}


#define DIM(a) (sizeof(a)/sizeof(*a))

void maindy003001()
{
	int inum = 0;
	int pos = 0;
	int a[10];
	int i = 0;

	//指针数组
	char* c_keyword[] = {
		"while",
		"case",
		"static",
		"do"
	};

	searchKeyTable(c_keyword, DIM(c_keyword), "do", &pos);

	printf("pos:%d\n", pos);

	system("pause");
}


//数组作函数参数会退化为指针，关键是看内存块是谁分配的
int maindy033002(int argc, char* argv[], char** env)
{
	int i = 0;
	printf("*********** Begin argv ************\n");
	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	printf("*********** End argv ************\n");

	printf("\n");
	printf("\n");

	printf("*********** Begin env ************\n");
	for (i = 0; env[i] != NULL; i++)//以\0结束字符串
	{
		printf("%s\n", env[i]);
	}

	printf("*********** End env ************\n");

	printf("\n");
	printf("\n");

	system("pause");
}

void maindy033003()
{
	int inum = 0;
	int pos = 0;
	int a[10];
	int i = 0;

	//指针数组 拥有自我结束能力
	char* c_keyword[] = {
		"while",
		"case",
		"static",
		"do",
		'\0'//拥有自我结束能力
	};

	//指针数组 拥有自我结束能力
	char* c_keyword1[] = {
		"while",
		"case",
		"static",
		"do",
		0//拥有自我结束能力
	};

	//指针数组 拥有自我结束能力
	char* c_keyword2[] = {
		"while",
		"case",
		"static",
		"do",
		NULL//拥有自我结束能力
	};


	for (i = 0; c_keyword[i] != NULL; i++)
	{
		printf("%s\n", c_keyword[i]);
	}
	for (i = 0; c_keyword1[i] != NULL; i++)
	{
		printf("%s\n", c_keyword1[i]);
	}
	for (i = 0; c_keyword2[i] != NULL; i++)
	{
		printf("%s\n", c_keyword2[i]);
	}

	system("pause");
}

