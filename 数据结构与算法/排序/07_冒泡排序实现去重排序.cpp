#include <iostream>
using namespace std;
int main()
{
	int a[101], i, j, n, t, count;
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
	count = 1;
	for (i = 2;i <= n;i++)
	{
		if (a[i] != a[i - 1])
		{
			count++;
		}
	}
	cout << count << endl;
	cout << a[1];
	for (i = 2;i <= n;i++)
	{
		if (a[i] != a[i - 1])
		{
			cout << " " << a[i];
		}
	}
	system("pause");
	return 0;
}