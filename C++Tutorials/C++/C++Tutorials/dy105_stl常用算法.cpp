
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <list>

using namespace std;


class ShowElement
{
public:
	ShowElement()
	{
		num = 0;
	}
	void operator () (int& n)
	{
		cout << n << " ";
		num++;
	}
	void PrintNum()
	{
		cout << num << endl;
	}
private:
	int num;
};


void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void printList(list<int> myList)
{
	for (list<int>::iterator it = myList.begin(); it != myList.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void showElem(int& n)
{
	cout << n << " ";
}
int showElemElem(int n)
{
	cout << n << " ";
	return n;
}


void foreach_Transform()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	printVector(v1);
	for_each(v1.begin(), v1.end(), showElem);//������������Ǻ����ص���ڵ�ַ
	cout << endl;

	// FUNCTION TEMPLATE for_each
	//template <class _InIt, class _Fn>
	//_CONSTEXPR20 _Fn for_each(_InIt _First, _InIt _Last, _Fn _Func) { // perform function for each element [_First, _Last)
	//	_Adl_verify_range(_First, _Last);
	//	auto _UFirst = _Get_unwrapped(_First);
	//	const auto _ULast = _Get_unwrapped(_Last);
	//	for (; _UFirst != _ULast; ++_UFirst) {
	//		_Func(*_UFirst);
	//	}

	//	return _Func;
	//}


	ShowElement se;
	ShowElement shouElem = for_each(v1.begin(), v1.end(), se);//������������Ǻ����ص���ڵ�ַ
	cout << endl;
	shouElem.PrintNum();
	cout << endl;
	se.PrintNum();
}

/*
	replace��transform���и���
	*/
int increae(int& i)
{
	return i + 100;
}


void transform_transform()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	printVector(v1);

	vector<int> v2;
	v2.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), increae);//ʹ�ûص�����
	printVector(v2);

	vector<int> v3;
	v3.resize(v1.size());
	transform(v1.begin(), v1.end(), v3.begin(), negate<int>());//ʹ��Ԥ���庯������
	printVector(v3);

	list<int> myList;
	myList.resize(v1.size());
	transform(v1.begin(), v1.end(), myList.begin(), bind2nd(multiplies<int>(), 10));//ʹ�ú��� ������
	printList(myList);

	//transform���԰�������ֱ���������Ļ

	transform(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "), negate<int>());
}

void transform_pk_foreach()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);

	vector<int> v1 = v;

	//һ������£�for_each��ʹ�õĺ������󣬲��������ã�û�з���ֵ

	for_each(v.begin(), v.end(), showElem);
	cout << endl;

	/*�鿴�����ڱ���ĺ��� ģ�� ʵ������_OutIt std::transform<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<_Ty>>>, std::_Vector_iterator<std::_Vector_val<std::_Simple_types<_Ty>>>, void(__cdecl*)(int&)>(const _InIt, const _InIt, _OutIt, _Fn)��������
		with
		[
			_OutIt = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<int>>>,
			_Ty = int,
			_InIt = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<int>>>,
			_Fn = void(__cdecl*)(int&)
		]*/


		//template <class _InIt, class _OutIt, class _Fn>
		//_CONSTEXPR20 _OutIt transform(const _InIt _First, const _InIt _Last, _OutIt _Dest, _Fn _Func) {
		//	// transform [_First, _Last) with _Func
		//	_Adl_verify_range(_First, _Last);
		//	auto _UFirst = _Get_unwrapped(_First);
		//	const auto _ULast = _Get_unwrapped(_Last);
		//	auto _UDest = _Get_unwrapped_n(_Dest, _Idl_distance<_InIt>(_UFirst, _ULast));
		//	for (; _UFirst != _ULast; ++_UFirst, (void) ++_UDest) {
		//		*_UDest = _Func(*_UFirst);
		//	}

		//	_Seek_wrapped(_Dest, _UDest);
		//	return _Dest;
		//}
		/*
			������ΪʲôҪ�з���ֵ
			*/

	//transform��ʹ�õĺ������󣬲���һ�㲻ʹ�����ã����ǻ��з���ֵ
	transform(v.begin(), v.end(), v1.begin(), showElemElem);
	cout << endl;
}



int main()
{
	foreach_Transform();
	transform_transform();
	transform_pk_foreach();
	transform_pk_foreach();
	system("pause");
	return 0;
}
