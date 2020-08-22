
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>


using namespace std;
/*
	multimap案例
*/


class Person
{
public:
	string name;
	int		age;
};


void MultiMap()
{
	Person p1, p2, p3, p4, p5;
	p1.name = "kangzhenqiang";
	p1.age = 32;

	p2.name = "wangjing";
	p2.age = 33;

	p3.name = "kang";
	p3.age = 32;

	p4.name = "wang";
	p4.age = 32;

	p5.name = "jing";
	p5.age = 32;

	multimap<string, Person> mMap;

	//sale部门
	mMap.insert(make_pair("sale", p1));
	mMap.insert(make_pair("sale", p2));
	//development
	mMap.insert(make_pair("development", p3));
	mMap.insert(make_pair("development", p4));
	//financial
	mMap.insert(make_pair("financial", p5));


	for (multimap<string, Person>::iterator it = mMap.begin(); it != mMap.end(); it++)
	{
		cout << it->first << " " << it->second.name << endl;
	}
	cout << "遍历结束" << endl;

	cout << "sale count:" << mMap.count("sale") << endl;

	 multimap<string, Person>::iterator itNew = mMap.find("development");

	int llll = mMap.count("development");
	int tag = 0;
	while (itNew !=mMap.end()&& tag< llll)
	{
		cout << itNew->first << " " << itNew->second.name << endl;
		itNew++;
		tag++;
	}
}


//把age为32的修改成name32
void InsertAndDelete()
{
	Person p1, p2, p3, p4, p5;
	p1.name = "kangzhenqiang";
	p1.age = 32;

	p2.name = "wangjing";
	p2.age = 33;

	p3.name = "kang";
	p3.age = 32;

	p4.name = "wang";
	p4.age = 32;

	p5.name = "jing";
	p5.age = 32;

	multimap<string, Person> mMap;

	//sale部门
	mMap.insert(make_pair("sale", p1));
	mMap.insert(make_pair("sale", p2));
	//development
	mMap.insert(make_pair("development", p3));
	mMap.insert(make_pair("development", p4));
	//financial
	mMap.insert(make_pair("financial", p5));


	for (multimap<string, Person>::iterator it = mMap.begin(); it != mMap.end(); it++)
	{
		//cout << it->first << " " << it->second.name << endl;

		if (it->second.age==32)
		{
			it->second.name = "name32";
		}
	}

	for (multimap<string, Person>::iterator it = mMap.begin(); it != mMap.end(); it++)
	{
		cout << it->first << " " << it->second.name << endl;
	}
	cout << "遍历结束" << endl;

}


int main()
{
	MultiMap();
	InsertAndDelete();
	system("pause");
	return 0;
}
