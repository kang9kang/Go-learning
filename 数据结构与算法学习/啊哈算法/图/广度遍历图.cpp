#include<iostream>
using namespace std;

int main()
{
	int i, j, n, m, a, b, cur, book[101] = { 0 }, e[101][101];
	int que[10001], head, tail;
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

	head = 1;
	tail = 1;
	que[tail] = 1;
	tail++;
	book[1] = 1;

	while (head < tail)
	{
		cur = que[head];
		for (i = 1;i <= n;i++)
		{
			if (e[cur][i] == 1 && book[i] == 0)
			{
				que[tail] = i;
				tail++;
				book[i] = 1;
			}

			if (tail > n)
			{
				break;
			}
		}
		head++;
	}

	for (i = 1;i < tail;i++)
		cout << que[i] << " ";
}