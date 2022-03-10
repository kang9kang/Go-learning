#include<iostream>
using namespace std;

class node
{
public:
	int x;
	int y;
	int s;
	int f;
};

int main()
{
	node que[2501];
	int a[51][51] = { 0 }, book[51][51] = { 0 };
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int head, tail;
	int i, j, k, n, m, startx, starty, p, q, tx, ty, flag;

	cin >> n >> m;
	for (i = 1;i <= n;i++)
		for (j = 1;j <= m;j++)
			cin >> a[i][j];
	cin >> startx >> starty >> p >> q;

	head = 1;tail = 1;

	que[tail].x = startx;que[tail].y = starty;que[tail].s = 0;que[tail].f = 0;
	tail++;
	book[startx][starty] = 1;

	flag = 0;

	while (head < tail)
	{
		for (k = 0;k <= 3;k++)
		{
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			if (tx<1 || tx>n || ty<1 || ty>m)
				continue;
			if (a[tx][ty] == 0 && book[tx][ty] == 0)
			{
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].f = head;
				que[tail].s = que[head].s + 1;
				tail++;
			}

			if (tx == p && ty == q)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			break;
		}
		head++;
	}
	cout << que[tail - 1].s;
	return 0;
}