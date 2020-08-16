
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;

class Teacher
{
public:
	Teacher();
	Teacher(const char* name, int age);

	~Teacher();

private:
	int age;
	char name[36];
};

Teacher::Teacher()
{
	age = 32;
	strcpy(name, "");
}

Teacher::Teacher(const char* name, int age)
{
	this->age = age;
	strcpy(this->name, name);
}

Teacher::~Teacher()
{
}


int main()
{
	const char* pFileName = "C:/Users/Administrator/Desktop/out.txt";
	ofstream fout(pFileName, ios::binary);
	if (!fout)
	{
		cout << "打开失败" << endl;
		return -1;
	}

	Teacher t1("康振强", 32); 
	Teacher t2("康振强", 32);

	fout.write((char*)&t1, sizeof(t1));
	fout.write((char*)&t2, sizeof(t1));
	fout.close();

	ifstream fin(pFileName);//建立一个输入流对象
	Teacher t;
	fin.read((char*)&t, sizeof(t));
	fin.close();
	system("pause");
	return 0;
}
