#include<iostream>
using namespace std;
int main()
{
	int data[101], right[101];
	int i, n, t, len;
	cin >> n;
	for (i = 1;i <= n;i++)
		cin >> data[i];
	len = n;
	for (i = 1;i <= n;i++)
	{
		if (i != n)
			right[i] = i + 1;
		else
			right[i] = 0;
	}

	len++;
	cin >> data[len];

	t = 1;
	while (t != 0)
	{
		if (data[right[t]] > data[len])
		{
			right[len] = right[t];
			right[t] = len;
			break;
		}
		t = right[t];
	}

	t = 1;
	while (t != 0)
	{
		cout << data[t] << " ";
		t = right[t];
	}
	system("pause");
	return 0;
}