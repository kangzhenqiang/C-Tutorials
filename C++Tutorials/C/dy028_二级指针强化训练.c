#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/*��һ���ַ�������������������abcdef,acccd,eeee,aaaa,e3eeee,sssss����*/

//�����ָ������Ͳ����߼�֮��Ĺ�ϵ
int splitString(const char* strSource, char split, char** myp/*in*/, int* count)
{
	char* p = NULL;
	char* tempP = NULL;
	int tempCount = 0;

	p = strSource;
	tempP = strSource;

	do
	{
		//��������������λ�� p���ƣ��γɲ�ֵ ���ַ�
		p = strchr(p, split);
		if (p != NULL)
		{
			if (p - tempP > 0)
			{
				strncpy(myp[tempCount], tempP, p - tempP);
				myp[tempCount][p - tempP] = '\0';
				tempCount++;
				//������p��tempP�ﵽ��һ�μ�������
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
	//������ʼ����
	int ret = 0, i = 0;
	char* strP = "abcdef,acccd,eeee,aaaa,e3eeee,sssss";
	int count = 0;

	//�����ڴ�
	char** p = NULL;//�൱�ڷ���char buf[10][30]
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

	//��ӡ
	for (i = 0; i < count; i++)
	{
		printf("%s\n", p[i]);
	}

	//�ͷ��ڴ�
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