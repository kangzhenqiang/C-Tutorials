#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "cfg_op.h"

#define MaxLine 2048

//��ȡ������
int GetCfgItem(char* pFileName/*in*/, char* pKey/*in*/, char* pValue/*out*/, int* pValueLen/*out*/)
{
	int ret = 0;
	FILE* fp = NULL;
	char lineBuf[MaxLine];
	char* temp = NULL, * pBegin = NULL, * pEnd = NULL;

	fp = fopen(pFileName, "r");

	if (fp == NULL)
	{
		ret = -1;
		return ret;
	}

	while (!feof(fp))
	{
		memset(lineBuf, 0, sizeof(lineBuf));
		fgets(lineBuf, MaxLine, fp);
		//printf("lineBuf:%s", lineBuf);
		temp = strchr(lineBuf, '=');
		if (temp == NULL)//û�еȺ�
		{
			continue;
		}
		temp = strstr(lineBuf, pKey);
		if (temp == NULL)//�ж�key�Ƿ���ڵ�ǰ��
		{
			continue;
		}
		temp = temp + strlen(pKey);//
		temp = strstr(temp, "=");
		if (temp == NULL)
		{
			continue;
		}
		temp = temp + 1;
		//printf("temp:%s", temp);

#pragma region ��ȡvalue���
		while (1)
		{
			if (*temp == ' ')
			{
				temp++;
			}
			else
			{
				pBegin = temp;
				if (*pBegin == '\n')
				{
					//û������value
					printf("�����%s û������value \n", pKey);
					goto End;
				}
				break;
			}
		}

#pragma endregion

#pragma region ��ȡvalue�յ�

		while (1)
		{
			if (*temp == ' ' || *temp == '\n')
			{
				break;
			}
			else
			{
				temp++;
			}
		}
		pEnd = temp;

#pragma endregion

		* pValueLen = pEnd - pBegin;
		memcpy(pValue, pBegin, pEnd - pBegin);
	}

End:
	{
		if (fp != NULL)
		{
			fclose(fp);
		}
	}
	return ret;
}


//д��������
//ʵ������
//ѭ��ÿһ�У����Key�������Ƿ���� �������޸Ķ�Ӧ��valueֵ
//�������ڣ����ļ�ĩβ ��� ��key==value��
//�ѵ㣺����޸����е�ֵ
int WriteCfgItem(char* pFileName/*in*/, char* pKey/*in*/, char* pValue/*in*/, int itemValueLen/*in*/)
{
	int rv = 0, iTag = 0, length = 0;
	FILE* pFile = NULL;
	char lineBuf[MaxLine];
	char* pTemp = NULL, * pBegin = NULL, * pEnd = NULL;
	char filebuf[1024 * 8] = { 0 };

	if (pFileName == NULL || pKey == NULL || pValue == NULL)
	{
		rv = -1;
		printf("WriteCfgItem() err. param err \n");
		goto End;
	}
	pFile = fopen(pFileName, "r+");
	if (pFile == NULL)
	{
		rv = -2;
		printf("WriteCfgItem() err. load file");
		//goto End;
	}
	if (pFile == NULL)
	{
		pFile = fopen(pFileName, "w+t");
		if (pFile == NULL)
		{
			rv = -3;
			printf("WriteCfgItem() err. create file");
			goto End;
		}
	}

	//���ļ�ָ���0λ�ÿ�ʼ���ƶ����ļ�ĩβ
	fseek(pFile, 0L, SEEK_END);
	//��ȡ�ļ�����
	length = ftell(pFile);
	//���ļ�ָ����ļ�ĩβ��ʼ���ƶ���0λ��
	fseek(pFile, 0L, SEEK_SET);

	if (length > 1024 * 8)
	{
		rv = -4;
		printf("�ļ�����1024*8, nunsupport.");
		goto End;
	}


	while (!feof(pFile))
	{
		//��ÿһ��
		memset(lineBuf, 0, sizeof(lineBuf));

		pTemp = fgets(lineBuf, MaxLine, pFile);

		if (pTemp == NULL)
		{
			break;
		}
		//key�ؼ����Ƿ��ڱ���
		pTemp = strstr(lineBuf, pKey);

		//�ؼ��ֲ��ڱ��У�copy��filebuf��
		if (pTemp == NULL)
		{
			strcat(filebuf, lineBuf);
			continue;
		}
		//key�ؼ����ڱ����У��滻�ɵ��У���copy��filebuf��
		else
		{
			sprintf(lineBuf, "%s=%s\n", pKey, pValue);
			strcat(filebuf, lineBuf);
			//������key
			iTag = 1;
		}
	}

	//��key�ؼ��֣�������׷��
	if (iTag == 0)
	{
		fprintf(pFile, "%s=%s\n", pKey, pValue);
	}
	//���ؼ��ִ��ڣ������´����ļ�
	else
	{
		if (!pFile == NULL)
		{
			fclose(pFile);
			pFile = NULL;
		}
		pFile = fopen(pFileName, "w+t");
		if (pFile == NULL)
		{
			rv = -4;
			printf("fopen() err");
			goto End;
		}
		fputs(filebuf, pFile);
	}

End:
	{
		if (pFile!=NULL)
		{
			fclose(pFile);
		}
	}
	return rv;
}
