#include <iostream>

using namespace std;

class CCCC
{
public:
	CCCC();
	~CCCC();

	int GetC()
	{
		return m_c;
	}

	int AddC()
	{
		m_c = m_c + 1;
		return m_c;
	}

	static void GetCC()//��̬��Ա����
	{
		//�ھ�̬��Ա�����У��ܵ�����ͨ��Ա���Ի�����ͨ��Ա������
		cout << m_c << endl;
	}

private:
	int m_a;
	int m_b;
	static int m_c;
};

CCCC::CCCC()
{
	m_a = 0;
	m_b = 0;
	m_c = 0;
}

CCCC::~CCCC()
{
}


int CCCC::m_c = 0;
int maindy028()
{
	CCCC c1, c2, c3;
	c1.AddC();
	c2.AddC();
	//��̬��Ա����
	CCCC::GetCC();
	c1.GetCC();
	return 0;
}