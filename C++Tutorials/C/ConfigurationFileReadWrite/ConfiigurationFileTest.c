
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "cfg_op.h"

#define CFGNAME "C:/mycfg.ini"

void showMenu()
{
	printf("=================================\n");

	printf("1 测试写配置文件\n");
	printf("2 测试读配置文件\n");
	printf("0 退出\n");

	printf("=================================\n");
}

//获取配置项
int tGetCfgItem()
{
	int ret = 0;

	//写配置项
	char name[1024] = { 0 };
	char value[1024] = { 0 };
	int len = 0;

	printf("\n请键入key:");
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

//写入配置项
int tWriteCfgItem()
{
	int ret = 0;

	//写配置项
	char name[1024] = { 0 };
	char value[1024] = { 0 };

	printf("\n请键入key:");
	scanf("%s", name);

	printf("\n请键入value:");
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
		printf("\n请输入选项:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			return;
			//exit(0);
			break;
		case 1://写配置项
			tWriteCfgItem();
			break;
		case 2://读配置项
			tGetCfgItem();
			break;
		default:
			printf("\n请输入选项:");
			scanf("%d", &choice);
			break;
		}
	}

	system("pause");
}
