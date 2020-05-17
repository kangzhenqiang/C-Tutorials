#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/*有一个字符串符合以下特征（“abcdef,acccd,eeee,aaaa,e3eeee,sssss”）*/

//分清楚指针变量和操作逻辑之间的关系
int splitString(const char* strSource, char split, char** myp/*in*/, int* count)
{
	char* p = NULL;
	char* tempP = NULL;
	int tempCount = 0;

	p = strSource;
	tempP = strSource;

	do
	{
		//检索符合条件的位置 p后移，形成差值 挖字符
		p = strchr(p, split);
		if (p != NULL)
		{
			if (p - tempP > 0)
			{
				strncpy(myp[tempCount], tempP, p - tempP);
				myp[tempCount][p - tempP] = '\0';
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
	return 0;
}



void maindy028()
{
	//声明初始变量
	int ret = 0, i = 0;
	char* strP = "abcdef,acccd,eeee,aaaa,e3eeee,sssss";
	int count = 0;

	//申请内存
	char** p = NULL;//相当于分配char buf[10][30]
	p = (char**)malloc(10 * sizeof(char*));//char arr[10]
	if (p == NULL)
	{
		return;
	}
	for (i = 0; i < 10; i++)
	{
		p[i] = (char*)malloc(sizeof(char) * 30);
	}

	ret = splitString(strP,',',p,&count);

	//打印
	for (i = 0; i < count; i++)
	{
		printf("%s\n", p[i]);
	}

	//释放内存
	for (i = 0; i < 10; i++)
	{
		free(p[i]);
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	system("pause");
}