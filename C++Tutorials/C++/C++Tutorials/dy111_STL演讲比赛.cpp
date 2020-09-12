
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


//产生选手
int GenSpeakers(map<int, Speaher>& mapSpeakers, vector<int>& v) {
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	random_shuffle(str.begin(), str.end());
	for (int i = 0; i < 24; i++)
	{
		Speaher temp;
		temp.m_name = "选手";
		temp.m_name = temp.m_name + str[i];
		mapSpeakers.insert(pair<int, Speaher>(100 + i, temp));
	}
	for (int i = 0; i < 24; i++)
	{
		v.push_back(100 + i);
	}
	return 0;
}

//选手比赛
int Speech_Contest_Draw(vector<int>& v) {
	random_shuffle(v.begin(), v.end());
	return 0;
}

//选手比赛
int Speech_Contest(int index, vector<int>& v1, map<int, Speaher>& mapSpeakers, vector<int>& v2) {

	//小组得分记录下来 求出前三名 后三名
	multimap<int, int, greater<int>> multmapGroup;
	int tempCount = 0;

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		tempCount++;
		//打分
		{
			deque<int> dScore;
			for (size_t i = 0; i < 10; i++)//10个评委答复
			{
				int score = 50 + rand() % 50;
				dScore.push_back(score);
			}
			sort(dScore.begin(), dScore.end());
			dScore.pop_back();//去除最低分
			dScore.pop_front();//去除最高分

			//求平均分
			int scoresum = accumulate(dScore.begin(), dScore.end(), 0);
			int scoreavg = scoresum / dScore.size();

			mapSpeakers[*it].m_score[index] = scoreavg;

			multmapGroup.insert(pair<int, int>(scoreavg, *it));
		}
		//处理分组
		if (tempCount % 6 == 0)
		{
			cout << "小组的成绩:" << endl;
			for (multimap<int, int, greater<int>>::iterator mit = multmapGroup.begin(); mit != multmapGroup.end(); mit++) {
				//编号 姓名 得分
				cout << mit->second << "\t" << mapSpeakers[mit->second].m_name << "\t" << mit->first << endl;
			}

			//前三名晋级
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

//打印
int Speech_Contest_printf(int index, vector<int> v, map<int, Speaher> mapSpeakers) {
	cout << "第" << index << "几轮晋级名单:" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "参赛编号：" << *it << "\t" << mapSpeakers[*it].m_name << "\t" << mapSpeakers[*it].m_score[index] << endl;
	}
	cout << endl;

	return 0;
}

int main()
{
	//容器设计
	map<int, Speaher> mapSpeakers;//参加比赛的选手
	vector<int> v1;//第一轮 演讲比赛名单
	vector<int> v2;//第二轮 演讲比赛名单
	vector<int> v3;//第三轮 演讲比赛名单
	vector<int> v4;//前三名 演讲比赛名单

	//产生选手 得到第一轮选手的比赛名单
	GenSpeakers(mapSpeakers, v1);

	//第一轮 选手抽签 选手比赛 查看比赛记过
	Speech_Contest_Draw(v1);
	Speech_Contest(0, v1, mapSpeakers, v2);
	Speech_Contest_printf(0, v2, mapSpeakers);

	//第二轮 选手抽签 选手比赛 查看比赛记过
	Speech_Contest_Draw(v2);
	Speech_Contest(1, v2, mapSpeakers, v3);
	Speech_Contest_printf(1, v3, mapSpeakers);

	//第三轮 选手抽签 选手比赛 查看比赛记过
	Speech_Contest_Draw(v3);
	Speech_Contest(2, v3, mapSpeakers, v4);
	Speech_Contest_printf(2, v4, mapSpeakers);


	system("pause");
	return 0;
}
