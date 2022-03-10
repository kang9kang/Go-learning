#include<iostream>
using namespace std;

int f[1000] = { 0 }, n, m, k, sum = 0;
void init()
{
	int i;
	for (i = 1;i <= n;i++)
		f[i] = i;
}

int getf(int v)
{
	if (f[v] == v)
		return v;
	else
	{
		f[v] = getf(f[v]);
		return f[v];
	}
}
void merge(int v, int u)
{
	int t1, t2;
	t1 = getf(v);
	t2 = getf(u);
	if (t1 != t2)
	{
		f[t2] = t1;
	}
}

int main()
{
	int i, x, y;
	cin >> n >> m;

	init();
	for (i = 1;i <= m;i++)
	{
		cin >> x >> y;
		merge(x, y);
	}

	for (i = 1;i <= n;i++)
	{
		if (f[i] == i)
			sum++;
	}

	cout << sum << endl;
}