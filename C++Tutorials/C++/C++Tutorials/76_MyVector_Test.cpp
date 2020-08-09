
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"76_MyVector.cpp"

using namespace std;

/*
	1. �Ż�Teacher�࣬���Ա�� char *pname ���캯��������ڴ�
	2. �������� �ͷ�pnameָ����ڴ�ռ�
	3. ����ǳ���� ���� = ��д�������캯��
	4. ��Teacher����<<
	5. ��ģ�����������int char Teacher Teacher*
	*/

class Teacher
{
	friend ostream& operator<<(ostream& out, Teacher& obj)
	{
		cout << "name:" << obj.pname << "," << "age:" << obj.age << endl;
	}

public:
	Teacher() {
		age = 33;
		pname = new char[1];
		strcpy(pname, "");
	}

	Teacher(const char* name, int age) {
		this->age = age;
		pname = new char[strlen(name) + 1];
		strcpy(this->pname, name);
	}


	Teacher(const Teacher& obj)
	{
		pname = new char[strlen(obj.pname) + 1];
		age = obj.age;
		strcpy(pname, obj.pname);
	}

	~Teacher()
	{
		if (pname != NULL)
		{
			delete[] pname;
			pname = NULL;
			age = 0;
		}
	}

	void print()
	{
		cout << "Name:" << pname << "," << "age:" << age << endl;
	}

	Teacher operator=(const Teacher& obj)
	{
		if (pname!=NULL)
		{
			delete[] pname;
			pname = NULL;
			age = 0;
		}

		pname = new char[strlen(obj.pname) + 1];
		strcpy(pname, obj.pname);
		age = obj.age;
		return *this;
	}

private:
	char* pname;
	int age;
};


int main01()
{
	MyVector<int> vector(10);

	for (size_t i = 0; i < vector.GetLen(); i++)
	{
		vector[i] = i;
		cout << vector[i] << " ";
	}
	cout << endl;

	MyVector<int> v = vector;

	for (size_t i = 0; i < v.GetLen(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	cout << v;

	Teacher t1("t1", 32), t2("t2", 33);
	MyVector<Teacher> teachers(2);
	teachers[0] = t1;
	teachers[1] = t2;

	for (size_t i = 0; i < teachers.GetLen(); i++)
	{
		Teacher temp = teachers[i];
		temp.print();
	}

	system("pause");
	return 0;
}


int main()
{
	Teacher t1("t1", 32), t2("t2", 33);
	MyVector<Teacher*> teachers(2);
	teachers[0] = &t1;
	teachers[1] = &t2;

	for (size_t i = 0; i < teachers.GetLen(); i++)
	{
		Teacher temp = *teachers[i];
		temp.print();
	}

	system("pause");
	return 0;
}

/*
	������ߣ�
		���������ṩ�Ķ���ֵ(value)���⣬��������(reference)���⡣
		����ִ�в���Ԫ�صĲ���ʱ���ڲ����Կ���������
		����STL�����ڴ洢��Ԫ�ر��붼�ܹ��������������ṩ�������캯������

	���ۣ�
		�����Teacher���뵽MyTeacher�����У�����Teacher������Ժ���ָ�룬���ǳ��������ǳ����������

		��ҪTeacher���װ�ĺ����У�
			1. ��д�������캯��
			2. ���صȺŲ�����
			3. �������Ʋ�����
	*/
