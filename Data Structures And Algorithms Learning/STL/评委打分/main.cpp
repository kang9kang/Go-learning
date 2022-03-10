#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<algorithm>
#include<string>

class Person
{
public:
	Person(string name, int score);
	~Person();

	string m_name;
	int m_score;
};

Person::Person(string name, int score)
{
	this->m_name = name;
	this->m_score = score;
}

Person::~Person()
{
}


void creatPerson(vector<Person>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0;i < 5;i++)
	{
		string str = "选手";
		str += nameSeed[i];
		Person p(str, 0);
		v.push_back(p);
	}
}

void printPerson(const vector<Person>& v)
{
	for (vector<Person>::const_iterator it=v.begin();it != v.end();it++)
	{
		cout << "选手：" << it->m_name << " 得分：" <<it->m_score<< endl;
	}

}

void cinPerson(vector<Person>& v)
{
	for (int i = 0;i < 5;i++)
	{
		deque<int> d;
		for (int i = 0;i < 10;i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
			//cout << score << " ";
		}
		//cout << endl;
		sort(d.begin(), d.end());
		d.pop_front();
		d.pop_back();
		int sum = 0;
		for (int i = 0;i < d.size();i++)
		{
			sum += d[i];
		}
		v[i].m_score = sum / d.size();
	}

}

int main()
{
	vector<Person> v;
	creatPerson(v);
	cinPerson(v);
	printPerson(v);
}