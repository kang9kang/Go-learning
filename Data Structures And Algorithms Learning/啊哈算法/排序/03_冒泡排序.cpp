#include<iostream>
using namespace std;
int main()
{
	int a[100], i, j, n, t;
	cin >> n;
	for (i = 1;i <= n;i++) 
	{
		cin >> a[i];
	}
	for (i = 1;i <= n - 1;i++)
	{
		for (j = 1;j <= n - i;j++)
		{
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	for (i = 1;i <= n;i++)
	{
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}