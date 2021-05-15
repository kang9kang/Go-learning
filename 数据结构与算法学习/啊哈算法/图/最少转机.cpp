#include<iostream>
using namespace std;

struct note
{
	int x;
	int s;
};

int main()
{
	struct note que[2501];
	int e[51][51] = { 0 }, book[51] = { 0 };
	int head, tail;
	int i, j, n, m, a, b, cur, start, end, flag = 0;
	cin >> n >> m >> start >> end;
	for (i = 1;i <= n;i++)
		for (j = 1;j <= m;j++)
			if (i == j)e[i][j] = 0;
			else e[i][j] = 99999999;

	for (i = 1;i <= m;i++)
	{
		cin >> a >> b;
		e[a][b] = 1;
		e[b][a] = 1;
	}

	head = 1;tail = 1;

	que[tail].x = start;
	que[tail].s = 0;
	tail++;
	book[start] = 1;

	while (head < tail)
	{
		cur = que[head].x;
		for (j = 1;j <= n;j++)
		{
			if (e[cur][j] == 1 && book[j] == 0)
			{
				que[tail].x = j;
				que[tail].s = que[head].s + 1;
				tail++;
				book[j] = 1;

			}

			if (que[tail].x == end)
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
}
