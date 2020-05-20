
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "cfg_op.h"

#define CFGNAME "C:/mycfg.ini"

void showMenu()
{
	printf("=================================\n");

	printf("1 ����д�����ļ�\n");
	printf("2 ���Զ������ļ�\n");
	printf("0 �˳�\n");

	printf("=================================\n");
}

//��ȡ������
int tGetCfgItem()
{
	int ret = 0;

	//д������
	char name[1024] = { 0 };
	char value[1024] = { 0 };
	int len = 0;

	printf("\n�����key:");
	scanf("%s", name);

	ret = GetCfgItem(CFGNAME/*in*/, name/*in*/, value/*out*/, &len /*out*/);

	if (ret != 0)
	{
		printf("func GetCfgItem error:%d", ret);
		return ret;
	}

	printf("vaule:%s\n", value);

	return ret;
}

//д��������
int tWriteCfgItem()
{
	int ret = 0;

	//д������
	char name[1024] = { 0 };
	char value[1024] = { 0 };

	printf("\n�����key:");
	scanf("%s", name);

	printf("\n�����value:");
	scanf("%s", value);

	ret = WriteCfgItem(CFGNAME/*in*/, name/*in*/, value/*in*/, strlen(value)/*in*/);

	if (ret != 0)
	{
		printf("func WriteCfgItem error:%d", ret);
		return ret;
	}

	return ret;
}



void main()
{
	int choice;
	for (; ;)
	{
		showMenu();
		printf("\n������ѡ��:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			return;
			//exit(0);
			break;
		case 1://д������
			tWriteCfgItem();
			break;
		case 2://��������
			tGetCfgItem();
			break;
		default:
			printf("\n������ѡ��:");
			scanf("%d", &choice);
			break;
		}
	}

	system("pause");
}
