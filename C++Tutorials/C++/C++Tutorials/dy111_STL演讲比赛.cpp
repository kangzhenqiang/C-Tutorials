
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>  
#include <string>

using namespace std;


class Speaher
{
public:
	string m_name;
	int m_score[3];
};


//����ѡ��
int GenSpeakers(map<int, Speaher>& mapSpeakers, vector<int>& v) {
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	random_shuffle(str.begin(), str.end());
	for (int i = 0; i < 24; i++)
	{
		Speaher temp;
		temp.m_name = "ѡ��";
		temp.m_name = temp.m_name + str[i];
		mapSpeakers.insert(pair<int, Speaher>(100 + i, temp));
	}
	for (int i = 0; i < 24; i++)
	{
		v.push_back(100 + i);
	}
	return 0;
}

//ѡ�ֱ���
int Speech_Contest_Draw(vector<int>& v) {
	random_shuffle(v.begin(), v.end());
	return 0;
}

//ѡ�ֱ���
int Speech_Contest(int index, vector<int>& v1, map<int, Speaher>& mapSpeakers, vector<int>& v2) {

	//С��÷ּ�¼���� ���ǰ���� ������
	multimap<int, int, greater<int>> multmapGroup;
	int tempCount = 0;

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		tempCount++;
		//���
		{
			deque<int> dScore;
			for (size_t i = 0; i < 10; i++)//10����ί��
			{
				int score = 50 + rand() % 50;
				dScore.push_back(score);
			}
			sort(dScore.begin(), dScore.end());
			dScore.pop_back();//ȥ����ͷ�
			dScore.pop_front();//ȥ����߷�

			//��ƽ����
			int scoresum = accumulate(dScore.begin(), dScore.end(), 0);
			int scoreavg = scoresum / dScore.size();

			mapSpeakers[*it].m_score[index] = scoreavg;

			multmapGroup.insert(pair<int, int>(scoreavg, *it));
		}
		//�������
		if (tempCount % 6 == 0)
		{
			cout << "С��ĳɼ�:" << endl;
			for (multimap<int, int, greater<int>>::iterator mit = multmapGroup.begin(); mit != multmapGroup.end(); mit++) {
				//��� ���� �÷�
				cout << mit->second << "\t" << mapSpeakers[mit->second].m_name << "\t" << mit->first << endl;
			}

			//ǰ��������
			while (multmapGroup.size() > 3)
			{
				multimap<int, int, greater<int>>::iterator it = multmapGroup.begin();
				v2.push_back(it->second);
				multmapGroup.erase(it);
			}
			multmapGroup.clear();
		}
	}
	return 0;
}

//��ӡ
int Speech_Contest_printf(int index, vector<int> v, map<int, Speaher> mapSpeakers) {
	cout << "��" << index << "���ֽ�������:" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "������ţ�" << *it << "\t" << mapSpeakers[*it].m_name << "\t" << mapSpeakers[*it].m_score[index] << endl;
	}
	cout << endl;

	return 0;
}

int main()
{
	//�������
	map<int, Speaher> mapSpeakers;//�μӱ�����ѡ��
	vector<int> v1;//��һ�� �ݽ���������
	vector<int> v2;//�ڶ��� �ݽ���������
	vector<int> v3;//������ �ݽ���������
	vector<int> v4;//ǰ���� �ݽ���������

	//����ѡ�� �õ���һ��ѡ�ֵı�������
	GenSpeakers(mapSpeakers, v1);

	//��һ�� ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�����ǹ�
	Speech_Contest_Draw(v1);
	Speech_Contest(0, v1, mapSpeakers, v2);
	Speech_Contest_printf(0, v2, mapSpeakers);

	//�ڶ��� ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�����ǹ�
	Speech_Contest_Draw(v2);
	Speech_Contest(1, v2, mapSpeakers, v3);
	Speech_Contest_printf(1, v3, mapSpeakers);

	//������ ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�����ǹ�
	Speech_Contest_Draw(v3);
	Speech_Contest(2, v3, mapSpeakers, v4);
	Speech_Contest_printf(2, v4, mapSpeakers);


	system("pause");
	return 0;
}
