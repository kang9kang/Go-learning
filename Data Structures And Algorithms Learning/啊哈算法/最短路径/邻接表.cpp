#include<iostream>
using namespace std;

int main()
{
	int n, m, i;
	int u[6], v[6], w[6];
	int first[6], next[6];
	cin >> n >> m;
	for (i = 1;i <= n;i++)
		first[i] = -1;
	for (i = 1;i <= m;i++)
	{
		cin >> u[i] >> v[i] >> w[i];
		next[i] = first[u[i]];
		first[u[i]] = i;
	}
	for (i = 1;i <= n;i++)
	{
		int k = first[i];
		while (k != -1)
		{
			cout << u[k] << v[k] << w[k]<<endl;
			k = next[k];
		}
	}
}