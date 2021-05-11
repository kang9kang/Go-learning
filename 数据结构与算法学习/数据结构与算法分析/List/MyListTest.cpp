#include<iostream>
using namespace std;
#include<MyList.h>

int main()
{
	List<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);

	lst.insert(lst.begin(), 7);

	for (auto it = lst.begin();it != lst.end();it++)
	{
		cout << *it << endl;
	}

	lst.erase(++lst.begin());

	for (auto it = lst.begin();it != lst.end();it++)
	{
		cout << *it << endl;
	}
}