
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "des.h"


/*
1 加密 分为对称加密 和 非对称加密
2 对称加密：加密的密钥和解密的密钥一样
  非对称加密：加密的密钥和解密的密钥不一样
3 加密解密三要素：明文 密文 密钥

4 对称加密：
			场景：运算速度块，适合做大数据加密，强度弱
			eg:des 3des AES196 521
  非对称加密：
			场景：运算速度慢，强度大 安全
			eg:ras1024 2048 ECC椭圆曲线（SM系列）
5 散列 哈希（指纹）
*/

/*
	对称加密原理 

*/


int FileSymEnc(const char* pFile, const char* pfileSave)
{
	int ret = 0;

	FILE* fp = NULL, * fpSava = NULL;
	unsigned char plain[4096];
	int readPlainLen = 0;
	int writePlainLen = 0;

	unsigned char crpytbuf[4096] = { 0 };
	int crytlen = 0;

	fp = fopen(pFile, "rb");
	if (fp == NULL)
	{
		ret = -1;
		goto END;
	}

	fpSava = fopen(pfileSave, "wb");
	if (fp == NULL)
	{
		ret = -2;
		goto END;
	}

	while (!feof(fp))
	{
		readPlainLen = fread(plain, 1, 4096, fp);
		if (feof(fp))//检查文件是否已经读取完
		{
			break;
		}
		//加密等于4K的数据
		ret = DesEnc_raw(plain, readPlainLen, crpytbuf, &crytlen);

		if (ret != 0)
		{
			ret = -3;
			printf("func DesEnc() err:%d\n");
			goto END;
		}

		writePlainLen = fwrite(crpytbuf, 1, crytlen, fpSava);
		if (writePlainLen != crytlen)
		{
			ret = -4;
			printf("写密等于4k文失败，请检查磁盘是否已满!");
			goto END;
		}
	}

	//加密小于4k的数据
	ret = DesEnc(plain, readPlainLen, crpytbuf, &crytlen);

	if (ret != 0)
	{
		ret = -3;
		printf("func DesEnc() err:%d\n");
		goto END;
	}

	writePlainLen = fwrite(crpytbuf, 1, crytlen, fpSava);
	if (writePlainLen != crytlen)
	{
		ret = -4;
		printf("写小于4K文失败，请检查磁盘是否已满!");
		goto END;
	}

END:
	if (fp != NULL)
	{
		fclose(fp);
	}
	if (fpSava != NULL)
	{
		fclose(fpSava);
	}
	return ret;
}


int FileSymDec(const char* pFile, const char* pfileSave)
{
	int ret = 0;

	FILE* fp = NULL, * fpSava = NULL;
	unsigned char plain[4096];
	int readPlainLen = 0;
	int writePlainLen = 0;

	unsigned char crpytbuf[4096] = { 0 };
	int crytlen = 0;

	fp = fopen(pFile, "rb");
	if (fp == NULL)
	{
		ret = -1;
		goto END;
	}

	fpSava = fopen(pfileSave, "wb");
	if (fp == NULL)
	{
		ret = -2;
		goto END;
	}

	while (!feof(fp))
	{
		readPlainLen = fread(plain, 1, 4096, fp);
		if (feof(fp))//检查文件是否已经读取完
		{
			break;
		}
		//加密等于4K的数据
		ret = DesDec_raw(plain, readPlainLen, crpytbuf, &crytlen);

		if (ret != 0)
		{
			ret = -3;
			printf("func DesEnc() err:%d\n");
			goto END;
		}

		writePlainLen = fwrite(crpytbuf, 1, crytlen, fpSava);
		if (writePlainLen != crytlen)
		{
			ret = -4;
			printf("写明等于4k文失败，请检查磁盘是否已满!");
			goto END;
		}
	}

	//加密小于4k的数据
	ret = DesDec(plain, readPlainLen, crpytbuf, &crytlen);

	if (ret != 0)
	{
		ret = -3;
		printf("func DesEnc() err:%d\n");
		goto END;
	}

	writePlainLen = fwrite(crpytbuf, 1, crytlen, fpSava);
	if (writePlainLen != crytlen)
	{
		ret = -4;
		printf("写明小于4K文失败，请检查磁盘是否已满!");
		goto END;
	}

END:
	if (fp != NULL)
	{
		fclose(fp);
	}
	if (fpSava != NULL)
	{
		fclose(fpSava);
	}
	return ret;
}


void main_enc()
{
	char* file = "E:/04 学习/C++/C++Tutorials/Files/4.txt";
	char* fileEnc = "E:/04 学习/C++/C++Tutorials/Files/4Enc.txt";
	int ret = 0;

	ret = FileSymEnc(file, fileEnc);
	if (ret != 0)
	{
		printf("FileSymEnc err:%d.", ret);
	}
	else
	{
		printf("加密成功！\n");
	}
}

void mian_dec()
{
	char* file = "E:/04 学习/C++/C++Tutorials/Files/4Enc.txt";
	char* fileEnc = "E:/04 学习/C++/C++Tutorials/Files/4Dec.txt";
	int ret = 0;

	ret = FileSymDec(file, fileEnc);
	if (ret != 0)
	{
		printf("FileSymEnc err:%d.", ret);
	}
	else
	{
		printf("解密成功！\n");
	}
	
}


void main()
{
	main_enc();
	mian_dec();
	system("pause");
}