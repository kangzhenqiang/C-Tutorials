#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "cfg_op.h"

#define MaxLine 2048

//获取配置项
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
		if (temp == NULL)//没有等号
		{
			continue;
		}
		temp = strstr(lineBuf, pKey);
		if (temp == NULL)//判断key是否存在当前行
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

#pragma region 获取value起点
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
					//没有配置value
					printf("配置项：%s 没有配置value \n", pKey);
					goto End;
				}
				break;
			}
		}

#pragma endregion

#pragma region 获取value终点

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


//写入配置项
//实现流程
//循环每一行，检查Key配置项是否存在 若存在修改对应的value值
//若不存在，在文件末尾 添加 “key==value”
//难点：如何修改流中的值
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

	//把文件指针从0位置开始，移动到文件末尾
	fseek(pFile, 0L, SEEK_END);
	//获取文件长度
	length = ftell(pFile);
	//把文件指针从文件末尾开始，移动到0位置
	fseek(pFile, 0L, SEEK_SET);

	if (length > 1024 * 8)
	{
		rv = -4;
		printf("文件超过1024*8, nunsupport.");
		goto End;
	}


	while (!feof(pFile))
	{
		//读每一行
		memset(lineBuf, 0, sizeof(lineBuf));

		pTemp = fgets(lineBuf, MaxLine, pFile);

		if (pTemp == NULL)
		{
			break;
		}
		//key关键字是否在本行
		pTemp = strstr(lineBuf, pKey);

		//关键字不在本行，copy到filebuf中
		if (pTemp == NULL)
		{
			strcat(filebuf, lineBuf);
			continue;
		}
		//key关键字在本行中，替换旧的行，再copy到filebuf中
		else
		{
			sprintf(lineBuf, "%s=%s\n", pKey, pValue);
			strcat(filebuf, lineBuf);
			//若存在key
			iTag = 1;
		}
	}

	//若key关键字，不存在追加
	if (iTag == 0)
	{
		fprintf(pFile, "%s=%s\n", pKey, pValue);
	}
	//若关键字存在，则重新创建文件
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
