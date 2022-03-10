#include <iostream>
using namespace std;

int a[101], n;

void quicksort(int left, int right)
{
	if (left > right)
	{
		return;
	}

	int temp, i, j, t;
	temp = a[left];
	i = left;
	j = right;
	while (i != j)
	{
		while (a[j] >= temp && i < j)
		{
			j--;
		}
		while (a[i] <= temp && i < j)
		{
			i++;
		}
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];
	a[i] = temp;

	quicksort(left, i - 1);
	quicksort(i + 1, right);
}

int main()
{
	int i;
	cin >> n;
	for (i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	quicksort(1, n);
	int count = 1;
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