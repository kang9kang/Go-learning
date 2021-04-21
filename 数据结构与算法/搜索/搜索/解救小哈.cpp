#include<iostream>


int q,p,n,m,min=99999999;
int a[51][51], book[51][51];

void dfs(int x, int y, int step)
{
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int tx, ty;

	if (x == p && y == q)
	{
		if (min > step)
		{
			min = step;

			return;
		}
	}

	for (int k = 0;k <= 3;k++)
	{
		tx = x + next[k][0];
		ty = y + next[k][1];
		if (tx<1 || tx>n || ty<1 || ty>m)
		{
			continue;
		}
		if (a[tx][ty] == 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			dfs(tx, ty, step + 1);
			book[tx][ty] = 0;
		}

	}

	return;
}

int main()
{
	int startx, starty;
	std::cin >> n >> m;
	for (int i = 1;i <=n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			std::cin >> a[i][j];
		}
	}

	std::cin >> startx >> starty >> p >> q;

	book[startx][starty] = 1;
	dfs(startx, starty, 0);

	std::cout << min;
	return 0;
}