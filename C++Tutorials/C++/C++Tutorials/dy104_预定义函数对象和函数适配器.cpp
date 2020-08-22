
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
		Ԥ����õĺ���������ʵ�ֲ�ͬ���͵����ݵ� + ����
		ʵ�����������ͺ��㷨�ķ���=====>ͨ������������

	˼����
		��ô֪��plus<type>��������������Դ��
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

	//��ccc���ֵĴ���
	string sc = "ccc";

	//����������

	//equal_to<string>������������ left������������, right��������sc
	//bind2nd ���������� ��Ԥ���庯������͵ڶ����������а�
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

	//�����3�ĸ���
	int greaterNum = count_if(v.begin(), v.end(), IsGreat(3));
	cout << "greater 3 num:" << greaterNum << endl;

	//�����3�ĸ���
	//greator<int>() �����������������������Ԫ�أ��Ҳ����̶���2��ͨ��bind2nd���ģ�
	int greaterN = count_if(v.begin(), v.end(), bind2nd(greater<int>(), 3));
	cout << "greater 3 num:" << greaterN << endl;

	//����������
	int greaterNn = count_if(v.begin(), v.end(), bind2nd(modulus<int>(), 2));
	cout << "ż����ʽ:" << greaterN << endl;

	//��ż������
	int greaterNnn = count_if(v.begin(), v.end(), not1(bind2nd(modulus<int>(), 2)));
	cout << "��������:" << greaterN << endl;

}


int main()
{
	plusAdd();

	FunctionAdapter();

	system("pause");
	return 0;
}
