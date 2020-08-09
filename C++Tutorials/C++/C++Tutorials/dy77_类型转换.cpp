
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
	C����ǿ������ת��(Type Cast)�ܼ򵥣�����ʲô���͵�ת��ͳͳ�ǣ�TYPE b = (TYPE)a

	C++��������ת���ṩ��4������ת����������Ӧ�Բ�ͬ���ϵ�Ӧ�ã�

		static_cast ��̬����ת������ int ת���� char

		reinterpreter_cast ���½�������

		dynamic_cast ����������Ƕ�̬����ת����������͸���֮��Ķ�̬����ת��

		const_cast ������������ȥconst����

		4������ת���ĸ�ʽ��
		TYPE B = static_cast<TYPE>(a)

	*/


class Aninal
{
public:
	virtual void cry() = 0;
private:

};


class Dog :public Aninal
{
public:
	virtual void cry()
	{
		cout << "����" << endl;
	}

	void doHome()
	{
		cout << "����" << endl;
	}

private:

};


class Cat :public Aninal
{
public:
	virtual void cry()
	{
		cout << "����" << endl;
	}

	void doThing()
	{
		cout << "ץ����" << endl;
	}

private:

};


void playObj(Aninal* base)
{
	base->cry();
	//dynamic_cast ����ʱ����ʶ��

	Dog* dog = dynamic_cast<Dog*>(base);

	if (dog != NULL)
	{
		dog->doHome();
	}

	Cat* cat = dynamic_cast<Cat*>(base);

	if (cat != NULL)
	{
		cat->doThing();
	}

}

class Tree
{
public:

private:

};


//const char* p ��const���� ��pָ����ڴ�ռ� ���ֻ������
void printBuf(const char *p)
{
	//p[0] = 'x';
	char* p1 = NULL;

	p1 = const_cast<char*>(p);
	
	p1[0] = 'Z';
}

/*
	����ת����
		����1 ����ԱҪ�����֪����Ҫת�ı���������ת��ǰ��ʲô���ͣ�����ת������ʲô���ͣ�ת������ʲô���
		����2 һ������£��������������ת���������������ת��
*/


int main()
{
	char buf[] = "kangzhenqiang";

	//��̬�����������޸�
	const char* my = "wangjing";

	//����Ա Ҫȷ�� p��ָ����ڴ�ռ� ȷʵ���޸ģ���������޸Ļ���������Ժ��
	printBuf(buf);
	printBuf(my);
	cout << buf << endl;
	return 0;
}


int mian02()
{
	Dog d;
	Cat c;

	Aninal* base = NULL;

	base = static_cast<Aninal*>(&d);//��c++�������ڱ����ʱ��������ͼ��

	base = reinterpret_cast<Aninal*>(&c);//ǿ������ת��

	Tree t;

	{

		//base = static_cast<Aninal*>(&t);//��c++�������ڱ����ʱ��������ͼ��

		base = reinterpret_cast<Aninal*>(&t);//ǿ������ת�� ���½��� ǿ������ת����ζ��

	}



	playObj(&d);

	playObj(&c);
	return 0;
}


int main01()
{
	/*C���*/
	double dPi = 3.1415926;
	int num1 = (int)dPi;//C����ת��
	int num2 = static_cast<int>(dPi);//��̬����ת�� �����ʱ��c++�������������ͼ��
	int num3 = dPi;//c������ ��ʽ����ת���ĵط�����ʹ��static_cast<>()��������ת��

	//char *p =====> int *
	const char* p1 = "kangzhenqiang";

	const int* p2 = NULL;

	//p2 = static_cast<int*> (p1);//ʹ��static_cast<TYPE>(),����������ʱ���������ͼ�飬���д��� ��ʾ����

	//p2 = reinterpret_cast<int*>(p1);//����ͬ����֮�䣬����ǿ������ת������reinterpret_cast()�������±���

	system("pause");
	return 0;
}
