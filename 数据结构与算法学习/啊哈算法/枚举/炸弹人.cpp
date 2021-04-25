#include<iostream>
using namespace std;
int main()
{
	char a[20][21];
	int i, j, sum, map = 0, p, q, x, y, n, m;
	cin >> n >> m;
	for (i = 0;i < n;i++)
		cin >> a[i];
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < m;j++)
		{
			if (a[i][j] == '.')
			{
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
				if (sum > map)
				{
					map = sum;
					p = i;
					q = j;
				}
			}
		}
	}
	cout << "将炸弹放置在(" << p << "," << q << ")，最多可以消灭" << map << "个敌人" << endl;
	system("pause");
	return 0;
}