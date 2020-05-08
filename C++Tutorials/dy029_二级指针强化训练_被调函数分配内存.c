#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/*��һ���ַ�������������������abcdef,acccd,eeee,aaaa,e3eeee,sssss����*/

//�����ָ������Ͳ����߼�֮��Ĺ�ϵ
char** splitString1(const char* strSource, char split, char** myp/*in*/, int* count)
{
	char* p = NULL;
	char* tempP = NULL;
	int tempCount = 0;
	int i = 0;
	char** tempMyP = NULL;

	p = strSource;
	tempP = strSource;

	//��һ�����count

	do
	{
		//��������������λ�� p���ƣ��γɲ�ֵ ���ַ�
		p = strchr(p, split);
		if (p != NULL)
		{
			if (p - tempP > 0)
			{
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
		//��������������λ�� p���ƣ��γɲ�ֵ ���ַ�
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
				tempMyP[tempCount][len - 1] = '\0';//��һ�����ݱ��C����ַ���
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
	return tempMyP;
}

//ָ������������
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

	//��һ�����count

	do
	{
		//��������������λ�� p���ƣ��γɲ�ֵ ���ַ�
		p = strchr(p, split);
		if (p != NULL)
		{
			if (p - tempP > 0)
			{
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

	////////////////////////////////////////////////////////////

	tempMyP = (char**)malloc(tempCount * sizeof(char*));//char arr[10]
	if (tempMyP == NULL)
	{
		ret = -1;
		printf("fun spitString() err:%d (tempcount * sizeof(char *))", ret);
		goto END;
	}
	memset(tempMyP, 0, tempCount * sizeof(char*));//������ռ���0�����ж�

	p = strSource;
	tempP = strSource;
	tempCount = 0;
	do
	{
		//��������������λ�� p���ƣ��γɲ�ֵ ���ַ�
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
				tempMyP[tempCount][len - 1] = '\0';//��һ�����ݱ��C����ַ���
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

END:
	if (ret != 0)//ʧ��
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
	else//�ɹ�
	{
		*count = tempCount;
		*myp = tempMyP;
	}
	return ret;
}

//�ͷ��ڴ�
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


//�༶ָ�����Ұָ��ķ�����1�����жϣ�2���ͷţ�3����ֵNULL

void maindy029()
{
	//������ʼ����
	int ret = 0, i = 0;
	char* strP = "abcdef,acccd,eeee,aaaa,e3eeee,sssss";
	int count = 0;

	//�����ڴ�
	char** p = NULL;//�൱�ڷ���char buf[10][30]

	//p = splitString1(strP, ',', p, &count);

	ret = splitString2(strP, ',', &p, &count);

	//��ӡ
	for (i = 0; i < count; i++)
	{
		printf("%s\n", p[i]);
	}

	//�ͷ��ڴ�
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