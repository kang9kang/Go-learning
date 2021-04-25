#include<iostream>
using namespace std;

int a[51][51];
int book[51][51],n,m,sum;

void dfs(int x, int y, int color)
{
	int next[4][2] = { {0,1},{1,0},{0,-1} ,{-1,0} };
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
			sum++;
			book[tx][ty] = 1;
			dfs(tx, ty,color);
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
	dfs(startx, starty, -1);

	for (i = 0;i < n;i++)
	{
		for (j = 0;j < m;j++)
		{
			printf("%3d", a[i][j]);
		}
		cout << endl;
	}
	return 0;
}