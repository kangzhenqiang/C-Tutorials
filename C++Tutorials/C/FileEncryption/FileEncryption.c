
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "des.h"


/*
1 ���� ��Ϊ�ԳƼ��� �� �ǶԳƼ���
2 �ԳƼ��ܣ����ܵ���Կ�ͽ��ܵ���Կһ��
  �ǶԳƼ��ܣ����ܵ���Կ�ͽ��ܵ���Կ��һ��
3 ���ܽ�����Ҫ�أ����� ���� ��Կ

4 �ԳƼ��ܣ�
			�����������ٶȿ飬�ʺ��������ݼ��ܣ�ǿ����
			eg:des 3des AES196 521
  �ǶԳƼ��ܣ�
			�����������ٶ�����ǿ�ȴ� ��ȫ
			eg:ras1024 2048 ECC��Բ���ߣ�SMϵ�У�
5 ɢ�� ��ϣ��ָ�ƣ�
*/

/*
	�ԳƼ���ԭ�� 

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
		if (feof(fp))//����ļ��Ƿ��Ѿ���ȡ��
		{
			break;
		}
		//���ܵ���4K������
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
			printf("д�ܵ���4k��ʧ�ܣ���������Ƿ�����!");
			goto END;
		}
	}

	//����С��4k������
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
		printf("дС��4K��ʧ�ܣ���������Ƿ�����!");
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
		if (feof(fp))//����ļ��Ƿ��Ѿ���ȡ��
		{
			break;
		}
		//���ܵ���4K������
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
			printf("д������4k��ʧ�ܣ���������Ƿ�����!");
			goto END;
		}
	}

	//����С��4k������
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
		printf("д��С��4K��ʧ�ܣ���������Ƿ�����!");
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
	char* file = "E:/04 ѧϰ/C++/C++Tutorials/Files/4.txt";
	char* fileEnc = "E:/04 ѧϰ/C++/C++Tutorials/Files/4Enc.txt";
	int ret = 0;

	ret = FileSymEnc(file, fileEnc);
	if (ret != 0)
	{
		printf("FileSymEnc err:%d.", ret);
	}
	else
	{
		printf("���ܳɹ���\n");
	}
}

void mian_dec()
{
	char* file = "E:/04 ѧϰ/C++/C++Tutorials/Files/4Enc.txt";
	char* fileEnc = "E:/04 ѧϰ/C++/C++Tutorials/Files/4Dec.txt";
	int ret = 0;

	ret = FileSymDec(file, fileEnc);
	if (ret != 0)
	{
		printf("FileSymEnc err:%d.", ret);
	}
	else
	{
		printf("���ܳɹ���\n");
	}
	
}


void main()
{
	main_enc();
	mian_dec();
	system("pause");
}