
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//�� �ַ� ���� ���������������

template<typename T,typename L>
int mySort(T* arr, L len)
{
	if (arr == NULL)
	{
		return -1;
	}

	int temp = 0;

	for (L i = 0; i < len; i++)
	{
		for (L j = i; j < len; j++)
		{
			if (arr[i]<arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	return 0;
}

template<typename T, typename L>
int myPrint(T* arr, L len)
{
	if (arr==NULL)
	{
		return -1;
	}

	for (L i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}

int main()
{
	int myArr[] = { 1,56,78,32,46,21 };
	int len = sizeof(myArr) / sizeof(*myArr);

	/*cout << "����֮ǰ��" << endl;
	myPrint(myArr, len);
	mySort(myArr, len);
	cout << "����֮��" << endl;
	myPrint(myArr, len);*/
	
	cout << "����֮ǰ��" << endl;
	myPrint<int, int>(myArr, len);
	mySort<int, int>(myArr, len);
	cout << "����֮��" << endl;
	myPrint<int, int>(myArr, len);

	{
		//char����

		char myArr[] = "kangzhenqiang";
		int len = sizeof(myArr) / sizeof(*myArr);

		/*cout << "����֮ǰ��" << endl;
		myPrint(myArr, len);
		mySort(myArr, len);
		cout << "����֮��" << endl;
		myPrint(myArr, len);*/

		cout << "����֮ǰ��" << endl;
		myPrint<char, int>(myArr, len);
		mySort<char, int>(myArr, len);
		cout << "����֮��" << endl;
		myPrint<char, int>(myArr, len);

	}

	system("pause");
	return 0;
}
