
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"76_MyVector.cpp"

using namespace std;

/*
	1. 优化Teacher类，属性变成 char *pname 构造函数里分配内存
	2. 析构函数 释放pname指向的内存空间
	3. 避免浅拷贝 重载 = 重写拷贝构造函数
	4. 在Teacher增加<<
	5. 在模板数组类存在int char Teacher Teacher*
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
	理论提高：
		所有容器提供的都是值(value)语意，而非引用(reference)语意。
		容器执行插入元素的操作时，内部试试拷贝动作。
		所以STL容器内存储的元素必须都能够被拷贝（必须提供拷贝构造函数）。

	结论：
		如果把Teacher放入到MyTeacher数组中，并且Teacher类的属性含有指针，就是出现深拷贝和浅拷贝的问题

		需要Teacher类封装的函数有：
			1. 重写拷贝构造函数
			2. 重载等号操作符
			3. 重载左移操作符
	*/
