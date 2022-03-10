#include<iostream>
using namespace std;

class note
{
public:
	int x;
	int y;
};

int main()
{
	note que[2501];
	int head, tail;
	int a[51][51];
	int book[51][51] = { 0 };
	int i, j, k, n, m, sum, max = 0, mx, my, startx, starty, tx, ty;
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

	cin >> n >> m >> startx >> starty;

	for (i = 0;i < n;i++)
		for (j = 0;j < m;j++)
			cin >> a[i][j];

	head = 1;tail = 1;
	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	sum = 1;

	while (head < tail)
	{
		for (k = 0;k < 4;k++)
		{
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			if (tx<0 || tx>=n || ty<0 || ty>=m)
				continue;

			if (a[tx][ty] > 0 && book[tx][ty] == 0)
			{
				sum++;
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;
			}

		}
		head++;
	}

	cout << sum << endl;
	return 0;
}