#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

class Name
{
public:
	Name(const char* p);
	~Name();
	Name(const Name& name);

	Name& operator=(const Name& name);

private:
	char* m_p;
	size_t m_len;
};

Name::Name(const char* p)
{
	m_len = strlen(p);
	m_p = (char*)malloc(sizeof(char) * (m_len + 1));
	strcpy(m_p, p);
}

Name::~Name()
{
	if (m_p != NULL)
	{
		free(m_p);
		m_p = NULL;
		m_len = 0;
	}
}

Name::Name(const Name& name)
{
	m_len = name.m_len;
	m_p = (char*)malloc(sizeof(char) * (m_len + 1));
	strcpy(m_p, name.m_p);
}

/// <summary>
/// 等号操作符重载
/// </summary>
/// <param name="name"></param>
//返回void不支持链式编程，返回name&

/*
	重载=号操作符
	1. 先释放旧的内存
	2. 返回引用（支持连等）
*/


Name& Name::operator=(const Name& name)
{
	if (this->m_p != NULL)
	{
		free(m_p);
		m_len = 0;
		m_p = NULL;
	}
	this->m_len = name.m_len;
	this->m_p = (char*)malloc(sizeof(char) * (m_len + 1));
	strcpy(m_p, name.m_p);
	return *this;
}

void playObj()
{
	Name kangzhenqiang("kangzhenqiang");
	Name wangjing("wangjing");
	Name haohongmei("haohongmei");
	haohongmei = wangjing = kangzhenqiang;
}

int main()
{
	playObj();
	system("pause");
	return 0;
}

