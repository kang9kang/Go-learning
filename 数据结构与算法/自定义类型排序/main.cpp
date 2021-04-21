#include<iostream>
using namespace std;
#include<string>
#include<list>


class Person
{
public:
	Person(string name ,int height,int age);
	~Person();

	string m_name;
	int m_height;
	int m_age;
};

Person::Person(string name,int height,int age)
{
	this->m_age = age;
	this->m_height = height;
	this->m_name = name;
}

Person::~Person()
{
}

void printPerson(const list<Person>&p)
{
	for (list<Person>::const_iterator it = p.begin();it != p.end();it++)
	{
		cout << "姓名：" << it->m_name << " 年龄：" << it->m_age << " 身高：" << it->m_height << endl;
	}
}


bool cmp(Person& p1, Person& p2)
{
	if (p1.m_age != p2.m_age)
	{
		return p1.m_age < p2.m_age;
	}
	else
	{
		return p1.m_height < p2.m_height;
	}
}

int main()
{
	list<Person> p;
	Person p1("张飞", 180, 45);
	Person p2("曹操", 170, 55);
	Person p3("刘备", 150, 56);
	Person p4("关羽", 160, 45);
	Person p5("孙权", 190, 45);
	p.push_back(p1);
	p.push_back(p2);
	p.push_back(p3);
	p.push_back(p4);
	p.push_back(p5);
	cout << "反转前：" << endl;
	printPerson(p);
	p.reverse();
	cout << "反转后：" << endl;
	printPerson(p);
	cout << "排序后：" << endl;
	p.sort(cmp);
	printPerson(p);
}