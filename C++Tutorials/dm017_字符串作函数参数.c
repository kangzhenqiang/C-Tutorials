//������ΪһЩ�ϵ�.c�ļ�ʹ����strcpy,scanf,malloc�Ȳ���ȫ�ĺ�������������ʹ��󣬶������޷�����ͨ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����д��
void maindm01701()
{
	char a[] = "I am s student";
	char b[64];
	int i = 0;
	for (i = 0; i < *(a + i) != '\0'; i++)
	{
		*(b + i) = *(a + i);
	}
	b[i] = '\0';//��Ҫ


	printf("a:%s\n", a);

	printf("b:%s\n", b);

	system("pause");
}


//�ַ���copy������������

//�ַ���copy����
//form�β� to�β� ��ͣ���ڱ仯..
//�����޸���from��to��ָ��
void str_copy(char* from, char* to)
{
	for (; *from != '\0'; from++, to++)
	{
		*to = *from;
	}
	*(to) = '\0';
}

//*������++����
//++���ȼ���

void string_Copy(char* from, char* to)
{
	for (; *from != '\0';)
	{
		*to++ = *from++;//��*to=*from,from++,to++
	}
	*to = '\0';
}

void strString_Copy(char* from, char* to)
{
	while ((*to = *from) != '\0')
	{
		from++;
		to++;
	}
}

void stringString_Copy(char* from, char* to)
{
	while ((*to++ = *from++) != '\0')
	{

	}
}

void strStringString_Copy(char* from, char* to)
{
	while ((*to++ = *from++))
	{

	}
}

void strStringString_Copy_err(char* from, char* to)
{
	while ((*to++ = *from++))
	{

	}
	printf("buf:%s\n", from);
}

//���������Ż�
//��Ҫ���׸ı��βε�ֵ��Ҫ�����βθ�������ָ�룬���βνӹ���
int stringStringString_Copy(char* from, char* to)
{
	char* tempFrom = from;
	char* tempTo = to;

	if (from == NULL || to == NULL)
	{
		return -1;
	}
	while (*tempTo++ = *tempFrom++);//�����
	printf("buf:%s\n", from);
	return 0;
}

void mainddm01702()
{
	char* from = "abcde";
	char buf[100];

	strStringString_Copy_err(from, buf);

	str_copy(from, buf);
	printf("buf:%s\n", buf);
	string_Copy(from, buf);
	printf("buf:%s\n", buf);
	strString_Copy(from, buf);
	printf("buf:%s\n", buf);
	stringString_Copy(from, buf);
	printf("buf:%s\n", buf);
	strStringString_Copy(from, buf);
	printf("buf:%s\n", buf);

	stringStringString_Copy(from, buf);
	{
		//������
		char* to = NULL;
		int res = stringStringString_Copy(from, to);//Ҫ�����ڴ�
		if (res != 0)
		{
			printf("fun stringStringString_Copy error%d", res);
		}
		printf("buf:%s\n", to);
	}

	system("pause");
}