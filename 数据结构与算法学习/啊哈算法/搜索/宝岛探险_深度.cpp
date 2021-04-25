#include<iostream>
using namespace std;

int a[51][51];
int book[51][51], n, m, sum;

void dfs(int x,int y)
{
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int k, tx, ty;

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
			dfs(tx, ty);
		}
	}
	return;
}

int main()
{
	int i, j, startx, starty;
	cin >> n >> m >> startx >> starty;
	for (i = 0;i < n;i++)
		for (j = 0;j < m;j++)
			cin >> a[i][j];

	book[startx][starty] = 1;
	sum = 1;
	dfs(startx, starty);

	cout << sum;
	return 0;
}