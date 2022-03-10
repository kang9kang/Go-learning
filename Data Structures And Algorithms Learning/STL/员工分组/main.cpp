#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<map>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
	string m_name;
	int m_salary;

};

void creatWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i=0;i<10;i++)
	{
		Worker w;
		string str = "Ա��";
		str += nameSeed[i];
		w.m_name = str;
		w.m_salary = rand() % 10000 + 10000;
		v.push_back(w);
	}
}

void printWorker(const vector<Worker>& v)
{
	for (vector<Worker>::const_iterator it = v.begin();it != v.end();it++)
	{
		cout << "������" << it->m_name << " ���ʣ�" << it->m_salary << endl;
	}
}

void creatMap(multimap<int, Worker>& m, vector<Worker>& v)
{
	for (int i = 0;i < 10;i++) {
		int index = rand() % 3;
		m.insert(make_pair(index, v[i]));
	}
}

void showGroup(const multimap<int, Worker>& m)
{
	int index = 0;
	map<int, Worker>::const_iterator it = m.find(CEHUA);
	cout << "�߻���" << endl;
	for (;it != m.end() && index < m.count(CEHUA);it++, index++)
	{
		cout << "������" << it->second.m_name << " ���ʣ�" << it->second.m_salary << endl;
	}
	cout << "-------------------------" << endl;
	index = 0;
    it = m.find(MEISHU);
	cout << "������" << endl;
	for (;it != m.end() && index < m.count(MEISHU);it++, index++)
	{
		cout << "������" << it->second.m_name << " ���ʣ�" << it->second.m_salary << endl;
	}
	cout << "-------------------------" << endl;
	index = 0;
	it = m.find(YANFA);
	cout << "�з���" << endl;
	for (;it != m.end() && index < m.count(YANFA);it++, index++)
	{
		cout << "������" << it->second.m_name << " ���ʣ�" << it->second.m_salary << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	vector<Worker> v;
	creatWorker(v);
	//printWorker(v);
	multimap<int, Worker> m;
	creatMap(m,v);
	showGroup(m);
}