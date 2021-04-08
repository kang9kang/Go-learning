#include<iostream>
using namespace std;
int main()
{
	int book[1001] = { 0 };
	int i, n, t, j;
	j = 0;
	cin >> n;
	for (i = 1;i <= n;i++)
	{
		cin >> t;
		if (book[t] != 1) 
		{
			book[t] = 1;
			j++;
		}
	}
	cout << j << endl;
	for (i = 1;i <= 1000;i++)
	{
		if (book[i] == 1)
		{
			cout << i << " ";
		}
	}
	system("pause");
	return 0;
}