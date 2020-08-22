
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>

using namespace std;


void ListOperate()
{
	list<int> l;
	cout << "List count:" << l.size() << endl;
	for (size_t i = 0; i < 10; i++)
	{
		l.push_back(i + 1);
	}
	cout << "List count:" << l.size() << endl;

	list<int>::iterator it = l.begin();

	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	it = l.begin();
	//list 不能随机访问
	it++;
	//it=it + 5;//不支持随机的访问
	//插入元素
	l.insert(it, 100);//请问100插在那个位置

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//结论1： 
		//链表的节点index 序号是从0号元素位置开始
		//在3号位置插入元素，让原来的3号位置变成4号位置，原来的4号位置变成5号位置

	//删除元素 作闭右开

	it = l.begin();
	it++;
	it++;
	it++;
	l.erase(l.begin(), it);
	l.remove(10);
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	ListOperate();

	system("pause");
	return 0;
}
