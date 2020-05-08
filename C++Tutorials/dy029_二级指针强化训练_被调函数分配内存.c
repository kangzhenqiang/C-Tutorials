#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/*有一个字符串符合以下特征（“abcdef,acccd,eeee,aaaa,e3eeee,sssss”）*/

//分清楚指针变量和操作逻辑之间的关系
char** splitString1(const char* strSource, char split, char** myp/*in*/, int* count)
{
	char* p = NULL;
	char* tempP = NULL;
	int tempCount = 0;
	int i = 0;
	char** tempMyP = NULL;

	p = strSource;
	tempP = strSource;

	//第一遍求出count

	do
	{
		//检索符合条件的位置 p后移，形成差值 挖字符
		p = strchr(p, split);
		if (p != NULL)
		{
			if (p - tempP > 0)
			{
				tempCount++;
				//重新让p和tempP达到下一次检索条件
				tempP = p = p + 1;
			}
		}
		else
		{
			break;
		}
	} while (*p != '\0');

	////////////////////////////////////////////////////////////

	tempMyP = (char**)malloc(tempCount * sizeof(char*));//char arr[10]
	if (tempMyP == NULL)
	{
		return NULL;
	}

	p = strSource;
	tempP = strSource;
	tempCount = 0;
	do
	{
		//检索符合条件的位置 p后移，形成差值 挖字符
		p = strchr(p, split);
		if (p != NULL)
		{
			if (p - tempP > 0)
			{
				int len = p - tempP + 1;
				tempMyP[tempCount] = (char*)malloc(sizeof(char) * len);
				if (tempMyP[tempCount] == NULL)
				{
					return NULL;
				}
				strncpy(tempMyP[tempCount], tempP, p - tempP);
				tempMyP[tempCount][len - 1] = '\0';//把一行数据变成C风格字符串
				tempCount++;
				//重新让p和tempP达到下一次检索条件
				tempP = p = p + 1;
			}
		}
		else
		{
			break;
		}
	} while (*p != '\0');

	*count = tempCount;
	return tempMyP;
}

//指针做函数参数
int splitString2(const char* strSource, char split, char*** myp/*in*/, int* count)
{
	int ret = 0;

	char* p = NULL;
	char* tempP = NULL;
	int tempCount = 0;
	int i = 0;
	char** tempMyP = NULL;

	p = strSource;
	tempP = strSource;

	//第一遍求出count

	do
	{
		//检索符合条件的位置 p后移，形成差值 挖字符
		p = strchr(p, split);
		if (p != NULL)
		{
			if (p - tempP > 0)
			{
				tempCount++;
				//重新让p和tempP达到下一次检索条件
				tempP = p = p + 1;
			}
		}
		else
		{
			break;
		}
	} while (*p != '\0');

	////////////////////////////////////////////////////////////

	tempMyP = (char**)malloc(tempCount * sizeof(char*));//char arr[10]
	if (tempMyP == NULL)
	{
		ret = -1;
		printf("fun spitString() err:%d (tempcount * sizeof(char *))", ret);
		goto END;
	}
	memset(tempMyP, 0, tempCount * sizeof(char*));//把申请空间变成0便于判断

	p = strSource;
	tempP = strSource;
	tempCount = 0;
	do
	{
		//检索符合条件的位置 p后移，形成差值 挖字符
		p = strchr(p, split);
		if (p != NULL)
		{
			if (p - tempP > 0)
			{
				int len = p - tempP + 1;
				tempMyP[tempCount] = (char*)malloc(sizeof(char) * len);
				if (tempMyP[tempCount] == NULL)
				{
					ret = -2;
					printf("fun spitString() err:%d (char*)malloc(sizeof(char) * len)", ret);
					goto END;

					//return -2;
				}
				strncpy(tempMyP[tempCount], tempP, p - tempP);
				tempMyP[tempCount][len - 1] = '\0';//把一行数据变成C风格字符串
				tempCount++;
				//重新让p和tempP达到下一次检索条件
				tempP = p = p + 1;
			}
		}
		else
		{
			break;
		}
	} while (*p != '\0');

END:
	if (ret != 0)//失败
	{
		/*
		int i = 0;
		if (tempMyP == NULL)
		{
			return ret;
		}
		for (i = 0; i < tempCount; i++)
		{
			if (tempMyP[i] != NULL)
			{
				free(tempMyP[i]);
			}
		}
		if (tempMyP != NULL)
		{
			free(tempMyP);
			tempMyP = NULL;
		}
		*/

		freeMem2(&tempMyP, tempCount);
	}
	else//成功
	{
		*count = tempCount;
		*myp = tempMyP;
	}
	return ret;
}

//释放内存
void freeMemMe2(char*** p, int count)
{
	if (p==NULL)
	{
		return;
	}

	char** temp = *p;

	int i = 0;
	if (temp == NULL)
	{
		return ;
	}
	for (i = 0; i < count; i++)
	{
		if (temp[i] != NULL)
		{
			free(temp[i]);
		}
	}
	if (temp != NULL)
	{
		free(temp);
		temp = NULL;
		*p = NULL;
	}
}


//多级指针避免野指针的方法：1、先判断，2、释放，3、赋值NULL

void maindy029()
{
	//声明初始变量
	int ret = 0, i = 0;
	char* strP = "abcdef,acccd,eeee,aaaa,e3eeee,sssss";
	int count = 0;

	//申请内存
	char** p = NULL;//相当于分配char buf[10][30]

	//p = splitString1(strP, ',', p, &count);

	ret = splitString2(strP, ',', &p, &count);

	//打印
	for (i = 0; i < count; i++)
	{
		printf("%s\n", p[i]);
	}

	//释放内存
	/*
	for (i = 0; i < count; i++)
	{
		free(p[i]);
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	*/

	freeMemMe2(&p, count);
	system("pause");
}