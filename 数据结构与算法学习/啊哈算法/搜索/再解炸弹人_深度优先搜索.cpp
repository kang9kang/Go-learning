#include<iostream>
using namespace std;

char a[20][21];
int book[20][20], max1, mx, my, n, m;

int getnum(int i, int j)
{
	int sum, x, y;
	sum = 0;
	x = i;y = j;

	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		x--;
	}

	x = i;y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		x++;
	}

	x = i;y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		y--;
	}

	x = i;y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		y++;
	}

	return sum;

}

void dfs(int x, int y)
{
	int next[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	int k, sum, tx, ty;
	sum = getnum(x, y);

	if (sum > max1)
	{
		max1 = sum;
		mx = x;my = y;
	}

	for (k = 0;k < 4;k++)
	{
		tx = x + next[k][0];
		ty = y + next[k][1];

		if (tx<0 || tx>n - 1 || ty<0 || ty>m - 1)
			continue;

		if (a[tx][ty] == '.' && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			dfs(tx, ty);
		}
	}
	return;
}

int main()
{
	int i, startx, starty;
	cin >> n >> m >> startx >> starty;
	for (i = 0;i < n;i++)
		cin >> a[i];

	book[startx][starty] = 1;
	max1 = getnum(startx, starty);
	mx = startx;my = starty;
	dfs(startx, starty);

	cout << "将炸弹放置在(" << mx << "," << my << ")处，可以消灭" << max1 << "个敌人" << endl;
	return 0;
}