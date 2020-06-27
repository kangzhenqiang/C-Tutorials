#pragma once //只包含一次,包含两次相当于声明了两次

#ifndef _TEACHERADVANCE //ctrl+shift+u 变大写
#define _TEACHERADVANCE


class TeacherAdvance
{
private:
	int m_age;
	char m_name[32];
public:
	int setAge(int age);
	int getAge();
};

#endif

