#include <iostream>

using namespace std;

/*
	1. iostream 文件中没有引入标注的std 需要我们程序员手工的写
	2. 如果不写using namespace std; 需要显示的引入std
	3. 定义命名空间
	4. 使用命名空间
	*/

namespace namespaceA {
	int a=10;
}

namespace namespaceB {
	int a=20;
	namespace namespaceC {
		struct  Teacher
		{
			string name;
			int age;
		};
	}
}

void maindy001()

{
	cout << "namespace test" << endl;
	cout << namespaceA::a << endl;

	namespaceB::namespaceC::Teacher t1;

	t1.name = "kangzhenqiang";
	t1.age = 32;

	cout << t1.name << endl;
	cout << t1.age << endl;

	system("pause");
}

/*
	1. 当使用<iostream>的时候，该头文件没有定义全局命名空间，必须使用namespace std，否则需要显示使用std;
	2. c++标准为了和c区别开，也为了正确使用命名空间，规定头文件不适用后缀.h
	3. c++命名空间的定义 namespace name{...}
	*/

