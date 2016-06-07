// Vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vector.h"
#include <iostream>
#include <string>

using namespace std;
class Student
{
private:
	string m_name;
	int m_age;

public:
	Student() : m_name("Unknown"), m_age(-1)
	{
	}

	Student(string name, int age)
	{
		setName(name);
		setAge(age);
	}

	void setName(string name)
	{
		m_name = name;
	}

	void setAge(int age)
	{
		if (age > 0)
		{
			m_age = age;
		}
	}

	Student& operator=(const Student& other)
	{
		if (this != &other)
		{
			m_name = other.m_name;
			m_age = other.m_age;
		}
		return *this;
	}
};
int main()
{
	Student student1("Ivan", 20);
	Student student2("Stamat", 20);

	Vector<Student> students;
	students.push_back(student1);
	students.push_back(student2);

	Vector<int> integers;
	integers.push_back(1);
	integers.push_back(13);
	integers.push_back(37);
	integers.push_back(73);
	integers.push_back(121);
	integers.push_back(181);
	integers.push_back(253);

	cout << integers.back() << endl; //253
	integers.pop_back();
	cout << integers.back() << endl << integers.front() << endl; //181, 1
	cout << integers[4] << endl; //121

	integers.push_back(777);

	for (int i = 0; i < integers.size(); i++)
	{
		cout << integers[i] << " "; //1 13 37 73 121 181 777
	}
	cout << endl;

	Vector<string> strings;
	strings.push_back("az ");
	strings.push_back("sum ");
	strings.push_back("string.");

	for (int i = 0; i < strings.size(); i++)
	{
		cout << strings[i];
	}
	cout << endl; //az sum string.

	strings.erase(1);
	for (int i = 0; i < strings.size(); i++)
	{
		cout << strings[i];
	}
	cout << endl; //az string

	return 0;
}

