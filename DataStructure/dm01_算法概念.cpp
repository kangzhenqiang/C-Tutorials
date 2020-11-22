
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
	算法的最终要编译成具体的计算机指令
	每一个指令在具体的计算机cpu上运行的时间是固定的
	通过具体提的n的步骤的多少就可以推到出算法的复杂度

	*/

/*
	高斯公式求和
*/
int sum(int n)// 2 O(2)
{
	int ret = 0;//1步
	if (n>0)
	{
		ret = n * (n + 1) / 2;//1步
	}
	return ret;
}


int main()
{
	int s= sum(50);
	cout << s << endl;
	system("pause");
	return 0;
}
