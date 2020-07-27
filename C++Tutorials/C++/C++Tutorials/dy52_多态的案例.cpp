#include <iostream>

using namespace std;

class HeroFighter
{
public:
	HeroFighter();
	~HeroFighter();

	//��дvirtual�ؼ��� �Ǿ�̬����  c++����������HeroFighter���ͣ�ȥִ�� ������͵�power���� �ڱ���������׶ξ��Ѿ����������ĵ���
	//��̬���ࣺ�ٰ󶨣������е�ʱ�򣬸��ݾ�����󣨾������ͣ���ִ�в�ͬ����ĺ��������ֳɶ�̬
	virtual int power()
	{
		return 10;
	}

private:

};

HeroFighter::HeroFighter()
{

}

HeroFighter::~HeroFighter()
{

}

class EnemyFighter
{
public:
	EnemyFighter();
	~EnemyFighter();

	int attck()
	{
		return 15;
	}

private:

};

EnemyFighter::EnemyFighter()
{
}

EnemyFighter::~EnemyFighter()
{
}

class AdvHeroFighter :public HeroFighter
{
public:
	AdvHeroFighter();
	~AdvHeroFighter();

	virtual int power()
	{
		return 20;
	}

private:

};

AdvHeroFighter::AdvHeroFighter()
{
}

AdvHeroFighter::~AdvHeroFighter()
{
}

void Play(HeroFighter* he, EnemyFighter* ef)
{
	if (he->power() > ef->attck())
	{
		cout << "����Ӯ��" << endl;
	}
	else
	{
		cout << "���ǹ���" << endl;
	}
}


/*
	��װ��ͻ��c�����ĸ���... ����������������ʱ�򣬿���ʹ�ö�������ԺͶ���ķ���
	�̳У�A B ���븴��...
	��̬������ʹ��δ��...
	*/

/*
	ʵ�ֶ�̬����������
		C�����м�Ӹ�ֵ��ָ����ڵ��������
		��c���Ե���������1 ������������ 2 �������� 3 *p�ڱ��������м�ӵ�ȥ�޸�ʵ�ε�ֵ��
		1��Ҫ�м̳�
		2��Ҫ�к�����д
		3���ø���ָ�루�������ã�ָ���������
	*/

int main()
{
	HeroFighter he;
	AdvHeroFighter ad;
	EnemyFighter en;

	Play(&he, &en);
	Play(&ad, &en);
	system("pause");
	return 0;
}