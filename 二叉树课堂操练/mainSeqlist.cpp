
#include "SeqList.cpp"
#include <iostream>


using namespace std;

struct Teacher
{
	char name[64];
	int age;
};


int main()
{
	Teacher t1, t2, t3;

	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	SeqList<Teacher> list(10);
	list.insert(t1,0);
	list.insert(t2,0);
	list.insert(t3,0);

	Teacher temp;
	for (size_t i = 0; i < list.getLength(); i++)
	{
		list.get(i, temp);
		cout << temp.age << endl;
	}

	while (list.getLength())
	{
		list.del(0,temp);
		cout << temp.age << endl;
	}

	return 0;
}