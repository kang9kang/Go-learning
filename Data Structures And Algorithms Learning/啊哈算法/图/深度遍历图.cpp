#include<iostream>
using namespace std;

int book[101], n, sum, e[101][101];

void dfs(int cur)
{
	int i;
	cout << cur << " ";
	sum++;
	if (sum == n)
	{
		return;
	}
	for (i = 1;i <= n;i++)
	{
		if (book[i] == 0 && e[cur][i] == 1)
		{
			book[i] = 1;
			dfs(i);
		}
	}
	return;
}

int main()
{
	int i, j, m, a, b;
	cin >> n >> m;
	for (i = 1;i <= n;i++)
		for (j = 1;j <= m;j++)
			if (i == j)e[i][j] = 0;
			else e[i][j] = 99999999;

	for (i = 1;i <= n;i++)
	{
		cin >> a >> b;
		e[a][b] = 1;
		e[b][a] = 1;
	}

	book[1] = 1;
	dfs(1);
	
}