#include <iostream>

using namespace std;

/*
	�� ��װ�����㺬��

	1. �����Ժͷ������з�װ
	2. �����Ժͷ������з��ʿ���
	3. ����ڲ�������ⲿ
	4. ��ķ��ʿ��ƹؼ��֣�
		public�����εĳ�Ա�����ͺ���������������ڲ�������ⲿ����
		private:���εĳ�Ա�����ͺ���������ֻ��������ڲ������ʣ�����������ⲿ����
		protected:���εĳ�Ա�����ͺ�����ֻ��������ڲ������ʣ�����������ⲿ���ʣ����ڼ̳���
*/


class MyCiircle
{
public:
	double m_r;//���� ��Ա����
	double m_s;

public:
	double getR()
	{
		return m_r;
	}

	void setR(double r)
	{
		m_r = r;
	}

	double get_S()
	{
		return 3.14 * m_r * m_r;
	}

protected:


private:

};

//��װ������
//���װ��Ա�ȱ����ͳ�Ա���� ͨ����Ĳ������Ե�����ĳ�Ա����

void printMyCircle01(MyCiircle* pC)
{
	cout << pC->get_S() << endl;
	cout << pC->getR() << endl;
}

//����
void printMyCircle02(MyCiircle& pC) 
{
	cout << pC.get_S() << endl;
	cout << pC.getR() << endl;
}

void printMyCircle03(MyCiircle pC)
{

}


//��ķ�װ��һ�㺬��
void maindy15001()
{
	MyCiircle c1;
	c1.setR(5);
	cout << c1.get_S() << endl;
	system("pause");
}

//��ķ�װ�ڶ��κ���

class MyCicrleAdvance
{
private:
	double m_r;//���� ��Ա���� Ĭ��ʱ˽�е�
	double m_s;//���˽�г�Ա�ͷ����൱���������벻�ܱ�����

public:
	double getR()
	{
		return m_r;
	}

	void setR(double r)
	{
		m_r = r;
	}

	double get_S()
	{
		return 3.14 * m_r * m_r;
	}

protected:

};

void maindy15002()
{

	MyCiircle c1;
	c1.setR(5);

	MyCicrleAdvance c2;
	c2.getR();

	system("pause");
}

/*
	stuct �� class ������
	*/

struct AAA
{
	int a;//Ĭ��������public��

public:

protected:

private:
		 
};

void miandy15003()
{
	AAA a;
	a.a;
}


