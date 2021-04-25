#include<iostream>
using namespace std;
#include<myvector.h>

int main()
{
	Vector<int> v;
	if (v.empty())
	{
		cout << "v为空" << endl;
	}
	else
	{
		cout << "v的size为" << v.size()<<endl;
	}

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	cout << "v的size为" << v.size()<<endl;
	cout << "v的capacity为"<<v.capacity()<<endl;

	v.reserve(8);
	cout << "v的capacity为" << v.capacity() << endl;

	for (Vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	for (Vector<int>::const_iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	for (int i=0;i<v.size();i++)
	{
		cout << v[i]<<" ";
	}
	cout << endl;
}