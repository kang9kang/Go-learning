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
		cout << "������" << it->m_name << " ���䣺" << it->m_age << " ��ߣ�" << it->m_height << endl;
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
	Person p1("�ŷ�", 180, 45);
	Person p2("�ܲ�", 170, 55);
	Person p3("����", 150, 56);
	Person p4("����", 160, 45);
	Person p5("��Ȩ", 190, 45);
	p.push_back(p1);
	p.push_back(p2);
	p.push_back(p3);
	p.push_back(p4);
	p.push_back(p5);
	cout << "��תǰ��" << endl;
	printPerson(p);
	p.reverse();
	cout << "��ת��" << endl;
	printPerson(p);
	cout << "�����" << endl;
	p.sort(cmp);
	printPerson(p);
}