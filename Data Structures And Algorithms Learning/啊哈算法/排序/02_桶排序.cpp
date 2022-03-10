#include<iostream>
using namespace std;
int main()
{
	int book[1001] = { 0 };
	int  i, j, t, n;
	cin >> n;
	for (i = 1;i <= n;i++)
	{
		cin >> t;
		book[t]++;
	}
	for (i = 1000;i >= 0;i--)
	{
		for (j = 1;j <= book[i];j++)
		{
			cout << i << " ";
		}
	}
	system("pause");
	return 0;
}