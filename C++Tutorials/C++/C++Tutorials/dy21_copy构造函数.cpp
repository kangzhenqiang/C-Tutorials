#include<iostream>

using namespace std;

//�������캯��
class Location
{
public:
	Location();
	Location(double x, double y);
	Location(const Location& obj);//����const����������ֵʱ��ʾ����Ӧcopy���캯��
	~Location();

	double GetX()
	{
		return m_x;
	}

	double GetY()
	{
		return m_y;
	}


private:

	double m_x;
	double m_y;

};

Location::Location()
{
	m_x = 0;
	m_y = 0;
	cout << "initilize" << endl;
}

Location::Location(double x, double y)
{
	m_x = x;
	m_y = y;
	cout << "X and Y initilize" << endl;
}

Location::Location(const Location& obj)
{
	m_x = obj.m_x;//ʹ��˽���ֶθ�ֵ
	m_y = obj.m_y;
	cout << "X and Y copy" << endl;
}



Location::~Location()
{
	cout << "X and Y ����" << endl;
}


void f(Location l)
{
	cout << l.GetX() << endl;
}

void playObj()
{
	Location a(5, 5);
	Location b = a;
	f(b);//bȥ��ʼ���β�p�������copy���캯��
}

/// <summary>
/// ����һ��Ԫ��
/// </summary>
/// <returns></returns>

/* ����1����������ֵ��һ��Ԫ�أ���ֵ���ͣ������ص���һ���µ������������Ի���������������copy���캯����*/
// ����2�����������ȥ���� 
// ������������� ��ʼ����һ�����͵Ķ����������� ת��Ϊ��������
// ������������� ��ֵ����һ��ͬ���͵Ķ���������������
//����ôд���룬��Ʊ������Ĵ�ţ�Ǿͻ���㷵��һ���¶���û������ ��������
Location GetLocation()
{
	Location a(5, 5);
	return a;
}


int maindy021()
{
	playObj();

	//�����������ʼ��m ��ʱc++������ ֱ�Ӱ������������ ������ת����������
	//������������� ��ʼ����һ�����͵Ķ����������� ת��Ϊ��������
	Location c = GetLocation();//Ĭ�ϵ���

	Location d;
	//������������� ��ֵ����һ��ͬ���͵Ķ���������������
	d = GetLocation();
	system("pause");
	return 0;
}