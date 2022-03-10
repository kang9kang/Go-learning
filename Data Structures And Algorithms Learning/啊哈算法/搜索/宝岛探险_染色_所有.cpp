#include<iostream>
using namespace std;

int a[51][51];
int book[51][51], n, m, sum;

void dfs(int x, int y, int color)
{
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int k, tx, ty;
	a[x][y] = color;
	for (k = 0;k < 4;k++)
	{
		tx = x + next[k][0];
		ty = y + next[k][1];

		if (tx<0 || tx>=n || ty<0 || ty>=m)
			continue;

		if (a[tx][ty] > 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			sum++;
			dfs(tx, ty, color);

		}
	}
	return;
}

int main()
{
	int i, j, num = 0;
	cin >> n >> m;
	for (i = 0;i < n;i++)
		for (j = 0;j < m;j++)
			cin >> a[i][j];
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < m;j++)
		{
			if (a[i][j] > 0)
			{
				num--;
				book[i][j] = 1;
				dfs(i, j, num);
			}
		}
	}

	for (i = 0;i < n;i++)
	{
		for (j = 0;j < m;j++)
		{
			printf("%3d", a[i][j]);
		}
		cout << endl;
	}

	cout << "Ð¡µº¸öÊý" << -num;
	return 0;
}