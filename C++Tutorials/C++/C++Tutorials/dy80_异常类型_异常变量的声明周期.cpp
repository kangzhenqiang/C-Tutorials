
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//��ͳ���������
int my_strcpy(char* to, char* from)
{
	if (from == NULL)
	{
		return 1;
	}
	if (to == NULL)
	{
		return 2;
	}
	//����
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
	return 0;
}


void my_strcpy1(char* to, char* from)
{
	if (from == NULL)
	{
		throw 1;
	}
	if (to == NULL)
	{
		throw 2;
	}
	//����
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}

//throw char *
void my_strcpy2(char* to, char* from)
{
	if (from == NULL)
	{
		throw "����Դ����";
	}
	if (to == NULL)
	{
		throw "Ŀ��buf����";
	}
	//����
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}


class BadStringErr
{
public:
	BadStringErr() {
		cout << "���캯��" << endl;
	}

	BadStringErr(const BadStringErr& obj) {
		cout << "�������캯��" << endl;
	}

	~BadStringErr() {
		cout << "��������" << endl;
	}

private:

};


void my_strcpy3(char* to, char* from)
{
	//if (from == NULL)
	//{
	//	throw BadStringErr();//�᲻�������������
	//}
	//if (from == NULL)
	//{
	//	throw &(BadStringErr());//�᲻�������������,���������
	//}
	if (from == NULL)
	{
		throw  new BadStringErr();//�᲻�������������,���������
	}
	if (to == NULL)
	{
		throw BadStringErr();
	}
	//����
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}


int main()
{
	int ret = 0;
	char buf[] = "kangzhenqiang";
	char buf1[1024];

	/*my_strcpy(buf1, buf);
	if (ret != 0)
	{
		switch (ret)
		{
		case 1:
			cout << "����Դ����" << endl;
		case 2:
			cout << "ģ��buf����" << endl;
		case 3:
			cout << "copy���̳���" << endl;
		default:
			cout << "δ֪����" << endl;
			break;
		}
	}
	cout << buf1 << endl;


	try
	{
		char buf2[1024];
		my_strcpy1(buf2, buf);
	}
	catch (int e)
	{

	}
	catch (...)
	{

	}

	try
	{
		char buf3[1024];
		my_strcpy2(buf3, NULL);
	}
	catch (char* e)
	{
		cout << e << endl;
	}
	catch (...)
	{

	}*/

	try
	{
		my_strcpy3(buf1, NULL);
	}
	//catch (BadStringErr e)//�ǰ���������copy��e������e,������������
	//{
		/*
		���� 1��
			��������쳣ʱ��ʹ��һ���쳣������copy�����쳣����

		*/
		//}

		//catch (BadStringErr& e)//�ǰ���������copy��e������e,������������
		//{
		//	/*
		//	���� 2��
		//		ʹ�����õĻ���ʹ��throw�Ǹ�����

		//	*/
		//}
	catch (BadStringErr* e)//�ǰ���������copy��e������e,������������
	{
		/*
		���� 3��
			ָ����Ժ�����Ԫ��д��һ�飬����Ԫ�غ����ò���д��һ��

		*/
		delete e;
	}
	system("pause");
	return 0;
}

