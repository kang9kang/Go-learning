#include<iostream>
using namespace std;

class note
{
public:
	int x;
	int y;
};

char a[20][21];

int getnum(int i, int j)
{
	int sum, x, y;
	sum = 0;
	x = i;y = j;

	while (a[x][y] != '#')
	{
		if(a[x][y] == 'G')
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

int main()
{
	note que[401];
	int head, tail;
	int book[20][20] = { 0 };
	int i, k, sum, max = 0, mx, my, n, m, startx, starty, tx, ty;

	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

	cin >> n >> m >> startx >> starty;

	for (i = 0;i < n;i++)
		cin >> a[i];

	head = 1;tail = 1;

	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;

	max = getnum(startx, starty);
	mx = startx;
	my = starty;


	while (head < tail)
	{
		for (k = 0;k < 4;k++)
		{
			tx = que[head].x+next[k][0];
			ty = que[head].y+next[k][1];


			if (tx<1 || tx>n - 1 || ty<1 || ty>m - 1)
				continue;

			if (a[tx][ty] == '.' && book[tx][ty] == 0)
			{
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;

				sum = getnum(tx, ty);

				if (sum > max)
				{
					max = sum;
					mx = tx;
					my = ty;
				}
			}
		}
		head++;
	}
	cout << "将炸弹放置在(" << mx << "," << my << ")处，可以消灭" << max << "个敌人" << endl;
	return 0;
}