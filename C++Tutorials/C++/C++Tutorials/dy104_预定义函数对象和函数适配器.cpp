
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

/*
	plus
		预定义好的函数对象，能实现不同类型的数据的 + 运算
		实现了数据类型和算法的分离=====>通过函数对象技术

	思考：
		怎么知道plus<type>是两个参数跟踪源码
*/
void plusAdd()
{
	/*
		// STRUCT TEMPLATE plus
		template <class _Ty = void>
		struct plus {
			_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _FIRST_ARGUMENT_TYPE_NAME;
			_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _SECOND_ARGUMENT_TYPE_NAME;
			_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _RESULT_TYPE_NAME;

			constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const {
				return _Left + _Right;
			}
		};
		*/

	plus<int> intAdd;
	int x = 10;
	int y = 10;
	int z = intAdd(x, y);
	cout << z << endl;

	plus<string> stringAdd;
	string s1 = "kangzhenqiang";
	string s2 = "wangjing";
	string s3 = stringAdd(s1, s2);
	cout << s3 << endl;

	vector<string> v;
	v.push_back("aaa");
	v.push_back("bbb");
	v.push_back("ccc");
	v.push_back("ccc");
	v.push_back("ccc");

	sort(v.begin(), v.end(), greater<string>());

	for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	//求ccc出现的次数
	string sc = "ccc";

	//函数适配器

	//equal_to<string>有两个参数， left参数来自容器, right参数来自sc
	//bind2nd 函数适配器 把预定义函数对象和第二个参数进行绑定
	int num = count_if(v.begin(), v.end(), bind2nd(equal_to<string>(), sc));

	cout << "ccc num:" << num << endl;
}


class IsGreat
{
public:
	IsGreat(int i)
	{
		m_num = i;
	}
	bool operator ()(int& num) {
		if (num > m_num)
		{
			return true;
		}
		return false;
	}

private:
	int m_num;
};


void FunctionAdapter()
{
	vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i + 1);
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	int num = count(v.begin(), v.end(), 3);
	cout << "3 num:" << num << endl;

	//求大于3的个数
	int greaterNum = count_if(v.begin(), v.end(), IsGreat(3));
	cout << "greater 3 num:" << greaterNum << endl;

	//求大于3的个数
	//greator<int>() 两个参数左参数来自容器的元素，右参数固定成2（通过bind2nd做的）
	int greaterN = count_if(v.begin(), v.end(), bind2nd(greater<int>(), 3));
	cout << "greater 3 num:" << greaterN << endl;

	//求奇数个数
	int greaterNn = count_if(v.begin(), v.end(), bind2nd(modulus<int>(), 2));
	cout << "偶数格式:" << greaterN << endl;

	//求偶数个数
	int greaterNnn = count_if(v.begin(), v.end(), not1(bind2nd(modulus<int>(), 2)));
	cout << "奇数个数:" << greaterN << endl;

}


int main()
{
	plusAdd();

	FunctionAdapter();

	system("pause");
	return 0;
}
